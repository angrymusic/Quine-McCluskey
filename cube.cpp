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
	int value = 0;
	Data* xtail = this;
	Data* ytail = this;
	Data* ztail = this;

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
	Data* standard = NULL;
	Data* curx = NULL;
	Data* cury = NULL;
	Data* curz = NULL;
	Data* curyz = NULL;
	Data* curxy = NULL;
	Data* curxz = NULL;
	void newcube(Root time, Root location, Root product)
	{
		//�� ť�� �����(0���� �ʱ�ȭ)
		for (int i = 0; i < product.root->nChild; i++)//x�� �����
		{
			for (int j = 0; j < product.root->pChild[i]->nChild; j++)
			{
				if (standard == NULL)
				{
					newdata = new Data;
					strcpy_s(newdata->product, product.root->pChild[0]->pChild[0]->name);
					strcpy_s(newdata->location, location.root->pChild[0]->pChild[0]->name);
					strcpy_s(newdata->time, time.root->pChild[0]->pChild[0]->name);
					standard = newdata;
					taillocation = standard;
					tailproduct = standard;
					tailtime = standard;
				}
				else
				{
					newdata = new Data;
					strcpy_s(newdata->product, product.root->pChild[i]->pChild[j]->name);
					strcpy_s(newdata->location, location.root->pChild[0]->pChild[0]->name);
					strcpy_s(newdata->time, time.root->pChild[0]->pChild[0]->name);
					tailproduct->nextproduct = newdata;
					newdata->prevproduct = tailproduct;
					tailproduct = newdata;
				}
				
			}
		}
		for (int k = 0; k < location.root->nChild; k++)//y�� �����
		{
			for (int l = 0; l < location.root->pChild[k]->nChild; l++)
			{
				if (k == 0 && l == 0)
				{
					strcpy_s(standard->location, location.root->pChild[k]->pChild[l]->name);
					continue;
				}
				newdata = new Data;
				strcpy_s(newdata->location, location.root->pChild[k]->pChild[l]->name);
				strcpy_s(newdata->product, product.root->pChild[0]->pChild[0]->name);
				strcpy_s(newdata->time, time.root->pChild[0]->pChild[0]->name);
				taillocation->nextlocation = newdata;
				newdata->prevlocation = taillocation;
				taillocation = newdata;
			}
		}
		//xy�� �����
		
		cury = standard->nextlocation;
		while (cury != NULL)
		{
			curx = standard->nextproduct;
			while (curx != NULL)
			{
				newdata = new Data;
				strcpy_s(newdata->location, cury->location);
				strcpy_s(newdata->product, curx->product);
				strcpy_s(newdata->time, time.root->pChild[0]->pChild[0]->name);
				curx->ytail->nextlocation = newdata;
				newdata->prevlocation = curx->ytail;
				curx->ytail = newdata;
				cury->xtail->nextproduct = newdata;
				newdata->prevproduct = cury->xtail;
				cury->xtail = newdata;

				curx = curx->nextproduct;
			}
			cury = cury->nextlocation;
		}
		for (int k = 0; k < time.root->nChild; k++)//z�� �����
		{
			for (int l = 0; l < time.root->pChild[k]->nChild; l++)
			{
				if (k == 0 && l == 0)
				{
					continue;
				}
				newdata = new Data;
				strcpy_s(newdata->time, time.root->pChild[k]->pChild[l]->name);
				strcpy_s(newdata->location, location.root->pChild[0]->pChild[0]->name);
				strcpy_s(newdata->product, product.root->pChild[0]->pChild[0]->name);
				tailtime->nexttime = newdata;
				newdata->prevtime = tailtime;
				tailtime = newdata;
			}
		}
		//xz��� �����
		curx = standard->nextproduct;
		while (curx != NULL)
		{
			curz = standard->nexttime;
			while (curz != NULL)
			{
				newdata = new Data;
				strcpy_s(newdata->location, location.root->pChild[0]->pChild[0]->name);
				strcpy_s(newdata->product, curx->product);
				strcpy_s(newdata->time, curz->time);
				curx->ztail->nexttime = newdata;
				newdata->prevtime = curx->ztail;
				curx->ztail = newdata;
				curz->xtail->nextproduct = newdata;
				newdata->prevproduct = curz->xtail;
				curz->xtail = newdata;

				curz = curz->nexttime;
			}
			curx = curx->nextproduct;
		}
		//yz��� �����
		cury = standard->nextlocation;
		while (cury != NULL)
		{
			curz = standard->nexttime;
			while (curz != NULL)
			{
				newdata = new Data;
				strcpy_s(newdata->location, cury->location);
				strcpy_s(newdata->product, product.root->pChild[0]->pChild[0]->name);
				strcpy_s(newdata->time, curz->time);
				curz->ytail->nextlocation = newdata;
				newdata->prevlocation = curz->ytail;
				curz->ytail = newdata;
				cury->ztail->nexttime = newdata;
				newdata->prevtime = cury->ztail;
				cury->ztail = newdata;

				curz = curz->nexttime;
			}
			cury = cury->nextlocation;
		}
		//cube ����
		curx = standard->nextproduct;
		while (curx != NULL)
		{
			cury = standard->nextlocation;
			curxy = curx->nextlocation;
			while (cury != NULL)
			{
				curz = standard->nexttime;
				curyz = cury->nexttime;
				curxz = curx->nexttime;
				while (curz != NULL)
				{
					newdata = new Data;
					strcpy_s(newdata->location, cury->location);
					strcpy_s(newdata->product, curx->product);
					strcpy_s(newdata->time, curz->time);
					//taily ����
					curxz->ytail->nextlocation = newdata;
					newdata->prevlocation = curxz->ytail;
					curxz->ytail = newdata;
					//tailx ����
					curyz->xtail->nextproduct = newdata;
					newdata->prevproduct = curyz->xtail;
					curyz->xtail = newdata;
					//tailz ����
					curxy->ztail->nexttime = newdata;
					newdata->prevtime = curxy->ztail;
					curxy->ztail = newdata;
					////////////////
					curxz = curxz->nexttime;
					curyz = curyz->nexttime;
					curz = curz->nexttime;
				}

				curxy = curxy->nextlocation;
				cury = cury->nextlocation;
			}
			curx = curx->nextproduct;
		}

		Data* finder = NULL;
		//sales���� ä���
		ifstream salestxt;//���� ���� ����
		salestxt.open("sales.txt");//���� ����
		if (salestxt.is_open())//������ ���
		{
			while (!salestxt.eof())//������ ������ �б�
			{
				char temp[100] = { '\0', };
				char whatP[100] = { '\0', };
				char whenT[100] = { '\0', };
				char whereL[100] = { '\0', };
				char howM[100] = { '\0', };
				char* token;
				salestxt.getline(temp, 100);//���پ� �ޱ�
				char* ptr = strtok_s(temp, " ", &token);//ù ���� �ڸ��� (time or procduc or location)
				strcpy_s(whatP, ptr);
				ptr = strtok_s(NULL, " ", &token);
				strcpy_s(whenT, ptr);
				ptr = strtok_s(NULL, " ", &token);
				strcpy_s(whereL, ptr);
				ptr = strtok_s(NULL, " ", &token);
				strcpy_s(howM, ptr);
				
				finder = standard;
				while (finder != NULL)
				{
					if (strcmp(whatP, finder->product) == 0)
					{
						while (finder != NULL)
						{
							if (strcmp(whereL, finder->location) == 0)
							{
								while (finder != NULL)
								{
									if (strcmp(whenT, finder->time) == 0)
									{
										finder->value = atoi(howM);
										break;
									}
									finder = finder->nexttime;
								}
								break;
							}
							finder = finder->nextlocation;
						}
						break;
					}
					finder = finder->nextproduct;
				}
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