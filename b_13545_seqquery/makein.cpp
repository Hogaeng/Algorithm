#include<iostream>
#define N 100000
using namespace std;
int main(){
	freopen("seq_in3.txt","w",stdout);
	cout<<1<<'\n';
	cout<<N<<'\n';
	for(int i=0;i<N/2-1;i++)
		cout<<1<<' ';
	cout<<1<<' ';
	cout<<-1<<' ';
	for(int i=N/2+1;i<N;i++)
		cout<<1<<' ';
	cout<<'\n'<<1<<'\n'<<1<<' '<<N;
}
