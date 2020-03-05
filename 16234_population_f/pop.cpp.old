//https://www.acmicpc.net/problem/16234
/*
첫째 줄에 N, L, R이 주어진다. (1 ≤ N ≤ 50, 1 ≤ L ≤ R ≤ 100)
/
둘째 줄부터 N개의 줄에 각 나라의 인구수가 주어진다. r행 c열에 주어지는 정수는 A[r][c]의 값이다. (1 ≤ A[r][c] ≤ 100)
인구 이동이 발생하는 횟수가 2,000번 보다 작거나 같은 입력만 주어진다.
*/

/*
   인구 이동이 몇 번 발생하는지 첫째 줄에 출력한다.
*/

#include<iostream>
using namespace std;
void printboard(int board[50][50],int boardn){
	  for(int i=0;i<boardn;i++){
		  for(int j=0;j<boardn;j++){
	  		cout<<board[i][j];
	  		cout<<' ';
		  }
		  cout<<'\n';
	  }
		cout<<'\n';
}
void printline(bool line[99][99],int linen,int boardn)
{
	for(int i=0;i<linen;i++){
		for(int j=0;j<boardn;j++){
	  		cout<<line[i][j];
	  		cout<<' ';
		}
		cout<<'\n';
  }
		cout<<'\n';
}
void opengate(int board[50][50],bool line[99][99],int L, int R, int boardn, int linen){
	int comp1, comp2;
	int tmp;
	for(int i=0;i<linen;i++){
		if(i%2==0)
			tmp = boardn-1;
		else
			tmp=boardn;
		for(int j=0;j<tmp;j++){
			if(i%2==1){
				comp1=board[(i-1)/2][j];
				comp2=board[(i+1)/2][j];
			}
			else{
				comp1 = board[i/2][j];
				comp2 = board[i/2][j+1];
			}
			//cout<<i<<' '<<j<<'\n';
			//cout<<comp1<<' '<<comp2<<'\n';
			//cout<<abs(comp1-comp2)<<'\n';
			if(abs(comp1-comp2)>=L && abs(comp1-comp2)<=R)
				line[i][j] = false;
		}
	}
	//printline(line, linen, boardn);
}
int main(){
	freopen("pop_input.txt","r",stdin);
	int n;
	cin>>n;
	for(int z=0;z<n;z++)
	{
	  int boardn, L, R;
	  cin>>boardn;
	  cin>>L;
	  cin>>R;
	  int board[50][50];
	  for(int i=0;i<boardn;i++){
		  for(int j=0;j<boardn;j++){
			  cin>>board[i][j];
		  }
		}
	  //printboard(board, boardn);
	  int linen=boardn+boardn-1;
	  bool line[99][99]={false,};//true: close, false: open
	  bool isend = true;
	  int tmpn;
	  for(int i=0;i<linen;i++){
			if(isend)
				tmpn = boardn-1;
			else
				tmpn = boardn;
		  for(int j=0;j<tmpn;j++){
			  line[i][j] = true;
		  }
		  isend=!isend;
	  }
	  //printline(line, linen,boardn);
	  opengate(board, line, L, R, boardn, linen);
  }
	return 0;
}
