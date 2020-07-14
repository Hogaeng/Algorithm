#include<iostream>
using namespace std;
int main(){
	freopen("ladder_in2.txt","w",stdout);
	cout<<1<<'\n';
	cout<<10<<' '<<150<<' '<<30<<'\n';
	for(int i=1;i<=30;i++){
		for(int j=1;j<=9;j++){
			if(i%2==1){
				if(j%2==1)
					cout<<i<<' '<<j<<'\n';
			}
			else{
				if(j%2==0)
					cout<<i<<' '<<j<<'\n';
			}
		}
	}
	return 0;
}
