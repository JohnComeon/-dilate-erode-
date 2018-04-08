#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int elementsize = 3;
int maxsize = 21;
char Outputwin[] = "output image";
void on_Trackerbar(int, void*);     //函数声明
Mat src,dst;
int main()
{
	src = imread("C:\\IMAGE\\3.jpg");
	if (!src.data)
	{
		printf("could not load...");
			return -1;
	}
	namedWindow("input image",CV_WINDOW_AUTOSIZE);
	imshow("input image",src);

	namedWindow(Outputwin,CV_WINDOW_AUTOSIZE);
	createTrackbar("Element_size", Outputwin, &elementsize, maxsize,on_Trackerbar);
//创建滑动条函数createTracker(轨迹条的名字,窗口的名字,滑块的初始位置的地址指针,滑块最大位置处，指向回调函数的指针-函数名为指向函数地址的指针) 

	on_Trackerbar(0, 0);

	waitKey(0);
	return 0;
}
void on_Trackerbar(int, void*)
{
	int s = elementsize * 2 + 1;
	Mat structureElement = getStructuringElement(MORPH_RECT,Size(s,s),Point(-1,-1));
	dilate(src,dst, structureElement,Point(-1,-1));     //膨胀函数dilate(src,dst,膨胀操作的核,锚点位置)
	//erode(src,dst,structureElement,Point(-1,-1),1);   //腐蚀函数erode()
	imshow(Outputwin, dst);    
	return;
}