#pragma once
#include"��ͼ.h"
#include"����.h"
void printtitle()
{
	printf("---------------------------��ӭʹ��Dead4left����ͼ��������---------------------------\n");
	printf("��ѧ����������\nPI---Բ����\ne---��Ȼ����\nQ---�ƽ�ָ���\nK---Khinchin����\nO---ŷ������\n");
	printf("-----------------------------------------------------------------------------------------------\n");
}

char menu()
{
	printf("����������1-5ѡ��������Ҫ�Ĺ��ܣ�\n1.���뺯�����ʽ�����Ƴ�����ͼ��\n2.�����󵼹���\n3.�ı亯��ͼ�����\n4.����ͼ��\n5.�˳�");
	printf("-----------------------------------------------------------------------------------------------\n");
	char choice = getchar();
	return choice;
}

void choice2()
{
	char input[100];
	printf("��������ʽ:");
	scanf("%s", input);
	constant(input);
	buquan(input);
	float x;
	printf("\n�󵼵�:");
	scanf("%f", &x);
	int n;
	printf("\n������");
	scanf("%d", &n);
	float d = qiudao(input, x, n);
	printf("�õ�ĵ���ֵΪ%f\n", d);
}