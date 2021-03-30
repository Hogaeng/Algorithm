#include<iostream>
#include<vector>
using namespace std;
int main(void){
    vector<int> t;
    for(int i=0;i<10;i++)
	t.push_back(i);

    t.insert(t.begin()+4,11);

    for(int i=0;i<t.size();i++)
	cout<<t[i]<<endl;

    t.erase(t.begin()+4);

    for(int i=0;i<t.size();i++)
	cout<<t[i]<<endl;
}
