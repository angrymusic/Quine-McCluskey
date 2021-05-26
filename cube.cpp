#include <iostream>
#include <fstream>
using namespace std;


class Data
{
	char product[100];
	char location[100];
	char time[100];

	Data* nextproduct = NULL;
	Data* prevproduct = NULL;
	Data* nextlocation = NULL;
	Data* prevlocation = NULL;
	Data* nexttime = NULL;
	Data* prevtime = NULL;
};
class tree_node
{
public:
	int nChild=0;//자식수
	char name[32];
	tree_node* pParent = NULL;
	tree_node* pChild[100] = { NULL, };
};
class Root
{
	tree_node* root;
	tree_node* newnode;
public:
	Root(char name1[])
	{
		root = new tree_node;
		strcpy_s(root->name, name1);
	}
	void readtimetxt()
	{
		ifstream timetxt;//읽을 파일 선언
		timetxt.open("time.txt");//파일 열기
		if (timetxt.is_open())//열였을 경우
		{
			char temp[100] = { '\0', };
			timetxt.getline(temp, 100);//한줄씩 받기
			char* ptr = strtok(temp, " ");//첫 간격 자르기 (time or procduc or location)
			if (ptr == NULL)//아무 정보도 입력되지 않았다면
			{
				return ;
			}
			char* ptr = strtok(temp, " ");
			while (ptr != NULL)//2계층 형성
			{
				root->pChild[root->nChild] = new tree_node;
				strcpy_s(root->pChild[root->nChild]->name, ptr);
				root->nChild++;
				ptr = strtok(NULL, " ");
			}
			while (!timetxt.eof())//파일을 끝까지 읽기
			{
				char temp[100] = { '\0', };
				timetxt.getline(temp, 100);//한줄씩 받기
				char* ptr = strtok(temp, " ");//첫 간격 자르기 (time or procduc or location)
				char whatQ[10] = { '\0' };
				strcpy_s(whatQ , ptr);
				int thisQ = 0;
				for (int i = 0; i < root->nChild; i++)
				{
					if (strcmp(root->pChild[i]->name, whatQ) == 0)
					{
						thisQ = i;
						break;
					}
				}
				char* ptr = strtok(temp, " ");
				while (ptr != NULL)//2계층 형성
				{
					root->pChild[thisQ]->pChild[root->nChild] = new tree_node;
					strcpy_s(root->pChild[thisQ]->pChild[root->nChild]->name, ptr);
					root->pChild[thisQ]->nChild++;
					ptr = strtok(NULL, " ");
				}
			}
		}
	}
};
int main()
{
	
}