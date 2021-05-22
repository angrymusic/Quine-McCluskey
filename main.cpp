#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Tminterm
{
public:
	char tvalue[100];
	Tminterm* next;
	int coverd = 0;
	int check = 0;
};
class Tlist
{
public:
	Tminterm* tlisthead = NULL;
	Tminterm* tlisttail = NULL;
	Tminterm* tlistcur = NULL;
	Tminterm* tlistnewtmin = NULL;
	void addtlist(char arr[])
	{
		tlistnewtmin = new Tminterm;
		strcpy_s(tlistnewtmin->tvalue, arr);
		if (tlisthead == NULL)
		{
			tlisthead = tlistnewtmin;
			tlisttail = tlistnewtmin;
		}
		else
		{
			tlisttail->next = tlistnewtmin;
			tlisttail = tlistnewtmin;
		}
	}
	bool countchecked()
	{
		tlistcur = tlisthead;
		while (tlistcur != NULL)
		{
			if (tlistcur->check == 0)
			{
				return true;
			}
				
			tlistcur = tlistcur->next;
		}
		return false;
	}
};
class Minterm
{
public:
	int dorm = -1;//dontcare 0 minterm 1
	int check = 0;//���É������ �ƴ���
	int numofone = 0;//1�� ����
	char value[100] = "";//��
	int countcover = 0;
	Tminterm* head = NULL;
	Tminterm* tail = NULL;
	Tminterm* cur = NULL;
	Tminterm* newtmin = NULL;
	Minterm* next = NULL;
	void addtmin(char arr[])
	{
		newtmin = new Tminterm;
		strcpy_s(newtmin->tvalue, arr);
		if (head == NULL)
		{
			head = newtmin;
			tail = newtmin;
		}
		else
		{
			tail->next = newtmin;
			tail = newtmin;
		}
	}
	int isthere(char arr[100])
	{
		cur = head;
		while (cur != NULL)
		{
			if (strcmp(cur->tvalue, arr) == 0)
			{
				return 0;
			}
			cur = cur->next;
		}
		return 1;
	}
	void checker(char arr[100])
	{
		Tminterm* cur1;
		cur1 = head;
		while (cur1 != NULL)
		{
			if (strcmp(cur1->tvalue, arr) == 0)
			{
				cur1->check = 1;
			}
			
			cur1 = cur1->next;
		}
	}
	int covercounter()
	{
		int covercount = 0;
		cur = head;
		while (cur != NULL)
		{
			if (cur->check == 0)
			{
				covercount++;
			}
			cur = cur->next;
		}
		return covercount;
	}
};

int countone(char arr[]);

