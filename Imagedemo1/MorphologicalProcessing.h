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
	IplImage* corrosion(IplImage *img); //∏Ø ¥
	IplImage* expand(IplImage *img);  //≈Ú’Õ
	IplImage* OpenOperation(IplImage *img);//ø™‘ÀÀ„
	IplImage* ClosedOperation(IplImage *img);//±’‘ÀÀ„
	IplImage* MorphologicalGradient(IplImage *img);//–ŒÃ¨—ßÃ›∂»
	IplImage* TopHatTransformation(IplImage *img);//∂•√±±‰ªª
	IplImage* TroughDetection(IplImage *img);//≤®π»ºÏ≤‚


};







#endif //MORPHOLOGICALPROCESSING_H