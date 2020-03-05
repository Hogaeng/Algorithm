#include<iostream>
#define MAX 1000000
using namespace std;
int A[MAX] = {-1,};
int nA;
int B,C;
long long ret;
int main(){
	freopen("superv_in2.txt","r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
		ret=0;
		cin>>nA;
		for(int i=0;i<nA;i++)
			cin>>A[i];
		cin>>B;
		cin>>C;
		for(int i=0;i<nA;i++){
			A[i]-=B;
			ret++;
			if(A[i]<1)
				continue;
			ret+=A[i]/C;
			if(A[i]%C>0)
				ret++;
		}
		cout<<ret;
	}
	return 0;
}
