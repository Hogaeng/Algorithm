#include<iostream>
#include<typeinfo>
using namespace std;
int main(void){
    long long cnt=0;
    int n=36;
    int m=18;
    for(int i=1;i<=m;i++){
        float son=1,mom=1;
        for(int j=0;j<i;j++)
            son*=n-j;
        for(int j=1;j<=i;j++)
            mom*=j;
        cnt=son/mom;
        //cout<<son<<' '<<mom<<endl;
        cout<<son/mom<<endl;
        cnt=0;
        //cout<<typeid(cnt).name()<<endl;
    }
}