#ifndef BINARIZATIONWINDOW_H
#define BINARIZATIONWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_BinarizationWindow1.h"
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

using namespace  cv;
using namespace std;

class BinarizationWindow : public QDialog
{
	Q_OBJECT

public:
	BinarizationWindow(QWidget *parent = 0);
	~BinarizationWindow();
private:
	Ui::BinarizationWindow ui;

}
#endif //  BINARIZATIONWINDOW_H