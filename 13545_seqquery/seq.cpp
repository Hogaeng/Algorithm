#include<iostream>
#include<cmath>
#include<vector>
#define debug
#define FILENAME "seq_in.txt"
#define FILE_CIN

using namespace std;
struct Query{
    int lo;
    int hi;
};
int n;
bool c[100000];

int sz;

int cn;
int csqt[400]={0,};

int qn;
vector<Query> q;

void init(){
    sz=sqrt(n);
    for(int i=0;i<sz;i++)
	csqt[i]=0;
    for(int i=0;i<n;i++){
	if(c[i])
	    csqt[i/sz]+=1;
	else
	    csqt[i/sz]+=-1;
    }
    if(sz*sz<n)
	cn=sz+1;
    else
	cn=sz;

    for(int i=0;i<cn;i++)
	cout<<csqt[i]<<' ';
    cout<<endl;
}
void findit(){
    for(int i=0;i<qn;i++){
	int res=0;
	int lo=q[i].lo;
	int hi=q[i].hi;
	int l=q[i].lo/sz;
	int h=q[i].hi/sz;

	int st0ind=-1, end0ind=-1;
	int cnt0=0;
	int tst,tend,tcnt=0;
	for(int j=l;j<=h;j++){
	    if(csqt[j]==0){
		if(tcnt==0)
		    tst=j;
		tend=j;
		tcnt++;
	    }
	    else{
		if(tcnt>0){
		    if(cnt0<tcnt){
			cnt0=tcnt;
			st0ind=tst;
			end0ind=tend;
		    }
		    tcnt=0;
		}
	    }
	}
	//cout<<st0ind<<' '<<end0ind<<' '<<cnt0<<endl;
	for(int i=0;i<
    }
}
int main(){
#ifdef FILE_CIN
    freopen(FILENAME,"r",stdin);
    int tmp;
    cin>>tmp;
    for(int z=0;z<tmp;z++){
#endif
	cin>>n;
	for(int i=0;i<n;i++){
	    int t;
	    cin>>t;
	    if(t==1)
		c[i]=true;
	    else
		c[i]=false;
	}
	cin>>qn;
	for(int i=0;i<qn;i++){
	    Query tq;
	    cin>>tq.lo;
	    cin>>tq.hi;
	    tq.lo--;
	    tq.hi--;
	    q.push_back(tq);
	}
	init();
	findit();
#ifdef FILE_CIN
	cout<<endl;
    }
#endif
    return 0;
}
