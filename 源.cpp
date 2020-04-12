/*用链表完成一个学生教学系统*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n = 0;
struct student
{
	int num;//书籍编号
	char name[15];//书籍名称
	struct student* next;
};
int ShowMenu()
{
	int num;
	system("cls");
	printf("--------------------学生教学系统-----------------------\n");
	printf("\t\t1.学生信息入库\n");//输入
	printf("\t\t2.删除信息\n");//从库里删除
	printf("\t\t3.添加信息\n");//插入数据
	printf("\t\t4.输出数据\n");
	printf("\t\t0.退出系统\n");
	printf("--------------------请选择-----------------------\n");
	while (scanf("%d", &num) != 1 || num < 0 || num > 4)
	{
		printf("你选择的菜单错误！按任意键重新选择。\n");
		system("pause");
		fflush(stdin);//清空输入缓冲区
	}
	return num;
}
struct student* creat()
{
	printf("请输入数据,以-1表示输入结束\n");
	struct student* head, *p1, *p2;
	head = NULL;
	head = (struct student*)malloc(10);//带头结点的链表
	p1 = p2 = (struct student*)malloc(10);//建立存储空间
	scanf("%d %s", &p1->num, p1->name);
	while (p1->num != -1)
	{
		n++;
		if (n == 1)
		{
			head->next = p1;
		}//带头节点的从head->next  开始操作
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1 = (struct student*)malloc(10);
		scanf("%d %s", &p1->num, p1->name);
	}
	p2->next = NULL;
	return (head);//返回带头结点的函数
}
struct student* delect(struct student* head)
{
	printf("输入即将删除学生的学号\n");
	int num;
	scanf("%d", &num);
	struct student* p1, *p2 = head;//p1用于寻找，p2始终指向p1前面的那个节点
	p1 = (struct student*)malloc(10);
	int t = 0;
	p1 = head->next;
	while (p1)
	{
		if (p1->num == num)//找到了
		{
			t = 1;
			p2->next = p1->next;
		}
		p2 = p1;
		p1 = p1->next;
	}//查询要删除的节点
	if (t == 0) //没有找到要找到的数据
	{
		printf("no data ");
		fflush(stdin);
	}
	head = head->next;
	return (head);
}
struct student* deinsert(struct student* head)
{
	printf("请输入学号名字和要插入的位置：\n");
	int a, b;//a是插入数据，b是位置
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
	printf("输出数据：\n");
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