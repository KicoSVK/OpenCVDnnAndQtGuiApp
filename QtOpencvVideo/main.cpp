#include "QtOpencvVideo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtOpencvVideo w;
	w.show();
	return a.exec();
}
