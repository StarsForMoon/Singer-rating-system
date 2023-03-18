#pragma once
#include "singer.h"
#include <iostream>
using namespace std;

/*菜单函数*/
void menu(Singer singers[], Judge judges[], int* n, int* m, int* judge_num, bool* system_key)
{
	int choice;
	cout << "  ******************************************************\n\n";
	cout << "  *                歌手比赛管理系统                    *\n \n";
	cout << "  ******************************************************\n\n";
	cout << "  *********************系统功能菜单*********************       \n";
	cout << "     ---------------------------------------------   \n";
	cout << "     *********************************************     \n";
	cout << "     * 0.系统帮助及说明  * *  1.输入选手信息   *     \n";
	cout << "     *********************************************     \n";
	cout << "     * 2.输入评委打分    * *  3.选手成绩排序   *     \n";
	cout << "     *********************************************     \n";
	cout << "     * 4.查询选手数据    * *  5.追加选手数据   *     \n";
	cout << "     *********************************************     \n";
	cout << "     * 6.保存选手数据    * *  7.删除选手信息   *     \n";
	cout << "     *********************************************     \n";
	cout << "     * 8.显示选手信息    * *  9.修改选手信息*     \n";
	cout << "     *********************************************     \n";
	cout << "     * 10.退出系统       *     \n";
	cout << "     ---------------------------------------------     \n";
	cout << "请选择菜单编号:";
	cin >> choice;
	switch (choice)//switch多分支用于功能选择
	{
	case 0:
	{
		SystemHelp();
		break;
	}

	case 1:
	{
		ContestantInfo(singers, judges, n, m);
		break;
	}

	case 2:
	{
		JudgeScores(singers, judges, n, m, *judge_num);
		break;
	}
	case 3:
	{
		ContestantRankings(singers, *n);
		break;
	}

	case 4:
	{
		QueryInfo(singers, *n);
		break;
	}

	case 5:
	{
		InsertInfo(singers, judges, n, m, *judge_num);
		break;
	}

	case 6:
	{
		SaveInfo(singers, *n);
		break;
	}
	case 7:
	{
		DelInfo(singers, n);
		break;
	}
	case 8:
	{
		DisplayInfo(singers, *n);
		break;
	}
	case 9:
	{
		ModifyInfo(singers, *n, *judge_num);
		break;
	}
	case 10:
	{
		*system_key = 0;
		cout << "即将退出程序!\n";
		break;
		//exit(0);	//终止整个程序运行
	}
	default:
	{
		cout << "请在0-10之间选择\n";//增加使用友好性
	}
	}
}

/*系统帮助函数*/
void SystemHelp()
{
	cout << "\n1.欢迎使用系统帮助！\n";
	cout << "\n2.初次进入系统后,请先按照菜单提示键入数字代号\n";
	cout << "\n3.请先输入增加选手信息再进行后续操作\n";
	cout << "\n4.增加学生信息后,切记保存\n";
	cout << "\n5.谢谢您的使用！\n";
}

/*构造函数*/
Singer::Singer(float presc[], int Num, const char* nam,
	float maxsc, float minsc, float totalsc, float evensc, float averagesc)
{
	/*析构函数用于对象的初始化*/
	int x = 0;//循环变量                                                    
	Number = Num;
	/*此处运用动态内存分配*/
	name = new char(strlen(nam) + 1);
	if (name != 0)
	{
		strcpy(name, nam);
	}
	/*裁判评分初始化*/
	for (x = 0; x < 10; x++)
	{
		prescores[x] = presc[x];
	}
	maxscore = maxsc;
	minscore = minsc;
	totalscore = totalsc;
	evenscore = evensc;
	averagescore = averagesc;
}

/*Singer类的析构函数*/
Singer::~Singer()
{
	cout << "\nSinger类对象已经销毁" << endl;
}

/*Judge类的析构函数*/
Judge::~Judge()
{
	cout << "\nJudge类对象已经销毁" << endl;
}

/*求最高分函数*/
float Singer::GetMax(float a[], int len)
{
	int v = 0;
	float max = a[0];
	while (v < len)
	{
		if (a[v] > max)
		{
			max = a[v];
		}
		v++;
	}
	return max;
}

/*求最低分函数*/
float Singer::GetMin(float b[], int len)
{
	int v = 0;
	float min = b[0];
	while (v < len)
	{
		if (b[v] < min)
		{
			min = b[v];
		}
		v++;
	}
	return min;
}

/*求和函数*/
float Singer::sum(float c[], int len)
{
	int o;
	float total = 0;
	for (o = 0; o < len; o++)
	{
		total += c[o];
	}
	return total;
}

/*选手信息函数*/
void ContestantInfo(Singer singers[], Judge judges[], int* n, int* m)
{
	int i = *n;
	int j = 0;
	int flag = -1;//i，j循环变量
	char name[20];
	cout << "请输入待增加的学生数：";
	cin >> *m;//输入增加的人数m
	if (*m > 0)
	{
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				cout << "请输入第" << i + 1 << "位选手的编号：";
				cin >> singers[i].Number;//输入选手编号 因为只有选手编号是唯一的
				/*校验选手编号*/
				for (j = 0; j < i; j++)//从已有选手编号中查重
				{
					if (singers[i].Number == singers[j].Number)
					{
						cout << "该选手编号已存在，请重新输入！\n";
						flag = 1;
						break;
					}
				}
			}
			/*只有当编号输入正确后才能录入后续信息*/
			cout << "请输入第" << i + 1 << "位选手的姓名：";
			/*动态内存分配*/
			cin >> name;
			singers[i].name = new char(strlen(name) + 1);
			if (singers[i].name != 0)
			{
				strcpy(singers[i].name, name);
			}

			if (flag == 0)
			{
				i++;
			}
		} while (i < *n + *m);
	}
	*n = *n + *m;//总人数
	cout << "选手信息增加完毕！！！\n";
	cout << "请稍后选择 “输入评委打分” 进行成绩记录。" << endl;
	system("pause");
}

