#include<iostream>
#include<vector>
//#define debug
#define FILENAME "19236_broshark/broshark_in.txt"
#define FILE_CIN
using namespace std;
int dir[8][2]={{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};
const int shark=17;
int dfs(int bv[4][4], int bd[4][4], int vi, int vj){
	int answer=0;
	answer+=bv[vi][vj];
	bv[vi][vj]=shark;
	int sd=bd[vi][vj];
	for(int i=1;i<shark;i++){
		int x,y;
		bool flag=false;
		for(x=0;x<4;x++){
			for(y=0;y<4;y++)
				if(bv[x][y]==i){
					flag=true;
					break;
				}
			if(flag)
				break;
		}
		if(x==4 && y==4)
			continue;
		bool turnover=true;
		while(turnover){
			int dx=dir[bd[x][y]][0],dy=dir[bd[x][y]][1];
			int nx=x+dx,ny=y+dy;
			if(nx>-1&&nx<4&&ny>-1&&ny<4){
				if(bv[nx][ny]==0){
					bv[x][y]=0;
					bv[nx][ny]=i;

					bd[nx][ny]=bd[x][y];
					turnover=false;
				}
				else if(bv[nx][ny]==shark){
					bd[x][y]++;
					if(bd[x][y]>7)
						bd[x][y]=0;
				}
				else{
					int tmp=bv[nx][ny];
					bv[nx][ny]=bv[x][y];
					bv[x][y]=tmp;

					tmp=bd[nx][ny];
					bd[nx][ny]=bd[x][y];
					bd[x][y]=tmp;

					turnover=false;
				}

			}
			else{
				bd[x][y]++;
				if(bd[x][y]>7)
					bd[x][y]=0;
			}
		}
#ifdef debug
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(bv[i][j]/10==0)
				cout<<' ';
			cout<<bv[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
#endif
	}
	vector<pair<int,int> > candi;
	int di=dir[sd][0],dj=dir[sd][1];
	int ni=vi+di,nj=vj+dj;
	while(ni>-1&&ni<4&&nj>-1&&nj<4){
		if(bv[ni][nj]>0)
			candi.push_back(make_pair(ni,nj));
		ni+=di;nj+=dj;
	}
	int answerb=0;
	for(int i=0;i<candi.size();i++){
		int bv_clone[4][4], bd_clone[4][4];
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++){
				bv_clone[i][j]=bv[i][j];
				bd_clone[i][j]=bd[i][j];
			}
		bv_clone[vi][vj]=0;
		int tmp=dfs(bv_clone,bd_clone,candi[i].first,candi[i].second);
		answerb=max(tmp,answerb);
	}
	return answer+answerb;
}
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
		int bv[4][4];
		int bd[4][4];
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++){
				int a,b;
				cin>>a>>b;
				bv[i][j]=a;
				bd[i][j]=b-1;
			}
		int answer=0;
		answer=dfs(bv,bd,0,0);
		cout<<answer<<endl;
#ifdef FILE_CIN
	}
#endif
	return 0;
}
