#pragma once
#pragma warning (disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


float change(char *arg, float a);
float numberchange(char *arg, int i, int j);
void buquan(char *str);
void bianhuan(char str[], int i, int j, float a);
void kuohao(char str[], float a);
void dealfunction(char str[], float a);
void constant(char * arg);
void StrReplace(char* strSrc, char* strFind, char* strReplace);

//�������ţ�����˼�����ҵ����������ţ����㣬�ٵ���
void kuohao(char str[], float a)
{
	int flag[100] = { 0 }, cout = 0, max = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '(')
		{
			cout += 1;
			flag[i] = cout;
			if (max < flag[i])max = flag[i];
		}
		if (str[i] == ')')
		{
			cout -= 1;
			flag[i] = cout;
		}
	}
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == ')') flag[i] += 1;
	if (max != 0)
	{
		int c1, c2, ctl = 0;
		for (int i = 0; i < 100, ctl < 2; i++)
		{
			if (str[i] == '('&&flag[i] == max) { c1 = i; ctl += 1; }
			if (str[i] == ')'&&flag[i] == max) { c2 = i; ctl += 1; }
		}
		bianhuan(str, c1, c2, a);
		kuohao(str, a);
	}
}

//����i��j���arg���ٱ���ַ���Ƕ��ȥ
void bianhuan(char str[], int i, int j, float a)
{
	char qian[100] = { 0 }, hou[100] = { 0 };
	for (int n = 0; n < i; n++)qian[n] = str[n];
	strcpy(hou, str + j + 1);
	char zhong[100] = { 0 }; int cout = 0;
	for (int n = i + 1; n < j; n++)zhong[cout++] = str[n];
	char jieguo[100] = { 0 };
	sprintf(jieguo, "%f", change(zhong, a));
	for (int n = i; n < i + strlen(jieguo); n++)
		qian[n] = jieguo[n - i];
	for (int n = i + strlen(jieguo); n < i + strlen(jieguo) + strlen(hou); n++)
		qian[n] = hou[n - i - strlen(jieguo)];
	strcpy(str, qian);
}

//��where�����ַ�
void insert(char a[], char num, int where)
{
	int i;
	for (i = strlen(a); i >= where; i--)		 a[i + 1] = a[i];
	a[i + 1] = num;
}

//sin����
void dealfunction_sin(char str[], float a)
{
	int sign[10] = { 0 }, cout = 0;
	for (int i = 0; i < strlen(str); ++i)
		if (str[i] == 's'&&str[i + 1] == 'i'&&str[i + 2] == 'n')sign[cout++] = i;
	for (int i = 0; i < cout; ++i)
	{
		char middle[30] = { 0 }, later[100] = { 0 };
		sscanf(str + sign[i] + 4, "%[^)]", middle);
		float y = change(middle, a);
		for (int n = sign[i] + 5 + strlen(middle); n < strlen(str); n++)	later[n - sign[i] - 5 - strlen(middle)] = str[n];
		char jieguo[30] = { 0 };
		sprintf(jieguo, "%f", sin(y));
		char front[100] = { 0 };
		for (int n = 0; n < sign[i]; n++)	front[n] = str[n];
		strcat(front, jieguo);
		strcat(front, later);
		strcpy(str, front);
	}
}

//cos����
void dealfunction_cos(char str[], float a)
{
	int sign[10] = { 0 }, cout = 0;
	for (int i = 0; i < strlen(str); ++i)
		if (str[i] == 'c'&&str[i + 1] == 'o'&&str[i + 2] == 's')sign[cout++] = i;
	for (int i = 0; i < cout; ++i)
	{
		char middle[30] = { 0 }, later[100] = { 0 };
		sscanf(str + sign[i] + 4, "%[^)]", middle);
		float y = change(middle, a);
		for (int n = sign[i] + 5 + strlen(middle); n < strlen(str); n++)	later[n - sign[i] - 5 - strlen(middle)] = str[n];
		char jieguo[30] = { 0 };
		sprintf(jieguo, "%f", cos(y));
		char front[100] = { 0 };
		for (int n = 0; n < sign[i]; n++)	front[n] = str[n];
		strcat(front, jieguo);
		strcat(front, later);
		strcpy(str, front);
	}
}

//tan����
void dealfunction_tan(char str[], float a)
{
	int sign[10] = { 0 }, cout = 0;
	for (int i = 0; i < strlen(str); ++i)
		if (str[i] == 't'&&str[i + 1] == 'a'&&str[i + 2] == 'n')sign[cout++] = i;
	for (int i = 0; i < cout; ++i)
	{
		char middle[30] = { 0 }, later[100] = { 0 };
		sscanf(str + sign[i] + 4, "%[^)]", middle);
		float y = change(middle, a);
		for (int n = sign[i] + 5 + strlen(middle); n < strlen(str); n++)	later[n - sign[i] - 5 - strlen(middle)] = str[n];
		char jieguo[30] = { 0 };
		sprintf(jieguo, "%f", tan(y));
		char front[100] = { 0 };
		for (int n = 0; n < sign[i]; n++)	front[n] = str[n];
		strcat(front, jieguo);
		strcat(front, later);
		strcpy(str, front);
	}
}

