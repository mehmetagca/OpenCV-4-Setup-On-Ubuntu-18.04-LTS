#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("../lena.png");
    
    if (img.empty())
       {
	cout << "Image does not found!";
	return -1;
       }

    imshow("img", img);
    waitKey();

    return 0;
}
