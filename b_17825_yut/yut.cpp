#include<iostream>
#include<fstream>
using namespace std;
int input[10]={0,};
ofstream wf;
void write(){
    //freopen("yut_in4.txt","w",stdout);
    for(int i=0;i<10;i++)
	wf<<input[i]<<' ';
    wf<<'\n';
}
void recur(int in, int im, int lm, int lv){
    if(lv==lm){
	write();
	return;
    }
    else
	for(int i=in;i<=im;i++){
	    if(lv==0)
		cout<<i;
	    input[lv]=i;
	    recur(in,im,lm,lv+1);
	}
    return;
}
int main(){
    wf.open("yut_in4.txt",fstream::out);
    wf.close();
    wf.open("yut_in4.txt",fstream::out|fstream::app);
    int n=5;
    int in=1;
    int a=1;
    for(int i=0;i<10;i++)
	a*=n;
    wf<<a<<'\n';
    recur(in,n,10,0);
    wf.close();
}
