#include <easyx.h>//图形库graphics.h
#include <iostream>//cpp头文件
#include <conio.h>//按键操作的头文件
#include <time.h>//提取时间，用来生成随机数
#include <graphics.h>
using namespace std;
void area1();//开始界面
void area2();//游戏界面
void area3();//结束界面

int main() {
	initgraph(500, 500);//初始一个图形区域（宽500，长500）
	BeginBatchDraw();//开始绘图
	area1();//开始界面
	area2();//游戏界面
	area3();//死亡界面
	return 0;
}

void area1() {//开始界面的函数
	do {
		setbkmode(TRANSPARENT);
		setfillcolor(WHITE);//设置背景颜色
		solidrectangle(0, 0, 500, 500);
		settextcolor(GREEN);//设置字体颜色
		settextstyle(50, 0, _T("楷体"));//设置字体样式;
		outtextxy(110, 100, _T("贪吃蛇游戏"));//输出字体
		settextcolor(BLACK);
		settextstyle(30, 0, _T("楷体"));
		outtextxy(200, 200, _T("START"));
		settextstyle(20, 0, _T("楷体"));
		outtextxy(150, 230, _T("(按回车进入下一步)"));
		settextcolor(LIGHTGRAY);
		outtextxy(150, 250, _T("A代表左   D代表右"));
		outtextxy(150, 270, _T("W代表上   S代表下"));
		FlushBatchDraw();//输出绘图
		_getch();//停止，等待操作
	} while (GetKeyState(13) >= 0);//回车判断
}

void area2() {//游戏界面的函数
	int s[52][52];
	int lon = 3;//蛇的长度
	int way = 1;//蛇的方向
	int x = 25, y = 25;//蛇的初始位置
	srand(int(time(0)));
	int rx = 1 + rand() % 49;//食物的横坐标
	int ry = 1 + rand() % 49;//食物的纵坐标
	for (int i = 1; i <= 50; i++)
		for (int j = 1; j <= 50; j++)
			s[i][j] = 0;//空地的值为0
	while (s[rx][ry] != 0) {
		rx = 1 + rand() % 49;
		ry = 1 + rand() % 49;
	}
	s[rx][ry] = -1;//食物的值为-1
	while (1) {//主循环开头
		Sleep(100);
		setfillcolor(WHITE);//设置背景颜色
		solidrectangle(0, 0, 500, 500);
		if (GetKeyState(65) < 0 && way != 2)//a,向左，同时确保不反向自杀
			way = 1;
		if (GetKeyState(68) < 0 && way != 1)//d,向右，同时确保不反向自杀
			way = 2;
		if (GetKeyState(83) < 0 && way != 4)//s,向下，同时确保不反向自杀
			way = 3;
		if (GetKeyState(87) < 0 && way != 3)//w,向上，同时确保不反向自杀
			way = 4;
		if (way == 1)x--;
		if (way == 2)x++;
		if (way == 3)y++;
		if (way == 4)y--;
		if (x <= 0 || x > 50 || y <= 0 || y > 50 || s[x][y] > 0)//撞墙或自食则游戏结束
			break;
		s[x][y] = lon;//蛇的值为正数
		for (int i = 1; i <= 50; i++) {
			for (int j = 1; j <= 50; j++) {
				if (s[i][j] > 0) {
					s[i][j]--;
					setfillcolor(GREEN);//设置当前颜色为绿色(蛇)
					solidrectangle((i - 1) * 10, (j - 1) * 10, i * 10, j * 10);//形成无边框矩形
				}
				if (s[i][j] == -1) {
					setfillcolor(RED);//设置当前颜色为红色(食物)
					solidrectangle((i - 1) * 10, (j - 1) * 10, i * 10, j * 10);//形成无边框矩形
				}
				if (x == rx && y == ry) {//蛇吃到食物
					lon++;
					while (s[rx][ry] != 0) {
						rx = 1 + rand() % 49;
						ry = 1 + rand() % 49;
					}//while
					s[rx][ry] = -1;
				}//if
			}//for
		}//for
		FlushBatchDraw();//输出绘图
	}//主循环结尾
}

void area3() {//死亡界面的函数
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);//设置背景颜色
	solidrectangle(0, 0, 500, 500);
	settextcolor(BLACK);//设置字体颜色
	settextstyle(50, 0, _T("楷体"));//设置字体样式;
	outtextxy(120, 200, _T("有待提高！"));//输出字体
	settextstyle(20, 0, _T("楷体"));
	outtextxy(150, 270, _T("(3秒后自动关闭)"));
	FlushBatchDraw();//输出绘图
	Sleep(3000);//单位以毫秒计算
	_getch();
	closegraph();
}

