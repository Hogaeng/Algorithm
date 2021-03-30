//recursive의 벡터 thr을 생성해야한다.
//원복시키는 기능도 추가해야함
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int board[20][20]={0,};
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
enum {U,R,D,L};
void combThr(int n,vector<int> *thr){
	for(int i=0;i<n;i++){
		queue<int> que;
		for(int j=0;j<thr[i].size();j++){
			que.push(thr[i][j]);
		}
		thr[i].clear();
		for(;que.size()>0;){
			int tmp=que.front();
			que.pop();
			if(tmp==0){
				continue;
			}
			else if(tmp==que.front()){
				thr[i].push_back(tmp*2);
				que.pop();
			}
			else{
				thr[i].push_back(tmp);
			}
		}
		for(int j=0;j<n-thr[i].size();j++)
			thr[i].push_back(0);
	}
}
void collectThr(int d, int n, vector<int> *thr){
	int i=0,j=0;
	switch(d){
		case U:
			i=n-1;
			j=0;
			break;
		case R:
			i=0;
			j=0;
			break;
		case D:
			i=0;
			j=0;
			break;
		case L:
			i=0;
			j=n-1;
			break;
	}
	for(int k=0;k<n;k++){
		for(int l=0;l<n;l++){
			thr[k].push_back(board[i][j]);
			i+=dir[d][0];
			j+=dir[d][0];
		}
	}
	combThr(n,thr);
}
void recur(int lv, int n){
	if(lv==0)
		return;
	for(int i=0;i<4;i++){
	}
	cout<<lv<<'\n';
	recur(lv-1);
}
int main(){
	freopen("twotwo_in.txt","r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>board[i][j];
		//recur(5);
		int i=0;
		thr[i].push_back(2);
		thr[i].push_back(2);
		thr[i].push_back(2);
		thr[i].push_back(0);
		thr[i].push_back(0);
		thr[i].push_back(2);
		thr[i].push_back(2);
		combThr(1);
		for(int j=0;j<thr[0].size();j++)
			cout<<thr[0][j]<<endl;
	}
	return 0;
}