/*裁判信息和评分函数*/
void JudgeScores(Singer singers[], Judge judges[], int* n, int* m, int judge_num)
{
	/*选手录入的人数为0时则不能该功能*/
	if (n == 0)
	{
		cout << "\n                !请先增加选手信息!\n\n";
		return;
	}
	int r;//循环变量
	for (r = 0; r < judge_num; r++)
	{
		cout << "请输入第" << r + 1 << "位评委号码：";
		cin >> judges[r].JudgeNo;
	}
	cout << "已完成对评委号码录入！" << endl;
	int p;//循环变量
	int q;//循环变量
	int order = 1;//裁判顺序变量
	int sorder = *n - *m;//选手顺序变量
	for (p = 1; p <= *m; p++)//外层循环为选手 每一位选手打完分之后进入下一名选手
	{
		int restart = 0;
	loop:
		for (q = restart; q <= judge_num - 1; q++)//内层循环为评委 即10位评委依次对选手打分
		{
			cout << "请输入第" << order << "位评委对第" << p + *n - *m << "位选手的评分([0,10]）：";
			cin >> judges[q].score;
			int s = 0;
			int signal = 0;//判断标志变量
			/*判断是否打分在[0,10]*/
			for (s = 0; s <= 10; s++)
			{
				if ((int)judges[q].score == s)
				{
					signal = 1;
					break;
				}
			}
			if (signal == 0)//不是在[0,10]则重新输入
			{
				restart = q;
				cout << "评分错误！请重新输入！" << endl;
				goto loop;
			}
			singers[sorder].prescores[order - 1] = judges[q].score;//输入评委打分的同时 储存到选手的prescore数组里
			order++;
		}
		/*所有选手的所有评分完成，开始处理并录入到选手的个人信息里*/
		singers[sorder].maxscore = singers[sorder].GetMax(singers[sorder].prescores, judge_num);
		singers[sorder].minscore = singers[sorder].GetMin(singers[sorder].prescores, judge_num);
		singers[sorder].totalscore = singers[sorder].sum(singers[sorder].prescores, judge_num);
		singers[sorder].evenscore = singers[sorder].totalscore - singers[sorder].maxscore - singers[sorder].minscore;
		singers[sorder].averagescore = singers[sorder].evenscore / (judge_num - 2);
		sorder++;
		order = 1;
		cout << "已完成对第" << p + *n - *m << "位选手的成绩记录！" << endl;
		system("pause");
	}
	cout << "所有评分信息已经输入完毕！！！\n";
}

/*二分查找函数*/
int binaryFindNo(Singer singers[], int n, int no)
{
	int low = 0;//低位位置下标
	int high = n - 1;//高位位置下标
	int mid = 0;//中间位置下标

	//先按编号排序-冒泡法
	BubbleSort(singers, n);
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (singers[mid].Number == no)
		{
			return mid;//查询成功
		}
		else if (singers[mid].Number > no)
		{
			high = mid - 1;
		}
		if (singers[mid].Number < no)
		{
			low = mid + 1;
		}

	}
	return -1;//查询失败
}

/*信息显示函数*/
void DisplayInfo(Singer singers[], int n)
{
	cout << "系统中所有选手信息：" << endl;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cout << "-----------------------------------------------" << endl;
		cout << "选手编号：" << singers[i].Number << endl;
		cout << "选手姓名：" << singers[i].name << endl;
		cout << "选手最高分：" << singers[i].maxscore << endl;
		cout << "选手最低分：" << singers[i].minscore << endl;
		cout << "选手总分：" << singers[i].evenscore << endl;
		cout << "选手平均分：" << singers[i].averagescore << endl;
		cout << "-----------------------------------------------" << endl;
	}
}

/*正序输出函数*/
void ObverseOrder(Singer singers[], int n)
{
	/*默认从小到大排序*/
	/*从正序输出*/
	int g = 0;
	int count = 0;//总数
	int rank = 0;//排名
	cout << left << setw(4) << "排名" << '\t' << "编号" << '\t' << '\t' << setw(8) << "姓名"
		<< '\t' << setw(5) << "平均成绩" << endl;
	for (g = 0; g < n; g++)
	{
		if (g == 0)							//先输出第一个的 即是最小的那一个
		{
			rank++;
			count++;
			cout << left << setw(4) << rank << '\t' << singers[g].Number << '\t' << '\t' << setw(8) << left
				<< singers[g].name << '\t' << setw(5) << fixed << setprecision(2) << singers[g].averagescore;
		}
		else
		{

			if (singers[g].Number == singers[g + 1].Number) //如果前面的成绩和后面的成绩相等 则人数+1但排名不变
			{
				count++;
				cout << left << setw(4) << rank << '\t' << singers[g].Number << '\t' << '\t' << setw(8) << left
					<< singers[g].name << '\t' << setw(5) << fixed << setprecision(2) << singers[g].averagescore;

			}
			else //若前面的成绩和后面的成绩不相等 则人数 + 1 排名赋值为人数
			{
				count++;
				rank = count;
				cout << left << setw(4) << rank << '\t' << singers[g].Number << '\t' << '\t' << setw(8) << left
					<< singers[g].name << '\t' << setw(5) << fixed << setprecision(2) << singers[g].averagescore;

			}
		}
		cout << endl;
	}
	return;
}

