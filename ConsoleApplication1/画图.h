#pragma once
#define _USE_MATH_DEFINES
#include<opencv2\opencv.hpp>
#include"输入.h"
#define background_length 1530
#define background_width 800


using namespace cv;
using namespace std;


float function(char arg[], float x);
void functioncolourchange(char arg[], float store[], float store1[], Mat Mat_background,int ratiochange);
void colourchange(int x_dot, int y_dot, int length, int width, Mat Mat1);
void drawaxis(Mat Mat_background,float);
int sgn(int m);



//初始化背景长宽，制作背景
Mat Mat_background(background_width, background_length, CV_8U, Scalar(255));


//定义一个函数
float function(char arg[], float x)
{
	float y = change(arg, x);
	return y;
}

//对所定义的函数进行变色
void functioncolourchange(char arg[], float store[], float store1[], Mat Mat_background,int ratiochange)
{
	Mat dst;//定义滤波器（待定）
	int m=0;
	int x_draw, y_draw, last_y_draw;                                     //前后两次的点
	for (m = 0;m < 1530;m++)
	{
		x_draw = background_length / 2 + int(ratiochange*store1[m]);     //注意坐标变换    
		y_draw = background_width / 2 - int(ratiochange*store[m]);
		if (m!=0)
		{
			x_draw = background_length / 2 + int(ratiochange*store1[m]);
			last_y_draw = background_width / 2 - int(ratiochange*store[m-1]);
		}
		if (y_draw < background_width&&y_draw>1&&x_draw<background_length&&x_draw>1)                                   //判断是否可画，相当于判断计算的点是否在屏幕规定范围内
		{
			colourchange(x_draw, y_draw, 1, 1, Mat_background);
		}
		if (m!=0)
		{
			if (x_draw<background_length&&x_draw>1&&y_draw < background_width&&y_draw>1 && last_y_draw < background_width&&last_y_draw>1 && abs(y_draw - last_y_draw) > 0.1)//判断是否存在两个连续y间距大于1
			{
				//补点
                //-----------------------------------------------原始补点法————————————————————————————————
				/*for (int i = 0; i <= int(abs(y_draw - last_y_draw)) / 2; i++) colourchange(x_draw - 1, last_y_draw + sgn(y_draw - last_y_draw)*i, 1, 1, Mat_background);
				for (int i = 0; i <int(abs(y_draw - last_y_draw)) / 2; i++) colourchange(x_draw, y_draw - sgn(y_draw - last_y_draw)*i, 1, 1, Mat_background);*/
				//---------------------------------------------改为用line函数——————————————————————————————————
				line(Mat_background,cvPoint(x_draw, y_draw), cvPoint(x_draw - 1, last_y_draw),Scalar(0));
			}
		}
		////尝试利用滤波消除锯齿断层，功能是否添加待定！！！！！！！！！！！！！！！运行速度的考虑
		//GaussianBlur(Mat_background,dst,Size(9,9),0,0);
		//namedWindow("MEDIAN BLUR", WINDOW_AUTOSIZE);
		//imshow("MEDIAN BLUR", dst);
	}
}


/*定义一个colourchange函数，输入变色区域左上角横纵坐标
,以及变色区域长宽，变化图片，进行变色
x_dot横坐标，y_dot纵坐标，length长， width宽，Mat1图片*/
void colourchange(int x_dot, int y_dot, int length, int width, Mat Mat1)
{
	//创建一个黑色的相对背景
	Mat Mat_black(background_width, background_length, CV_8U, Scalar(0));

	//选取ROI
	Mat Mat1ROI = Mat1(Rect(x_dot, y_dot, length, width));
	Mat Mat_blackROI = Mat_black(Rect(x_dot, y_dot, length, width));
	Mat Mat_output;
	addWeighted(Mat1ROI, 0, Mat_blackROI, 1, 0, Mat_output);

	//变色
	Mat_output.copyTo(Mat1ROI);
}

void changewhite(int x_dot, int y_dot, int length, int width, Mat Mat1)
{
	//创建一个黑色的相对背景
	Mat Mat_black(background_width, background_length, CV_8U, Scalar(255));

	//选取ROI
	Mat Mat1ROI = Mat1(Rect(x_dot, y_dot, length, width));
	Mat Mat_blackROI = Mat_black(Rect(x_dot, y_dot, length, width));
	Mat Mat_output;
	addWeighted(Mat1ROI, 0, Mat_blackROI, 1, 0, Mat_output);

	//变色
	Mat_output.copyTo(Mat1ROI);
}



//绘制x，y轴,绘制箭头
void drawaxis(Mat Mat_background,float ratiochange)
{
	int delta=10;
	line(Mat_background, cvPoint(0, background_width / 2), cvPoint(background_length , background_width / 2), Scalar(0,0,0));//x轴
	line(Mat_background, cvPoint(background_length / 2, 0), cvPoint(background_length / 2, background_width), Scalar(0, 0, 0));//y轴																					
	line(Mat_background, cvPoint(background_length - delta, background_width / 2 - delta), cvPoint(background_length, background_width / 2), Scalar(0, 0, 0));//x箭头
	line(Mat_background, cvPoint(background_length - delta, background_width / 2 + delta), cvPoint(background_length, background_width / 2), Scalar(0, 0, 0));
	line(Mat_background, cvPoint(background_length/2 - delta, delta), cvPoint(background_length / 2, 0), Scalar(0, 0, 0));//y箭头
	line(Mat_background, cvPoint(background_length / 2 + delta, delta), cvPoint(background_length / 2, 0), Scalar(0, 0, 0));
	float abscissa[11] = { 0 };
	for (int i = 0; i < 11; ++i)//x坐标
	{
		char a[10];
		int move = 15;
		abscissa[i] = (-750 + 150 * i) / ratiochange;
		sprintf(a, "%.1f", abscissa[i]);
		if (abscissa[i] == 0.0)continue;
		line(Mat_background, cvPoint(15 + i * 150, background_width / 2), cvPoint(15 + i * 150, background_width / 2 - 5), Scalar(0, 0, 0));
		putText(Mat_background, a, cvPoint(i * 150, background_width / 2 + move), CV_FONT_HERSHEY_DUPLEX, 0.4, Scalar(0, 0, 0));
	}
	float ordinate[7] = { 0 };
	for (int i = 0; i < 7; ++i)//y坐标
	{
		char b[10];
		int move = 15;
		ordinate[i] = (360 - 120 * i) / ratiochange;
		sprintf(b, "%.1f", ordinate[i]);
		line(Mat_background, cvPoint(background_length / 2, 40 + i * 120), cvPoint(background_length / 2 +10, 40 + i * 120), Scalar(0, 0, 0));
		putText(Mat_background, b, cvPoint(background_length / 2-50, 50 + i * 120), CV_FONT_HERSHEY_DUPLEX, 0.4, Scalar(0, 0, 0));
	}
}



//定义sgn函数
int sgn(int m)
{
	if (m > 0)
		return (1);
	if (m < 0)
		return(-1);
	if (m = 0)
		return(0);
}

