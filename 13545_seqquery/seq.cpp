#include<iostream>
#include<cmath>
#define debug
#define FILENAME "seq_in.txt"
#define FILE_CIN

using namespace std;
int qb[400]={0,};//구간의 시작 
int qe[400]={0,};//구간의 끝
int qv[400]={0,};//구간의 값
//int qi[400]={0,};//구간의 순서
bool c[100000]={0,};
int n,qn,qs;

void makeit(){
    qn=sqrt(n);
    qs=n-qn*qn;
    for(int i=0;i<qn;i++){
	int cnt=0;
	int j;
	for(j=0;i==qn-1?j<qn:j<qn+qs;j++){
	    cnt+=c[i*qn+j];
	}
	qb[i]=i*qn;
	qe[i]=i*qn+j-1;
	qv[i]=cnt;
    }
}
int findit(int t1,int t2){
    int b=t1/qn,e=t2/qn;
    int cnt=qv[b]+qe[e];
    return cnt;
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
	makeit();
	int s;
	cin>>s;
	for(int i=0;i<s;i++){
	    int t1,t2;
	    cin>>t1;
	    cin>>t2;
	    cout<<findit(t1,t2)<<endl;
	}
#ifdef FILE_CIN
    }
#endif
    return 0;
}
