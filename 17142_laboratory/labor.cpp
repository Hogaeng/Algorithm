#include<iostream>
#include<vector>
#include<climits>
#define debug
#define FILENAME "labor_in.txt"
#define FILE_CIN
using namespace std;
int n;
int r;
int board[50][50];
vector<int> vir;
vector<int> sel;
int mini=INT_MAX;
int z;
int dir[4][2]={
    {1,0},
    {0,1},
    {-1,0},
    {0,-1},
};
void printsel(){
    for(int i=0;i<sel.size();i++){
	cout<<sel[i]<<' ';
    }
    cout<<endl;
}
bool check(int cb[50][50]){
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    if(cb[i][j]==0)
		return false;
	}
    }
    if(z==4){
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
		cout<<cb[i][j]<<' ';
	    }
	    cout<<endl;
	}
	cout<<endl;
    }
    return true;
}
int bfs(){
    int cnt=0;
    vector<vector<int> > que;
    que.push_back(sel);
    int cboard[50][50];
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    cboard[i][j]=board[i][j];
	}
    }
    while(que.size()>0){
	vector<int> subque=que[0];
	vector<int> newsq;
	que.erase(que.begin());
	while(subque.size()>0){
	    if(z==4)
		cout<<subque.size()<<endl;
	    int i=subque[0];
	    int j=subque[1];
	    subque.erase(subque.begin());
	    subque.erase(subque.begin());
	    for(int k=0;k<4;k++){
		int di=i+dir[k][0];
		int dj=j+dir[k][1];
		if(di>-1&&di<n&&dj>-1&&dj<n){
		    if(cboard[di][dj]==1)
			continue;
		    else{
			cboard[di][dj]=2;
			newsq.push_back(di);
			newsq.push_back(dj);
		    }
		}
	    }
	}
	cnt++;
	if(check(cboard))
	    return cnt;
	if(newsq.size()>0)
	    que.push_back(newsq);
    }
    return INT_MAX;
}
void comb(int ind, int lev){
    if(lev==r){
	int cnt=bfs();
	mini=min(mini,cnt);
	//printsel();
    }
    else{
	for(int i=ind;i<vir.size();i+=2){
	    sel.push_back(vir[i]);
	    sel.push_back(vir[i+1]);
	    comb(i+2,lev+1);
	    sel.erase(sel.end()-1);
	    sel.erase(sel.end()-1);
	}
    }
}
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(z=0;z<tmp;z++){
#endif
	    cin>>n;
	    cin>>r;
	    for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		    cin>>board[i][j];
		    if(board[i][j]==2){
			vir.push_back(i);
			vir.push_back(j);
		    }
		}
	    }
	    comb(0,0);
	    if(mini==INT_MAX)
		cout<<-1<<endl;
	    else
		cout<<mini<<endl;
#ifdef FILE_CIN
	    vir.clear();
	    sel.clear();
	    mini=INT_MAX;
	}
#endif
	return 0;
}
