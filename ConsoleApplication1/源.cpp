#include"输入.h"
#include"画图.h"
#include"界面.h"


float main()
{
	float ratiochange; float i = -background_length / 2;																	//声明一个用于坐标变换的变量
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
			printf("请根据你的需要输入函数图像与原图像的放大比例(建议舒适比例范围为1到100)\n");
			scanf("%f", &ratiochange);
			drawaxis(Mat_background, ratiochange);
			constant(arg);
			buquan(arg);
			strcpy(origin, arg);
			float storex[1530] = { 0 };													//构建一个数组来储存点纵坐标
			float storey[1530] = { 0 };													//构建一个数组来储存点横坐标
			int gstore = 0;																//单独构建一个变量来处理点坐标的储存问题，避免引起混乱
			i = i / ratiochange;
			while ((i) < k / ratiochange)
			{
				float y = qiudao(origin, i, 0);
				storex[gstore] = y;															//储存纵坐标
				storey[gstore] = i;															//储存横坐标
				i = i + (1.0 / ratiochange);												//1.0是为了精度需要，请不要擅自改动
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
				printf("请再次输入表达式y=");
				scanf("%s", arg);
				printf("请重新输入你想看到的图像比例\n");
				scanf("%f", &ratiochange);
				constant(arg);
				buquan(arg);
				strcpy(origin, arg);
				float store[1530] = { 0 };													//构建一个数组来储存点纵坐标
				float store1[1530] = { 0 };												//构建一个数组来储存点横坐标
				int gstore = 0;																//单独构建一个变量来处理点坐标的储存问题，避免引起混乱
				i = i / ratiochange;
				while ((i) < k / ratiochange)																//循环
				{
					float y = qiudao(origin, i, 0);
					store[gstore] = y;															//储存纵坐标
					store1[gstore] = i;															//储存横坐标
					i = i + (1.0 / ratiochange);													//1.0是为了精度需要，请不要擅自改动
					gstore = gstore + 1;
				}
				functioncolourchange(arg, store, store1, Mat_background, ratiochange);       //这里要改一下
				imshow("test", Mat_background);
				waitKey(0);
			}                                                                                   //这里还需要调试
		if (choice == '4')
		{
			char source[20] = { 0 };
			printf("请输入要保存的路径");
			scanf("%s", source);
			strcat(source, "\\结果.png");
			imwrite(source, Mat_background);
		};
		if (choice == '5')break;
		if (choice != '1' && choice != '2' && choice != '3' && choice != '4'&& choice != '5')printf("请输入数字1-5\n");
		printf("-------------------------------------------------------------------------------------------\n");
	}

}
    







