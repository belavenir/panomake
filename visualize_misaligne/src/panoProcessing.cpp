#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace cv;

int main( int argc, char** argv )
{

const int ROWS = 256;
const int COLS = 512;


	float depth[ROWS][COLS];

    FILE *file = fopen("../data/depth/depth.csv", "r");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(file, "%f,", &depth[i][j]);
        }
    }

 	Mat src1;
 	/// Read image ( same size, same type )
	src1 = imread("../data/depth/depth.png");
	 Mat src2(src1.size(), CV_8UC3);



if( !src1.data ) { printf("Error loading src1 \n"); return -1; }




for(int i=0;i <src1.rows;i++) 
	for (int j=0;j<src1.cols;j++){
	if (depth[i][j] != 0 ) {//0-black 255 white
		src2.at<Vec3b>(i,j)[0]= 0;
		src2.at<Vec3b>(i,j)[1]= 0;
		src2.at<Vec3b>(i,j)[2]= 255;

	}else{

		src2.at<Vec3b>(i,j)[0]= 255;
		src2.at<Vec3b>(i,j)[1]= 255;
		src2.at<Vec3b>(i,j)[2]= 255;}

    }



 imwrite( "../data/depth/source.png", src2 );

 return 0;


}
