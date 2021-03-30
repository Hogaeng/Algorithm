#include<iostream>
using namespace std;
int main(){
	freopen("baby_in3.txt","w",stdout);
	cout<<1<<endl;
	cout<<20<<endl;
	int fish=1;
	int state=2;
	int fishcnt=0;
	bool babyshark=false;
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			if(fish<7){
				cout<<fish<<' ';
				fishcnt++;
				if(fishcnt==state){
					fishcnt=0;fish++;state++;
				}
			}
			else
				if(!babyshark){
					babyshark=!babyshark;
					cout<<9<<' ';
				}
				else
					cout<<0<<' ';
		}
		cout<<endl;
	}
}
