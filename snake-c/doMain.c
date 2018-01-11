#include<time.h>


#include <windows.h>
#include "snake.h"

void main(){
	int testNum = 0;	//ʳ��������ص�������
	char c = 'd';		//���򰴼���ʼ��Ϊd,���߳�ʼ�����ƶ�
	srand((unsigned)time(NULL));	//�������

	Food food = { 5, 8, 'A' };		//��ʼ��ʳ��
	Snake snake, *head, *rear;		//��ͷ����β
	initSnake(&snake);				//��ʼ����
	head = rear = &snake;

	while (1){
		drawPicture(head, &food);				//����ǽ���ߡ�ʳ��
		if (isSnakeEatMeetFood(head, &food)){	//�߳Ե�ʳ���
			rear = snakeGrow(head);				//����һ������
			createFood(&food);					//��������
			testNum = avoidOverlap(head, &food);		//�ж������ɵ�ʳ�����������Ƿ����ص���������������
			setFoodLocation(&food, head, testNum, c);	//���ص�����Ԥ���������������ǰ���ķ�������ʳ��
		}
		/*��������*/
		if (_kbhit())
			c = setCurKeyButton(c);		//���õ�ǰ�İ���
		if (c == 'x')				
			break;						//�����˳�����
		snakeMove(head, rear, c);		//���ƶ�
		if (isSnakeEatItself(head)){	//����������ͽ�����Ϸ
			puts("game over!\n");
			break;
		}
		Sleep(300);			//��Ļˢ��ʱ����
	}
	_getch();
}