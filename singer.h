#pragma once
#define _CRT_SECURE_NO_WARNINGS//fopen函数不安全
#include<string>//字符串比较
#include<iomanip>//格式控制
#include<fstream>//文件输入输出流
#include<stdlib.h>

/*裁判信息*/
class Judge
{
public:
	int JudgeNo;				//评委编号
	float score;				//评委评分
	friend class Singer;		//judge和singer互为友元类
	~Judge();					//析构函数
};

/*歌手信息*/
class Singer
{
private:
	int Number;			//选手编号
	char* name;		//选手姓名
	float prescores[10];//选手初始10个成绩数据
	float maxscore;		//选手最高分
	float minscore;		//选手最低分
	float totalscore;	//选手总分(10)
	float evenscore;	//选手(8)
	float averagescore;	//选手平均分
public:
	friend class Judge;														//judge和singer互为友元类

	Singer(float presc[], int Num, const char* nam,							//构造函数
		float maxsc, float minsc, float totalsc, float evensc, float averagesc);
	~Singer();																//析构函数

	/*类的成员函数*/
	float GetMax(float a[], int len);										//最大值
	float GetMin(float b[], int len);										//最小值
	float sum(float c[], int len);											//求和

	/*友元函数*/
	friend void menu(Singer singers[], Judge judges[], int* n, int* m, int* judge_num, bool* system_key);				//菜单函数
	friend void ContestantInfo(Singer singers[], Judge judges[], int* n, int* m);	//选手个人信息输入函数
	friend void ContestantRankings(Singer singers[], int n);						//选手排名
	friend bool QueryInfo(Singer singers[], int n);									//查询选手信息
	friend void InsertInfo(Singer singers[], Judge judges[], int* n, int* m, int judge_num);		//插入选手数据
	friend void SaveInfo(Singer singers[], int n);									//保存函数
	friend void JudgeScores(Singer singers[], Judge judges[], int* n, int* m, int judge_num);		//裁判打分函数
	friend bool ModifyInfo(Singer singers[], int n, int judge_num);								//修改函数
	friend void DelInfo(Singer singers[], int* n);									//删除函数
	friend void DisplayInfo(Singer singers[], int n);								//信息展示函数

	/*友元函数子函数*/
	friend int binaryFindNo(Singer singers[], int n, int score);					//二分查找函数
	friend void RankView(Singer singers[], int n);									//排序查看函数
	friend void ObverseOrder(Singer singers[], int n);								//正序输出
	friend void ReverseOrder(Singer singers[], int n);								//逆序输出
	friend void BubbleSort(Singer singers[], int n);								//冒泡排序
	friend void SelectSort(Singer singers[], int n);								//选择排序
	friend void ShellSort(Singer singers[], int n);									//希尔排序
	friend void InsertSort(Singer singers[], int n);								//插入排序
};

/*系统帮助函数*/
void SystemHelp();