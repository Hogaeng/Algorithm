#include<iostream>
#include<vector>
using namespace std;
int main(void){
    int n=8;
    int arr[]= {1,2,5,8,9,9,10,11};
    int x=11;
    vector<int> A(arr,arr+n);
    int l=0,r=n-1;
    while(l<r){
        int m=(l+r)/2;
        if(x<A[m]){
            r=m-1;
            //r==-1?r=0:r=m-1;
        }
        else{
            l=m;
            l==m?(A[m]==x?r=m:l=m+1):l=m;
        }
    }
    if(A[l]==x)
    
        cout<<l<<endl;
    else
    {
        cout<<-1<<endl;
    }
    
    
}