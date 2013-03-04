/*************************************************************************
	> File Name: zoj1072.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月04日 星期一 08时49分21秒
 ************************************************************************/

#include<stdio.h>

#define MAX_LEN 300
char inst[MAX_LEN];
int pos;
int A,B;
char dec2hex(int x)
{
	char ch;
	if (A < 10)
		ch = A + '0';
	else
		ch = A - 10 + 'A';
	return ch;
}
int hex2dec(char ch)
{
	int x;
	if (ch >= '0' && ch <= '9')
		x = ch - '0';
	else
		x = ch - 'A' + 10;
	return x;
}
void command0()
{
	int p = hex2dec(inst[pos+1]) * 16 + hex2dec(inst[pos+2]);
	A = hex2dec(inst[p]);
	pos += 3;
	if (pos >= 0xf0)
		pos -= 0xf0;
}
void command1()
{
	int p = hex2dec(inst[pos+1]) * 16 + hex2dec(inst[pos+2]);
	inst[p] = dec2hex(A);
	pos += 3;
	if (pos >= 0xf0)
		pos -= 0xf0;
}
void command2()
{
	int tmp = A;
	A = B;
	B = tmp;
	pos++;
	if (pos >= 0xf0)
		pos -= 0xf0;
}
void command3()
{
	int sum = A + B;
	B = sum / 16;
	A = sum % 16;
	pos++;
	if (pos >= 0xf0)
		pos -= 0xf0;
}
void command4()
{
	A++;
	if (A > 15)
		A = 0;
	pos++;
	if (pos >= 0xf0)
		pos -= 0xf0;
}
void command5()
{
	A--;
	if (A < 0)
		A = 15;
	pos++;
	if (pos >= 0xf0)
		pos -= 0xf0;
}
void command6()
{
	int p = hex2dec(inst[pos+1]) * 16 + hex2dec(inst[pos+2]);
	if (A == 0)
		pos = p;
	else
		pos += 3;
	if (pos >= 0xf0)
		pos -= 0xf0;
}
void command7()
{
	pos = hex2dec(inst[pos+1]) * 16 + hex2dec(inst[pos+2]);
	if (pos >= 0xf0)
		pos -= 0xf0;
}
int main()
{
	while (1)
	{
		scanf("%s",inst);
		if (inst[0] == '8')
			break;
		pos = 0;
		int over = 0;
		A = B = 0;
		while (1)
		{
			switch (inst[pos])
			{
				case '0':command0();break;
				case '1':command1();break;
				case '2':command2();break;
				case '3':command3();break;
				case '4':command4();break;
				case '5':command5();break;
				case '6':command6();break;
				case '7':command7();break;
				case '8':over = 1;break;
				default:over = 1;break;
			}
			if (over || pos > 255)
				break;
		}
		printf("%s\n",inst);
	}
	return 0;
}
