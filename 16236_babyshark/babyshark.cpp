//첫번째 문제점. 바둑판 배열 케이스에서 에러가 남. 아기상어가 원판 바깥으로 넘어가는 문제. y<n를 ny<n으로 고침. &&의 띄어쓰기가 안되어 확인이 안된 실수
//두번째 문제점. 위의 상황을 반면교사 삼아 코드를 보고 찾아냄. 먹이후보군에서 최종 먹이를 찾기 위한 조건문에서 ocean[x][y]>=ocean[tx][ty]을 ocean[tx][ty]<state로 바꿈. 최초 바뀌었을 때는 상관없지만, 두번째 이후로는 전보다 작은 물고기를 최종 먹이로 채택할 가능성이 있으며 이는 있어서는 안되는 조건이다.
#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
#define FILE_CIN
#define FILE_NAME "baby_in.txt"
//#define debug_z 1
//#define debug
using namespace std;
int z=0;
vector<pair<int,int> > vec;
vector<int> veccnt;
int ocean[20][20] ={0,};
int eocean[20][20] ={0,};
int n=0;
int state=2;
int stomach=0;
int tt=0;
int bx=0,by=0;
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
//int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
void printeocean(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<eocean[i][j]<<' ';
		cout<<endl;
	}
}
void printocean(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<ocean[i][j]<<' ';
		cout<<endl;
	}
	cout<<'s'<<state<<endl;
}
void wipee(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			eocean[i][j]=0;
	vec.clear();
	veccnt.clear();
}
void wipe(){
	stomach=0;
	state=2;
	tt=0;
	wipee();
}
void eat(int x, int y){
	ocean[x][y]=9;
	ocean[bx][by]=0;
	bx=x;
	by=y;
	stomach++;
	if(stomach==state){
		stomach=0;
		state++;
		if(state>9)
			state=9;
	}
#ifdef debug
	//printocean();
#endif
}
int bfs2(){
#ifdef debug
#ifdef debug_z
	if(z==debug_z){
#endif
	for(int i=0;i<vec.size();i++)
		cout<<vec[i].first<<':'<<vec[i].second<<' ';
	cout<<endl;
	for(int i=0;i<vec.size();i++)
		cout<<"  "<<veccnt[i]<<' ';
	cout<<endl;
	//printeocean();
#ifdef debug_z
	}
#endif
#endif
	int N=INT_MAX;
	int x,y,t;
	if(vec.size()>0){
		x=vec[0].first;y=vec[0].second;vec.erase(vec.begin());
		t=veccnt[0];veccnt.erase(veccnt.begin());
	}
	else
		return N;
	if(ocean[x][y]>0 && ocean[x][y]<state){
		for(int i=0;i<vec.size();i++){
			int tx=vec[i].first, ty=vec[i].second, tc=veccnt[i];
			if(t>tc){
					x=tx;y=ty;t=tc;
			}
			else if(ocean[tx][ty]<state && ocean[tx][ty]>0 && t==tc)
				if(x>tx || (x==tx && y>ty)){
					x=tx;y=ty;t=tc;
				}
		}
		eat(x,y);
		return t;
	}
	if(ocean[x][y]<9 && ocean[x][y]>state)
		return N;
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0], ny=y+dir[i][1];
		if(nx>-1&&nx<n && ny>-1&&ny<n && eocean[nx][ny]==0){
			eocean[nx][ny]=1;
			vec.push_back(pair<int,int>(nx,ny));
			veccnt.push_back(t+1);
		}
	}
	return N;
}
int bfs(){
	int m;
#ifdef debug
#ifdef debug_z
	if(z==debug_z){
#endif
		cout<<"tt"<<tt<<endl;
		cout<<"bs"<<bx<<'-'<<by<<endl;
		for(int j=0;j<vec.size();j++){
			cout<<'t'<<vec[j].first<<':'<<vec[j].second<<' ';
			cout<<'c'<<veccnt[j]<<' ';
			cout<<endl;
		}
		cout<<endl;
		printocean();
#ifdef debug_z
	}
#endif
#endif
	for(;vec.size()>0;)
		if((m=bfs2())!=INT_MAX){
			wipee();
			return m;
		}
	return INT_MAX;
}
int main(){
#ifdef FILE_CIN
	freopen(FILE_NAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(z=0;z<tmp;z++){
#endif
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>ocean[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(ocean[i][j] == 9){
					bx = i;
					by = j;
				}
		while(true){
			vec.push_back(pair<int,int>(bx,by));
			eocean[bx][by]=1;
			veccnt.push_back(0);
			int tmp;
			if((tmp=bfs())==INT_MAX)
				break;
			else{
				tt+=tmp;
			}
		}
#ifdef debug_z
		if(z==debug_z)
#endif
			cout<<tt<<'\n';
#ifdef debug
#ifdef debug_z
		if(z==debug_z)
#endif
			printocean();
#endif
#ifdef FILE_CIN
		wipe();
	}
#endif
	return 0;
}
