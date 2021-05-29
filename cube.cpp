#include <iostream>
#include <fstream>
using namespace std;



class tree_node
{
public:
	int nChild=0;//�ڽļ�
	char name[32];
	tree_node* pParent = NULL;
	tree_node* pChild[100] = { NULL, };
};
class Root
{
	
public:
	tree_node* root;
	tree_node* newnode;
	Root(char name1[])
	{
		root = new tree_node;
		strcpy_s(root->name, name1);
	}
	void readtimetxt()
	{
		int countline = 0;
		ifstream timetxt;//���� ���� ����
		timetxt.open("time.txt");//���� ����
		if (timetxt.is_open())//������ ���
		{
			while (!timetxt.eof())//������ ������ �б�
			{
				char temp[100] = { '\0', };
				char* token;
				timetxt.getline(temp, 100);//���پ� �ޱ�
				if (countline == 0)
				{
					char* ptr = strtok_s(temp, " ", &token);//ù ���� �ڸ��� (time or procduc or location)
					if (ptr == NULL)//�ƹ� ������ �Էµ��� �ʾҴٸ�
					{
						return;
					}
					ptr = strtok_s(NULL, " ", &token);
					while (ptr != NULL)//2���� ����
					{
						root->pChild[root->nChild] = new tree_node;
						strcpy_s(root->pChild[root->nChild]->name, ptr);
						root->nChild++;
						ptr = strtok_s(NULL, " ", &token);
					}
					countline++;
					continue;
				}
				if (countline >= 1)
				{
					char *ptr = strtok_s(temp, " ", &token);//ù ���� �ڸ��� (2����)
					char whatQ[10] = { '\0' };
					strcpy_s(whatQ, ptr);
					int thisQ = 0;
					for (int i = 0; i < root->nChild; i++)
					{
						if (strcmp(root->pChild[i]->name, whatQ) == 0)
						{
							thisQ = i;
							break;
						}
					}
					ptr = strtok_s(NULL, " ", &token);
					while (ptr != NULL)//3���� ����
					{
						root->pChild[thisQ]->pChild[root->pChild[thisQ]->nChild] = new tree_node;
						strcpy_s(root->pChild[thisQ]->pChild[root->pChild[thisQ]->nChild]->name, ptr);
						root->pChild[thisQ]->nChild++;
						ptr = strtok_s(NULL, " ", &token);
					}
				}
				
			}
		}
		timetxt.close();
	}