/*逆序输出函数*/
void ReverseOrder(Singer singers[], int n)
{
	/*默认从小到大排序*/
	/*从逆序输出*/
	int g = 0;
	int count = 0;//总数
	int rank = 0;//排名
	cout << left << setw(4) << "排名" << '\t' << "编号" << '\t' << '\t' << setw(8) << "姓名"
		<< '\t' << setw(5) << "平均成绩" << endl;
	for (g = n - 1; g >= 0; g--)
	{
		if (g == n - 1)//先输出最后一个 即最大的
		{
			rank++;
			count++;
			cout << left << setw(4) << rank << '\t' << singers[g].Number << '\t' << '\t' << setw(8) << left
				<< singers[g].name << '\t' << setw(5) << fixed << setprecision(2) << singers[g].averagescore;
		}
		else
		{

			if (singers[g].Number == singers[g + 1].Number) //如果前面的成绩和后面的成绩相等 则人数+1但排名不变
			{
				count++;
				cout << left << setw(4) << rank << '\t' << singers[g].Number << '\t' << '\t' << setw(8) << left
					<< singers[g].name << '\t' << setw(5) << fixed << setprecision(2) << singers[g].averagescore;
			}
			else //若前面的成绩和后面的成绩不相等 则人数 + 1 排名赋值为人数
			{
				count++;
				rank = count;
				cout << left << setw(4) << rank << '\t' << singers[g].Number << '\t' << '\t' << setw(8) << left
					<< singers[g].name << '\t' << setw(5) << fixed << setprecision(2) << singers[g].averagescore;

			}
		}
		cout << endl;
	}
	return;
}

/*选手成绩排序函数*/
void ContestantRankings(Singer singers[], int n)
{
	if (n == 0)
	{
		cout << "\n                !请先增加选手信息!\n\n";
		return;
	}
	int choice = -1;
	cout << "****************排序方式*****************" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "*	1、按照编号排序			*" << endl;
	cout << "*	2、按照平均成绩排序		*" << endl;
	cout << "*	3、基于编号优先的成绩排序	*" << endl;
	cout << "*	4、基于成绩优先的编号排序	*" << endl;
	cout << "*	0、退出本菜单			*" << endl;
	cout << "\n请输入排序方式：";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		/*对数量在0-2之内的数据单独处理*/
		if (singers == NULL || n == 0)
		{
			cout << "\n 选手信息未录入！" << endl;
			return;
		}
		if (n == 1)//不用排序了，所以直接输出
		{
			RankView(singers, n);
		}
		else if (n == 2)
		{
			/*默认排成从小到大再按需求输出*/
			/*Singer tmp;*/
			if (singers[0].Number > singers[1].Number)
			{
				/*tmp = singers[0];
				singers[0] = singers[1];
				singers[1] = tmp;*/
				swap(singers[0], singers[1]);
			}
			RankView(singers, n);
		}
		else if (n >= 3)
		{
			/*冒泡排序*/
			/*编号排序*/
			RankView(singers, n);
		}
		break;
	}
	case 2:
	{
		/*对数量在0-2之内的数据单独处理*/
		if (singers == NULL || n == 0)
		{
			cout << "\n 选手信息未录入！" << endl;
			return;
		}
		if (n == 1)//不用排序了，所以直接输出
		{
			RankView(singers, n);
		}
		else if (n == 2)
		{
			/*默认排成从小到大再按需求输出*/
			/*Singer tmp;*/
			if (singers[0].averagescore > singers[1].averagescore)
			{
				/*tmp = singers[0];
				singers[0] = singers[1];
				singers[1] = tmp;*/
				swap(singers[0], singers[1]);
			}
			RankView(singers, n);
		}
		else if (n >= 3)
		{
			/*选择排序*/
			/*成绩排序*/
			SelectSort(singers, n);
			RankView(singers, n);
		}
		break;
	}
	case 3:
	{
		/*对数量在0-2之内的数据单独处理*/
		if (singers == NULL || n == 0)
		{
			cout << "\n 选手信息未录入！" << endl;
			return;
		}
		if (n == 1)//不用排序了，所以直接输出
		{
			RankView(singers, n);
		}
		else if (n == 2)
		{
			/*默认排成从小到大再按需求输出*/
			/*Singer tmp;*/
			if ((1.0 * singers[0].Number + 1.0 / singers[0].averagescore)
		> (1.0 * singers[1].Number + 1.0 / singers[1].averagescore))
			{
				/*tmp = singers[0];
				singers[0] = singers[1];
				singers[1] = tmp;*/
				swap(singers[0], singers[1]);
			}
			RankView(singers, n);
		}
		else if (n >= 3)
		{
			/*希尔排序*/
			/*编号优先的成绩排序*/
			ShellSort(singers, n);
			RankView(singers, n);
		}
		break;
	}
	case 4:
	{
		/*对数量在0-2之内的数据单独处理*/
		if (singers == NULL || n == 0)
		{
			cout << "\n 选手信息未录入！" << endl;
			return;
		}
		if (n == 1)//不用排序了，所以直接输出
		{
			RankView(singers, n);
		}
		else if (n == 2)
		{
			/*Singer tmp;*/
			/*默认排成从小到大再按需求输出*/
			if ((double(singers[0].averagescore) + double(1.0 / singers[0].Number))
		> (double(singers[1].averagescore) + double(1.0 / singers[1].Number)))
			{
				/*tmp = singers[0];
				singers[0] = singers[1];
				singers[1] = tmp;*/
				swap(singers[0], singers[1]);
			}
			RankView(singers, n);
		}
		else if (n >= 3)
		{
			/*插入排序*/
			/*基于成绩优先的编号排序*/
			InsertSort(singers, n);
			RankView(singers, n);
		}
		break;
	}
	case 0:
	{
		return;
	}
	default:
	{
		cout << "请在0-4之间输入，输入0退出。" << endl;
	}
	}
}

