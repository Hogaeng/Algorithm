#include<iostream>
#include<vector>
#include<algorithm>
#define debug
#define FILENAME "baseball_in.txt"
#define FILE_CIN
using namespace std;
int n;
vector<int> player[50];
int simul(int ind, int &indj){
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
		    if(loota[j])
			res++;
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
	for(int j=2;j>-1;j--){
	    cout<<loota[j]<<' ';
	}
	cout<<res<<' '<<i<<endl;
	*/
    }
    indj=i+1;
    return res;
}
/*
void swap(int i, int j,int ind){
    int t=player[ind][i];
    player[ind][i]=player[ind][j];
    player[ind][j]=t;
}
int recur_p(int ind,int lev, int &indj){
    if(lev==9){
	return simul(ind,indj);
    }
    else{
	int maxi=0;
	for(int i=lev;i<9;i++){
	    swap(i,lev,ind);
	    int t=recur_p(ind,lev+1,indj);
	    maxi=max(t,maxi);
	    swap(i,lev,ind);
	}
	return maxi;
    }
}
*/
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
	    cin>>n;
	    for(int i=0;i<n;i++){
		vector<int> tmp;
		for(int j=0;j<9;j++){
		    int t;
		    cin>>t;
		    tmp.push_back(t);
		}
		player[i]=tmp;
	    }
	    int total=0;
	    int indj=0;
	    for(int i=0;i<n;i++){
		rearrange(i,indj);
		total+=simul(i,indj);
	    }
	    cout<<total<<endl;
#ifdef FILE_CIN
	}
#endif
	return 0;
}
