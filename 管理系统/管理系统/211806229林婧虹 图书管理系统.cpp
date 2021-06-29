/*
	��Ŀ���ƣ�ͼ�����ϵͳ
	��������: C����
	�������ߣ�Visual Studio 2019
	����ʱ�䣺2020.03
	�����ߣ�211806229 ��溺�
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bookInfo //����ͼ����Ϣ�ṹ�����
{
	char name[20];      //����
	char author[20];    //������
	char publisher[20]; //������
	char date[20];      //��������
	char price[20];	    //�۸�
}Information;

typedef struct PNode	//��������ڵ�
{
	Information info;   //ͼ����Ϣ
	struct PNode* next; //��һ���ڵ�
	
}Node;

Node* head = NULL;		//����ͷָ��

void Menu();                   //�˵�
void InputBookInfo();		   //���ͼ����Ϣ
void PrintBookInfo();		   //��ӡͼ����Ϣ
void SaveBookInfo();		   //����ͼ����Ϣ
void Locate_BookInfo_name();   //����������
void Locate_BookInfo_author(); //�����߲���
int CountBookInfo();		   //ͳ��ͼ����Ϣ
void ChangeBookInfo();		   //�޸�ͼ����Ϣ
void DeletBookInfo();		   //ɾ��ͼ����Ϣ
void ReadBookInfo();		   //��ʾ����ͼ����Ϣ
void ExitBookInfo();		   //�˳�ͼ����Ϣϵͳ
void RecommendBook(int count); 
int main()
{
	while (1)
	{
		Menu();					  	 //�˵�
		char ch = getchar();
		int count = CountBookInfo();
		switch (ch)
		{
		case'1':
			InputBookInfo();		 //���ͼ����Ϣ
			break;
		case'2':
			PrintBookInfo();		 //��ӡͼ����Ϣ
			break;
		case'3':
			SaveBookInfo();			 //����ͼ����Ϣ
			break;
		case'4':
			Locate_BookInfo_name();  //����������
			break;
		case'5':
			Locate_BookInfo_author();//�����߲���
			break;
		case'6':
			RecommendBook(count);	 //�Ƽ�ͼ����Ϣ
			break;
		case'7':
			ChangeBookInfo();		 //�޸�ͼ����Ϣ
			break;
		case'8':
			DeletBookInfo();		 //ɾ��ͼ����Ϣ
			break;
		case'9':
			ReadBookInfo();
			break;
		case'0':
			ExitBookInfo();          //�˳�ͼ����Ϣϵͳ
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
	printf("\t\t    ��ӭʹ��ͼ�����ϵͳV1.0\n");
	printf("\t\t\t    ��ѡ����\n");
	printf("\t*************************************************\n");
	printf("\t\t\t  1.���ͼ����Ϣ\n");
	printf("\t\t\t  2.��ӡͼ����Ϣ\n");
	printf("\t\t\t  3.����ͼ����Ϣ\n");
	printf("\t\t\t  4.����������  \n");
	printf("\t\t\t  5.�����߲���  \n");
	printf("\t\t\t  6.�Ƽ�ͼ����Ϣ\n");
	printf("\t\t\t  7.�޸�ͼ����Ϣ\n");
	printf("\t\t\t  8.ɾ��ͼ����Ϣ\n");
	printf("\t\t\t  9.��ʾ����ͼ����Ϣ\n");
	printf("\t\t\t  0.�˳�ͼ����Ϣϵͳ\n");
	printf("\t*************************************************\n");
}
void InputBookInfo()     //���ͼ����Ϣ
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
	printf("������������");
	scanf("%s", pNewNode->info.name);
	printf("��������������");
	scanf("%s", pNewNode->info.author);
	printf("����������磺");
	scanf("%s", pNewNode->info.publisher);
	printf("������������ڣ�");
	scanf("%s", pNewNode->info.date);
	printf("������۸�");
	scanf("%s", pNewNode->info.price);
	char c;
	int num = 0;
	do 
	{
		printf("¼��ɹ���");
		printf("�Ƿ����¼�루Y/N������");
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
				printf("�����������������");
		}
	} while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
	system("pause");
	system("cls");
}
void PrintBookInfo() //��ӡͼ����Ϣ
{
	Node* p = head;
	int count = 1;
	if (p == NULL)
		printf("ϵͳ������ͼ����Ϣ����ȷ�������Ƿ���ȷ");
	else
	{
		while (p != NULL)
		{
			printf("************��%d��ͼ��************",count);
			printf("\n");
			printf("\t������    %-20s\n",p->info.name);
			printf("\t��������  %-20s\n", p->info.author);
			printf("\t�����磺  %-20s\n", p->info.publisher);
			printf("\t�������ڣ�%-20s\n", p->info.date);
			printf("\t�۸�    %-20s\n", p->info.price);
			p = p->next;
			count++;
		}
		printf("������������ز˵�\n");
		getchar();
	}
	system("pause");
	system("cls");
}
void RecommendBook(int count) //�Ƽ�ͼ����Ϣ
{
	int a = rand() % 10;
	Node* p = head;
	bool flag = false;
	int i = 1;
	if (p == NULL)
		printf("ϵͳ������ͼ����Ϣ����ȷ�������Ƿ���ȷ");
	else
	{
		while (p != NULL)
		{
			if (a == i) {
				flag = true;
				printf("************��%d��ͼ��************", i);
				printf("\n");
				printf("\t������    %-20s\n", p->info.name);
				printf("\t��������  %-20s\n", p->info.author);
				printf("\t�����磺  %-20s\n", p->info.publisher);
				printf("\t�������ڣ�%-20s\n", p->info.date);
				printf("\t�۸�    %-20s\n", p->info.price);
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
			printf("�����Ƽ�ͼ�飡");
		}
		printf("������������ز˵�\n");
		getchar();
	}
	system("pause");
	system("cls");
}
void SaveBookInfo() //����ͼ����Ϣ
{
	FILE* pFile;
	pFile = fopen("bookInfomation.txt", "w");
	if (pFile == NULL)
	{
		printf("���ļ�ʧ��\n");
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
	printf("����ɹ�\n");
	system("pause");
	system("cls");
}
void Locate_BookInfo_name() //����������
{
	int flag = 0;
	char name[20];
	Node* p = head;
	printf("����������Ҫ��ѯ��������");
	scanf("%s", name);
	printf("\n");
	printf("����ɹ���\n");
	printf("�����������ҵ���Ϣ��\n");
	while (p != NULL)
	{
		if (strcmp(p->info.name, name) == 0)
		{
			printf("����:    %-20s\n", p->info.name);
			printf("������:  %-20s\n", p->info.author);
			printf("������:  %-20s\n", p->info.publisher);
			printf("��������:%-20s\n", p->info.date);
			printf("�۸�:    %-20s\n", p->info.price);
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
		printf("û�и���������Ϣ\n");
		printf("������������ز˵�\n");
		getchar();
	}
	system("pause");
	system("cls");
}
void Locate_BookInfo_author() //�����߲���
{
	int flag = 0;
	char author[20];
	Node* p = head;
	printf("����������Ҫ��ѯ����������");
	scanf("%s", author);
	printf("\n");
	printf("����ɹ���\n");
	printf("�����������ҵ���Ϣ��\n");
	printf("\n");
	while (p != NULL)
	{
		if (strcmp(p->info.author, author) == 0)
		{
			printf("����:    %-20s\n", p->info.name);
			printf("������:  %-20s\n", p->info.author);
			printf("������:  %-20s\n", p->info.publisher);
			printf("��������:%-20s\n", p->info.date);
			printf("�۸�:    %-20s\n", p->info.price);
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
		printf("û�и����ߵ���Ϣ\n");
		printf("\n");
		printf("������������ز˵�\n");
		getchar();
	}
	system("pause");
	system("cls");
}
int CountBookInfo() //ͳ��ͼ����Ϣ
{
	int count = 0;
	Node* p = head;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
	//printf("ϵͳ�й���%d��ͼ����Ϣ\n", count);
	//system("pause");
	//system("cls");
}
void ChangeBookInfo() //�޸�ͼ����Ϣ
{
	char name[20];
	printf("��������Ҫ�޸ĵ�ͼ������\n");
	scanf("%s", name);
	Node* p = head;
	int flag = 0;
	while (p != NULL)
	{
		if (strcmp(p->info.name, name) == 0)
		{
			printf("����:    %-20s\n", p->info.name);
			printf("������:  %-20s\n", p->info.author);
			printf("������:  %-20s\n", p->info.publisher);
			printf("��������:%-20s\n", p->info.date);
			printf("�۸�:    %-20s\n", p->info.price);
			printf("\n");
			flag = 1;
			printf("������������");
			scanf("%s", p->info.name);
			printf("��������������");
			scanf("%s", p->info.author);
			printf("����������磺");
			scanf("%s", p->info.publisher);
			printf("������������ڣ�");
			scanf("%s", p->info.date);
			printf("������۸�");
			scanf("%s", p->info.price);
			printf("\n");
			printf("ͼ����Ϣ�޸ĳɹ����뼰ʱ���棡\n");
			char ch;
			do
			{
				printf("�Ƿ񱣴棨Y/N����");
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
					printf("����������������룡\n");
			} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
		}
		p = p->next;
	}
	if (flag == 0)
	{
		printf("û�и���������Ϣ\n");
		printf("������������ز˵�\n");
		getchar();
	}
	system("pause");
	system("cls");
}
void DeletBookInfo() //ɾ��ͼ����Ϣ
{
	char name[20];
	printf("��������Ҫɾ����ͼ������\n");
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
			printf("����:    %-20s\n", p->info.name);
			printf("������:  %-20s\n", p->info.author);
			printf("������:  %-20s\n", p->info.publisher);
			printf("��������:%-20s\n", p->info.date);
			printf("�۸�:    %-20s\n", p->info.price);
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
			printf("ͼ����Ϣɾ���ɹ����뼰ʱ���棡\n");
			char ch;
			do
			{
				printf("�Ƿ񱣴棨Y/N����");
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
					printf("����������������룡\n");
			} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
		}
		q = p;
		p = p->next;
	}
	if (flag == 0)
	{
		printf("û�и���������Ϣ\n");
		printf("\n");
		printf("������������ز˵�\n");
		printf("\n");
		getchar();
	}
	system("pause");
	system("cls");
}
void ReadBookInfo() //��ʾ����ͼ����Ϣ
{
	FILE* pFile;
	pFile = fopen("bookInfomation.txt", "r");
	if (pFile == NULL)
	{
		printf("���ļ�ʧ��\n");
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
void ExitBookInfo() //�˳�ͼ�����ϵͳ
{
	char ch;
	do
	{
		printf("�����˳�����\n");
		printf("\n");
		printf("�Ƿ񱣴棨Y/N����");
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
			printf("����������������룡\n");
	} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
}
