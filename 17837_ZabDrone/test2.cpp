#define N 100000000
#include<vector>
#include<ctime>
#include<iostream>
using namespace std;
int main(void){
    clock_t s;
    s=clock();
    vector<int> milion;
    vector<int> milion_raw;
    for(int i=0;i<N;i++)
	milion.push_back(i);
    cout<<"insert_end"<<endl;
    cout<<(float)(clock()-s)/CLOCKS_PER_SEC<<endl;
    
    milion_raw=milion;

    s=clock();
    for(int i=0;i<100;i++)
	milion.erase(milion.begin());
    cout<<"erase_end1"<<endl;
    cout<<(float)(clock()-s)/CLOCKS_PER_SEC<<endl;

    milion=milion_raw;
    //cout<<milion.size()<<endl;

    s=clock();
    for(int i=0;i<100;i++)
	milion.erase(milion.begin()+milion.size()/2);
    cout<<"erase_end2"<<endl;
    cout<<(float)(clock()-s)/CLOCKS_PER_SEC<<endl;

    milion=milion_raw;
    //cout<<milion.size()<<endl;

    s=clock();
    for(int i=0;i<100;i++)
	milion.erase(milion.begin()+milion.size()/2);
    cout<<"erase_end2"<<endl;
    cout<<(float)(clock()-s)/CLOCKS_PER_SEC<<endl;
}
