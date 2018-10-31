#include "stdio.h"
#include "windows.h"
#include "stdlib.h"
#pragma warning(disable:4996)

#define ROW 3
#define COL 3

/*≤Àµ•*/
int menu()
{
	printf("###########################\n");
	printf("##   1.Play	2.Exit   ##\n");
	printf("###########################\n");
	return 0;
}
/*œ‘ æ√Ê∞Â*/
int ShowBroad(char chess[][COL])
{
	printf(" %c | %c |%c \n",chess[0][0],chess[0][1],chess[0][2]);
	printf(" ----------\n");
	printf(" %c | %c |%c \n", chess[1][0], chess[1][1], chess[1][2]);
	printf(" ----------\n");
	printf(" %c | %c |%c \n", chess[2][0], chess[2][1], chess[2][2]);

}
/*≈–∂œ*/
char Judge(char chess[][COL])
{
	for (int i = 0; i < 3; i++){
		if (chess[i][0] == chess[i][1] && chess[i][1] == chess[i][2] && chess[i][2] != ' ')
		{
			return chess[i][0];
		}
	}
	for (int i = 0; i < 3; i++){
		if (chess[0][i] == chess[1][i] && chess[1][i] == chess[1][i] && chess[2][i] != ' ')
		{
			return chess[0][i];
		}
	}
		if (chess[0][0] == chess[1][1] && chess[1][1] == chess[2][2] && chess[2][2] != ' ')
		{
			return chess[0][0];
		}
		if (chess[0][2] == chess[1][1] && chess[1][1] == chess[3][0] && chess[3][0] != ' ')
		{
			return chess[0][0];
		}
		return ' ';
}



int main()
{
	int a ,count =0;
	char chess[ROW][COL] = { ' ' };
	menu();
	printf("Please Enter Your Chose:>\n ");
	scanf("%d", &a);
	system("cls");
	ShowBroad(chess);
	srand((unsigned)time(NULL));
	while (1)
	{
		int x, y, user_x, user_y;
		printf("Please Enter:<x,y>\n");
		scanf("%d%d", &user_x, &user_y);
		if ((user_x >= 1 && user_x <= 3) && (user_y >= 1 && user_y <= 3)){
			chess[user_x - 1][user_y - 1] = 'X';
			count++;
			if (Judge(chess) == 'X'){
				system("cls");
				ShowBroad(chess);
				printf("You Win! :)\n");
				break;
			}
			else if (count == 9){
				printf("Draw!\n");
				break;
			}
			while (1){
				x = rand() % (3) + 0;
				y = rand() % (3) + 0;
				if (chess[x][y]=='\0'){
					chess[x][y] = 'O';
					break;
				}
			}
			system("cls");
			ShowBroad(chess);
			count++;
			if (Judge(chess) == 'O'){
				printf("You Lost!\n");
				break;
			}
		}
		else continue;
	}
	system("pause");
	return 0;
}
