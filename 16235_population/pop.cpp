//글로벌 변수와 초기화 함수를 쓰는것이 더욱 시간을 아낄수도 있다.
//1.2,3... 으로 세기로 결정했다면 0,1,2,3...으로 바꾸는 것은 삼가자.
//#define MAX_N 50을 쓰는 것을 습관화하자.
#include<iostream>
#include<math.h>

using namespace std;
enum {
	U,R,D,L
};
const int format[4][2]={
	{-1,0},{0,1},{1,0},{0,-1}
};
void check(int tboard[50][50],int board[50][50],int i,int j, int n, const int L, const int R, int checknum)
{
	int ni = i;
	int nj = j;
	//cout<<"check"<<' '<<i<<' '<<j<<' '<<n<<' '<<checknum<<'\n';
	for(int t=0;t<4;t++)
	{
	  ni+=format[t][0];
	  nj+=format[t][1];
	  if(ni<0||ni>n-1||nj<0||nj>n-1){
	  	ni-=format[t][0];
	  	nj-=format[t][1];
		  continue;
	  }
	  if(abs(board[ni][nj]-board[i][j])>=L && abs(board[ni][nj]-board[i][j])<=R && tboard[ni][nj]==-1){
		  tboard[ni][nj] = checknum;
		  check(tboard, board, ni, nj, n, L, R, checknum);
	  }
	  ni-=format[t][0];
	  nj-=format[t][1];
  }
	//cout<<"checkend"<<' '<<i<<' '<<j<<'\n';
}
int main(void)
{
	//freopen("pop_input.txt","r",stdin);
	//int tmp;
	//cin>>tmp;
	//for(int z=0;z<tmp;z++)
	{
	  int n, L, R;
	  cin>>n;
	  cin>>L;
	  cin>>R;
	  int board[50][50]={0,};
	  for(int i=0;i<n;i++)
		  for(int j=0;j<n;j++)
			  cin>>board[i][j];
	  int loopcnt=0;
	  while(true){
		  //int tboard[100][100] = {[0 ... 99]={[0 ... 99]=-1}};
		  //c++14: lambda error!!!!
		  int tboard[50][50];
		  fill(tboard[0],tboard[49]+50,-1);
		  int checknum = 0;
		  for(int i=0;i<n;i++)
			  for(int j=0;j<n;j++){
				  if(tboard[i][j]==-1){
					  tboard[i][j]=checknum;
					  check(tboard, board,i,j,n,L,R,checknum);
					  checknum++;
				  }
			  }
//	  	cout<<loopcnt<<'\n';
//		  for(int i=0;i<n;i++){
//			  for(int j=0;j<n;j++)
//				  cout<<board[i][j]<<' ';
//			  cout<<'\n';
//		  }
//		  for(int i=0;i<n;i++){
//			  for(int j=0;j<n;j++)
//				  cout<<tboard[i][j]<<' ';
//			  cout<<'\n';
//		  }
		  int cnt[50*50]={0,};
		  int cntS[50*50]={0,};
		  for(int i=0;i<n;i++)
			  for(int j=0;j<n;j++){
				  cntS[tboard[i][j]]+=board[i][j];
				  cnt[tboard[i][j]]++;
			  }
		  int k;
		  for(k=0;k<n*n;k++)
			  if(cnt[k]==0)
				  break;
		  if(k==n*n||loopcnt==2000)
			  break;
		  else
		  	loopcnt++;
		  for(int i=0;i<n*n;i++)
			  if(cntS[i] != 0){
				  cntS[i]/=cnt[i];
			  }
		  for(int i=0;i<n;i++)
			  for(int j=0;j<n;j++){
				  board[i][j]=cntS[tboard[i][j]];
				  }
	  }
	  cout<<loopcnt<<'\n';
  }
}
