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
 ���ͼ��ĵ�����ľ���ķ���������
*/
class pointOperation
{
public:
	IplImage* colorGrayScale(IplImage* img);   //ͼ��ת�ҽ�
	IplImage* ImageInversion(IplImage* img);   //ͼ����*  VerticalMirror(IplImage* img);  //��ֱ����
	IplImage*  HorizontalMirror(IplImage* img);  //ˮƽ����
	IplImage* VerticalMirror(IplImage* img);   //��ֱ���� 
	IplImage*  _180DegreeRotation(IplImage* img);  //180����ת
	IplImage*  _30DegreeRotation(IplImage* img);    //30����ת
	IplImage*  AffineTransformation(IplImage* img);  //����任
	IplImage*  PerspectiveTransformation(IplImage* img);//͸�ӱ任
    IplImage*  BrightnessTransformation(IplImage* img); //���ȱ任
	IplImage*  GrayscaleImageHistogram(IplImage* img);//�ҽ�ͼ��ֱ��ͼ
	IplImage* HistogramEqualization(IplImage* img); //ֱ��ͼ���⻯
};


#endif // POINTOPERATION_H