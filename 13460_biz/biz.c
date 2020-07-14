#include<stdio.h>
#include<string.h>
void init(int row, int col, char board[row][col]){
	  for(int i = 0; i<row;i++)
	  {
			memset(board[i],'\0',sizeof(board[i]));//모든 부분을 0으로 채움. 마지막 부분이 \0이 되게끔 하여 읽을 수 있도록 함.
			for (int j = 0 ;j<col;j++)
				scanf("%c",&board[i][j]);
		}
}
void printboard(int row, int col, char board[row][col]){
	for(int i = 0 ; i<row;i++)
		for (int j = 0 ;j<col;j++)
			printf("%c",board[i][j]);
		printf("\n");
}

int main()
{
	int tmp;
	//cin>>tmp;
	//for(int z = 0; z<tmp;z++)
	{
	  int col,row;
		scanf("%d",&row);
		scanf("%d",&col);
	  col++;
	  char board[row][col];
	  init(row, col,board);
	  printboard(row,col,board);
  }
}
