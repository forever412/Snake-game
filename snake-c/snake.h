#ifndef _SNAKE_H
#define _SNAKE_H

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define LENGTH 20	  //Χǽ�ĳ���
#define WIDTH 10	  //Χǽ�Ŀ��
#define OVERLAP 3     //ʳ���������ص�����������ʳ��ʱ��Ҫ�õ�

//�߽ṹ��
typedef struct Snake{
	int x;				//���������
	int y;				//����������
	struct Snake *pre;	//�ṹ��ָ�룬ָ��ǰ�����ǰһ������
	struct Snake *next;	//�ṹ��ָ�룬ָ��ǰ����ĺ�һ������
}Snake;

//ʳ��ṹ��
typedef struct Food{
	int x;				//ʳ�������
	int y;				//ʳ��������
	char c;				//ʳ����ַ���ʾ
}Food;


void initSnake(Snake *s);							//�����ʼ��
int isSnakeEatItself(Snake *head);					//�ж���Ϸ����������ͷ��������
int isSnakeEatMeetFood(Snake *snake, Food *food);	//���Ƿ�Ե�ʳ��
Snake *snakeGrow(Snake *head);		//��������һ��
void createFood(Food *food);		//�������ʳ��
//����ʳ������������ص�����������ʳ��
int avoidOverlap(Snake *head, Food *food);
//�������ʳ��������ص�������ֵ����ֱ�Ӱ����ƶ��ķ�������ʳ��λ��
void setFoodLocation(Food *food, Snake *head, int numOverlap, char c);
char setCurKeyButton(char c1 );				//���õ�ǰ����
void snakeMove(Snake *head, Snake *rear, char c);	//�����ߵ��ƶ�
void drawPicture(Snake *head, Food *food);			//�����ߡ�ʳ���Χǽ

#endif