/*插入函数*/
void InsertInfo(Singer singers[], Judge judges[], int* n, int* m, int judge_num)
{
	/*插入新选手数据分为两步骤：
	1.输入选手信息
	2.评委对该选手的评分
	调用前面的选手信息函数和评委评分函数即可*/
	cout << '\n' << "请增加选手信息" << '\n' << endl;
	ContestantInfo(singers, judges, n, m);
	cout << '\n' << "请输入评委评分" << '\n' << endl;
	JudgeScores(singers, judges, n, m, judge_num);
	system("pause");
}

/*保存函数*/
void SaveInfo(Singer singers[], int n)
{
	if (n == 0)
	{
		cout << "\n                !请先增加选手信息!\n\n";
		return;
	}
	int i;
	FILE* fp;
	char filename[30];
	cout << "请输入要保存的文件名：";
	cin >> filename;//cin.getline(filename,30);
	fp = fopen(filename, "w+");
	fstream outfile;
	outfile.open(filename);
	if (!outfile)//如果不能建立该文件的情况
	{
		cout << "不能建立输出文件" << endl;
		exit(0);
	}

	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%d\t%s\t%.2f\t%.2f\t\n", singers[i].Number, singers[i].name, singers[i].totalscore, singers[i].averagescore);
	}
	cout << "保存成功！！！\n";//友好性
	fclose(fp);
	system("pause");
}

/*排序结果展示函数*/
void RankView(Singer singers[], int n)
{
	/*排序完成后的输出*/
	/*升降序也就是正逆序输出*/
	cout << "***********选择查看方式**********" << endl;
	cout << "---------------------------------" << endl;
	cout << "* 0.升序查看 *	   * 1.降序查看 *" << endl;
	cout << "*********************************" << endl;
	cout << "-----输 入 3 退 出 本 菜 单-----" << endl;
	cout << "*********************************" << endl;
	int key = 1;
	while (key)
	{
		int rankchoice = -1;
		cout << "\n请输入查看方式：";
		cin >> rankchoice;
		switch (rankchoice)
		{
		case 0:
		{
			ObverseOrder(singers, n);//对排好序的数据正序查看 
			key = 0;
			break;
		}
		case 1:
		{
			ReverseOrder(singers, n);//对排好序的数据逆序查看
			key = 0;
			break;
		}
		case 3:
		{
			key = 0;
			break;
		}
		default:
		{
			cout << "请在0-3之间输入。" << endl;
		}
		}
	}
}

