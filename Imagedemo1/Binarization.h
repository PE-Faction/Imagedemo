#ifndef BINARIZATION_H
#define BINARIZATION_H

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include<cv.h>
#include<highgui.h>
#include<opencv2\core\core.hpp>
#include <Qsize>
#include <QFileDialog>
#include <QDebug>
#include <iostream>
#include <cmath>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>


/*
  ʵ�ֶ�ֵ������صĲ���
*/
class Binarization
{
public:
	IplImage *SelectTheThreshold(IplImage *img);    //�Զ�����ֵ��ֵ��
	IplImage *AdaptiveThreshold(IplImage *img);   //����Ӧ��ֵ��
	IplImage *BasedOnGlobalThreshold(IplImage *img);//���ɷ���ֵ��
   
};
#endif // BINARIZATION_H