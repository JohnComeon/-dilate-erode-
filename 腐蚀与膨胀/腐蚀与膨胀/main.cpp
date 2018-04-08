#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int elementsize = 3;
int maxsize = 21;
char Outputwin[] = "output image";
void on_Trackerbar(int, void*);     //��������
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
//��������������createTracker(�켣��������,���ڵ�����,����ĳ�ʼλ�õĵ�ַָ��,�������λ�ô���ָ��ص�������ָ��-������Ϊָ������ַ��ָ��) 

	on_Trackerbar(0, 0);

	waitKey(0);
	return 0;
}
void on_Trackerbar(int, void*)
{
	int s = elementsize * 2 + 1;
	Mat structureElement = getStructuringElement(MORPH_RECT,Size(s,s),Point(-1,-1));
	dilate(src,dst, structureElement,Point(-1,-1));     //���ͺ���dilate(src,dst,���Ͳ����ĺ�,ê��λ��)
	//erode(src,dst,structureElement,Point(-1,-1),1);   //��ʴ����erode()
	imshow(Outputwin, dst);    
	return;
}