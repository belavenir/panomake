// C++ 标准库
#include <iostream>
#include <string>
using namespace std;

// OpenCV 库
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

// PCL 库
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

// 定义点云类型
typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloud;

const double PI = 3.14159265358;
const int ROWS = 256;
const int COLS = 512;


// 主函数
int main( int argc, char** argv )
{
    // 读取./data/rgb.png和./data/depth.png，并转化为点云

    // 图像矩阵
    cv::Mat rgb;
    // 使用cv::imread()来读取图像
    // API: http://docs.opencv.org/modules/highgui/doc/reading_and_writing_images_and_video.html?highlight=imread#cv2.imread
    rgb = cv::imread( "../data/pano.png" );
    // rgb 图像是8UC3的彩色图像
    // depth 是16UC1的单通道图像，注意flags设置-1,表示读取原始数据不做任何修改
 	

 	float depth[ROWS][COLS];

    FILE *file = fopen("../data/depth.csv", "r");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(file, "%f,", &depth[i][j]);
        }
    }


    // 点云变量
    // 使用智能指针，创建一个空点云。这种指针用完会自动释放。
    PointCloud::Ptr cloud ( new PointCloud );
    // 遍历深度图
    for (int m = 0; m < rgb.rows; m++)
        for (int n=0; n < rgb.cols; n++)
        {
            // 获取深度图中(m,n)处的值

            float xnormalize = (rgb.cols-n-1.0)/(rgb.cols-1.0);
            float ynormalize = (rgb.rows-m-1.0)/(rgb.rows-1.0);

            float theta =  xnormalize * (2*PI) + PI/2;
            float phi = ynormalize* PI;

            float d =  depth[m][n];

            if (d == 0)
            {
            	d = 90.0;
            }

        
            // d 存在值，则向点云增加一个点
            PointT p;

            // 计算这个点的空间坐标
            p.z = d*cos(phi);
            p.x = d*sin(phi) * cos(theta);
            p.y = d*sin(phi) * sin(theta);


            // 从rgb图像中获取它的颜色
            // rgb是三通道的BGR格式图，所以按下面的顺序获取颜色
            p.b = rgb.ptr<uchar>(m)[n*3];
            p.g = rgb.ptr<uchar>(m)[n*3+1];
            p.r = rgb.ptr<uchar>(m)[n*3+2];

            // 把p加入到点云中
            cloud->points.push_back( p );
        }
    // 设置并保存点云
    cloud->height = 1;
    cloud->width = cloud->points.size();
    cout<<"point cloud size = "<<cloud->points.size()<<endl;
    cloud->is_dense = false;
    pcl::io::savePCDFile( "./pointcloud.pcd", *cloud );
    // 清除数据并退出
    cloud->points.clear();
    cout<<"Point cloud saved."<<endl;
    return 0;
}
