#ifndef POINTOPERATION_H
#define POINTOPERATION_H

#include <QtWidgets/QMainWindow>
#include "ui_imagedemo.h"
#include <QMessageBox>
#include<cv.h>
#include<highgui.h>
#include<opencv2\core\core.hpp>
#include <Qsize>
#include <QFileDialog>
#include <QDebug>
#include <iostream>
#include <cmath>

using namespace  cv;
using namespace std;
/*
 完成图像的点操作的具体的方法的声明
*/
class pointOperation
{
public:
	IplImage* colorGrayScale(IplImage* img);   //图像转灰阶
	IplImage* ImageInversion(IplImage* img);   //图像反相*  VerticalMirror(IplImage* img);  //垂直镜像
	IplImage*  HorizontalMirror(IplImage* img);  //水平镜像
	IplImage* VerticalMirror(IplImage* img);   //垂直镜像 
	IplImage*  _180DegreeRotation(IplImage* img);  //180度旋转
	IplImage*  _30DegreeRotation(IplImage* img);    //30度旋转
	IplImage*  AffineTransformation(IplImage* img);  //放射变换
	IplImage*  PerspectiveTransformation(IplImage* img);//透视变换
    IplImage*  BrightnessTransformation(IplImage* img); //亮度变换
	IplImage*  GrayscaleImageHistogram(IplImage* img);//灰阶图像直方图
	IplImage* HistogramEqualization(IplImage* img); //直方图均衡化
};


#endif // POINTOPERATION_H