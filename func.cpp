#pragma once
#include "singer.h"
#include <iostream>
using namespace std;

/*�˵�����*/
void menu(Singer singers[], Judge judges[], int* n, int* m, int* judge_num, bool* system_key)
{
	int choice;
	cout << "  ******************************************************\n\n";
	cout << "  *                ���ֱ�������ϵͳ                    *\n \n";
	cout << "  ******************************************************\n\n";
	cout << "  *********************ϵͳ���ܲ˵�*********************       \n";
	cout << "     ---------------------------------------------   \n";
	cout << "     *********************************************     \n";
	cout << "     * 0.ϵͳ������˵��  * *  1.����ѡ����Ϣ   *     \n";
	cout << "     *********************************************     \n";
	cout << "     * 2.������ί���    * *  3.ѡ�ֳɼ�����   *     \n";
	cout << "     *********************************************     \n";
	cout << "     * 4.��ѯѡ������    * *  5.׷��ѡ������   *     \n";
	cout << "     *********************************************     \n";
	cout << "     * 6.����ѡ������    * *  7.ɾ��ѡ����Ϣ   *     \n";
	cout << "     *********************************************     \n";
	cout << "     * 8.��ʾѡ����Ϣ    * *  9.�޸�ѡ����Ϣ*     \n";
	cout << "     *********************************************     \n";
	cout << "     * 10.�˳�ϵͳ       *     \n";
	cout << "     ---------------------------------------------     \n";
	cout << "��ѡ��˵����:";
	cin >> choice;
	switch (choice)//switch���֧���ڹ���ѡ��
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
		cout << "�����˳�����!\n";
		break;
		//exit(0);	//��ֹ������������
	}
	default:
	{
		cout << "����0-10֮��ѡ��\n";//����ʹ���Ѻ���
	}
	}
}

/*ϵͳ��������*/
void SystemHelp()
{
	cout << "\n1.��ӭʹ��ϵͳ������\n";
	cout << "\n2.���ν���ϵͳ��,���Ȱ��ղ˵���ʾ�������ִ���\n";
	cout << "\n3.������������ѡ����Ϣ�ٽ��к�������\n";
	cout << "\n4.����ѧ����Ϣ��,�мǱ���\n";
	cout << "\n5.лл����ʹ�ã�\n";
}

