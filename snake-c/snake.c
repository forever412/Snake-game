#include "snake.h"

//���ýṹ��ָ���ʼ��������Ϣ
void initSnake(Snake *s){
	s->x = 1;
	s->y = 1;
	s->pre = NULL;
	s->next = NULL;
}

//�ж���Ϸ����������ͷ����������Ϸ����
int isSnakeEatItself(Snake *head){
	int gameOver = 0;
	Snake *pt = head->next;
	while (pt){
		if (head->x == pt->x && head->y == pt->y){
			gameOver = 1;
			break;
		}
		pt = pt->next;
	}
	return gameOver;
}


//���Ƿ�Ե�ʳ��
int isSnakeEatMeetFood(Snake *snake, Food *food){
	if (snake->x == food->x && snake->y == food->y)
		return 1;
	else
		return 0;
}

//��������һ��
Snake *snakeGrow(Snake *head){
	Snake *p = (Snake *)malloc(sizeof(Snake));
	Snake *pt = head;	//��ͷ
	while (pt->next)	//��ȡ��β��ָ���ַ
		pt = pt->next;
	p->pre = pt;		//������һ�������ṹ��pre��ָ��ԭ����β���һ������ָ���ַ��
	pt->next = p;		//ԭ������β���һ�������ṹ��next��ָ��������ָ���ַ��
	p->next = NULL;
	return p;
}


//�������ʳ��
void createFood(Food *food){
	food->x = rand() % LENGTH;
	food->y = rand() % WIDTH;
	food->c = 65 + rand() % 26;
}


//����ʳ������������ص�������ص�����������ʳ��
int avoidOverlap(Snake *head, Food *food){
	int t = 0, flag = 1;
	while (flag){
		if (t > OVERLAP)
			break;
		flag = 0;
		t++;
		Snake *pt = head;
		while (pt){
			if (isSnakeEatMeetFood(pt, food)){
				flag = 1;
				createFood(food);
				break;
			}
			pt = pt->next;
		}
	}
	return t;
}


//ʳ��������ص������������ص���ֵⷧ����������˶��ķ�������ʳ������
void setFoodLocation(Food *food, Snake *head, int numOverlap, char c){
	if (numOverlap > OVERLAP){
		if (c == 'd'){
			food->x = head->x + 1;
			food->y = head->y + 1;
			if (food->x >= LENGTH)
				food->x -= LENGTH;
		}
		else if (c == 'a'){
			food->x = head->x - 1;
			food->y = head->y - 1;
			if (food->x >= LENGTH)
				food->x -= LENGTH;
		}
		else if (c == 'w'){
			food->x = head->x + 1;
			food->y = head->y + 1;
			if (food->x >= LENGTH)
				food->x -= LENGTH;
		}
		else if (c == 's'){
			food->x = head->x - 1;
			food->y = head->y - 1;
			if (food->x >= LENGTH)
				food->x -= LENGTH;
		}
	}
}


//���õ�ǰ����
char setCurKeyButton(char c){
	char c1 = _getch();
	if (c1 == 27)
		return 'x';
	if (c != 'd'&&c1 == 'a')
		c = c1;
	else if (c != 'a' && c1 == 'd')
		c = c1;
	else if (c != 'w' && c1 == 's')
		c = c1;
	else if (c != 's'&& c1 == 'w')
		c = c1;
	return c;
}


//�����ߵ��ƶ�
void snakeMove(Snake *head, Snake *rear, char c){
	Snake *pt = rear;
	while (pt != head){
		pt->x = pt->pre->x;
		pt->y = pt->pre->y;
		pt = pt->pre;
	}
	if (c == 's'){
		head->y += 1;
		if (head->y >= WIDTH)
			head->y -= WIDTH;
	}
	else if (c == 'a'){
		head->x -= 1;
		if (head->x >= WIDTH)
			head->x -= WIDTH;
	}
	else if (c == 'w'){
		head->y -= 1;
		if (head->y >= WIDTH)
			head->y -= WIDTH;
	}
	else if (c == 'd'){
		head->x += 1;
		if (head->x >= WIDTH)
			head->x -= WIDTH;
	}
}


//�����ߡ�ʳ�Χǽ
void drawPicture(Snake *head, Food *food){
	int flag;
	Snake *pt;
	system("cls");
	printf("--------------------------------------------\n");  //������Χǽ
	for (int j = 0; j < WIDTH; j++){
		printf("|");										  //������Χǽ
		for (int i = 0; i < LENGTH; i++){
			flag = 0;
			pt = head;
			while (pt){								//������
				if (i == pt->x&&j == pt->y){
					if (pt == head)
						printf("��");				//������ͷ
					else
						printf("��");				//��������
					flag = 1;
					break;
				}
				pt = pt->next;
			}
			if (flag == 0){							//����ʳ��
				if (i == food->x&&j == food->y){
					putchar(food->c);
					putchar(food->c);
					continue;
				}
				printf("  ");
			}
		}
		printf("|");								//������Χǽ
		putchar('\n');
	}
	printf("--------------------------------------------\n");	//������Χǽ
}









