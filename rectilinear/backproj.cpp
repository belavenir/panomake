
#include <vector>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <iostream>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat backProjection(double &heading, Mat &pano, double &stepPano ){
	
	int image_height = 480; 
	int image_width  = 640; 
	Mat rectilinear(image_height, image_width, CV_8UC3);

	Mat R(3,3, CV_64F);

	//double heading; //z axis (0 - 2*M_PI)
	double pitch = 0;  //acorrding to camera on fly
	double roll =0; 

	double c1 = cos(heading*M_PI/180);
    double s1 = sin(heading*M_PI/180);
    double c2 = cos(pitch*M_PI/180);
    double s2 = sin(pitch*M_PI/180);

   	double m1[3][3] = {{c1,s1,0},{-s1,c1,0},{0,0,1}}; //heading counterclockwise
    double m2[3][3] = {{c2,0,-s2},{0,1,0},{s2,0,c2}};  //pitch

    Mat R1(3,3,CV_64F,m1);
    Mat R2(3,3,CV_64F,m2);

    //back projection
    //2D => 3D
    R =R1.t() * R2.t(); 


    //camera instrinsic parameters
		/*k = [f 0 cu
			0 f cv
			0 0 1] */

	//The fov is defined according to the focal lenth of camera on fly 
	double fov =  57.7890;
	double f = (double) image_width/(2*tan(fov*M_PI/180/2));
	double cu = (double) image_width /2;
	double cv = (double) image_height /2;


    for (int u = 0; u < image_width; u++){
    	for (int v = 0; v < image_height; v++)
    	{
    		//d = direction of 3D point in camera frame (z forward)
    		//d = inverse (k) * [u,v,1]^T suppose dz=1 
    		double dx = (double)(u-cu)/f;
    		double dy = (double)(cv-v)/f;
    		double dz = 1;//

    		Mat X(3,1,CV_64F); //3D point in image frame (x forward)

    		X.at<double>(0,0) = dz;
    		X.at<double>(1,0) = dx;
    		X.at<double>(2,0) = dy; 

    		Mat Xpano = R*X; // in panorama frame (x forward)

    		double x, y, z;
		    // here I choose psi in (0 2pi) while theta in (0 pi)
    		x = Xpano.at<double>(0,0); //=cos(psi)*sin(theta)
    		y = Xpano.at<double>(1,0); //=sin(psi)*sin(theta)
			z = Xpano.at<double>(2,0); //=cos(theta)

    		double psi; //psi in range (0, 2*Pi)

            if (y>=0 & x >0)
            {
               	psi = atan(y/x);
            }else if (y>0 & x<0)
            {
                psi = M_PI +atan(y/x);
           	}else if (y<0 & x<0)
            {
                psi  = M_PI+atan(y/x);
            }else{
                psi = 2*M_PI + atan(y/x);
            }

    		double theta = acos(z/sqrt(dx*dx+dy*dy+dz*dz)); // theta in range (0, pi)
    
            theta *= 180/M_PI;
    		psi *= 180/M_PI;
            
            //outfile << theta <<", " << psi << endl;

            double c, r; // col/row of pixel in panorama
    		c = (double)(psi)/stepPano;
    		r = (double)(theta)/stepPano;
    			
    		//cout << "c= " << c << ", r= " << r << endl;

    		if (isnan(c)||isnan(r) )
    		{
    			continue;
    		}else{
    			//
    			//Bilinear interpolation 
    			int cInt = int (c);
    			int rInt = int (r);
    			double thetaC = fabs(c -cInt);
    			double thetaR = fabs(r -rInt);
    				
                //cout << "pixel position =" << cInt <<", " << rInt << endl;
    				
    			Vec3b color1 = pano.at<Vec3b>(Point(cInt,rInt));
    			Vec3b color2 = pano.at<Vec3b>(Point(cInt,rInt+1));
    			Vec3b color3 = pano.at<Vec3b>(Point(cInt+1,rInt));
    			Vec3b color4 = pano.at<Vec3b>(Point(cInt+1,rInt+1)); 

    			Vec3b colorFinal = color1*(1-thetaC)*(1-thetaR) + color2*thetaR*(1-thetaC)
    							+ color3*(1-thetaR)*thetaC + color4*thetaR*thetaC;

    			rectilinear.at<Vec3b>(v, u) = colorFinal;

    		}
    	}
    }
return rectilinear;
}


int main(int argc, const char *argv[]){


	char *PANORAMA_PATH = new char[100];

	sprintf(PANORAMA_PATH, "../pano.png");
	cout << PANORAMA_PATH << endl;
	Mat pano = imread(PANORAMA_PATH);

	int pano_width = pano.cols;
	int pano_height = pano.rows;
	assert(pano_width == 2 * pano_height); // W : H = 2 : 1

	// create 8 virtual cameras 
	int num_camera = 6;
	double segment_length = (double)(pano_width)/(double)num_camera;
		

    //cout << "pitchMin="<< pitchMin <<" ,pitchMax=" << pitchMax <<endl;
	
	double stepPano = 360.0 / pano_width; //resolution in degree
	double angle_segment = (360.0) / (double)num_camera;


	for (int idx = 0; idx < num_camera; idx++)
	{
			// 8 virtual cameras' extrinsic parameters [R t], t doesn't change
			// in sphere frame
        	//ofstream outfile("/home/yu/Documents/Method1/data/panoNew/save.txt");
        	//double heading = angle_segment*(idx +1)- angle_segment/2.0;

        double heading = angle_segment*idx;
       	cout << heading << endl;
        	
        Mat rectilinear = backProjection(heading, pano, stepPano);

        char * savefile = new char[100];
        sprintf(savefile,"%s%d%s", "../result/virtual_rect_", idx, ".png");
        cout << savefile << endl;
        imwrite(savefile, rectilinear);
        delete [] savefile;
	}
	
	delete [] PANORAMA_PATH;

return 0;
}