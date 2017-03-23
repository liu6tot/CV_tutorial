// eg151.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<opencv2/opencv.hpp>
using namespace cv;

void main()
{
	Mat srcImage = imread("jdsd.jpg");
	imshow("1st Title",srcImage);
	waitkey(0);
	//return 0;
}

