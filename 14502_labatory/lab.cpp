#include<iostream>
#include<vector>
#define debug
#define FILENAME "lab_in.txt"
#define FILE_CIN
using namespace std;
int ib,jb;
int dir[4][2]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
vector<vector<int> > vir;
vector<vector<int> > vir_raw;
int check(int lab[8][8]){
    int answer=0;
    for(int i=0;i<ib;i++)
	for(int j=0;j<jb;j++)
	    if(lab[i][j]==0)
		answer++;
    return answer;
}
void printlab(int lab[8][8]){
    for(int i=0;i<ib;i++){
	for(int j=0;j<jb;j++)
	    cout<<lab[i][j]<<' ';
	cout<<endl;
    }
    cout<<endl;
}
void spread(int lab[8][8]){
    //cout<<"spread"<<vir.size()<<endl;
    int vs=vir.size();
    for(int z=0;z<4;z++){
	int di=dir[z][0];
	int dj=dir[z][1];
	for(int v=0;v<vs;v++){
	    int i=vir[v][0];
	    int j=vir[v][1];
	    if(i+di<ib && i+di>-1 && j+dj<jb && j+dj>-1)
		if(lab[i+di][j+dj]==0){
		    lab[i+di][j+dj]=2;
		    vector<int> tmp;
		    tmp.push_back(i+di);
		    tmp.push_back(j+dj);
		    vir.push_back(tmp);
		}
	}
    }
    vir.erase(vir.begin(),vir.begin()+vs);
    //cout<<"spreadend"<<vir.size()<<endl;
}
int recur(int lev, int ie, int je,int lab[8][8]){
    int tlab[8][8];
    for(int i=0;i<ib;i++)
	for(int j=0;j<jb;j++)
	    tlab[i][j]=lab[i][j];
    if(lev==0){
	while(vir.size()>0)
	    spread(tlab);
	vir=vir_raw;
	int tt=check(tlab);
	return tt;
    }
    else{
	int answer=0;
	int tt=0;
	for(int i=ie;i<ib;i++)
	    for(int j=i==ie?je:0;j<jb;j++){
		if(tlab[i][j]==0){
		    tlab[i][j]=1;
		    if(j==jb-1)
			tt=recur(lev-1,i+1,0,tlab);
		    else
			tt=recur(lev-1,i,j+1,tlab);
		    tlab[i][j]=0;
		    if(answer<tt)
			answer=tt;
		}
	    }
	return answer;
    }
}

int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
	    int lab[8][8]={0,};
	    cin>>ib;
	    cin>>jb;
	    for(int i=0;i<ib;i++)
		for(int j=0;j<jb;j++){
		    cin>>lab[i][j];
		    if(lab[i][j]==2){
			vector<int> vp;
			vp.push_back(i);
			vp.push_back(j);
			vir.push_back(vp);
		    }
		}
	    vir_raw=vir;
	    cout<<recur(3,0,0,lab)<<'\n';
	    vir.clear();
#ifdef FILE_CIN
	}
#endif
	return 0;
}
