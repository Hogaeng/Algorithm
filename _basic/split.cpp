#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
void stringfind(string s,string fs,vector<string> &sv){
    string::size_type cursor;
    cursor = s.find(fs);
    if(cursor == string::npos)
	sv.push_back("noting");
    else
	sv.push_back(s.substr(cursor,fs.size()));
    //sv.push_back(as.substr(previous, current - previous));
    //출처: https://makedotworld.tistory.com/28 [옥토의 학습저널]
}
void split(string s,vector<string> &sv){
    istringstream ss(s);
    string t;
    while(getline(ss, t,'_'))
	sv.push_back(t);
}
void vectorfind_replace(int fi, vector<int> &iv){
    auto it = find(iv.begin(),iv.end(),fi);
    int ind = distance(iv.begin(),it);
    for(;it!=iv.end();){
	it = find(iv.begin(),iv.end(),fi);
	ind = distance(iv.begin(),it);
	iv[ind]=fi+10;
    }
}
int main(){
    string s="hello_im_human";
    string s2="hello,_im,_human";
    vector<string> sv;
    vector<string> sv2;
    vector<int> iv;
    for(int i=0;i<10;i++)
	iv.push_back(i%3);
	
    split(s,sv);
    stringfind(s2,"im",sv2);
    vectorfind_replace(2,iv);

    for(int i=0;i<sv.size();i++)
	cout<<sv[i]<<' ';
    cout<<'\n';

    for(int i=0;i<sv2.size();i++)
	cout<<sv2[i]<<' ';
    cout<<'\n';

    for(int i=0;i<iv.size();i++)
	cout<<iv[i]<<' ';
    cout<<'\n';
}
