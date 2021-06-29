/*
	项目名称：图书管理系统
	开发语言: C语言
	开发工具：Visual Studio 2019
	开发时间：2020.03
	开发者：211806229 林婧虹
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bookInfo //定义图书信息结构体变量
{
	char name[20];      //书名
	char author[20];    //作者名
	char publisher[20]; //出版社
	char date[20];      //出版日期
	char price[20];	    //价格
}Information;

typedef struct PNode	//创建链表节点
{
	Information info;   //图书信息
	struct PNode* next; //下一个节点
	
}Node;

Node* head = NULL;		//定义头指针

void Menu();                   //菜单
void InputBookInfo();		   //添加图书信息
void PrintBookInfo();		   //打印图书信息
void SaveBookInfo();		   //保存图书信息
void Locate_BookInfo_name();   //按书名查找
void Locate_BookInfo_author(); //按作者查找
int CountBookInfo();		   //统计图书信息
void ChangeBookInfo();		   //修改图书信息
void DeletBookInfo();		   //删除图书信息
void ReadBookInfo();		   //显示所有图书信息
void ExitBookInfo();		   //退出图书信息系统
void RecommendBook(int count); 
int main()
{
	while (1)
	{
		Menu();					  	 //菜单
		char ch = getchar();
		int count = CountBookInfo();
		switch (ch)
		{
		case'1':
			InputBookInfo();		 //添加图书信息
			break;
		case'2':
			PrintBookInfo();		 //打印图书信息
			break;
		case'3':
			SaveBookInfo();			 //保存图书信息
			break;
		case'4':
			Locate_BookInfo_name();  //按书名查找
			break;
		case'5':
			Locate_BookInfo_author();//按作者查找
			break;
		case'6':
			RecommendBook(count);	 //推荐图书信息
			break;
		case'7':
			ChangeBookInfo();		 //修改图书信息
			break;
		case'8':
			DeletBookInfo();		 //删除图书信息
			break;
		case'9':
			ReadBookInfo();
			break;
		case'0':
			ExitBookInfo();          //退出图书信息系统
			break;
		default:
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
void Menu()
{
	printf("\t*************************************************\n");
	printf("\t\t    欢迎使用图书管理系统V1.0\n");
	printf("\t\t\t    请选择功能\n");
	printf("\t*************************************************\n");
	printf("\t\t\t  1.添加图书信息\n");
	printf("\t\t\t  2.打印图书信息\n");
	printf("\t\t\t  3.保存图书信息\n");
	printf("\t\t\t  4.按书名查找  \n");
	printf("\t\t\t  5.按作者查找  \n");
	printf("\t\t\t  6.推荐图书信息\n");
	printf("\t\t\t  7.修改图书信息\n");
	printf("\t\t\t  8.删除图书信息\n");
	printf("\t\t\t  9.显示所有图书信息\n");
	printf("\t\t\t  0.退出图书信息系统\n");
	printf("\t*************************************************\n");
}
void InputBookInfo()     //添加图书信息
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->next = NULL;
	Node* p = head;
	while (head != NULL && p->next != NULL)
		p = p->next;
	if (head == NULL)
		head = pNewNode;
	else
		p->next = pNewNode;
	printf("请输入书名：");
	scanf("%s", pNewNode->info.name);
	printf("请输入作者名：");
	scanf("%s", pNewNode->info.author);
	printf("请输入出版社：");
	scanf("%s", pNewNode->info.publisher);
	printf("请输入出版日期：");
	scanf("%s", pNewNode->info.date);
	printf("请输入价格：");
	scanf("%s", pNewNode->info.price);
	char c;
	int num = 0;
	do 
	{
		printf("录入成功！");
		printf("是否继续录入（Y/N）？：");
		getchar();
		scanf("%c", &c);
		if (c == 'y' || c == 'Y')
			InputBookInfo();
		else
		{
			if (c == 'n' || c == 'N')
			{
				system("cls");
				return;
			}
			else
				printf("输入错误，请重新输入");
		}
	} while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
	system("pause");
	system("cls");
}
void PrintBookInfo() //打印图书信息
{
	Node* p = head;
	int count = 1;
	if (p == NULL)
		printf("系统中暂无图书信息，请确认名称是否正确");
	else
	{
		while (p != NULL)
		{
			printf("************第%d本图书************",count);
			printf("\n");
			printf("\t书名：    %-20s\n",p->info.name);
			printf("\t作者名：  %-20s\n", p->info.author);
			printf("\t出版社：  %-20s\n", p->info.publisher);
			printf("\t出版日期：%-20s\n", p->info.date);
			printf("\t价格：    %-20s\n", p->info.price);
			p = p->next;
			count++;
		}
		printf("输入任意键返回菜单\n");
		getchar();
	}
	system("pause");
	system("cls");
}
void RecommendBook(int count) //推荐图书信息
{
	int a = rand() % 10;
	Node* p = head;
	bool flag = false;
	int i = 1;
	if (p == NULL)
		printf("系统中暂无图书信息，请确认名称是否正确");
	else
	{
		while (p != NULL)
		{
			if (a == i) {
				flag = true;
				printf("************第%d本图书************", i);
				printf("\n");
				printf("\t书名：    %-20s\n", p->info.name);
				printf("\t作者名：  %-20s\n", p->info.author);
				printf("\t出版社：  %-20s\n", p->info.publisher);
				printf("\t出版日期：%-20s\n", p->info.date);
				printf("\t价格：    %-20s\n", p->info.price);
				p = p->next;
				i++;
			}
			else
			{
				p = p->next;
				i++;
			}
		}
		if (!false) {
			printf("暂无推荐图书！");
		}
		printf("输入任意键返回菜单\n");
		getchar();
	}
	system("pause");
	system("cls");
}
void SaveBookInfo() //保存图书信息
{
	FILE* pFile;
	pFile = fopen("bookInfomation.txt", "w");
	if (pFile == NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	Node* p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	p = head;
	while (p != NULL )
	{
		fprintf(pFile, "%s\n", p->info.name);
		fprintf(pFile, "%s\n", p->info.author);
		fprintf(pFile, "%s\n", p->info.publisher);
		fprintf(pFile, "%s\n", p->info.date);
		fprintf(pFile, "%s\n", p->info.price);
		p = p->next;
	}
	fclose(pFile);
	printf("保存成功\n");
	system("pause");
	system("cls");
}
void Locate_BookInfo_name() //按书名查找
{
	int flag = 0;
	char name[20];
	Node* p = head;
	printf("请输入您需要查询的书名：");
	scanf("%s", name);
	printf("\n");
	printf("输入成功！\n");
	printf("以下是您查找的信息：\n");
	while (p != NULL)
	{
		if (strcmp(p->info.name, name) == 0)
		{
			printf("书名:    %-20s\n", p->info.name);
			printf("作者名:  %-20s\n", p->info.author);
			printf("出版社:  %-20s\n", p->info.publisher);
			printf("出版日期:%-20s\n", p->info.date);
			printf("价格:    %-20s\n", p->info.price);
			printf("\n");
			flag = 1;
			p = p->next;
		}
		else
		{
			p = p->next;
		}
	}
	if (flag == 0)
	{
		printf("没有该书名的信息\n");
		printf("输入任意键返回菜单\n");
		getchar();
	}
	system("pause");
	system("cls");
}
void Locate_BookInfo_author() //按作者查找
{
	int flag = 0;
	char author[20];
	Node* p = head;
	printf("请输入您需要查询的作者名：");
	scanf("%s", author);
	printf("\n");
	printf("输入成功！\n");
	printf("以下是您查找的信息：\n");
	printf("\n");
	while (p != NULL)
	{
		if (strcmp(p->info.author, author) == 0)
		{
			printf("书名:    %-20s\n", p->info.name);
			printf("作者名:  %-20s\n", p->info.author);
			printf("出版社:  %-20s\n", p->info.publisher);
			printf("出版日期:%-20s\n", p->info.date);
			printf("价格:    %-20s\n", p->info.price);
			printf("\n");
			flag = 1;
			p = p->next;
		}
		else
		{
			p = p->next;
		}
	}
	if (flag == 0)
	{
		printf("没有该作者的信息\n");
		printf("\n");
		printf("输入任意键返回菜单\n");
		getchar();
	}
	system("pause");
	system("cls");
}
int CountBookInfo() //统计图书信息
{
	int count = 0;
	Node* p = head;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
	//printf("系统中共有%d本图书信息\n", count);
	//system("pause");
	//system("cls");
}
void ChangeBookInfo() //修改图书信息
{
	char name[20];
	printf("请输入需要修改的图书名：\n");
	scanf("%s", name);
	Node* p = head;
	int flag = 0;
	while (p != NULL)
	{
		if (strcmp(p->info.name, name) == 0)
		{
			printf("书名:    %-20s\n", p->info.name);
			printf("作者名:  %-20s\n", p->info.author);
			printf("出版社:  %-20s\n", p->info.publisher);
			printf("出版日期:%-20s\n", p->info.date);
			printf("价格:    %-20s\n", p->info.price);
			printf("\n");
			flag = 1;
			printf("请输入书名：");
			scanf("%s", p->info.name);
			printf("请输入作者名：");
			scanf("%s", p->info.author);
			printf("请输入出版社：");
			scanf("%s", p->info.publisher);
			printf("请输入出版日期：");
			scanf("%s", p->info.date);
			printf("请输入价格：");
			scanf("%s", p->info.price);
			printf("\n");
			printf("图书信息修改成功，请及时保存！\n");
			char ch;
			do
			{
				printf("是否保存（Y/N）？");
				getchar();
				scanf("%c", &ch);
				printf("\n");
				if (ch == 'y' || ch == 'Y')
				{
					SaveBookInfo();
				}
				else if (ch == 'n' || ch == 'N')
				{
					p = p->next;
					return;
				}
				else
					printf("输入错误，请重新输入！\n");
			} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
		}
		p = p->next;
	}
	if (flag == 0)
	{
		printf("没有该书名的信息\n");
		printf("输入任意键返回菜单\n");
		getchar();
	}
	system("pause");
	system("cls");
}
void DeletBookInfo() //删除图书信息
{
	char name[20];
	printf("请输入需要删除的图书名：\n");
	scanf("%s", name);
	printf("\n");
	Node* p = head;
	Node* q = head;
	Node* s = (Node*)malloc(sizeof(Node));
	int flag = 0;
	while (p != NULL)
	{
		if (strcmp(p->info.name, name) == 0)
		{
			printf("书名:    %-20s\n", p->info.name);
			printf("作者名:  %-20s\n", p->info.author);
			printf("出版社:  %-20s\n", p->info.publisher);
			printf("出版日期:%-20s\n", p->info.date);
			printf("价格:    %-20s\n", p->info.price);
			printf("\n");
			flag = 1;
			
			if (p == head)
			{
				head = p->next;
			}
			else if (p->next == NULL)
			{
				p = q;
				p->next = NULL;
			}
			else
			{
				q->next = p->next;
			}
			printf("图书信息删除成功，请及时保存！\n");
			char ch;
			do
			{
				printf("是否保存（Y/N）？");
				getchar();
				scanf("%c", &ch);
				printf("\n");
				if (ch == 'y' || ch == 'Y')
				{
					s = p;
					SaveBookInfo();
					p = s;
				}
				else if (ch == 'n' || ch == 'N')
				{
					break;
				}
				else
					printf("输入错误，请重新输入！\n");
			} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
		}
		q = p;
		p = p->next;
	}
	if (flag == 0)
	{
		printf("没有该书名的信息\n");
		printf("\n");
		printf("输入任意键返回菜单\n");
		printf("\n");
		getchar();
	}
	system("pause");
	system("cls");
}
void ReadBookInfo() //显示所有图书信息
{
	FILE* pFile;
	pFile = fopen("bookInfomation.txt", "r");
	if (pFile == NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	Node* p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	head = p;
	char str[200];
	int i = 0;
	while (fscanf(pFile, "%s", str) != EOF)
	{
		if (str != NULL)
		{
			switch (i)
			{
			case 0:
				strcpy(p->info.name, str);
				break;
			case 1:
				strcpy(p->info.author, str);
				break;
			case 2:
				strcpy(p->info.publisher, str);
				break;
			case 3:
				strcpy(p->info.date, str);
				break;
			case 4:
				strcpy(p->info.price, str);
				break;
			default:
				Node* pNewNode = (Node*)malloc(sizeof(Node));
				pNewNode->next = NULL;
				p->next = pNewNode;
				p = p->next;
				strcpy(p->info.name, str);
				i = 0;
				break;
			}
			i++;
		}
	}
	fclose(pFile);
	PrintBookInfo();
}
void ExitBookInfo() //退出图书管理系统
{
	char ch;
	do
	{
		printf("正在退出……\n");
		printf("\n");
		printf("是否保存（Y/N）？");
		getchar();
		scanf("%c", &ch);
		printf("\n");
		if (ch == 'y' || ch == 'Y')
		{
			SaveBookInfo();
			exit(0);
		}
		else if (ch == 'n' || ch == 'N')
			return;
		else
			printf("输入错误，请重新输入！\n");
	} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
}
