﻿/*
OpenCv版本 opencv-4.5.5-vc14_vc15
内容：canny边缘检测
博客：http://www.bilibili996.com/Course?id=4371839000008
作者：高仁宝
时间：2023.11
*/

#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
	//载入原始图  
	Mat srcImage = imread("../images/orange.jpg");
	Mat srcImage1 = srcImage.clone();

	//显示原始图 
	imshow("【原始图】Canny边缘检测", srcImage);

	//----------------------------------------------------------------------------------
	//	一、最简单的canny用法，拿到原图后直接用。
	//	注意：此方法在OpenCV2中可用，在OpenCV3中已失效
	//----------------------------------------------------------------------------------
	//Canny(srcImage, srcImage, 150, 100, 3);
	//imshow("【效果图】Canny边缘检测", srcImage);

	//----------------------------------------------------------------------------------
	//	二、高阶的canny用法，转成灰度图，降噪，用canny，最后将得到的边缘作为掩码，拷贝原图到效果图上，得到彩色的边缘图
	//----------------------------------------------------------------------------------
	Mat dstImage, edge, grayImage;

	// 【1】创建与src同类型和大小的矩阵(dst)
	dstImage.create(srcImage1.size(), srcImage1.type());

	// 【2】将原图像转换为灰度图像
	cvtColor(srcImage1, grayImage, COLOR_BGR2GRAY);

	// 【3】先用使用 3x3内核来降噪
	blur(grayImage, edge, Size(3, 3));

	// 【4】运行Canny算子
	Canny(edge, edge, 3, 9, 3);

	//【5】将g_dstImage内的所有元素设置为0 
	dstImage = Scalar::all(0);

	//【6】使用Canny算子输出的边缘图g_cannyDetectedEdges作为掩码，来将原图g_srcImage拷到目标图g_dstImage中
	srcImage1.copyTo(dstImage, edge);

	//【7】显示效果图 
	imshow("【效果图】Canny边缘检测2", dstImage);

	waitKey(0);

	return 0;
}