//ln����
void dealfunction_ln(char str[], float a)
{
	int sign[10] = { 0 }, cout = 0;
	for (int i = 0; i < strlen(str); ++i)
		if (str[i] == 'l'&&str[i + 1] == 'n')sign[cout++] = i;
	for (int i = 0; i < cout; ++i)
	{
		char middle[30] = { 0 }, later[100] = { 0 };
		sscanf(str + sign[i] + 3, "%[^)]", middle);
		float y = change(middle, a);
		for (int n = sign[i] + 4 + strlen(middle); n < strlen(str); n++)	later[n - sign[i] - 4 - strlen(middle)] = str[n];
		char jieguo[30] = { 0 };
		sprintf(jieguo, "%f", log(y));
		char front[100] = { 0 };
		for (int n = 0; n < sign[i]; n++)	front[n] = str[n];
		strcat(front, jieguo);
		strcat(front, later);
		strcpy(str, front);
	}
}

//��������
void dealfunction(char str[], float a)
{
	dealfunction_sin(str, a);
	dealfunction_cos(str, a);
	dealfunction_tan(str, a);
	dealfunction_ln(str, a);
}

//��ȫ�˺�
void buquan(char *str)
{
	int j = 0, j1 = 0;
	int count = 0;
	int flag[100] = { 0 };
	int flag1[100] = { 0 };
	int l = strlen(str);
	if (str[0] == '-')
	{
		insert(str, '1', 1);
		insert(str, '*', 2);
	}
	for (int i = 1; i <= l; i++)
	{
		if ((str[i] == 'x') && str[i - 1] != '+' && str[i - 1] != '-' && str[i - 1] != '*' && str[i - 1] != '/' && str[i - 1] != '^' && str[i - 1] != '(' && str[i - 1] != 'n'&& str[i - 1] != 's')
			flag[j++] = i;
		if ((str[i] == 'x') && str[i - 1] == '-' && (str[i - 2] == '-' || str[i - 2] == '*' || str[i - 2] == '/' || str[i - 2] == '^' || str[i - 2] == '(' || str[i - 1] != 'n' || str[i - 1] != 's'))
			flag1[j1++] = i;
		if (str[i] == 's'  && str[i + 1] == 'i' && str[i + 2] == 'n' && str[i - 1] != '+' && str[i - 1] != '-' && str[i - 1] != '*' && str[i - 1] != '/' && str[i - 1] != '^'&&str[i - 1] != '(')
			flag[j++] = i;
		if (str[i] == 'c'   && str[i + 1] == 'o' && str[i + 2] == 's' && str[i - 1] != '+' && str[i - 1] != '-' && str[i - 1] != '*' && str[i - 1] != '/' && str[i - 1] != '^'&&str[i - 1] != '(')
			flag[j++] = i;
		if (str[i] == 'l'  && str[i + 1] == 'n' && str[i - 1] != '+' && str[i - 1] != '-' && str[i - 1] != '*' && str[i - 1] != '/' && str[i - 1] != '^' && str[i - 1] != '(')
			flag[j++] = i;
		if (str[i] == 't'  && str[i + 1] == 'a' && str[i + 2] == 'n' && str[i - 1] != '+' && str[i - 1] != '-' && str[i - 1] != '*' && str[i - 1] != '/' && str[i - 1] != '^' && str[i - 1] != '(')
			flag[j++] = i;
		if ((str[i] == '(') && str[i - 1] != '+' && str[i - 1] != '-' && str[i - 1] != '*' && str[i - 1] != '/' && str[i - 1] != '^'&& str[i - 1] != '(' && str[i - 1] != 'n' && str[i - 1] != 's')
			flag[j++] = i;


	}
	for (int i = 0; i <= j - 1; i++)
		insert(str, '*', flag[i] + (count++));
	for (int i = 0; i <= j1 - 1; i++)
	{
		insert(str, '1', flag1[i] + (count++));
		insert(str, '*', flag1[i] + (count++));
	}
}


//��i��j����ַ����float��
float numberchange(char *arg, int i, int j)
{
	char newp[100] = { 0 };
	int cout = 0;
	while (i <= j)
		newp[cout++] = arg[i++];
	float result = atof(newp);
	return result;
}

