#include<iostream>
using namespace std;
int main(void){
    int m=1;
    bool tt[m];
    for(int i=0;i<m;i++)
	cout<<tt[i]<<' ';
    cout<<endl;
    cout<<sizeof(tt)<<endl;
}