/*查询函数*/
bool QueryInfo(Singer singers[], int n)
{
	int i = 0;//数组下标
	int no = 0;//编号
	bool flag = 0;//查找结果，1表示查找成功，0表示查找失败
	int noMin = 0;//编号起始值
	int noMax = 0;//编号结束值
	int find_no = 0;//二分查找到的编号
	int menuSelect = 0;//三级菜单选择
	int menu = 0; //属性查询二级菜单选择
	char str[20]; //查询的字符串（姓名)
	float score = 0;//分数
	float scoreMin = 0;//分数起始值
	float scoreMax = 0;//分数结束值
	menu = 9;
	while (menu != 0)
	{
		flag = 0;
		/*属性查询选择二级菜单*/
		cout << "***********选择查询功能**********" << endl;
		cout << "---------------------------------" << endl;
		cout << "* 1.编号查询 *	   * 2.姓名查看 *" << endl;
		cout << "*********************************" << endl;
		cout << "* 3.成绩查询 *	   * 0.返回菜单 *" << endl;
		cout << "*********************************" << endl;
		cout << "欢迎使用查询功能！" << endl;
		cout << "请输入查询信息选项：";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			/*编号查询二级菜单及其调用*/
			cout << "  *********************编号查询菜单*********************       \n";
			cout << "     ---------------------------------------------   \n";
			cout << "     *********************************************     \n";
			cout << "     * 1.精确查询及说明  *         *  2.范围查询   *     \n";
			cout << "     *********************************************     \n";
			cout << "     * 0.返回上一级菜单  *         \n";
			cout << "     *********************************************     \n";
			cout << "     ---------------------------------------------   \n";
			cout << "  ******************************************************\n\n";
			cout << "请输入你的选择（0-2）：";
			cin >> menuSelect;
			switch (menuSelect)
			{
			case 1:
			{
				/*精确查找编号*/
				int i = 0;//数组下标
				int no = 0;//编号
				bool flag = 0;//查找结果，1表示查找成功，0表示查找失败
				cout << "\n请输入查找的选手编号（整数）：";
				cin >> no;
				cout << "要查找的选手编号是：" << no << endl;
				/*此处应用二分查找*/
				find_no = binaryFindNo(singers, n, no);
				if (find_no != -1)
				{
					cout << "符合条件的记录：\n";
					cout << left << setw(4) << "选手编号" << '\t' << setw(4) << "姓名" << '\t' << setw(4) << "平均成绩"
						<< '\t' << setw(4) << "最高分" << '\t' << setw(4) << "最低分" << endl;
					cout << left << setw(4) << singers[find_no].Number << '\t' << '\t' << setw(4) << singers[find_no].name << '\t' << setw(4)
						<< singers[find_no].averagescore << '\t' << '\t' << singers[find_no].maxscore << '\t' << singers[find_no].minscore << endl;
					flag = 1;
					break;
				}
				else if (find_no == -1)
				{
					cout << "该编号不存在！请核对编号！" << endl;
				}
				break;
			}
			case 2:
			{
				/*范围查找编号*/
				cout << "请输入查找的选手编号范围：\n选手编号>=";
				cin >> noMin;
				cout << "选手编号<=";
				cin >> noMax;
				cout << "要查找的编号范围是：" << noMin << "<= 编号 <=" << noMax << endl;
				cout << "符合条件的记录" << endl;
				cout << left << setw(4) << "选手编号" << '\t' << setw(4) << "姓名" << '\t' << setw(4) << "平均成绩"
					<< '\t' << setw(4) << "最高分" << '\t' << setw(4) << "最低分" << endl;
				for (i = 0; i < n; i++)
				{
					if (singers[i].Number >= noMin && singers[i].Number <= noMax)
					{
						cout << left << setw(4) << singers[i].Number << '\t' << '\t' << setw(4) << singers[i].name << '\t' << setw(4)
							<< singers[i].averagescore << '\t' << '\t' << singers[i].maxscore << '\t' << singers[i].minscore << endl;
						flag = 1;
					}
				}
				break;
			}
			case 0:
				break;
			default:
			{
				cout << "请在0-2之间选择！" << endl;
			}
			}
			break;
		}
		case 2:
		{
			/*模糊查找职工姓名*/
			cout << "请输入查找的职工姓名：";
			cin >> str;
			cout << "要查找的职工姓名是：" << str << endl;
			cout << "符合条件的记录：\n";
			cout << left << setw(4) << "选手编号" << '\t' << setw(4) << "姓名" << '\t' << setw(4) << "平均成绩"
				<< '\t' << setw(4) << "最高分" << '\t' << setw(4) << "最低分" << endl;
			for (i = 0; i < n; i++)
			{
				if (strstr(singers[i].name, str))//实现模糊 精确同
				{
					cout << left << setw(4) << singers[i].Number << '\t' << '\t' << setw(4) << singers[i].name << '\t' << setw(4)
						<< singers[i].averagescore << '\t' << '\t' << singers[i].maxscore << '\t' << singers[i].minscore << endl;
					flag = 1;
				}
			}
			break;
		}

		case 3:
		{
			/*按成绩查询*/
			/*成绩查询三级菜单及其调用*/
			cout << "  *********************成绩查询菜单*********************       \n";
			cout << "     ---------------------------------------------   \n";
			cout << "     *********************************************     \n";
			cout << "     * 1.精确查询及说明  *         *  2.范围查询   *     \n";
			cout << "     *********************************************     \n";
			cout << "     * 0.返回上一级菜单  *         \n";
			cout << "     *********************************************     \n";
			cout << "     ---------------------------------------------   \n";
			cout << "  ******************************************************\n\n";
			cout << "请输入你的选择（0-2）：";
			cin >> menuSelect;
			switch (menuSelect)
			{
			case 1:
			{
				/*精确查找成绩*/
				cout << "请输入查找的平均成绩：";
				cin >> score;
				cout << "要查找的平均成绩是：" << score << endl;
				cout << "符合条件的记录：" << endl;
				cout << left << setw(4) << "选手编号" << '\t' << setw(4) << "姓名" << '\t' << setw(4) << "平均成绩"
					<< '\t' << setw(4) << "最高分" << '\t' << setw(4) << "最低分" << endl;
				for (i = 0; i < n; i++)
				{
					if (singers[i].averagescore == score)
					{
						cout << left << setw(4) << singers[i].Number << '\t' << '\t' << setw(4) << singers[i].name << '\t' << setw(4)
							<< singers[i].averagescore << '\t' << '\t' << singers[i].maxscore << '\t' << singers[i].minscore << endl;
						flag = 1;
					}
				}
				break;
			}
			case 2:
			{
				/*范围查找成绩*/
				cout << "请输入查找的平均成绩范围：\n";
				cout << "平均成绩 >= ";
				cin >> scoreMin;
				cout << "平均成绩<=";
				cin >> scoreMax;
				cout << "要查找的编号范围是：" << scoreMin << "<= 平均成绩 <=" << scoreMax << endl;
				cout << "符合条件的记录：" << endl;
				cout << left << setw(4) << "选手编号" << '\t' << setw(4) << "姓名" << '\t' << setw(4) << "平均成绩"
					<< '\t' << setw(4) << "最高分" << '\t' << setw(4) << "最低分" << endl;
				for (i = 0; i < n; i++)
				{
					if (singers[i].averagescore >= scoreMin && singers[i].averagescore <= scoreMax)
					{
						cout << left << setw(4) << singers[i].Number << '\t' << '\t' << setw(4) << singers[i].name << '\t' << setw(4)
							<< singers[i].averagescore << '\t' << '\t' << singers[i].maxscore << '\t' << singers[i].minscore << endl;
						flag = 1;
					}
				}
				break;
			}
			case 0:
				break;
			default:
			{
				cout << "请在0-2之间选择！" << endl;
			}
			}
			break;
		}
		case 0:
			break;
		default:
		{
			cout << "请在0-3中选择！" << endl;
		}
		}
	}
	if (flag == 0 && menu != 0)
	{
		cout << "查询信息无效，系统未查询成功。" << endl;
	}
	return flag;
}

