#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void split_substr(string s,string deli,vector<string> &sv){
    size_t cursor;
    cursor = s.find(deli);
    //string::npos는 string의 가장 큰 인덱스 값을 의미.
    //string::npos의 타입 string::size_type는 (size_t라고도 함) unsigned integer이므로 -1이 가장 큰값이다.
    if(cursor == string::npos)
	    sv.push_back("nothing");
    else
	    sv.push_back(s.substr(cursor,deli.size()));
    //sv.push_back(as.substr(previous, current - previous));
    //출처: https://makedotworld.tistory.com/28 [옥토의 학습저널]
}
void split_sstream(string s,vector<string> &sv){
    istringstream ss(s);
    string t;
    while(getline(ss, t,'_'))
	    sv.push_back(t);
}
void split_find_distance(int fi, vector<int> &iv){
    auto it = find(iv.begin(),iv.end(),fi);
    int ind = distance(iv.begin(),it);
    for(;it!=iv.end();){
        it = find(iv.begin(),iv.end(),fi);
        ind = distance(iv.begin(),it);
        iv[ind]=fi+10;
    }
}
int main(){
    //스플릿 할 스트링
    string s="hello_im_human";
    string s2="hello,_im,_human";
    //스플릿 받을 벡터
    vector<string> sv;
    vector<string> sv2;
    //0,1,2,0,1,2,0,1,2,0이 들어갈 벡터
    vector<int> iv;
    for(int i=0;i<10;i++)
    	iv.push_back(i%3);
	
    split_sstream(s,sv);
    for(int i=0;i<sv.size();i++)
	    cout<<sv[i]<<' ';
    cout<<'\n';
    
    split_substr(s2,"im",sv2);
    for(int i=0;i<sv2.size();i++)
	    cout<<sv2[i]<<' ';
    cout<<'\n';

    split_find_distance(2,iv);
    for(int i=0;i<iv.size();i++)
    	cout<<iv[i]<<' ';
    cout<<'\n';
}
