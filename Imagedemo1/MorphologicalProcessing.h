#ifndef MORPHOLOGICALPROCESSING_H
#define MORPHOLOGICALPROCESSING_H

#include <QWidget>
#include "ui_binarizationwindow1.h"
#include <QSpinBox>
#include <QHBoxLayout>
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
#include <windows.h>
#include <QScrollBar>

class MorphologicalProcessing
{
public:
	IplImage* corrosion(IplImage *img); //��ʴ
	IplImage* expand(IplImage *img);  //����
	IplImage* OpenOperation(IplImage *img);//������
	IplImage* ClosedOperation(IplImage *img);//������
	IplImage* MorphologicalGradient(IplImage *img);//��̬ѧ�ݶ�
	IplImage* TopHatTransformation(IplImage *img);//��ñ�任
	IplImage* TroughDetection(IplImage *img);//���ȼ��


};







#endif //MORPHOLOGICALPROCESSING_H