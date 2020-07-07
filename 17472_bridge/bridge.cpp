#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#define debug
#define FILENAME "bridge_in3.txt"
#define FILE_CIN
using namespace std;
int m,n;
int board[10][10];
int cn;
void printb(){
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++)
	    cout<<board[i][j]<<' ';
	cout<<endl;
    }
    cout<<endl;
}
void bfs(int i,int j,int cl){
    int dir[4][2]={
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
    };
    board[i][j]=cl;
    vector<int> is;
    is.push_back(i);
    vector<int> js;
    js.push_back(j);
    while(!is.empty()){
	int x=is[0];
	int y=js[0];
	is.erase(is.begin());
	js.erase(js.begin());
	for(int z=0;z<4;z++)
	{	
	    int dx=dir[z][0];
	    int dy=dir[z][1];
	    if(x+dx<n && x+dx>-1 && y+dy<m && y+dy>-1){
		dx+=x;dy+=y;
		if(board[dx][dy]==7){
		    board[dx][dy]=cl;
		    is.push_back(dx);
		    js.push_back(dy);
		}
	    }
	}
    }
}
bool check(vector<int> &choice){
    //Island bridge lookup table
    vector<int> conn[7];
    //max num island is 6
    //start at 1, 
    for(int i=0;i<choice.size()-1;i+=2){
	conn[choice[i]].push_back(choice[i+1]);
	conn[choice[i+1]].push_back(choice[i]);
    }
    //bfs로 모든 섬이 이어지는지 확인
    //모든 섬에서부터 하나씩 시작해본다.
    vector<int> q;
    for(int i=1;i<cn;i++){
	bool visited[7]={0,};
	int cnt=1;
	q.push_back(i);
	visited[i]=true;
	while(!q.empty()){
	    int tmp=q[0];
	    q.erase(q.begin());
	    for(int j=0;j<conn[tmp].size();j++){
		//다음 방문한 섬이 방문하지 않은 새로운 섬이면
		//방문했다는 표시를 하고 큐에 집어넣는다.
		if(!visited[conn[tmp][j]]){
		    visited[conn[tmp][j]]=true;
		    q.push_back(conn[tmp][j]);
		}
	    }
	    //방문한 섬은 세어준다.
	    //여기서 세어줘도 새로 방문한 곳만 센다.
	    cnt++;
	}
	if(cnt==cn)
	    return true;
    }
    return false;
}
int comb (int lev,int ind,vector<vector<int> > &brr, vector<vector<int> > &brc, vector<int> &choice) {
    if(lev==0){
	int tmp=0;
	vector<int> checker;
	//섬이 이어진 시작, 끝을 checker에 넣기
	for(int i=0;i<choice.size();i++){
	    if(choice[i]<brr.size()){
		checker.push_back(brr[choice[i]][0]);
		checker.push_back(brr[choice[i]][1]);
		tmp+=brr[choice[i]][2];
	    }
	    else{
		checker.push_back(brc[choice[i]-brr.size()][0]);
		checker.push_back(brc[choice[i]-brr.size()][1]);
		tmp+=brc[choice[i]-brr.size()][2];
	    }
	}
	//모든 섬이 이어지는지 확인
	if(check(checker))
	    return tmp;
	else
	    return INT_MAX;
    }
    else{
	int mini=INT_MAX;
	for(int i=ind;i<brr.size()+brc.size();i++){
	    choice.push_back(i);
	    mini=min(mini,comb(lev-1,i+1,brr,brc,choice));
	    choice.erase(choice.end()-1);
	}
	return mini;
    }
}
void makeit(vector<vector<int> > &brp, bool iscolum){
    int in=n,jm=m;
    if(iscolum){
	in=m;jm=n;
    }
    for(int i=0;i<in;i++){
	int cnt=0;
	int bf=0;
	for(int j=0;j<jm;j++){
	    int b=board[i][j];;
	    if(iscolum)
		b=board[j][i];
	    if(b==0){
		cnt++;
	    }
	    else{
		if(bf!=0 && cnt>1 && bf!=b){
		    vector<int> tmp;
		    tmp.push_back(bf);
		    tmp.push_back(b);
		    tmp.push_back(cnt);
		    brp.push_back(tmp);
		}
		bf=b;
		cnt=0;
	    }
	}
    }
    for(int i=0;i<brp.size();i++){
	vector<int> dels;
	bool t=true;
	for(int j=i+1;j<brp.size();j++){
	    for(int k=0;k<3;k++)
		if(brp[i][k]!=brp[j][k])
		    t=false;
	    if(t)
		dels.push_back(j);
	    else
		t=true;
	}
	for(int j=dels.size()-1;j>-1;j--)
	    brp.erase(brp.begin()+dels[j]);
    }
}
void bridges(){
    //모든 다리 그리기
    vector<vector<int> > brr;
    vector<vector<int> > brc;
    //printb();
    makeit(brr,false);
    makeit(brc,true);

    /*
    for(int i=0;i<brr.size();i++)
	cout<<brr[i][0]<<' '<<brr[i][1]<<' '<<brr[i][2]<<endl;
    cout<<'n'<<endl;
    for(int i=0;i<brc.size();i++)
	cout<<brc[i][0]<<' '<<brc[i][1]<<' '<<brc[i][2]<<endl;
    */

    //다리 조합 하기
    int mini=INT_MAX;
    for(int i=1;i<=brc.size()+brr.size();i++){
	vector<int> checker;
	mini=min(comb(i,0,brr,brc,checker),mini);
    }
    if(mini!=INT_MAX)
	cout<<mini<<endl;
    else
	cout<<-1<<endl;
}
void color(){
    //섬에 색칠하는 코드
    int cnt=1;
    for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	    if(board[i][j]==7){
		bfs(i,j,cnt);
		cnt++;
	    }
    cn=cnt;
    bridges();
}
int main(){
#ifdef FILE_CIN
    freopen(FILENAME,"r",stdin);
    int tmp;
    cin>>tmp;
    for(int z=0;z<tmp;z++){
#endif
	cin>>n>>m;
	for(int i=0;i<n;i++)
	    for(int j=0;j<m;j++){
		int tmp;
		cin>>tmp;
		if(tmp==1)
		    tmp=7;
		board[i][j]=tmp;
		}
	color();

#ifdef FILE_CIN
    }
#endif
    return 0;
}
