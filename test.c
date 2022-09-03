#define _CRT_SECURE_NO_WARNINGS 1


#include"test.h"

void menu()
{
	printf("********************************\n");
	printf("****1.play            0.exit****\n");
	printf("********************************\n");
}
void game()
{
	char ret = 0;
	//������������Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//�������
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=IsWin(board,ROW,COL);
		if (ret != 'c')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ!\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ!\n");
	}
	else
	{
		printf("ƽ��!\n");
	}
	

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:<");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
				  game();
				  break;
		}
		case 0:
		{
				  printf("�˳���Ϸ!\n");
				  break;
		}
		default:
		{
				   printf("ѡ�����������ѡ��!\n");
				   break;
		}
		}
	} while (input);
	return 0;
}
