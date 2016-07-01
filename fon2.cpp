// fon2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	

 
/**
* @function main
*/

//CvCapture* capture;
CvCapture* tcapture;
IplImage* frame = 0;
//IplImage* gframe = 0;
IplImage* fon=0;
//IplImage* gfon=0;
CvArr* tmp1=0;
CvArr* tmp2=0;
//IplImage* dst=0;
//IplImage* grey = cvCreateImage( cvGetSize(img0), IPL_DEPTH_8U, 1 );
//////////////////////////определение размера
tcapture = cvCaptureFromCAM(0);
cvNamedWindow("Fon", CV_WINDOW_AUTOSIZE);
fon = cvQueryFrame( tcapture );
////// тест
/*while (true)
{
fon = cvQueryFrame( tcapture );
cvShowImage("Fon", fon);
 char c = cvWaitKey(1);
                if (c == 27) { // нажата ESC
                        break;
                }
}*/
//cvNamedWindow("Fon", CV_WINDOW_AUTOSIZE);
//cvShowImage("Fon", fon);
IplImage* gfon = cvCreateImage( cvGetSize(fon), IPL_DEPTH_8U , 1 );
IplImage* gframe = cvCreateImage( cvGetSize(fon), IPL_DEPTH_8U, 1 );
IplImage* dst = cvCreateImage( cvGetSize(fon), IPL_DEPTH_8U , 1 );
////////////////////////////////////////////////////////////////////
bool t=true ;
 while (t)
{
//Read the video stream
//capture = cvCaptureFromCAM(0);
fon = cvQueryFrame( tcapture );
//IplImage* grey = cvCreateImage( cvGetSize(fon), IPL_DEPTH_8U, 1 );
// create a window to display detected faces
cvNamedWindow("Fon", CV_WINDOW_AUTOSIZE);
cvCvtColor( fon,gfon,CV_RGB2GRAY );
//(fon, tmp1, 0.5, 128);

cvShowImage("Fon", gfon);

int c = cvWaitKey(10);
if( (char )c == 's' ) { t=false ; }
 
}

while (true )
{
//Read the video stream
//capture = cvCaptureFromCAM(0);
frame = cvQueryFrame( tcapture );
cvNamedWindow("Sample Program", CV_WINDOW_AUTOSIZE);
//IplImage* greyfr = cvCreateImage( cvGetSize(frame), IPL_DEPTH_8U, 1 );
/////////////////////преобразование и вычитание
cvCvtColor( frame,gframe,CV_RGB2GRAY);
//cvConvertScale(frame, tmp2, 0.5, 0);
//dst = frame - fon;
cvSub(gfon, gframe, dst);// вычитание фона

// create a window to display detected faces

 
// display face detections
cvShowImage("Sample Program", dst);
 
int c = cvWaitKey(10);
if( (char )c == 'z' ) { exit(0); }
 
}
 
// clean up and release resources
cvReleaseImage(&frame);

	return 0;
}

