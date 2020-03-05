#define N 100000000
#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;
int main(void){

    /*
    for(int i=1;i<=N;i*=10){
	vector<int> t;
	t.reserve(N);
	clock_t s=clock();
	for(int j=0;j<i;j++)
	    t.push_back(j);
	cout<<i<<' '<<(float)(clock()-s)/CLOCKS_PER_SEC<<' '<<t[N-1]<<endl;
    }
    */

    /*
    //천만부터 안됨
    for(int i=1;i<=N;i*=10){
	int arr[i];
	clock_t s=clock();
	for(int j=0;j<i;j++)
	    arr[j]=j;
	cout<<i<<' '<<(float)(clock()-s)/CLOCKS_PER_SEC<<endl;
    }
    */

    /*
    int *arr=new int(N);
    arr[N-1]=100;
    cout<<(int)arr[N-1]<<endl;
    */
    char *arr=(char*)malloc(INT_MAX);
    arr[INT_MAX-1]=100;
    cout<<(int)arr[INT_MAX-1]<<endl;

    /*
    int i=N/100;
    char arr[i];
    arr[i-1]=100;
    cout<<(int)arr[i-1]<<endl;
    */
}

