#include"����.h"
#include"��ͼ.h"
#include"����.h"


float main()
{
	float ratiochange; float i = -background_length / 2;																	//����һ����������任�ı���
	int k = background_length / 2;
	char origin[100], arg[100];
	printtitle();
	while (true) 
	{
		char choice = menu();
		if (choice == '1')
		{
			printf("y=");
			scanf("%s", arg);
			printf("����������Ҫ���뺯��ͼ����ԭͼ��ķŴ����(�������ʱ�����ΧΪ1��100)\n");
			scanf("%f", &ratiochange);
			drawaxis(Mat_background, ratiochange);
			constant(arg);
			buquan(arg);
			strcpy(origin, arg);
			float storex[1530] = { 0 };													//����һ�������������������
			float storey[1530] = { 0 };													//����һ������������������
			int gstore = 0;																//��������һ�����������������Ĵ������⣬�����������
			i = i / ratiochange;
			while ((i) < k / ratiochange)
			{
				float y = qiudao(origin, i, 0);
				storex[gstore] = y;															//����������
				storey[gstore] = i;															//���������
				i = i + (1.0 / ratiochange);												//1.0��Ϊ�˾�����Ҫ���벻Ҫ���ԸĶ�
				gstore = gstore + 1;
			}
			functioncolourchange(arg, storex, storey, Mat_background, ratiochange);
			imshow("test", Mat_background);
			waitKey(0);
		}
		if (choice == '2')
		{
			choice2();
		}                                         
		if (choice == '3') {
			    i = -765.0;
				printf("���ٴ�������ʽy=");
				scanf("%s", arg);
				printf("�������������뿴����ͼ�����\n");
				scanf("%f", &ratiochange);
				constant(arg);
				buquan(arg);
				strcpy(origin, arg);
				float store[1530] = { 0 };													//����һ�������������������
				float store1[1530] = { 0 };												//����һ������������������
				int gstore = 0;																//��������һ�����������������Ĵ������⣬�����������
				i = i / ratiochange;
				while ((i) < k / ratiochange)																//ѭ��
				{
					float y = qiudao(origin, i, 0);
					store[gstore] = y;															//����������
					store1[gstore] = i;															//���������
					i = i + (1.0 / ratiochange);													//1.0��Ϊ�˾�����Ҫ���벻Ҫ���ԸĶ�
					gstore = gstore + 1;
				}
				functioncolourchange(arg, store, store1, Mat_background, ratiochange);       //����Ҫ��һ��
				imshow("test", Mat_background);
				waitKey(0);
			}                                                                                   //���ﻹ��Ҫ����
		if (choice == '4')
		{
			char source[20] = { 0 };
			printf("������Ҫ�����·��");
			scanf("%s", source);
			strcat(source, "\\���.png");
			imwrite(source, Mat_background);
		};
		if (choice == '5')break;
		if (choice != '1' && choice != '2' && choice != '3' && choice != '4'&& choice != '5')printf("����������1-5\n");
		printf("-------------------------------------------------------------------------------------------\n");
	}

}
    