/*冒泡排序*/
void BubbleSort(Singer singers[], int n)
{
	int p = 0;
	int q = 0;
	/*Singer temp1;*/
	/*冒泡排序*///（从小到大）
	for (p = 0; p < n - 1; p++)
	{
		for (q = 0; q < n - p - 1; q++)
		{
			if (singers[q].Number > singers[q + 1].Number)
			{
				/*temp1 = singers[q];
				singers[q] = singers[q + 1];
				singers[q + 1] = temp1;*/
				swap(singers[q], singers[q + 1]);
			}
		}
	}
}

/*选择排序*/
void SelectSort(Singer singers[], int n)
{
	/*选择排序*/
	int x = 0;
	int y = 0;
	int temp2 = 0;
	for (x = 0; x < n - 1; x++)
	{
		temp2 = x;
		for (y = x + 1; y < n; y++)
		{
			if (singers[temp2].averagescore > singers[y].averagescore)
			{
				temp2 = y;
			}
		}
		swap(singers[x], singers[temp2]);
	}
}

/*希尔排序*/
void ShellSort(Singer singers[], int n)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int gap = 0;
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		for (a = 0; a < gap; a++)
		{
			for (b = a + gap; b < n; b += gap)
			{
				for (c = b; c > a; c -= gap)
				{
					if ((1.0 * singers[c].Number + 1.0 / singers[c].averagescore)
						< (1.0 * singers[c - gap].Number + 1.0 / singers[c - gap].averagescore))
					{
						swap(singers[c - gap], singers[c]);
					}
				}
			}
		}
	}
}

/*插入排序*/
void InsertSort(Singer singers[], int n)
{
	int s = 0;
	int t = 0;
	for (int s = 1; s < n; s++)
	{
		Singer temp4 = singers[s];
		for (int t = s - 1; t >= 0; t--)
		{
			if ((double(singers[t].averagescore) + double(1.0 / singers[t].Number))
	> (double(temp4.averagescore) + double(1.0 / temp4.Number)))
			{
				singers[t + 1] = singers[t];
				singers[t] = temp4;
			}
			else
			{
				break;
			}

		}
	}
}

/*删除函数*/
void DelInfo(Singer singers[], int* n)
{
	/*loop和key用于控制本功能的继续或退出*/
	int key = 1;
loop:
	while (key)
	{
		int i = 0; //数组下标，循环控制变量
		int num = 0;//数组下标，循环控制变量
		int location = -1; //被删除的位置
		int NO = 0;			//需要被删除人员的编号
		char isOperate1 = 'N'; //第一次询问是否操作
		char isOperate2 = 'N'; //第二次询问是否操作
		cout << "欢迎使用删除功能！" << endl;

		/*先查后删，编号唯一*/
		cout << "请输入要删除人员的编号：";
		cin >> NO;
		for (num = 0; num < *n; num++)
		{
			if (singers[num].Number == NO)
			{
				location = num;//成功查询
				break;
			}
			else
			{
				location = -1;//查询失败
			}
		}
		/*显示被删除人员信息*/
		if (location != -1)
		{
			cout << "被删除的选手信息：" << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "选手编号：" << singers[location].Number << endl;
			cout << "选手姓名：" << singers[location].name << endl;
			cout << "选手最高分：" << singers[location].maxscore << endl;
			cout << "选手最低分：" << singers[location].minscore << endl;
			cout << "选手总分：" << singers[location].evenscore << endl;
			cout << "选手平均分：" << singers[location].averagescore << endl;
			cout << "-----------------------------------------------" << endl;
		}
		else
		{
			cout << "没有找到人员" << NO << ",删除失败" << endl;
			return;//删除失败
		}
		/*删除人员信息*/
		cout << "是否删除？(Y/N)";
		cin >> isOperate1;
		if (isOperate1 == 'Y' || isOperate1 == 'y')
		{
			cout << "是否保存？(Y/N)";
			cin >> isOperate2;
			if (isOperate2 == 'Y' || isOperate2 == 'y')
			{
				i = location;

				while (i < *n - 1)
				{
					singers[i] = singers[i + 1];//从后往前移动
					i++;
				}
				*n = *n - 1;
				/*将每个学生信息写入文件*/
				SaveInfo(singers, *n);//保存删除后的人事信息
				cout << "删除结果已保存成功文件！" << endl;
			}
			else/*即使不保存也要进行删除操作*/
			{
				i = location;

				while (i < *n - 1)
				{
					singers[i] = singers[i + 1];//从后往前移动
					i++;
				}
				*n = *n - 1;
				cout << "已删除，但并未保存到文件。" << endl;
			}
		}
		else
		{
			cout << "已取消删除！" << endl;
			return;
		}
		cout << "\n是否继续使用删除功能？" << endl;
		while (1)
		{
			cout << "退出：0		继续：1" << endl;
			cout << "\n请输入你的选择：";
			cin >> key;
			switch (key)
			{
			case 1:
				goto loop;
			case 0:
				return;
			default:
				cout << "请在0-1之间输入！\n";
			}
		}

	}



}