//+-*/^������
float change(char *arg, float a)
{
	int symbol[100] = { 0 };
	for (int i = 0; i < 100; i++)
	{

		if (arg[i] == '^')							symbol[i] = 2;
		if (arg[i] == '*')							symbol[i] = 3;
		if (arg[i] == '/')							symbol[i] = 4;
		if (arg[i] == '+')							symbol[i] = 5;
		if (arg[i] == '-'&&symbol[i - 1] == 0)		symbol[i] = 6;
	}
	int symbol1[100] = { 0 }, cout = 0;
	for (int i = 0; i < 100; i++) if (symbol[i] != 0) symbol1[cout++] = symbol[i];
	float number[100] = { 0.0 }; int sign = 0, cout1 = 0;
	for (int i = 0; i < 100; i++)
	{
		if (symbol[i] != 0)
		{
			if (arg[i - 1] == 'x')
			{
				number[cout1++] = a;
				sign = i + 1;
			}
			else
			{
				number[cout1++] = numberchange(arg, sign, i - 1);
				sign = i + 1;
			}
		}
	}
	if (arg[sign] == 'x')number[cout1] = a;
	else
		number[cout1] = numberchange(arg, sign, 100);
	while (symbol1[0] != 0)
	{
		for (int i = 0; i < cout; i++)
			if (symbol1[i] == 2)
			{
				number[i] = pow(number[i], number[i + 1]);
				for (int j = i + 1; j < cout + 1; j++)number[j] = number[j + 1];
				for (int m = i; m < cout; m++)symbol1[m] = symbol1[m + 1];
				i = i - 1;
			}
		for (int i = 0; i < cout; i++)
			if (symbol1[i] == 3)
			{
				number[i] = number[i] * number[i + 1];
				for (int j = i + 1; j < cout + 1; j++)number[j] = number[j + 1];
				for (int m = i; m < cout; m++)symbol1[m] = symbol1[m + 1];
				i = i - 1;
			}
		for (int i = 0; i < cout; i++)
			if (symbol1[i] == 4)
			{
				number[i] = number[i] / number[i + 1];
				for (int j = i + 1; j < cout + 1; j++)number[j] = number[j + 1];
				for (int m = i; m < cout; m++)symbol1[m] = symbol1[m + 1];
				i = i - 1;
			}
		for (int i = 0; i < cout; i++)
			if (symbol1[i] == 5)
			{
				number[i] = number[i] + number[i + 1];
				for (int j = i + 1; j < cout + 1; j++)number[j] = number[j + 1];
				for (int m = i; m < cout; m++)symbol1[m] = symbol1[m + 1];
				i = i - 1;
			}
		for (int i = 0; i < cout; i++)
			if (symbol1[i] == 6)
			{
				number[i] = number[i] - number[i + 1];
				for (int j = i + 1; j < cout + 1; j++)number[j] = number[j + 1];
				for (int m = i; m < cout; m++)symbol1[m] = symbol1[m + 1];
				i = i - 1;
			}
	}
	return number[0];
}


//ʶ��ת������
void constant(char * arg)
{
	StrReplace(arg, "PI", "3.141592653589793238462643383");    //Բ����
	StrReplace(arg, "e", "2.7182818284590452353602874713");    //��Ȼ����
	StrReplace(arg, "Q", "1.6180339887498948482");             //�ƽ�ָ���
	StrReplace(arg, "K", "2.6854520010653064453");             //Khinchin����
	StrReplace(arg, "O", "0.57721566490153286060651209");      //ŷ������
}

//����ַ��������������滻������
void StrReplace(char* strSrc, char* strFind, char* strReplace)
{
	while (*strSrc != '\0')
	{
		if (*strSrc == *strFind)
		{
			if (strncmp(strSrc, strFind, strlen(strFind)) == 0)
			{
				int i = strlen(strFind);
				int j = strlen(strReplace);
				char* q = strSrc + i;
				char* p = q;                                   //p��q��ָ��ʣ���ַ������׵�ַ
				char* repl = strReplace;
				int lastLen = 0;
				while (*q++ != '\0')
					lastLen++;
				char* temp = new char[lastLen + 1];            //��ʱ����һ���ڴ汣��ʣ�µ��ַ���,��ֹ�ڴ渲��
				for (int k = 0; k < lastLen; k++)
				{
					*(temp + k) = *(p + k);
				}
				*(temp + lastLen) = '\0';
				while (*repl != '\0')
				{
					*strSrc++ = *repl++;
				}
				p = strSrc;
				char* pTemp = temp;                           //���ն�̬�����ڴ�
				while (*pTemp != '\0')
				{
					*p++ = *pTemp++;
				}
				delete temp;
				*p = '\0';
			}
			else
				strSrc++;
		}
		else
			strSrc++;
	}
}

//����任��������ȫ���origin�ַ������󵼵�x��n��
float qiudao(char origin[], float i, int n)
{
	float deltax = 0.00009;
	float y[100] = { 0 };
	for (int x = 0; x < n + 1; ++x)
	{
		char arg[100];
		strcpy(arg, origin);
		dealfunction(arg, i);
		kuohao(arg, i);
		y[x] = change(arg, i);
		i += deltax;
		
	}
	for (; n>0; --n)
		for (int x = 0; x < n; ++x)
			y[x] = (y[x + 1] - y[x]) / deltax;
	return y[0];
}
