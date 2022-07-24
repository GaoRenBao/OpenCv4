/* ����ͷ�����������Զ����� */

#include "Camera.h"

/*
����ͷ��ʼ��
capid:����ͷid
rows:ͼ��߶�
cols:ͼ����
 */
bool Camera::CameraInit(int capid, int rows, int cols)
{
	if (capid >= MAXDEV)
		return false;
	Cap[capid].open(capid);
	if (!Cap[capid].isOpened()) 
		return false;
	Cap[capid].set(CAP_PROP_FRAME_WIDTH, cols);
	Cap[capid].set(CAP_PROP_FRAME_HEIGHT, rows);
	//Cap[capid].set(CAP_PROP_BRIGHTNESS, 1);  //���� 1
	//Cap[capid].set(CAP_PROP_CONTRAST, 0);   //�Աȶ� 40
	//Cap[capid].set(CAP_PROP_SATURATION, 100); //���Ͷ� 50
	//Cap[capid].set(CAP_PROP_HUE, 0);        //ɫ�� 50
	//Cap[capid].set(CAP_PROP_EXPOSURE, 0);    //�ع� 50
	return true;
}

/*
��ȡһ֡ͼ��
capid:����ͷid
*/
Mat Camera::CameraImg(int capid)
{
	Mat Img;
	if (capid < MAXDEV)
		Cap[capid] >> Img;
	return Img;
}

/*
��ȡ��ǰ��������ͷ��Ŀ(��OpenCv3֧��)
*/
int Camera::RefreshCameraNum()
{
	CvCapture *m_Captrue;
	int i = 0;
	//10�Ǻ�����VideoCapture Cap[10]��Ӧ�ģ�����ʵ����Ŀ���������ɴﵽ��������ͷ��Ŀ
	//for (i = 0; i < MAXDEV; i++)
	//{
	//	m_Captrue = cvCreateCameraCapture(i);
	//	if (m_Captrue == NULL) break;
	//	cvReleaseCapture(&m_Captrue);//һ��Ҫ�ͷ� ���������̲�����ȫ�˳�
	//}
	return i;
}




