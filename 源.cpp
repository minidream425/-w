/*���������һ��ѧ����ѧϵͳ*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n = 0;
struct student
{
	int num;//�鼮���
	char name[15];//�鼮����
	struct student* next;
};
int ShowMenu()
{
	int num;
	system("cls");
	printf("--------------------ѧ����ѧϵͳ-----------------------\n");
	printf("\t\t1.ѧ����Ϣ���\n");//����
	printf("\t\t2.ɾ����Ϣ\n");//�ӿ���ɾ��
	printf("\t\t3.�����Ϣ\n");//��������
	printf("\t\t4.�������\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("--------------------��ѡ��-----------------------\n");
	while (scanf("%d", &num) != 1 || num < 0 || num > 4)
	{
		printf("��ѡ��Ĳ˵����󣡰����������ѡ��\n");
		system("pause");
		fflush(stdin);//������뻺����
	}
	return num;
}
struct student* creat()
{
	printf("����������,��-1��ʾ�������\n");
	struct student* head, *p1, *p2;
	head = NULL;
	head = (struct student*)malloc(10);//��ͷ��������
	p1 = p2 = (struct student*)malloc(10);//�����洢�ռ�
	scanf("%d %s", &p1->num, p1->name);
	while (p1->num != -1)
	{
		n++;
		if (n == 1)
		{
			head->next = p1;
		}//��ͷ�ڵ�Ĵ�head->next  ��ʼ����
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct student*)malloc(10);
		scanf("%d %s", &p1->num, p1->name);
	}
	p2->next = NULL;
	return (head);//���ش�ͷ���ĺ���
}
struct student* delect(struct student* head)
{
	printf("���뼴��ɾ��ѧ����ѧ��\n");
	int num;
	scanf("%d", &num);
	struct student* p1, *p2 = head;//p1����Ѱ�ң�p2ʼ��ָ��p1ǰ����Ǹ��ڵ�
	p1 = (struct student*)malloc(10);
	int t = 0;
	p1 = head->next;
	while (p1)
	{
		if (p1->num == num)//�ҵ���
		{
			t = 1;
			p2->next = p1->next;
		}
		p2 = p1;
		p1 = p1->next;
	}//��ѯҪɾ���Ľڵ�
	if (t == 0) //û���ҵ�Ҫ�ҵ�������
	{
		printf("no data ");
		fflush(stdin);
	}
	head = head->next;
	return (head);
}
struct student* deinsert(struct student* head)
{
	printf("������ѧ�����ֺ�Ҫ�����λ�ã�\n");
	int a, b;//a�ǲ������ݣ�b��λ��
	char name1[15];
	scanf("%d %s %d", &a, name1, &b);
	struct student* p0, *pre, *p;
	p0 = (struct student*)malloc(10);
	pre = (struct student*)malloc(10);
	p
		= (struct student*)malloc(10);
	p0->num = a;
	strcpy(name1, p0->name);
	p = head->next;
	pre = head;
	int i = 1;
	while (i < b - 1)
	{
		pre = p;
		p = p->next;
		i++;
	}
	if (b < n)
	{
		pre->next = p0;
		p0->next = p;
	}
	if (b >= n)
	{
		pre->next = p0;
		p0->next = NULL;
	}
	//fflush(stdin);
	return (head);

}
void shuchu(struct student* head)
{
	printf("������ݣ�\n");
	while (head)
	{
		printf("%d %s \n", head->num, head->name);
		head = head->next;
	}
}
int main()
{
	struct student* head;
	int quit = 0;
	head = (struct student*)malloc(10);
	//scanf("%d",&quit);
	while (quit == 0)
	{
		switch (ShowMenu())
		{
		case 0:
			quit = 1;
			break;
		case 1:
			head = creat();
			break;
		case 2:
			head = delect(head);
			break;
		case 3:
			head = deinsert(head);
			break;
		case 4:
			shuchu(head);
			break;
		}
		system("pause");
	}
	return 0;
}