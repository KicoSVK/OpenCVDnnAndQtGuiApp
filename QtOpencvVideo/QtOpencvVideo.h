#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtOpencvVideo.h"

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <QCloseEvent>
#include <QMessageBox>
#include <fstream>

#include "opencv2/opencv.hpp"
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace dnn;
using namespace std;

class QtOpencvVideo : public QMainWindow
{
	Q_OBJECT

protected:
	void closeEvent(QCloseEvent* event);

public:
	QtOpencvVideo(QWidget* parent = Q_NULLPTR);
	// Initialize the parameters
	float confThreshold = 0.5; // Confidence threshold
	float nmsThreshold = 0.4;  // Non-maximum suppression threshold
	int inpWidth = 416;  // Width of network's input image
	int inpHeight = 416; // Height of network's input image
	vector<string> classes;

private:
	Ui::QtOpencvVideoClass ui;

	QGraphicsPixmapItem pixmap;
	cv::VideoCapture cap;
	// Remove the bounding boxes with low confidence using non-maxima suppression
	void postprocess(Mat& frame, const vector<Mat>& out);
	// Draw the predicted bounding box
	void drawPred(int classId, float conf, int left, int top, int right, int bottom, Mat& frame);
	// Get the names of the output layers
	vector<String> getOutputsNames(const Net& net);

private slots:
	void on_startBtn_pressed();
};
