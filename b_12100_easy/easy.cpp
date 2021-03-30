//첫째 줄에 보드의 크기 N (1 ≤ N ≤ 20)이 주어진다. 둘째 줄부터 N개의 줄에는 게임판의 초기 상태가 주어진다. 0은 빈 칸을 나타내며, 이외의 값은 모두 블록을 나타낸다. 블록에 쓰여 있는 수는 2보다 크거나 같고, 1024보다 작거나 같은 2의 제곱꼴이다. 블록은 적어도 하나 주어진다.
//최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록을 출력한다.
#include<iostream>
#include<vector>
#include<queue>
enum dir {R,L,D,U}
//right, left, down, up //{(1 == i=0,i++, j=0, j++)|(0 == i=0,i++,j=n-1,j<-1,j--) , (1 == map[i][j], 0==map[j][i]}
/*struct Pos{
	int i;
	int j;
	int val;
}*/
void printboard(int n, int map[20][20])
{
	for(int i =0 ; i<n;i++){
		for(int j=0;j<n;j++)
			cout<<map[i][j]<<" ";
		cout<<endl;
	}
}
void swipR(vector<int> &val, int n,int map[20][20]){
	for(int i =0 ; i<n;i++)
		for(int j=0;j<n;j++)
				val.push_back(map[i][j]);
}
void writeR(queue<int> &val, int n,int map[20][20]){
{
	for(int i =0;i<n;i++)
		for(int j=0;j<n;j++){
				map[i][j]=val.front();
				val.pop();
		}
}
void swipL(vector<int> &val, int n,int map[20][20]){
	for(int i =0 ;i<n;i++)
		for(int j=n-1;j>-1;j--)
				val.push_back(map[i][j]);
}
void writeL(queue<int> &val, int n,int map[20][20]){
{
	for(int i =0;i<n;i++)
		for(int j=n-1;j>-1;j--){
				map[i][j]=val.front();
				val.pop();
		}
}
void swipD(vector<int> &val, int n,int map[20][20]){
	for(int i =0;i<n;i++)
		for(int j=0;j<n;j++)
				val.push_back(map[j][i]);
}
void writeD(queue<int> &val, int n,int map[20][20]){
	for(int i =0;i<n;i++)
		for(int j=0;j<n;j++){
				map[j][i]=val.front();
				val.pop();
		}
}
void swipU(vector<int> &val, int n,int map[20][20]){
	for(int i =0 ; i<n;i++)
		for(int j=n-1;j>-1;j--)
				val.push_back(map[j][i]);
}
void writeU(queue<int> &val, int n,int map[20][20]){
	for(int i =0;i<n;i++)
		for(int j=n-1;j>-1;j--){
				map[j][i]=val.front();
				val.pop();
		}
}
void mkvalues(vector<int> &val,int n,int d,int map[20][20])
{
	switch(d)
	{
	  case 0:
		  /*for(int i =0; i<n; i++){
			  for
			  val[i].i=n-1;
			  val[i].j=i;
			  val[i].val=map[n-1][i];
		  }*/
		  swipR(val,n,map)
		  break;
	  case 1:
		  swipL(val,n,map)
		  break;
	  case 2:
		  swipD(val,n,map)
		  break;
	  case 3:
		  swipU(val,n,map)
		  break;
  }
}
void move(int d, int n,int[20][20] map)
{
	vector<int> val;
	mkvaluse(val,n,d,map);
	queue<int> ret;
	int tmp;
	for(int i=0;i<n*n;i++)
	{
	  if(vector[i]==0){
		  continue;
	  }
	  else{
	  	tmp=vector[i];
		}

  }
}
int main()
{
	int tmp;
	cin >> tmp;
	int ans=2;
	for(int z=0;z<tmp;z++){
		int map[20][20] = {0,};
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
		{
		for(int j=0;j<n;j++)
			cin >> map[i][j];
	}
		for(int i=0;i<5;i++){
			for(int j=0;j<4;j++){
				for(int ind=0;ind<n;ind++){
					move(ind,j,n,map);
				}
			}

		}
	}
	return ans;
}
