#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    vector<int> t;
    int ttt=342413;
    t.push_back(1);
    t.push_back(ttt);
    t.push_back(ttt);
    auto tt=find(t.begin(),t.end(),ttt);
    cout<<*tt<<endl;
    
    int idx=distance(t.begin(),tt);
    cout<<idx<<endl;

}
