#include "stdio.h"
#include "windows.h"
#include "stdlib.h"
#pragma warning(disable:4996)

#define ROW 3
#define COL 3

/*�˵�*/
int menu()
{
	printf("###########################\n");
	printf("##   1.Play	2.Exit   ##\n");
	printf("###########################\n");
	return 0;
}
/*��ʾ���*/
int ShowBroad(char chess[][COL])
{
	system("cls");
	printf(" %c | %c |%c          Player:   X\n",chess[0][0],chess[0][1],chess[0][2]);
	printf(" ----------        Computer: O\n");
	printf(" %c | %c |%c \n", chess[1][0], chess[1][1], chess[1][2]);
	printf(" ----------\n");
	printf(" %c | %c |%c \n", chess[2][0], chess[2][1], chess[2][2]);

}
/*�ж�*/
char Judge(char chess[][COL])
{
	for (int i = 0; i < COL; i++){
		if (chess[i][0] == chess[i][1] && chess[i][1] == chess[i][2] && chess[i][2] != '\0')
		{
			return chess[i][0];
		}
	}
	for (int i = 0; i < COL; i++){
		if (chess[0][i] == chess[1][i] && chess[1][i] == chess[2][i] && chess[2][i] != '\0')
		{
			return chess[0][i];
		}
	}
	if (chess[0][0] == chess[1][1] && chess[1][1] == chess[2][2] && chess[2][2] != '\0')
		{
			return chess[0][0];
		}
	if (chess[0][2] == chess[1][1] && chess[1][1] == chess[2][0] && chess[2][0] != '\0')
		{
			return chess[0][2];
		}
		return ' ';
}
/*��������*/
void computer(char chess[][COL])
{
	int x, y;
	while (1){
		x = rand() % (COL) + 0;
		y = rand() % (COL) + 0;
		if (chess[x][y] == '\0'){
			chess[x][y] = 'O';
			break;
		}
	}
	ShowBroad(chess);
	
}

int main()
{
	int a ,count =0;
	char chess[ROW][COL] = { '\0' };
	menu();											//��ʾ�˵�
	printf("Please Enter Your Chose:>\n ");
	scanf("%d", &a);
	if (a != 1){ return 0; }
	ShowBroad(chess);
	srand((unsigned)time(NULL));
	while (1)
	{
		int user_x, user_y;
		printf("Please Enter:<x,y>\n");
		scanf("%d%d", &user_x, &user_y);			//�������
		if ((user_x >= 1 && user_x <= 3) && (user_y >= 1 && user_y <= 3)&&\
			chess[user_x-1][user_y-1]=='\0'){		//�����Ƿ�Ϸ�
			chess[user_x - 1][user_y - 1] = 'X';
			count++;
			if (Judge(chess) == 'X'){				//�ж����Ӯ
				ShowBroad(chess);
				printf("You Win! :)\n");
				break;
			}
			else if (count == 9){					//�ж�ƽ��
				ShowBroad(chess);
				printf("Draw!\n");
				break;
			}
			computer(chess);						//��������
			count++;
			if (Judge(chess) == 'O'){				//�жϵ���Ӯ
				printf("You Lost!\n");
				break;
			}
		}
		else continue;
	}
	system("pause");
	return 0;
}
