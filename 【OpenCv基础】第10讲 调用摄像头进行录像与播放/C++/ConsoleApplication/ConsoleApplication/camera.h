/* ����ͷ�����������Զ����� */

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <iostream>    
#include <opencv2\opencv.hpp>    
#include <opencv2\highgui\highgui.hpp>    
#include <fstream> 

using namespace cv;
using namespace std;

// ��ǰ֧�ֵ�����ͷ��Ŀ
#define MAXDEV  10

class Camera
{
	public:
		bool CameraInit(int capid, int rows, int cols);// ��ʼ��ָ��ID������ͷ
		Mat CameraImg(int capid);                      // ��ȡָ���豸��һ֡ͼ��
		int RefreshCameraNum();                        // ��ȡ��ǰ���õ�����ͷ��Ŀ

	private:
		VideoCapture Cap[MAXDEV]; // ����ʵ����Ŀ���������ɴﵽ��������ͷ��Ŀ
};

#endif