int main()
{
	Minterm* head = NULL;
	Minterm* tail = NULL;
	Minterm* cur = NULL;
	Minterm* newminterm = NULL;
	Minterm* cutline = NULL;
	Minterm* column1line = NULL;
	Minterm* plshead = NULL;
	Minterm* plscur = NULL;
	Minterm* plstail = NULL;
	Minterm* plsprecur = NULL;
	Minterm* essentialhead = NULL;
	Minterm* essentialcur = NULL;
	Minterm* essentialtail = NULL;

	int bitnum;
	ifstream input;//���� ���� ����
	int i = 0;
	input.open("input_minterm.txt");//���� ����
	if (input.is_open())//������ ���
	{
		newminterm = new Minterm;
		head = newminterm;
		tail = newminterm;
		newminterm->next = NULL;
		input.getline(newminterm->value, 100);//���پ� �ޱ�

		while (!input.eof())//������ ������ �б�
		{
			newminterm = new Minterm;
			input.getline(newminterm->value, 100);//���پ� �ޱ�
			newminterm->numofone = countone(newminterm->value);//1�����ޱ�
			tail->next = newminterm;
			tail = newminterm;
			cutline = tail;
			column1line = tail;
		}
	}

	else//�ȿ����� ���
	{
		cout << "file is not open";
	}
	bitnum = atoi(head->value);

	cur = head;
	while (cur != NULL)//�ӽ� ����� ���
	{
		cout << cur->value << endl;
		cur = cur->next;
	}
	cur = head;
	while (cur != NULL)// d �� m �����ؼ� dorm�� ���� ���ֱ�
	{
		if (cur->value[0] == 'd')
		{
			cur->dorm = 0;
		}
		else if (cur->value[0] == 'm')
		{
			cur->dorm = 1;
		}
		cur = cur->next;
	}

	cur = head->next;

	while (cur != NULL)// d �� m�� �A ���� value������ ���� ���ֱ�
	{
		char temp[100];
		int t = 0;
		for (int i = 2; i < bitnum + 2; i++)
		{
			temp[t] = cur->value[i];
			cur->value[t] = temp[t];
			t++;
		}
		cur->value[bitnum] = '\0';
		cur = cur->next;
	}
	cur = head;
	while (cur != NULL)//�ӽ� ����� ���
	{
		cout << cur->value << endl;
		cur = cur->next;
	}
	cout << "------------------------------------" << endl;

	Minterm* standard = head->next;
	while (standard != NULL)
	{
		cur = standard->next;
		while (cur != cutline->next)//standard�� ���ϱ�
		{
			int countcheck = 0;
			int differentpoint = 0;

			for (int i = 0; i < bitnum; i++)
			{
				if (cur->value[i] == standard->value[i])
				{
					countcheck++;
				}
				else
				{
					differentpoint = i;
				}
			}
			if (countcheck == bitnum - 1)//�� bit�� �ٸ� ���
			{
				standard->check = 1;
				cur->check = 1;
				newminterm = new Minterm;
				strcpy_s(newminterm->value, standard->value);
				newminterm->value[differentpoint] = '_';
				tail->next = newminterm;//cutline�� next���Ͱ� ��������� ���ҵ��ΰ���.
				tail = newminterm;
			}
			cur = cur->next;
		}
		standard = standard->next;
		if (standard == cutline)
		{
			standard = standard->next;
			//check �ȵȰ� pls�� �ֱ�

			cutline = tail;
		}
	}
	Minterm* pcur = head->next;
	while (pcur != cutline->next)
	{
		if (pcur->check == 0)
		{
			newminterm = new Minterm;
			strcpy_s(newminterm->value, pcur->value);
			if (plshead == NULL)
			{
				plshead = newminterm;
				plstail = newminterm;
			}
			else
			{
				plstail->next = newminterm;
				plstail = newminterm;
			}
		}
		pcur = pcur->next;
	}

	standard = plshead;//�ߺ� pls����
	Minterm* mintermkiller;
	while (standard != NULL)
	{
		plscur = standard->next;
		plsprecur = standard;
		while (plscur != NULL)
		{
			if (strcmp(standard->value, plscur->value) == 0)
			{
				if (plscur == standard->next)
				{
					mintermkiller = plscur;
					standard->next = plscur->next;
					delete(mintermkiller);
					plscur = standard->next;
				}
				else if (plscur == plstail)
				{
					plsprecur->next = NULL;
					mintermkiller = plscur;
					delete(mintermkiller);
					plstail = plsprecur;
					break;
				}
				else
				{
					plsprecur->next = plscur->next;
					mintermkiller = plscur;
					plscur = plscur->next;
					delete(mintermkiller);

				}
			}
			else
			{
				plsprecur = plscur;
				plscur = plscur->next;
			}

		}
		standard = standard->next;
	}

	plscur = plshead;//pls�ӽ����
	while (plscur != NULL)
	{
		cout << plscur->value << endl;
		plscur = plscur->next;
	}
	cout << "-----------------------" << endl;
	Tlist tlist;
	cur = head;//tlist�� true���ҵ� �ֱ�
	while (1)
	{
		if (cur->dorm == 1)
		{
			tlist.addtlist(cur->value);
		}
		if (cur == column1line)
		{
			break;
		}
		cur = cur->next;
	}

	tlist.tlistcur = tlist.tlisthead;
	while (tlist.tlistcur != NULL)//pls�� Ŀ���ϴ� �� üũ
	{
		plscur = plshead;
		while (plscur != NULL)
		{
			for (int i = 0; i < bitnum; i++)
			{
				if ((plscur->value[i] == '_') || (plscur->value[i] == tlist.tlistcur->tvalue[i]))
				{
					if (i == bitnum - 1)
					{
						tlist.tlistcur->coverd++;
						plscur->addtmin(tlist.tlistcur->tvalue);
						plscur->countcover++;
					}
				}
				else
				{
					break;
				}
			}

			plscur = plscur->next;
		}
		tlist.tlistcur = tlist.tlistcur->next;
	}
	char deletemin[100];
	Tminterm* listcur2;
	Tminterm* prevlistcur2;
	Tminterm* plscur2;
	Tminterm* prevplscur2;
	Minterm* plscur3;
	tlist.tlistcur = tlist.tlisthead;
	while (tlist.tlistcur != NULL)//�ϳ��� Ŀ���Ǵ� ��찡 �ִٸ� �� pls essentialpls
	{
		if (tlist.tlistcur->coverd == 1)//�ϳ��� Ŀ���Ǵ� �� ã��
		{
			plscur = plshead;
			while (plscur != NULL)
			{
				if (tlist.tlisthead == NULL)
				{
					goto finish;
				}
				int find=plscur->isthere(tlist.tlistcur->tvalue);
				if (find == 0)
				{
					newminterm = new Minterm;
					strcpy_s(newminterm->value,plscur->value);
					if (essentialhead == NULL)
					{
						essentialhead = newminterm;
						essentialtail = newminterm;
					}
					else
					{
						essentialtail->next = newminterm;
						essentialtail = newminterm;
					}
					plscur->cur = plscur->head;
					while (plscur->cur != NULL)//essential pls�� cover�ϴ� minterm�� üũ
					{
						listcur2 = tlist.tlisthead;
						while (listcur2 != NULL)
						{
							if (strcmp(listcur2->tvalue, plscur->cur->tvalue) == 0)
							{
								listcur2->check = 1;
							}
							listcur2 = listcur2->next;
						}
						

						//pls���� coveredminterm countcover���ֱ�
						strcpy_s(deletemin, plscur->cur->tvalue);
						plscur3=plshead;
						while (plscur3 != NULL)
						{
							plscur3->checker(deletemin);
							plscur3 = plscur3->next;
						}
						plscur->cur = plscur->cur->next;
					}
				}
				plscur = plscur->next;
			}
		}

		tlist.tlistcur = tlist.tlistcur->next;
	}

	Minterm* bigpls;
	while (tlist.countchecked())//minterm ���� ���� üũ�� ������
	{
		bigpls = plshead;
		plscur = plshead;
		while (plscur != NULL)
		{
			if (plscur->covercounter() > bigpls->covercounter())
			{
				bigpls = plscur;
			}
			plscur = plscur->next;
		}
		newminterm = new Minterm;//���� Ŀ�� ���� �ϴ� pls �����ȷ� ������
		strcpy_s(newminterm->value, bigpls->value);
		if (essentialhead == NULL)
		{
			essentialhead = newminterm;
			essentialtail = newminterm;
		}
		else
		{
			essentialtail->next = newminterm;
			essentialtail = newminterm;
		}
		bigpls->cur = bigpls->head;
		while (bigpls->cur != NULL)
		{
			tlist.tlistcur = tlist.tlisthead;
			while (tlist.tlistcur != NULL)
			{
				if (strcmp(bigpls->cur->tvalue, tlist.tlistcur->tvalue)==0)
				{
					tlist.tlistcur->check = 1;
					bigpls->countcover--;
				}
				tlist.tlistcur = tlist.tlistcur->next;
			}
			//pls���� coveredminterm countcover���ֱ�
			strcpy_s(deletemin, bigpls->cur->tvalue);
			plscur3 = plshead;
			while (plscur3 != NULL)
			{
				plscur3->checker(deletemin);
				plscur3 = plscur3->next;
			}
			bigpls->cur = bigpls->cur->next;
		}
	}
	

finish:


	Minterm* essentialprecur;
	//essential �ߺ� ����
	standard = essentialhead;//�ߺ� pls����
	Minterm* essentialmintermkiller;
	while (standard != NULL)
	{
		essentialcur = standard->next;
		essentialprecur = standard;
		while (essentialcur != NULL)
		{
			if (strcmp(standard->value, essentialcur->value) == 0)
			{
				if (essentialcur == standard->next)
				{
					essentialmintermkiller = essentialcur;
					standard->next = essentialcur->next;
					delete(essentialmintermkiller);
					essentialcur = standard->next;
				}
				else if (essentialcur == essentialtail)
				{
					essentialprecur->next = NULL;
					essentialmintermkiller = essentialcur;
					delete(essentialmintermkiller);
					essentialtail = essentialprecur;
					break;
				}
				else
				{
					essentialprecur->next = essentialcur->next;
					essentialmintermkiller = essentialcur;
					essentialcur = essentialcur->next;
					delete(essentialmintermkiller);

				}
			}
			else
			{
				essentialprecur = essentialcur;
				essentialcur = essentialcur->next;
			}

		}
		standard = standard->next;
	}


	essentialcur = essentialhead;//essentialpls�ӽ����
	while (essentialcur != NULL)
	{
		cout << essentialcur->value << endl;
		essentialcur = essentialcur->next;
	}

	
	int countor = 0;//count plus gate
	int countand = 0;//count and gate
	int countandinput = 0;
	int countnot = 0;//count not gate
	int checknot[100] = { 0, };
	int cost = 0;
	essentialcur = essentialhead;
	while (essentialcur != NULL)
	{
		countandinput = 0;
		for (int i = 0; i < bitnum; i++)
		{
			if (essentialcur->value[i] == '0')
			{
				checknot[i] = 1;
			}
			if ((essentialcur->value[i] == '0') || (essentialcur->value[i] == '1'))
			{
				countandinput++;
			}
		}
		countand += countandinput * 2 + 2;

		countor++;
		essentialcur = essentialcur->next;
	}
	countor = countor * 2 + 2;
	int j = 0;

	for (int i = 0; i < bitnum; i++)
	{
		if (checknot[i] == 1)
		{
			countnot++;
		}
	}
	countnot = 2 * countnot;
	cost = countnot + countand + countor;
	cout << "Cost (# of transistors): " << cost << endl;
	//result.txt �����ϱ�
	ofstream fout("result.txt");
	essentialcur = essentialhead;//essentialpls�ӽ����
	while (essentialcur != NULL)
	{
		fout << essentialcur->value << endl;
		essentialcur = essentialcur->next;
	}
	fout << endl;
	fout << "Cost (# of transistors): " << cost << endl;



	/* ������ �ؾ� �� ��

	* minterm ���̶� �����ؼ� essential minterm  ã��
	* ���� ����� Ʈ�������� ���� ����
	* result.txt�� ����� �Է��ϱ�
	*/

}
int countone(char arr[])
{
	int count = 0;
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == '1')
		{
			count++;
		}
	}
	return count;
}