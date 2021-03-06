#include <easyx.h>//ͼ�ο�graphics.h
#include <iostream>//cppͷ�ļ�
#include <conio.h>//����������ͷ�ļ�
#include <time.h>//��ȡʱ�䣬�������������
#include <graphics.h>
using namespace std;
void area1();//��ʼ����
void area2();//��Ϸ����
void area3();//��������

int main() {
	initgraph(500, 500);//��ʼһ��ͼ�����򣨿�500����500��
	BeginBatchDraw();//��ʼ��ͼ
	area1();//��ʼ����
	area2();//��Ϸ����
	area3();//��������
	return 0;
}

void area1() {//��ʼ����ĺ���
	do {
		setbkmode(TRANSPARENT);
		setfillcolor(WHITE);//���ñ�����ɫ
		solidrectangle(0, 0, 500, 500);
		settextcolor(GREEN);//����������ɫ
		settextstyle(50, 0, _T("����"));//����������ʽ;
		outtextxy(110, 100, _T("̰������Ϸ"));//�������
		settextcolor(BLACK);
		settextstyle(30, 0, _T("����"));
		outtextxy(200, 200, _T("START"));
		settextstyle(20, 0, _T("����"));
		outtextxy(150, 230, _T("(���س�������һ��)"));
		settextcolor(LIGHTGRAY);
		outtextxy(150, 250, _T("A������   D������"));
		outtextxy(150, 270, _T("W������   S������"));
		FlushBatchDraw();//�����ͼ
		_getch();//ֹͣ���ȴ�����
	} while (GetKeyState(13) >= 0);//�س��ж�
}

void area2() {//��Ϸ����ĺ���
	int s[52][52];
	int lon = 3;//�ߵĳ���
	int way = 1;//�ߵķ���
	int x = 25, y = 25;//�ߵĳ�ʼλ��
	srand(int(time(0)));
	int rx = 1 + rand() % 49;//ʳ��ĺ�����
	int ry = 1 + rand() % 49;//ʳ���������
	for (int i = 1; i <= 50; i++)
		for (int j = 1; j <= 50; j++)
			s[i][j] = 0;//�յص�ֵΪ0
	while (s[rx][ry] != 0) {
		rx = 1 + rand() % 49;
		ry = 1 + rand() % 49;
	}
	s[rx][ry] = -1;//ʳ���ֵΪ-1
	while (1) {//��ѭ����ͷ
		Sleep(100);
		setfillcolor(WHITE);//���ñ�����ɫ
		solidrectangle(0, 0, 500, 500);
		if (GetKeyState(65) < 0 && way != 2)//a,����ͬʱȷ����������ɱ
			way = 1;
		if (GetKeyState(68) < 0 && way != 1)//d,���ң�ͬʱȷ����������ɱ
			way = 2;
		if (GetKeyState(83) < 0 && way != 4)//s,���£�ͬʱȷ����������ɱ
			way = 3;
		if (GetKeyState(87) < 0 && way != 3)//w,���ϣ�ͬʱȷ����������ɱ
			way = 4;
		if (way == 1)x--;
		if (way == 2)x++;
		if (way == 3)y++;
		if (way == 4)y--;
		if (x <= 0 || x > 50 || y <= 0 || y > 50 || s[x][y] > 0)//ײǽ����ʳ����Ϸ����
			break;
		s[x][y] = lon;//�ߵ�ֵΪ����
		for (int i = 1; i <= 50; i++) {
			for (int j = 1; j <= 50; j++) {
				if (s[i][j] > 0) {
					s[i][j]--;
					setfillcolor(GREEN);//���õ�ǰ��ɫΪ��ɫ(��)
					solidrectangle((i - 1) * 10, (j - 1) * 10, i * 10, j * 10);//�γ��ޱ߿����
				}
				if (s[i][j] == -1) {
					setfillcolor(RED);//���õ�ǰ��ɫΪ��ɫ(ʳ��)
					solidrectangle((i - 1) * 10, (j - 1) * 10, i * 10, j * 10);//�γ��ޱ߿����
				}
				if (x == rx && y == ry) {//�߳Ե�ʳ��
					lon++;
					while (s[rx][ry] != 0) {
						rx = 1 + rand() % 49;
						ry = 1 + rand() % 49;
					}//while
					s[rx][ry] = -1;
				}//if
			}//for
		}//for
		FlushBatchDraw();//�����ͼ
	}//��ѭ����β
}

void area3() {//��������ĺ���
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);//���ñ�����ɫ
	solidrectangle(0, 0, 500, 500);
	settextcolor(BLACK);//����������ɫ
	settextstyle(50, 0, _T("����"));//����������ʽ;
	outtextxy(120, 200, _T("�д���ߣ�"));//�������
	settextstyle(20, 0, _T("����"));
	outtextxy(150, 270, _T("(3����Զ��ر�)"));
	FlushBatchDraw();//�����ͼ
	Sleep(3000);//��λ�Ժ������
	_getch();
	closegraph();
}

