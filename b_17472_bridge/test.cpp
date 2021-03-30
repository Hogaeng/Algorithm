#include<iostream>
using namespace std;
//조합
void comb(int r, int c, int lev,int ind,int check[10]){
    if(lev==c){
	for(int i=0;i<r;i++){
	    if(check[i])
		cout<<check[i]<<' ';
	}
	cout<<endl;
    }
    else{
	for(int i=ind;i<r;i++){
	    check[lev]=i+1;
	    comb(r,c,lev+1,i+1,check);
	    check[lev]=0;
	}
    }
}
//중복조합
void combrepet(int r,int c, int lev, int ind,int check[10]){
    if(lev==c){
	for(int i=0;i<r;i++){
	    if(check[i])
		cout<<i<<' ';
	}
	cout<<endl;
    }
    else{
	for(int i=ind;i<r;i++){
	    check[lev]=i+1;
	    comb(r,c,lev+1,i,check);
	    check[lev]=0;
	}
    }
}
//순열
void permrepet(int r,int c, int lev,int check[10]){
    if(lev==c){
	for(int i=0;i<r;i++){
	    if(check[i])
		cout<<i<<' ';
	}
	cout<<endl;
    }
    else{
	for(int i=0;i<r;i++){
	    check[lev]=i+1;
	    comb(r,c,lev+1,i,check);
	    check[lev]=0;
	}
    }
}
int main(void){
    int check[10]={0,};

    comb(4,2,0,0,check);
    cout<<endl;

    combrepet(4,2,0,0,check);

    bool checkb[10]={0,};

    perm(4,2,0,0,check);
    permrepet(4,2,0,0,check);
}
