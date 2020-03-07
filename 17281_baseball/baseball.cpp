#include<iostream>
#include<vector>
#include<algorithm>
#define debug
#define FILENAME "baseball_in.txt"
#define FILE_CIN
using namespace std;
int z;
int n;
vector<int> answer[2] = {{3,1,2,4,4,2,3,1,0},{2,4,3,1,2,4,3,0,1}};
vector<int> player[50];
vector<int> taza;
bool chek(){
    bool bb=true;
    for(int i=0;i<n;i++)
	for(int j=0;j<9;j++)
	    if(answer[i][j]!=player[i][j])
		bb=false;
    return bb;
}
int simul(int ind,int &indj){
    bool loota[3]={0,};
    int out=0;
    int res=0;
    int i=indj-1;
    while(true){
	i++;
	if(i>8)
	    i=0;
	int k=2,l=2;
	switch(player[ind][i]){
	    case 0:
		out++;
		break;
	    case 4:
		res++;
		for(int j=0;j<3;j++){
		    if(loota[j]){
			loota[j]=false;
			res++;
		    }
		}
		break;
	    case 1:
		l=1;
		break;
	    case 2:
		l=0;
		break;
	    case 3:
		l=-1;
		break;
	}
	if(out>2)
	    break;
	if(l<2){
	    for(int j=k;j>l;j--){
		if(loota[j]){
		    loota[j]=!loota[j];
		    res++;
		}
	    }
	    if(out>2)
		break;
	    for(int j=l;j>-1;j--){
		if(loota[j]){
		    loota[j]=!loota[j];
		    loota[j+player[ind][i]]=true;
		}
	    }
	    loota[player[ind][i]-1]=true;
	}
	/*
	if(chek()){
	    for(int j=2;j>-1;j--){
		cout<<loota[j]<<' ';
	    }
	    cout<<res<<' '<<i<<' '<<player[ind][i]<<endl;
	}
	*/
    }
    indj=i+1;
    return res;
}
void printn(int endi){
    for(int i=0;i<n;i++){
	for(int j=0;j<endi;j++)
	    cout<<player[i][j]<<' ';
	cout<<endl;
    }
    cout<<endl;
}
void swap(int i, int j){
    for(int ind=0;ind<n;ind++){
	int t=player[ind][i];
	player[ind][i]=player[ind][j];
	player[ind][j]=t;
    }
}
int recur_p(int lev){
    if(lev==8){
	int indj=0;
	int total=0;
	for(int i=0;i<n;i++)
	    player[i].insert(player[i].begin()+3,taza[i]);
	for(int i=0;i<n;i++){
	    total+=simul(i,indj);
	}
	for(int i=0;i<n;i++)
	    player[i].erase(player[i].begin()+3);
	return total;
    }
    else{
	int maxi=0;
	for(int i=lev;i<8;i++){
	    swap(i,lev);
	    int t=recur_p(lev+1);
	    maxi=max(t,maxi);
	    swap(i,lev);
	}
	return maxi;
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
	    vector<int> tmp2;
	    for(int i=0;i<n;i++){
		vector<int> tmp;
		for(int j=0;j<9;j++){
		    int t;
		    cin>>t;
		    if(j==0)
			tmp2.push_back(t);
		    else
			tmp.push_back(t);
		}
		player[i]=tmp;
	    }
	    taza=tmp2;
	    int total=recur_p(0);
	    cout<<total<<endl;
#ifdef FILE_CIN
	}
#endif
	return 0;
}
