#include "imagedemo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Imagedemo w;
	w.show();
	
	return a.exec();
}
