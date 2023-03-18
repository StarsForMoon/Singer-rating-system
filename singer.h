#pragma once
#define _CRT_SECURE_NO_WARNINGS//fopen��������ȫ
#include<string>//�ַ����Ƚ�
#include<iomanip>//��ʽ����
#include<fstream>//�ļ����������
#include<stdlib.h>

/*������Ϣ*/
class Judge
{
public:
	int JudgeNo;				//��ί���
	float score;				//��ί����
	friend class Singer;		//judge��singer��Ϊ��Ԫ��
	~Judge();					//��������
};

/*������Ϣ*/
class Singer
{
private:
	int Number;			//ѡ�ֱ��
	char* name;		//ѡ������
	float prescores[10];//ѡ�ֳ�ʼ10���ɼ�����
	float maxscore;		//ѡ����߷�
	float minscore;		//ѡ����ͷ�
	float totalscore;	//ѡ���ܷ�(10)
	float evenscore;	//ѡ��(8)
	float averagescore;	//ѡ��ƽ����
public:
	friend class Judge;														//judge��singer��Ϊ��Ԫ��

	Singer(float presc[], int Num, const char* nam,							//���캯��
		float maxsc, float minsc, float totalsc, float evensc, float averagesc);
	~Singer();																//��������

	/*��ĳ�Ա����*/
	float GetMax(float a[], int len);										//���ֵ
	float GetMin(float b[], int len);										//��Сֵ
	float sum(float c[], int len);											//���

	/*��Ԫ����*/
	friend void menu(Singer singers[], Judge judges[], int* n, int* m, int* judge_num, bool* system_key);				//�˵�����
	friend void ContestantInfo(Singer singers[], Judge judges[], int* n, int* m);	//ѡ�ָ�����Ϣ���뺯��
	friend void ContestantRankings(Singer singers[], int n);						//ѡ������
	friend bool QueryInfo(Singer singers[], int n);									//��ѯѡ����Ϣ
	friend void InsertInfo(Singer singers[], Judge judges[], int* n, int* m, int judge_num);		//����ѡ������
	friend void SaveInfo(Singer singers[], int n);									//���溯��
	friend void JudgeScores(Singer singers[], Judge judges[], int* n, int* m, int judge_num);		//���д�ֺ���
	friend bool ModifyInfo(Singer singers[], int n, int judge_num);								//�޸ĺ���
	friend void DelInfo(Singer singers[], int* n);									//ɾ������
	friend void DisplayInfo(Singer singers[], int n);								//��Ϣչʾ����

	/*��Ԫ�����Ӻ���*/
	friend int binaryFindNo(Singer singers[], int n, int score);					//���ֲ��Һ���
	friend void RankView(Singer singers[], int n);									//����鿴����
	friend void ObverseOrder(Singer singers[], int n);								//�������
	friend void ReverseOrder(Singer singers[], int n);								//�������
	friend void BubbleSort(Singer singers[], int n);								//ð������
	friend void SelectSort(Singer singers[], int n);								//ѡ������
	friend void ShellSort(Singer singers[], int n);									//ϣ������
	friend void InsertSort(Singer singers[], int n);								//��������
};

/*ϵͳ��������*/
void SystemHelp();