	void readproducttxt()
	{
		ifstream producttxt;//���� ���� ����
		producttxt.open("product.txt");//���� ����
		int countline = 0;
		if (producttxt.is_open())//������ ���
		{
			while (!producttxt.eof())//������ ������ �б�
			{
				char temp[100] = { '\0', };
				char* token;
				producttxt.getline(temp, 100);//���پ� �ޱ�
				if (countline == 0)
				{
					char* ptr = strtok_s(temp, " ", &token);//ù ���� �ڸ��� (time or procduc or location)
					if (ptr == NULL)//�ƹ� ������ �Էµ��� �ʾҴٸ�
					{
						return;
					}
					ptr = strtok_s(NULL, " ", &token);
					while (ptr != NULL)//2���� ����
					{
						root->pChild[root->nChild] = new tree_node;
						strcpy_s(root->pChild[root->nChild]->name, ptr);
						root->nChild++;
						ptr = strtok_s(NULL, " ", &token);
					}
					countline++;
					continue;
				}
				if (countline >= 1)
				{
					char* ptr = strtok_s(temp, " ", &token);//ù ���� �ڸ��� (2����)
					char whatQ[10] = { '\0' };
					strcpy_s(whatQ, ptr);
					int thisQ = 0;
					for (int i = 0; i < root->nChild; i++)
					{
						if (strcmp(root->pChild[i]->name, whatQ) == 0)
						{
							thisQ = i;
							break;
						}
					}
					ptr = strtok_s(NULL, " ", &token);
					while (ptr != NULL)//3���� ����
					{
						root->pChild[thisQ]->pChild[root->pChild[thisQ]->nChild] = new tree_node;
						strcpy_s(root->pChild[thisQ]->pChild[root->pChild[thisQ]->nChild]->name, ptr);
						root->pChild[thisQ]->nChild++;
						ptr = strtok_s(NULL, " ", &token);
					}
				}

			}
		}
		producttxt.close();
	}
	void readlocationtxt()
	{
		ifstream locationtxt;//���� ���� ����
		locationtxt.open("location.txt");//���� ����
		int countline = 0;
		if (locationtxt.is_open())//������ ���
		{
			while (!locationtxt.eof())//������ ������ �б�
			{
				char temp[100] = { '\0', };
				char* token;
				locationtxt.getline(temp, 100);//���پ� �ޱ�
				if (countline == 0)
				{
					char* ptr = strtok_s(temp, " ", &token);//ù ���� �ڸ��� (time or procduc or location)
					if (ptr == NULL)//�ƹ� ������ �Էµ��� �ʾҴٸ�
					{
						return;
					}
					ptr = strtok_s(NULL, " ", &token);
					while (ptr != NULL)//2���� ����
					{
						root->pChild[root->nChild] = new tree_node;
						strcpy_s(root->pChild[root->nChild]->name, ptr);
						root->nChild++;
						ptr = strtok_s(NULL, " ", &token);
					}
					countline++;
					continue;
				}
				if (countline >= 1)
				{
					char* ptr = strtok_s(temp, " ", &token);//ù ���� �ڸ��� (2����)
					char whatQ[10] = { '\0' };
					strcpy_s(whatQ, ptr);
					int thisQ = 0;
					for (int i = 0; i < root->nChild; i++)
					{
						if (strcmp(root->pChild[i]->name, whatQ) == 0)
						{
							thisQ = i;
							break;
						}
					}
					ptr = strtok_s(NULL, " ", &token);
					while (ptr != NULL)//3���� ����
					{
						root->pChild[thisQ]->pChild[root->pChild[thisQ]->nChild] = new tree_node;
						strcpy_s(root->pChild[thisQ]->pChild[root->pChild[thisQ]->nChild]->name, ptr);
						root->pChild[thisQ]->nChild++;
						ptr = strtok_s(NULL, " ", &token);
					}
				}

			}
		}
		locationtxt.close();
	}
};
class Data
{
public:
	char product[100];
	char location[100];
	char time[100];
	int value;

	Data* nextproduct = NULL;
	Data* prevproduct = NULL;
	Data* nextlocation = NULL;
	Data* prevlocation = NULL;
	Data* nexttime = NULL;
	Data* prevtime = NULL;
};
class Cube
{
public:
	Data* headproduct = NULL;
	Data* tailproduct = NULL;
	Data* headlocation = NULL;
	Data* taillocation = NULL;
	Data* headtime = NULL;
	Data* tailtime = NULL;
	Data* newdata = NULL;
	void newcube(Root time,Root location, Root product)
	{
		//�� ť�� �����(0���� �ʱ�ȭ)
		




		//sales���� ä���
		ifstream salestxt;//���� ���� ����
		salestxt.open("sales.txt");//���� ����
		if (salestxt.is_open())//������ ���
		{
			while (!salestxt.eof())//������ ������ �б�
			{
				


			}
		}
		salestxt.close();
	}
};
int main()
{
	//LOAD
	char temp1[100] = "location";
	Root location(temp1);
	char temp2[100] = "time";
	Root time(temp2);
	char temp3[100] = "prodcut";
	Root product(temp3);
	time.readtimetxt();//tree ����
	location.readlocationtxt();//tree ����
	product.readproducttxt();//tree ����
	cout << time.root->pChild[0]->name;
	Cube rawcube;
	rawcube.newcube(time, location, product);
	
	

}