/*���캯��*/
Singer::Singer(float presc[], int Num, const char* nam,
	float maxsc, float minsc, float totalsc, float evensc, float averagesc)
{
	/*�����������ڶ���ĳ�ʼ��*/
	int x = 0;//ѭ������                                                    
	Number = Num;
	/*�˴����ö�̬�ڴ����*/
	name = new char(strlen(nam) + 1);
	if (name != 0)
	{
		strcpy(name, nam);
	}
	/*�������ֳ�ʼ��*/
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

/*Singer�����������*/
Singer::~Singer()
{
	cout << "\nSinger������Ѿ�����" << endl;
}

/*Judge�����������*/
Judge::~Judge()
{
	cout << "\nJudge������Ѿ�����" << endl;
}

/*����߷ֺ���*/
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

/*����ͷֺ���*/
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

/*��ͺ���*/
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

/*ѡ����Ϣ����*/
void ContestantInfo(Singer singers[], Judge judges[], int* n, int* m)
{
	int i = *n;
	int j = 0;
	int flag = -1;//i��jѭ������
	char name[20];
	cout << "����������ӵ�ѧ������";
	cin >> *m;//�������ӵ�����m
	if (*m > 0)
	{
		do
		{
			flag = 1;
			while (flag)
			{
				flag = 0;
				cout << "�������" << i + 1 << "λѡ�ֵı�ţ�";
				cin >> singers[i].Number;//����ѡ�ֱ�� ��Ϊֻ��ѡ�ֱ����Ψһ��
				/*У��ѡ�ֱ��*/
				for (j = 0; j < i; j++)//������ѡ�ֱ���в���
				{
					if (singers[i].Number == singers[j].Number)
					{
						cout << "��ѡ�ֱ���Ѵ��ڣ����������룡\n";
						flag = 1;
						break;
					}
				}
			}
			/*ֻ�е����������ȷ�����¼�������Ϣ*/
			cout << "�������" << i + 1 << "λѡ�ֵ�������";
			/*��̬�ڴ����*/
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
	*n = *n + *m;//������
	cout << "ѡ����Ϣ������ϣ�����\n";
	cout << "���Ժ�ѡ�� ��������ί��֡� ���гɼ���¼��" << endl;
	system("pause");
}

/*������Ϣ�����ֺ���*/
void JudgeScores(Singer singers[], Judge judges[], int* n, int* m, int judge_num)
{
	/*ѡ��¼�������Ϊ0ʱ���ܸù���*/
	if (n == 0)
	{
		cout << "\n                !��������ѡ����Ϣ!\n\n";
		return;
	}
	int r;//ѭ������
	for (r = 0; r < judge_num; r++)
	{
		cout << "�������" << r + 1 << "λ��ί���룺";
		cin >> judges[r].JudgeNo;
	}
	cout << "����ɶ���ί����¼�룡" << endl;
	int p;//ѭ������
	int q;//ѭ������
	int order = 1;//����˳�����
	int sorder = *n - *m;//ѡ��˳�����
	for (p = 1; p <= *m; p++)//���ѭ��Ϊѡ�� ÿһλѡ�ִ����֮�������һ��ѡ��
	{
		int restart = 0;
	loop:
		for (q = restart; q <= judge_num - 1; q++)//�ڲ�ѭ��Ϊ��ί ��10λ��ί���ζ�ѡ�ִ��
		{
			cout << "�������" << order << "λ��ί�Ե�" << p + *n - *m << "λѡ�ֵ�����([0,10]����";
			cin >> judges[q].score;
			int s = 0;
			int signal = 0;//�жϱ�־����
			/*�ж��Ƿ�����[0,10]*/
			for (s = 0; s <= 10; s++)
			{
				if ((int)judges[q].score == s)
				{
					signal = 1;
					break;
				}
			}
			if (signal == 0)//������[0,10]����������
			{
				restart = q;
				cout << "���ִ������������룡" << endl;
				goto loop;
			}
			singers[sorder].prescores[order - 1] = judges[q].score;//������ί��ֵ�ͬʱ ���浽ѡ�ֵ�prescore������
			order++;
		}
		/*����ѡ�ֵ�����������ɣ���ʼ����¼�뵽ѡ�ֵĸ�����Ϣ��*/
		singers[sorder].maxscore = singers[sorder].GetMax(singers[sorder].prescores, judge_num);
		singers[sorder].minscore = singers[sorder].GetMin(singers[sorder].prescores, judge_num);
		singers[sorder].totalscore = singers[sorder].sum(singers[sorder].prescores, judge_num);
		singers[sorder].evenscore = singers[sorder].totalscore - singers[sorder].maxscore - singers[sorder].minscore;
		singers[sorder].averagescore = singers[sorder].evenscore / (judge_num - 2);
		sorder++;
		order = 1;
		cout << "����ɶԵ�" << p + *n - *m << "λѡ�ֵĳɼ���¼��" << endl;
		system("pause");
	}
	cout << "����������Ϣ�Ѿ�������ϣ�����\n";
}

/*���ֲ��Һ���*/
int binaryFindNo(Singer singers[], int n, int no)
{
	int low = 0;//��λλ���±�
	int high = n - 1;//��λλ���±�
	int mid = 0;//�м�λ���±�

	//�Ȱ��������-ð�ݷ�
	BubbleSort(singers, n);
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (singers[mid].Number == no)
		{
			return mid;//��ѯ�ɹ�
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
	return -1;//��ѯʧ��
}

/*��Ϣ��ʾ����*/
void DisplayInfo(Singer singers[], int n)
{
	cout << "ϵͳ������ѡ����Ϣ��" << endl;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		cout << "-----------------------------------------------" << endl;
		cout << "ѡ�ֱ�ţ�" << singers[i].Number << endl;
		cout << "ѡ��������" << singers[i].name << endl;
		cout << "ѡ����߷֣�" << singers[i].maxscore << endl;
		cout << "ѡ����ͷ֣�" << singers[i].minscore << endl;
		cout << "ѡ���ܷ֣�" << singers[i].evenscore << endl;
		cout << "ѡ��ƽ���֣�" << singers[i].averagescore << endl;
		cout << "-----------------------------------------------" << endl;
	}
}

/*�����������*/
void ObverseOrder(Singer singers[], int n)
{
	/*Ĭ�ϴ�С��������*/
	/*���������*/
	int g = 0;
	int count = 0;//����
	int rank = 0;//����
	cout << left << setw(4) << "����" << '\t' << "���" << '\t' << '\t' << setw(8) << "����"
		<< '\t' << setw(5) << "ƽ���ɼ�" << endl;
	for (g = 0; g < n; g++)
	{
		if (g == 0)							//�������һ���� ������С����һ��
		{
			rank++;
			count++;
			cout << left << setw(4) << rank << '\t' << singers[g].Number << '\t' << '\t' << setw(8) << left
				<< singers[g].name << '\t' << setw(5) << fixed << setprecision(2) << singers[g].averagescore;
		}
		else
		{

			if (singers[g].Number == singers[g + 1].Number) //���ǰ��ĳɼ��ͺ���ĳɼ���� ������+1����������
			{
				count++;
				cout << left << setw(4) << rank << '\t' << singers[g].Number << '\t' << '\t' << setw(8) << left
					<< singers[g].name << '\t' << setw(5) << fixed << setprecision(2) << singers[g].averagescore;

			}
			else //��ǰ��ĳɼ��ͺ���ĳɼ������ ������ + 1 ������ֵΪ����
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

/*�����������*/
void ReverseOrder(Singer singers[], int n)
{
	/*Ĭ�ϴ�С��������*/
	/*���������*/
	int g = 0;
	int count = 0;//����
	int rank = 0;//����
	cout << left << setw(4) << "����" << '\t' << "���" << '\t' << '\t' << setw(8) << "����"
		<< '\t' << setw(5) << "ƽ���ɼ�" << endl;
	for (g = n - 1; g >= 0; g--)
	{
		if (g == n - 1)//��������һ�� ������
		{
			rank++;
			count++;
			cout << left << setw(4) << rank << '\t' << singers[g].Number << '\t' << '\t' << setw(8) << left
				<< singers[g].name << '\t' << setw(5) << fixed << setprecision(2) << singers[g].averagescore;
		}
		else
		{

			if (singers[g].Number == singers[g + 1].Number) //���ǰ��ĳɼ��ͺ���ĳɼ���� ������+1����������
			{
				count++;
				cout << left << setw(4) << rank << '\t' << singers[g].Number << '\t' << '\t' << setw(8) << left
					<< singers[g].name << '\t' << setw(5) << fixed << setprecision(2) << singers[g].averagescore;
			}
			else //��ǰ��ĳɼ��ͺ���ĳɼ������ ������ + 1 ������ֵΪ����
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

/*ѡ�ֳɼ�������*/
void ContestantRankings(Singer singers[], int n)
{
	if (n == 0)
	{
		cout << "\n                !��������ѡ����Ϣ!\n\n";
		return;
	}
	int choice = -1;
	cout << "****************����ʽ*****************" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "*	1�����ձ������			*" << endl;
	cout << "*	2������ƽ���ɼ�����		*" << endl;
	cout << "*	3�����ڱ�����ȵĳɼ�����	*" << endl;
	cout << "*	4�����ڳɼ����ȵı������	*" << endl;
	cout << "*	0���˳����˵�			*" << endl;
	cout << "\n����������ʽ��";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		/*��������0-2֮�ڵ����ݵ�������*/
		if (singers == NULL || n == 0)
		{
			cout << "\n ѡ����Ϣδ¼�룡" << endl;
			return;
		}
		if (n == 1)//���������ˣ�����ֱ�����
		{
			RankView(singers, n);
		}
		else if (n == 2)
		{
			/*Ĭ���ųɴ�С�����ٰ��������*/
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
			/*ð������*/
			/*�������*/
			RankView(singers, n);
		}
		break;
	}
	case 2:
	{
		/*��������0-2֮�ڵ����ݵ�������*/
		if (singers == NULL || n == 0)
		{
			cout << "\n ѡ����Ϣδ¼�룡" << endl;
			return;
		}
		if (n == 1)//���������ˣ�����ֱ�����
		{
			RankView(singers, n);
		}
		else if (n == 2)
		{
			/*Ĭ���ųɴ�С�����ٰ��������*/
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
			/*ѡ������*/
			/*�ɼ�����*/
			SelectSort(singers, n);
			RankView(singers, n);
		}
		break;
	}
	case 3:
	{
		/*��������0-2֮�ڵ����ݵ�������*/
		if (singers == NULL || n == 0)
		{
			cout << "\n ѡ����Ϣδ¼�룡" << endl;
			return;
		}
		if (n == 1)//���������ˣ�����ֱ�����
		{
			RankView(singers, n);
		}
		else if (n == 2)
		{
			/*Ĭ���ųɴ�С�����ٰ��������*/
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
			/*ϣ������*/
			/*������ȵĳɼ�����*/
			ShellSort(singers, n);
			RankView(singers, n);
		}
		break;
	}
	case 4:
	{
		/*��������0-2֮�ڵ����ݵ�������*/
		if (singers == NULL || n == 0)
		{
			cout << "\n ѡ����Ϣδ¼�룡" << endl;
			return;
		}
		if (n == 1)//���������ˣ�����ֱ�����
		{
			RankView(singers, n);
		}
		else if (n == 2)
		{
			/*Singer tmp;*/
			/*Ĭ���ųɴ�С�����ٰ��������*/
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
			/*��������*/
			/*���ڳɼ����ȵı������*/
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
		cout << "����0-4֮�����룬����0�˳���" << endl;
	}
	}
}

/*���뺯��*/
void InsertInfo(Singer singers[], Judge judges[], int* n, int* m, int judge_num)
{
	/*������ѡ�����ݷ�Ϊ�����裺
	1.����ѡ����Ϣ
	2.��ί�Ը�ѡ�ֵ�����
	����ǰ���ѡ����Ϣ��������ί���ֺ�������*/
	cout << '\n' << "������ѡ����Ϣ" << '\n' << endl;
	ContestantInfo(singers, judges, n, m);
	cout << '\n' << "��������ί����" << '\n' << endl;
	JudgeScores(singers, judges, n, m, judge_num);
	system("pause");
}

/*���溯��*/
void SaveInfo(Singer singers[], int n)
{
	if (n == 0)
	{
		cout << "\n                !��������ѡ����Ϣ!\n\n";
		return;
	}
	int i;
	FILE* fp;
	char filename[30];
	cout << "������Ҫ������ļ�����";
	cin >> filename;//cin.getline(filename,30);
	fp = fopen(filename, "w+");
	fstream outfile;
	outfile.open(filename);
	if (!outfile)//������ܽ������ļ������
	{
		cout << "���ܽ�������ļ�" << endl;
		exit(0);
	}

	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%d\t%s\t%.2f\t%.2f\t\n", singers[i].Number, singers[i].name, singers[i].totalscore, singers[i].averagescore);
	}
	cout << "����ɹ�������\n";//�Ѻ���
	fclose(fp);
	system("pause");
}

/*������չʾ����*/
void RankView(Singer singers[], int n)
{
	/*������ɺ�����*/
	/*������Ҳ�������������*/
	cout << "***********ѡ��鿴��ʽ**********" << endl;
	cout << "---------------------------------" << endl;
	cout << "* 0.����鿴 *	   * 1.����鿴 *" << endl;
	cout << "*********************************" << endl;
	cout << "-----�� �� 3 �� �� �� �� ��-----" << endl;
	cout << "*********************************" << endl;
	int key = 1;
	while (key)
	{
		int rankchoice = -1;
		cout << "\n������鿴��ʽ��";
		cin >> rankchoice;
		switch (rankchoice)
		{
		case 0:
		{
			ObverseOrder(singers, n);//���ź������������鿴 
			key = 0;
			break;
		}
		case 1:
		{
			ReverseOrder(singers, n);//���ź������������鿴
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
			cout << "����0-3֮�����롣" << endl;
		}
		}
	}
}

/*��ѯ����*/
bool QueryInfo(Singer singers[], int n)
{
	int i = 0;//�����±�
	int no = 0;//���
	bool flag = 0;//���ҽ����1��ʾ���ҳɹ���0��ʾ����ʧ��
	int noMin = 0;//�����ʼֵ
	int noMax = 0;//��Ž���ֵ
	int find_no = 0;//���ֲ��ҵ��ı��
	int menuSelect = 0;//�����˵�ѡ��
	int menu = 0; //���Բ�ѯ�����˵�ѡ��
	char str[20]; //��ѯ���ַ���������)
	float score = 0;//����
	float scoreMin = 0;//������ʼֵ
	float scoreMax = 0;//��������ֵ
	menu = 9;
	while (menu != 0)
	{
		flag = 0;
		/*���Բ�ѯѡ������˵�*/
		cout << "***********ѡ���ѯ����**********" << endl;
		cout << "---------------------------------" << endl;
		cout << "* 1.��Ų�ѯ *	   * 2.�����鿴 *" << endl;
		cout << "*********************************" << endl;
		cout << "* 3.�ɼ���ѯ *	   * 0.���ز˵� *" << endl;
		cout << "*********************************" << endl;
		cout << "��ӭʹ�ò�ѯ���ܣ�" << endl;
		cout << "�������ѯ��Ϣѡ�";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			/*��Ų�ѯ�����˵��������*/
			cout << "  *********************��Ų�ѯ�˵�*********************       \n";
			cout << "     ---------------------------------------------   \n";
			cout << "     *********************************************     \n";
			cout << "     * 1.��ȷ��ѯ��˵��  *         *  2.��Χ��ѯ   *     \n";
			cout << "     *********************************************     \n";
			cout << "     * 0.������һ���˵�  *         \n";
			cout << "     *********************************************     \n";
			cout << "     ---------------------------------------------   \n";
			cout << "  ******************************************************\n\n";
			cout << "���������ѡ��0-2����";
			cin >> menuSelect;
			switch (menuSelect)
			{
			case 1:
			{
				/*��ȷ���ұ��*/
				int i = 0;//�����±�
				int no = 0;//���
				bool flag = 0;//���ҽ����1��ʾ���ҳɹ���0��ʾ����ʧ��
				cout << "\n��������ҵ�ѡ�ֱ�ţ���������";
				cin >> no;
				cout << "Ҫ���ҵ�ѡ�ֱ���ǣ�" << no << endl;
				/*�˴�Ӧ�ö��ֲ���*/
				find_no = binaryFindNo(singers, n, no);
				if (find_no != -1)
				{
					cout << "���������ļ�¼��\n";
					cout << left << setw(4) << "ѡ�ֱ��" << '\t' << setw(4) << "����" << '\t' << setw(4) << "ƽ���ɼ�"
						<< '\t' << setw(4) << "��߷�" << '\t' << setw(4) << "��ͷ�" << endl;
					cout << left << setw(4) << singers[find_no].Number << '\t' << '\t' << setw(4) << singers[find_no].name << '\t' << setw(4)
						<< singers[find_no].averagescore << '\t' << '\t' << singers[find_no].maxscore << '\t' << singers[find_no].minscore << endl;
					flag = 1;
					break;
				}
				else if (find_no == -1)
				{
					cout << "�ñ�Ų����ڣ���˶Ա�ţ�" << endl;
				}
				break;
			}
			case 2:
			{
				/*��Χ���ұ��*/
				cout << "��������ҵ�ѡ�ֱ�ŷ�Χ��\nѡ�ֱ��>=";
				cin >> noMin;
				cout << "ѡ�ֱ��<=";
				cin >> noMax;
				cout << "Ҫ���ҵı�ŷ�Χ�ǣ�" << noMin << "<= ��� <=" << noMax << endl;
				cout << "���������ļ�¼" << endl;
				cout << left << setw(4) << "ѡ�ֱ��" << '\t' << setw(4) << "����" << '\t' << setw(4) << "ƽ���ɼ�"
					<< '\t' << setw(4) << "��߷�" << '\t' << setw(4) << "��ͷ�" << endl;
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
				cout << "����0-2֮��ѡ��" << endl;
			}
			}
			break;
		}
		case 2:
		{
			/*ģ������ְ������*/
			cout << "��������ҵ�ְ��������";
			cin >> str;
			cout << "Ҫ���ҵ�ְ�������ǣ�" << str << endl;
			cout << "���������ļ�¼��\n";
			cout << left << setw(4) << "ѡ�ֱ��" << '\t' << setw(4) << "����" << '\t' << setw(4) << "ƽ���ɼ�"
				<< '\t' << setw(4) << "��߷�" << '\t' << setw(4) << "��ͷ�" << endl;
			for (i = 0; i < n; i++)
			{
				if (strstr(singers[i].name, str))//ʵ��ģ�� ��ȷͬ
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
			/*���ɼ���ѯ*/
			/*�ɼ���ѯ�����˵��������*/
			cout << "  *********************�ɼ���ѯ�˵�*********************       \n";
			cout << "     ---------------------------------------------   \n";
			cout << "     *********************************************     \n";
			cout << "     * 1.��ȷ��ѯ��˵��  *         *  2.��Χ��ѯ   *     \n";
			cout << "     *********************************************     \n";
			cout << "     * 0.������һ���˵�  *         \n";
			cout << "     *********************************************     \n";
			cout << "     ---------------------------------------------   \n";
			cout << "  ******************************************************\n\n";
			cout << "���������ѡ��0-2����";
			cin >> menuSelect;
			switch (menuSelect)
			{
			case 1:
			{
				/*��ȷ���ҳɼ�*/
				cout << "��������ҵ�ƽ���ɼ���";
				cin >> score;
				cout << "Ҫ���ҵ�ƽ���ɼ��ǣ�" << score << endl;
				cout << "���������ļ�¼��" << endl;
				cout << left << setw(4) << "ѡ�ֱ��" << '\t' << setw(4) << "����" << '\t' << setw(4) << "ƽ���ɼ�"
					<< '\t' << setw(4) << "��߷�" << '\t' << setw(4) << "��ͷ�" << endl;
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
				/*��Χ���ҳɼ�*/
				cout << "��������ҵ�ƽ���ɼ���Χ��\n";
				cout << "ƽ���ɼ� >= ";
				cin >> scoreMin;
				cout << "ƽ���ɼ�<=";
				cin >> scoreMax;
				cout << "Ҫ���ҵı�ŷ�Χ�ǣ�" << scoreMin << "<= ƽ���ɼ� <=" << scoreMax << endl;
				cout << "���������ļ�¼��" << endl;
				cout << left << setw(4) << "ѡ�ֱ��" << '\t' << setw(4) << "����" << '\t' << setw(4) << "ƽ���ɼ�"
					<< '\t' << setw(4) << "��߷�" << '\t' << setw(4) << "��ͷ�" << endl;
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
				cout << "����0-2֮��ѡ��" << endl;
			}
			}
			break;
		}
		case 0:
			break;
		default:
		{
			cout << "����0-3��ѡ��" << endl;
		}
		}
	}
	if (flag == 0 && menu != 0)
	{
		cout << "��ѯ��Ϣ��Ч��ϵͳδ��ѯ�ɹ���" << endl;
	}
	return flag;
}

/*ð������*/
void BubbleSort(Singer singers[], int n)
{
	int p = 0;
	int q = 0;
	/*Singer temp1;*/
	/*ð������*///����С����
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

/*ѡ������*/
void SelectSort(Singer singers[], int n)
{
	/*ѡ������*/
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

/*ϣ������*/
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

/*��������*/
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

/*ɾ������*/
void DelInfo(Singer singers[], int* n)
{
	/*loop��key���ڿ��Ʊ����ܵļ������˳�*/
	int key = 1;
loop:
	while (key)
	{
		int i = 0; //�����±꣬ѭ�����Ʊ���
		int num = 0;//�����±꣬ѭ�����Ʊ���
		int location = -1; //��ɾ����λ��
		int NO = 0;			//��Ҫ��ɾ����Ա�ı��
		char isOperate1 = 'N'; //��һ��ѯ���Ƿ����
		char isOperate2 = 'N'; //�ڶ���ѯ���Ƿ����
		cout << "��ӭʹ��ɾ�����ܣ�" << endl;

		/*�Ȳ��ɾ�����Ψһ*/
		cout << "������Ҫɾ����Ա�ı�ţ�";
		cin >> NO;
		for (num = 0; num < *n; num++)
		{
			if (singers[num].Number == NO)
			{
				location = num;//�ɹ���ѯ
				break;
			}
			else
			{
				location = -1;//��ѯʧ��
			}
		}
		/*��ʾ��ɾ����Ա��Ϣ*/
		if (location != -1)
		{
			cout << "��ɾ����ѡ����Ϣ��" << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "ѡ�ֱ�ţ�" << singers[location].Number << endl;
			cout << "ѡ��������" << singers[location].name << endl;
			cout << "ѡ����߷֣�" << singers[location].maxscore << endl;
			cout << "ѡ����ͷ֣�" << singers[location].minscore << endl;
			cout << "ѡ���ܷ֣�" << singers[location].evenscore << endl;
			cout << "ѡ��ƽ���֣�" << singers[location].averagescore << endl;
			cout << "-----------------------------------------------" << endl;
		}
		else
		{
			cout << "û���ҵ���Ա" << NO << ",ɾ��ʧ��" << endl;
			return;//ɾ��ʧ��
		}
		/*ɾ����Ա��Ϣ*/
		cout << "�Ƿ�ɾ����(Y/N)";
		cin >> isOperate1;
		if (isOperate1 == 'Y' || isOperate1 == 'y')
		{
			cout << "�Ƿ񱣴棿(Y/N)";
			cin >> isOperate2;
			if (isOperate2 == 'Y' || isOperate2 == 'y')
			{
				i = location;

				while (i < *n - 1)
				{
					singers[i] = singers[i + 1];//�Ӻ���ǰ�ƶ�
					i++;
				}
				*n = *n - 1;
				/*��ÿ��ѧ����Ϣд���ļ�*/
				SaveInfo(singers, *n);//����ɾ�����������Ϣ
				cout << "ɾ������ѱ���ɹ��ļ���" << endl;
			}
			else/*��ʹ������ҲҪ����ɾ������*/
			{
				i = location;

				while (i < *n - 1)
				{
					singers[i] = singers[i + 1];//�Ӻ���ǰ�ƶ�
					i++;
				}
				*n = *n - 1;
				cout << "��ɾ��������δ���浽�ļ���" << endl;
			}
		}
		else
		{
			cout << "��ȡ��ɾ����" << endl;
			return;
		}
		cout << "\n�Ƿ����ʹ��ɾ�����ܣ�" << endl;
		while (1)
		{
			cout << "�˳���0		������1" << endl;
			cout << "\n���������ѡ��";
			cin >> key;
			switch (key)
			{
			case 1:
				goto loop;
			case 0:
				return;
			default:
				cout << "����0-1֮�����룡\n";
			}
		}

	}



}

/*�޸ĺ���*/
bool ModifyInfo(Singer singers[], int n, int judge_num)
{
	int i = 0;//�����±�
	int s = 0;//�����±�
	int k = 0;//���
	int scoremenu = 0;
	bool flag = 0;//�޸Ľ����1��ʾ�޸ĳɹ���0��ʾ�޸�ʧ��
	char name[20];//����
	int find_rslt = 0;//��ѯ���
	int no = 0;//���
	int key = 1;//ѭ������
	char choice = ' ';
	int jdgno = 0;//����˳��
	int signal = 0; //�����жϴ���Ƿ����� 1���� 0������
	float jdgscore = 0;//��������
	char savechoice = ' ';

	/*�Ȳ��ģ����Ψһ*/
	cout << "\n�����������Ϣ�޸ĵ�ѡ�ֱ�ţ���������";
	cin >> no;
	cout << "Ҫ���ҵ�ѡ�ֱ���ǣ�" << no << endl;
	find_rslt = binaryFindNo(singers, n, no);
	if (find_rslt != -1)
	{
		/*�޸�����չʾ*/
		cout << "���������Ĵ��޸ļ�¼��\n";
		cout << left << setw(4) << "ѡ�ֱ��" << '\t' << setw(4) << "����" << '\t' << setw(4) << "ƽ���ɼ�"
			<< '\t' << setw(4) << "��߷�" << '\t' << setw(4) << "��ͷ�" << endl;
		cout << left << setw(4) << singers[find_rslt].Number << '\t' << '\t' << setw(4) << singers[find_rslt].name << '\t' << setw(4)
			<< singers[find_rslt].averagescore << '\t' << '\t' << singers[find_rslt].maxscore << '\t' << singers[find_rslt].minscore << endl;
		cout << "\n\n�Ѳ��ҵ���ѡ��,��ѡ����Ҫ�޸ĵ���Ϣ��\n\n";
		cout << "  *********************�޸���Ϣ�˵�*********************       \n";
		cout << "     ---------------------------------------------   \n";
		cout << "     *********************************************     \n";
		cout << "     * 1.�޸�ѡ�ֱ��  *      *  2.�޸�ѡ������  *     \n";
		cout << "     *********************************************     \n";
		cout << "     * 3.�޸�ѡ�ֳɼ�  *      *  0.ȡ���޸���Ϣ  *     \n";
		cout << "     *********************************************     \n";
		cout << "     ---------------------------------------------   \n";
		cout << "  ******************************************************\n\n";
		cout << "��������޸�ѡ��0-3����";
		cin >> i;
		switch (i)
		{
		case 1:
			/*�޸�ѡ�ֱ��*/
			cout << "�����µ�ѡ�ֱ�ţ�";
			cin >> no;
			singers[find_rslt].Number = no;
			cout << "�޸ĺ�ļ�¼�ǣ�\n";
			cout << left << setw(4) << "ѡ�ֱ��" << '\t' << setw(4) << "����" << '\t' << setw(4) << "ƽ���ɼ�"
				<< '\t' << setw(4) << "��߷�" << '\t' << setw(4) << "��ͷ�" << endl;
			cout << left << setw(4) << singers[find_rslt].Number << '\t' << '\t' << setw(4) << singers[find_rslt].name << '\t' << setw(4)
				<< singers[find_rslt].averagescore << '\t' << '\t' << singers[find_rslt].maxscore << '\t' << singers[find_rslt].minscore << endl;
			cout << "�Ƿ񱣴��޸Ľ��?(Y or N):";
			cin >> savechoice;
			if (savechoice == 'Y' || savechoice == 'y')
			{
				SaveInfo(singers, n);
			}
			else
			{
				cout << "������޸ģ���δ�������ļ���" << endl;
			}
			break;
		case 2:
			/*�޸�ѡ������*/
			cout << "�����µ�ѡ��������";
			cin >> name;
			singers[i].name = new char(strlen(name) + 1);
			if (singers[i].name != 0)
			{
				strcpy(singers[i].name, name);
			}
			cout << "�޸ĺ�ļ�¼�ǣ�\n";
			cout << left << setw(4) << "ѡ�ֱ��" << '\t' << setw(4) << "����" << '\t' << setw(4) << "ƽ���ɼ�"
				<< '\t' << setw(4) << "��߷�" << '\t' << setw(4) << "��ͷ�" << endl;
			cout << left << setw(4) << singers[find_rslt].Number << '\t' << '\t' << setw(4) << singers[find_rslt].name << '\t' << setw(4)
				<< singers[find_rslt].averagescore << '\t' << '\t' << singers[find_rslt].maxscore << '\t' << singers[find_rslt].minscore << endl;
			cout << "�Ƿ񱣴��޸Ľ��?(Y or N):";
			cin >> savechoice;
			if (savechoice == 'Y' || savechoice == 'y')
			{
				SaveInfo(singers, n);
			}
			else
			{
				cout << "������޸ģ���δ�������ļ���" << endl;;
			}
			break;
		case 3:
			/*�޸ĳɼ�*/
			/*Ҫôָ���޸Ĳ��ֳɼ� Ҫôȫ���������޸�*/
			cout << "  ******************************************************\n\n";
			cout << "  *               �ɼ��޸Ĺ����Ӳ˵�                   *\n \n";
			cout << "  ******************************************************\n\n";
			cout << "     ---------------------------------------------   \n";
			cout << "     *********************************************     \n";
			cout << "     * 1.���������޸�  *       *  2.���������޸�   *     \n";
			cout << "     *********************************************     \n";
			cout << "     * 0.������һ���˵�*     \n";
			cout << "     *********************************************     \n";
			cout << "     ---------------------------------------------   \n";
			cout << "  ******************************************************\n\n";
			cout << "��ѡ���ܣ�";
			cin >> scoremenu;
			switch (scoremenu)
			{
			case 1:
			{
				/*�޸Ĳ��ֳɼ�*/
				while (key)
				{
					cout << "��������Ҫ�޸����з�����λ�ã�1-10����";
					cin >> jdgno;
					/*�ж��Ƿ����λ���Ƿ���[1,judge_num]*/
					for (s = 1; s <= judge_num; s++)
					{
						if (jdgno == s)
						{
							signal = 1;
							break;
						}
					}
					if (signal == 0)//������[0,10]����������
					{
						cout << "λ�ô������������룡" << endl;
						cout << "���������������з�λ�ã�1-10����";
						cin >> jdgno;
					}

					cout << "���������������з֣�0-10����";
					cin >> jdgscore;
					/*�ж��Ƿ�����[0,10]*/
					for (s = 0; s <= 10; s++)
					{
						if ((int)jdgscore == s)
						{
							signal = 1;
							break;
						}
					}
					if (signal == 0)//������[0,10]����������
					{
						cout << "���ִ������������룡" << endl;
						cout << "���������������з֣�0-10����";
						cin >> jdgscore;
					}

					/*ֻ�д�������Ž�����һ������*/
					singers[find_rslt].prescores[jdgno - 1] = jdgscore;
					singers[find_rslt].maxscore = singers[find_rslt].GetMax(singers[find_rslt].prescores, judge_num);
					singers[find_rslt].minscore = singers[find_rslt].GetMin(singers[find_rslt].prescores, judge_num);
					singers[find_rslt].totalscore = singers[find_rslt].sum(singers[find_rslt].prescores, judge_num);
					singers[find_rslt].evenscore = singers[find_rslt].totalscore - singers[find_rslt].maxscore - singers[find_rslt].minscore;
					singers[find_rslt].averagescore = singers[find_rslt].evenscore / (judge_num - 2);
					cout << "�޸ĺ�ļ�¼�ǣ�\n";
					cout << left << setw(4) << "ѡ�ֱ��" << '\t' << setw(4) << "����" << '\t' << setw(4) << "ƽ���ɼ�"
						<< '\t' << setw(4) << "��߷�" << '\t' << setw(4) << "��ͷ�" << endl;
					cout << left << setw(4) << singers[find_rslt].Number << '\t' << '\t' << setw(4) << singers[find_rslt].name << '\t' << setw(4)
						<< singers[find_rslt].averagescore << '\t' << '\t' << singers[find_rslt].maxscore << '\t' << singers[find_rslt].minscore << endl;
					flag = 1;
					cout << "�Ƿ񱣴��޸Ľ��?(Y or N):";
					cin >> savechoice;
					if (savechoice == 'Y' || savechoice == 'y')
					{
						SaveInfo(singers, n);
					}
					else
					{
						cout << "������޸ģ���δ�������ļ���" << endl;
					}
					cout << "\n�����޸�������Y�����������������˳������ܣ�";
					getchar();
					choice = getchar();
					if (choice == 'Y' || choice == 'y')
					{
						cout << "��ӭ����ʹ�ã�" << endl;
					}
					else
					{
						cout << "�����˳����˵�...." << endl;
						return flag;
					}
				}
				break;
			}
			case 2:
			{
				/*ȫ���ɼ����޸�*/
				while (key)
				{
					int q;//ѭ������
					int restart = 0;
				loop:
					for (q = restart; q <= judge_num - 1; q++)//�ڲ�ѭ��Ϊ��ί ��10λ��ί���ζ�ѡ�ִ��
					{
						cout << "�������" << q + 1 << "λ��ί�Ե�" << no << "��ѡ�ֵ�����([0,10]����";
						cin >> singers[find_rslt].prescores[q];
						int s = 0;
						int signal = 0;//�жϱ�־����
						/*�ж��Ƿ�����[0,10]*/
						for (s = 0; s <= 10; s++)
						{
							if ((int)singers[find_rslt].prescores[q] == s)
							{
								signal = 1;
								break;
							}
						}
						if (signal == 0)//������[0,10]����������
						{
							restart = q;
							cout << "���ִ������������룡" << endl;
							goto loop;
						}
					}
					/*����ѡ�ֵ�����������ɣ���ʼ����¼�뵽ѡ�ֵĸ�����Ϣ��*/
					singers[find_rslt].maxscore = singers[find_rslt].GetMax(singers[find_rslt].prescores, judge_num);
					singers[find_rslt].minscore = singers[find_rslt].GetMin(singers[find_rslt].prescores, judge_num);
					singers[find_rslt].totalscore = singers[find_rslt].sum(singers[find_rslt].prescores, judge_num);
					singers[find_rslt].evenscore = singers[find_rslt].totalscore - singers[find_rslt].maxscore - singers[find_rslt].minscore;
					singers[find_rslt].averagescore = singers[find_rslt].evenscore / (judge_num - 2);
					cout << "����ɶԵ�" << find_rslt << "��ѡ�ֵĳɼ���¼��" << endl;
					cout << "�޸ĺ�ļ�¼�ǣ�\n";
					cout << left << setw(4) << "ѡ�ֱ��" << '\t' << setw(4) << "����" << '\t' << setw(4) << "ƽ���ɼ�"
						<< '\t' << setw(4) << "��߷�" << '\t' << setw(4) << "��ͷ�" << endl;
					cout << left << setw(4) << singers[find_rslt].Number << '\t' << '\t' << setw(4) << singers[find_rslt].name << '\t' << setw(4)
						<< singers[find_rslt].averagescore << '\t' << '\t' << singers[find_rslt].maxscore << '\t' << singers[find_rslt].minscore << endl;
					flag = 1;
					cout << "�Ƿ񱣴��޸Ľ��?(Y or N):";
					cin >> savechoice;
					if (savechoice == 'Y' || savechoice == 'y')
					{
						SaveInfo(singers, n);
					}
					else
					{
						cout << "������޸ģ���δ�������ļ���" << endl;
					}
					cout << "\n�����޸�������Y�����������������˳������ܣ�";
					getchar();
					choice = getchar();
					if (choice == 'Y' || choice == 'y')
					{
						cout << "��ӭ����ʹ�ã�" << endl;
					}
					else
					{
						cout << "�����˳����˵�...." << endl;
						return flag;
					}
				}
				break;
			}
			case 0:
				break;
			default:
				cout << "����0-2֮�����룡" << endl;
			}
			break;
		case 0:
			break;
		default:
			cout << "����0-3֮�����룡\n";
		}
	}
	else if (find_rslt == -1)
	{
		cout << "�ñ�Ų����ڣ���˶Ա�ţ�" << endl;
	}
	return flag;
}