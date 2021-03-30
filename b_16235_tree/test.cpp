#include<vector>
#include<iostream>
using namespace std;
int main(){
	vector<int> vec;
	vec.push_back(0);
	vec.erase(vec.begin()+0,vec.end());
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<' ';
}
