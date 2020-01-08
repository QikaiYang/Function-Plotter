#pragma once
#include"画图.h"
#include"输入.h"
void printtitle()
{
	printf("---------------------------欢迎使用Dead4left函数图像绘制软件---------------------------\n");
	printf("数学常量声明：\nPI---圆周率\ne---自然常数\nQ---黄金分隔率\nK---Khinchin常数\nO---欧拉常数\n");
	printf("-----------------------------------------------------------------------------------------------\n");
}

char menu()
{
	printf("请输入数字1-5选择你所需要的功能：\n1.输入函数表达式并绘制出函数图像\n2.定点求导功能\n3.改变函数图象比例\n4.保存图像\n5.退出");
	printf("-----------------------------------------------------------------------------------------------\n");
	char choice = getchar();
	return choice;
}

void choice2()
{
	char input[100];
	printf("函数解析式:");
	scanf("%s", input);
	constant(input);
	buquan(input);
	float x;
	printf("\n求导点:");
	scanf("%f", &x);
	int n;
	printf("\n阶数：");
	scanf("%d", &n);
	float d = qiudao(input, x, n);
	printf("该点的导数值为%f\n", d);
}