// eg151.cpp : �������̨Ӧ�ó������ڵ㡣
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

