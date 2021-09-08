#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    vector<vector<int> > v{vector<int> {3,4,5},vector<int> {3,5,6},vector<int> {1,3,4},vector<int> {1,2,3}};
    for(int i=0;i<v.size();i++)cout<<v[i][0]<<v[i][1]<<v[i][2]<<endl;
    cout<<endl;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)cout<<v[i][0]<<v[i][1]<<v[i][2]<<endl;
}