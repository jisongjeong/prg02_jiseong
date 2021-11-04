#include<stdio.h>
#include<windows.h>
#include<conio.h>

void move(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

}
int main(void)
{
	int x = 0;
	int y = 0;

	while (1) {

		move(x, y);
		printf(" ");

		if (GetAsyncKeyState(VK_UP) & 0X8000)y--;  //GetAsyncKeyState는 getch()와 다르게 대각선 이동 가능.
		if (GetAsyncKeyState(VK_DOWN) & 0X8000)y++;
		if (GetAsyncKeyState(VK_LEFT) & 0X8000)x -= 2;
		if (GetAsyncKeyState(VK_RIGHT) & 0X8000)x += 2;
		move(x, y);
		printf("@");
		Sleep(50);
	}
	return 0;
}