﻿#include <opencv2/opencv.hpp>
using namespace cv;

//为窗口标题定义的宏 
#define WINDOW_NAME "【程序窗口】"

Rect g_rectangle;
bool g_bDrawingBox = false;//是否进行绘制
RNG g_rng(12345);

void DrawRectangle(cv::Mat& img, cv::Rect box)
{
    cv::rectangle(img, box.tl(), box.br(), cv::Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255)));//随机颜色
}

void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
    Mat& image = *(cv::Mat*)param;
    switch (event)
    {
        //鼠标移动消息
    case EVENT_MOUSEMOVE:
    {
        if (g_bDrawingBox)//如果是否进行绘制的标识符为真，则记录下长和宽到RECT型变量中
        {
            g_rectangle.width = x - g_rectangle.x;
            g_rectangle.height = y - g_rectangle.y;
        }
    }
    break;

    //左键按下消息
    case EVENT_LBUTTONDOWN:
    {
        g_bDrawingBox = true;
        g_rectangle = Rect(x, y, 0, 0);//记录起始点
    }
    break;

    //左键抬起消息
    case EVENT_LBUTTONUP:
    {
        g_bDrawingBox = false;//置标识符为false
        //对宽和高小于0的处理
        if (g_rectangle.width < 0)
        {
            g_rectangle.x += g_rectangle.width;
            g_rectangle.width *= -1;
        }
        if (g_rectangle.height < 0)
        {
            g_rectangle.y += g_rectangle.height;
            g_rectangle.height *= -1;
        }
        //调用函数进行绘制
        DrawRectangle(image, g_rectangle);
    }
    break;
    }
}

void ShowHelpText()
{
    printf("当前使用的OpenCV版本为：" CV_VERSION);
    printf("\n请在窗口中点击鼠标左键并拖动以绘制矩形");
}

int main(int argc, char** argv)
{
    //【0】改变console字体颜色
    system("color 9F");

    //【0】显示欢迎和帮助文字
    ShowHelpText();

    //【1】准备参数
    g_rectangle = Rect(-1, -1, 0, 0);
    Mat srcImage(600, 800, CV_8UC3), tempImage;
    srcImage = Scalar::all(0);

    //【2】设置鼠标操作回调函数
    namedWindow(WINDOW_NAME);
    setMouseCallback(WINDOW_NAME, on_MouseHandle, (void*)&srcImage);

    //【3】程序主循环，当进行绘制的标识符为真时，进行绘制
    while (1)
    {
        srcImage.copyTo(tempImage);//拷贝源图到临时变量
        if (g_bDrawingBox) DrawRectangle(tempImage, g_rectangle);//当进行绘制的标识符为真，则进行绘制
        imshow(WINDOW_NAME, tempImage);
        if (waitKey(10) == 27) break;//按下ESC键，程序退出
    }
    return 0;
}

