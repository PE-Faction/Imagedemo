#ifndef BINARIZATIONWINDOW1_H
#define BINARIZATIONWINDOW1_H

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



class BinarizationWIndow1 : public QWidget
{
	Q_OBJECT

public:
	BinarizationWIndow1(QWidget *parent = 0);
	~BinarizationWIndow1();
	int temp;
public slots:
	void onSpinValueChanged(int i);
	void getImage(IplImage *img);
	IplImage* sendImage(IplImage *img);

private:
	IplImage *img;
	Ui::BinarizationWIndow1 ui;
};

#endif // BINARIZATIONWINDOW1_H