/*修改函数*/
bool ModifyInfo(Singer singers[], int n, int judge_num)
{
	int i = 0;//数组下标
	int s = 0;//数组下标
	int k = 0;//编号
	int scoremenu = 0;
	bool flag = 0;//修改结果，1表示修改成功，0表示修改失败
	char name[20];//姓名
	int find_rslt = 0;//查询结果
	int no = 0;//编号
	int key = 1;//循环开关
	char choice = ' ';
	int jdgno = 0;//裁判顺序
	int signal = 0; //用于判断打分是否正常 1正常 0不正常
	float jdgscore = 0;//裁判评分
	char savechoice = ' ';

	/*先查后改，编号唯一*/
	cout << "\n请输入进行信息修改的选手编号（整数）：";
	cin >> no;
	cout << "要查找的选手编号是：" << no << endl;
	find_rslt = binaryFindNo(singers, n, no);
	if (find_rslt != -1)
	{
		/*修改数据展示*/
		cout << "符合条件的待修改记录：\n";
		cout << left << setw(4) << "选手编号" << '\t' << setw(4) << "姓名" << '\t' << setw(4) << "平均成绩"
			<< '\t' << setw(4) << "最高分" << '\t' << setw(4) << "最低分" << endl;
		cout << left << setw(4) << singers[find_rslt].Number << '\t' << '\t' << setw(4) << singers[find_rslt].name << '\t' << setw(4)
			<< singers[find_rslt].averagescore << '\t' << '\t' << singers[find_rslt].maxscore << '\t' << singers[find_rslt].minscore << endl;
		cout << "\n\n已查找到该选手,请选择需要修改的信息！\n\n";
		cout << "  *********************修改信息菜单*********************       \n";
		cout << "     ---------------------------------------------   \n";
		cout << "     *********************************************     \n";
		cout << "     * 1.修改选手编号  *      *  2.修改选手姓名  *     \n";
		cout << "     *********************************************     \n";
		cout << "     * 3.修改选手成绩  *      *  0.取消修改信息  *     \n";
		cout << "     *********************************************     \n";
		cout << "     ---------------------------------------------   \n";
		cout << "  ******************************************************\n\n";
		cout << "输入你的修改选择（0-3）：";
		cin >> i;
		switch (i)
		{
		case 1:
			/*修改选手编号*/
			cout << "输入新的选手编号：";
			cin >> no;
			singers[find_rslt].Number = no;
			cout << "修改后的记录是：\n";
			cout << left << setw(4) << "选手编号" << '\t' << setw(4) << "姓名" << '\t' << setw(4) << "平均成绩"
				<< '\t' << setw(4) << "最高分" << '\t' << setw(4) << "最低分" << endl;
			cout << left << setw(4) << singers[find_rslt].Number << '\t' << '\t' << setw(4) << singers[find_rslt].name << '\t' << setw(4)
				<< singers[find_rslt].averagescore << '\t' << '\t' << singers[find_rslt].maxscore << '\t' << singers[find_rslt].minscore << endl;
			cout << "是否保存修改结果?(Y or N):";
			cin >> savechoice;
			if (savechoice == 'Y' || savechoice == 'y')
			{
				SaveInfo(singers, n);
			}
			else
			{
				cout << "已完成修改，但未保存至文件。" << endl;
			}
			break;
		case 2:
			/*修改选手姓名*/
			cout << "输入新的选手姓名：";
			cin >> name;
			singers[i].name = new char(strlen(name) + 1);
			if (singers[i].name != 0)
			{
				strcpy(singers[i].name, name);
			}
			cout << "修改后的记录是：\n";
			cout << left << setw(4) << "选手编号" << '\t' << setw(4) << "姓名" << '\t' << setw(4) << "平均成绩"
				<< '\t' << setw(4) << "最高分" << '\t' << setw(4) << "最低分" << endl;
			cout << left << setw(4) << singers[find_rslt].Number << '\t' << '\t' << setw(4) << singers[find_rslt].name << '\t' << setw(4)
				<< singers[find_rslt].averagescore << '\t' << '\t' << singers[find_rslt].maxscore << '\t' << singers[find_rslt].minscore << endl;
			cout << "是否保存修改结果?(Y or N):";
			cin >> savechoice;
			if (savechoice == 'Y' || savechoice == 'y')
			{
				SaveInfo(singers, n);
			}
			else
			{
				cout << "已完成修改，但未保存至文件。" << endl;;
			}
			break;
		case 3:
			/*修改成绩*/
			/*要么指定修改部分成绩 要么全部都进行修改*/
			cout << "  ******************************************************\n\n";
			cout << "  *               成绩修改功能子菜单                   *\n \n";
			cout << "  ******************************************************\n\n";
			cout << "     ---------------------------------------------   \n";
			cout << "     *********************************************     \n";
			cout << "     * 1.部分评分修改  *       *  2.所有评分修改   *     \n";
			cout << "     *********************************************     \n";
			cout << "     * 0.返回上一级菜单*     \n";
			cout << "     *********************************************     \n";
			cout << "     ---------------------------------------------   \n";
			cout << "  ******************************************************\n\n";
			cout << "请选择功能：";
			cin >> scoremenu;
			switch (scoremenu)
			{
			case 1:
			{
				/*修改部分成绩*/
				while (key)
				{
					cout << "请输入需要修改评判分数的位置（1-10）：";
					cin >> jdgno;
					/*判断是否分数位置是否在[1,judge_num]*/
					for (s = 1; s <= judge_num; s++)
					{
						if (jdgno == s)
						{
							signal = 1;
							break;
						}
					}
					if (signal == 0)//不是在[0,10]则重新输入
					{
						cout << "位置错误！请重新输入！" << endl;
						cout << "请输入更正后的评判分位置（1-10）：";
						cin >> jdgno;
					}

					cout << "请输入更正后的评判分（0-10）：";
					cin >> jdgscore;
					/*判断是否打分在[0,10]*/
					for (s = 0; s <= 10; s++)
					{
						if ((int)jdgscore == s)
						{
							signal = 1;
							break;
						}
					}
					if (signal == 0)//不是在[0,10]则重新输入
					{
						cout << "评分错误！请重新输入！" << endl;
						cout << "请输入更正后的评判分（0-10）：";
						cin >> jdgscore;
					}

					/*只有打分正常才进行下一步操作*/
					singers[find_rslt].prescores[jdgno - 1] = jdgscore;
					singers[find_rslt].maxscore = singers[find_rslt].GetMax(singers[find_rslt].prescores, judge_num);
					singers[find_rslt].minscore = singers[find_rslt].GetMin(singers[find_rslt].prescores, judge_num);
					singers[find_rslt].totalscore = singers[find_rslt].sum(singers[find_rslt].prescores, judge_num);
					singers[find_rslt].evenscore = singers[find_rslt].totalscore - singers[find_rslt].maxscore - singers[find_rslt].minscore;
					singers[find_rslt].averagescore = singers[find_rslt].evenscore / (judge_num - 2);
					cout << "修改后的记录是：\n";
					cout << left << setw(4) << "选手编号" << '\t' << setw(4) << "姓名" << '\t' << setw(4) << "平均成绩"
						<< '\t' << setw(4) << "最高分" << '\t' << setw(4) << "最低分" << endl;
					cout << left << setw(4) << singers[find_rslt].Number << '\t' << '\t' << setw(4) << singers[find_rslt].name << '\t' << setw(4)
						<< singers[find_rslt].averagescore << '\t' << '\t' << singers[find_rslt].maxscore << '\t' << singers[find_rslt].minscore << endl;
					flag = 1;
					cout << "是否保存修改结果?(Y or N):";
					cin >> savechoice;
					if (savechoice == 'Y' || savechoice == 'y')
					{
						SaveInfo(singers, n);
					}
					else
					{
						cout << "已完成修改，但未保存至文件。" << endl;
					}
					cout << "\n继续修改请输入Y，输入其他输入则退出本功能：";
					getchar();
					choice = getchar();
					if (choice == 'Y' || choice == 'y')
					{
						cout << "欢迎继续使用！" << endl;
					}
					else
					{
						cout << "正在退出本菜单...." << endl;
						return flag;
					}
				}
				break;
			}
			case 2:
			{
				/*全部成绩的修改*/
				while (key)
				{
					int q;//循环变量
					int restart = 0;
				loop:
					for (q = restart; q <= judge_num - 1; q++)//内层循环为评委 即10位评委依次对选手打分
					{
						cout << "请输入第" << q + 1 << "位评委对第" << no << "号选手的评分([0,10]）：";
						cin >> singers[find_rslt].prescores[q];
						int s = 0;
						int signal = 0;//判断标志变量
						/*判断是否打分在[0,10]*/
						for (s = 0; s <= 10; s++)
						{
							if ((int)singers[find_rslt].prescores[q] == s)
							{
								signal = 1;
								break;
							}
						}
						if (signal == 0)//不是在[0,10]则重新输入
						{
							restart = q;
							cout << "评分错误！请重新输入！" << endl;
							goto loop;
						}
					}
					/*所有选手的所有评分完成，开始处理并录入到选手的个人信息里*/
					singers[find_rslt].maxscore = singers[find_rslt].GetMax(singers[find_rslt].prescores, judge_num);
					singers[find_rslt].minscore = singers[find_rslt].GetMin(singers[find_rslt].prescores, judge_num);
					singers[find_rslt].totalscore = singers[find_rslt].sum(singers[find_rslt].prescores, judge_num);
					singers[find_rslt].evenscore = singers[find_rslt].totalscore - singers[find_rslt].maxscore - singers[find_rslt].minscore;
					singers[find_rslt].averagescore = singers[find_rslt].evenscore / (judge_num - 2);
					cout << "已完成对第" << find_rslt << "号选手的成绩记录！" << endl;
					cout << "修改后的记录是：\n";
					cout << left << setw(4) << "选手编号" << '\t' << setw(4) << "姓名" << '\t' << setw(4) << "平均成绩"
						<< '\t' << setw(4) << "最高分" << '\t' << setw(4) << "最低分" << endl;
					cout << left << setw(4) << singers[find_rslt].Number << '\t' << '\t' << setw(4) << singers[find_rslt].name << '\t' << setw(4)
						<< singers[find_rslt].averagescore << '\t' << '\t' << singers[find_rslt].maxscore << '\t' << singers[find_rslt].minscore << endl;
					flag = 1;
					cout << "是否保存修改结果?(Y or N):";
					cin >> savechoice;
					if (savechoice == 'Y' || savechoice == 'y')
					{
						SaveInfo(singers, n);
					}
					else
					{
						cout << "已完成修改，但未保存至文件。" << endl;
					}
					cout << "\n继续修改请输入Y，输入其他输入则退出本功能：";
					getchar();
					choice = getchar();
					if (choice == 'Y' || choice == 'y')
					{
						cout << "欢迎继续使用！" << endl;
					}
					else
					{
						cout << "正在退出本菜单...." << endl;
						return flag;
					}
				}
				break;
			}
			case 0:
				break;
			default:
				cout << "请在0-2之间输入！" << endl;
			}
			break;
		case 0:
			break;
		default:
			cout << "请在0-3之间输入！\n";
		}
	}
	else if (find_rslt == -1)
	{
		cout << "该编号不存在！请核对编号！" << endl;
	}
	return flag;
}