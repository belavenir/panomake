#include <iostream>
#include <string>

using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

// this is used to verify if the real depth (float) in csv equals to the depth (ushort uint16) in image

int main(int argc, char const *argv[])
{
	Mat depth;

	depth = imread("../data/depth.png",-1);


	ushort d1 = depth.ptr<ushort>(121)[0];
	cout << double(d1)/200 << endl; //200 is the scale value


	ushort d2 = depth.ptr<ushort>(0)[0];
	cout << double(d2)/200 << endl;


	ushort d3 = depth.ptr<ushort>(255)[0];
	cout << double(d3)/200 << endl;
	return 0;
}

