#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> start;
vector<int> ended;
vector<int> bar;
int check(int s, int e, int k){
    if(s>=86399000+3000)
        e=86400000+3000;
    bool cnts[start.size()];
    for(int i=0;i<start.size();i++)
        cnts[i]=false;
    for(int j=0;j<start.size();j++){
        if( (s<=start[j] && e>=start[j]) || (s<=ended[j] && e>=ended[j]) || (start[j]<s && e<ended[j]) )
            cnts[j]=true;
    }
    int cntt=0;
    for(int i=0;i<start.size();i++)
        if(cnts[i])
            cntt++;
    //cout<<s<<' '<<e<<' '<<cntt<<endl;
    return cntt;
}
int solution(vector<string> lines) {
    int answer = 0;
    cout<<fixed;
    cout.precision(3);
    
    for(int i=0;i<lines.size();i++){
        string tmp2=lines[i].substr(11,23);
        int h=1000*60*60*stoi(tmp2.substr(0,2));
        int m=1000*60*stoi(tmp2.substr(3,2));
        float se=1000*stof(tmp2.substr(6,6))+3000;
        int ts=se+h+m;
        ended.push_back(ts);

        string tmp=lines[i].substr(24,6);
        tmp.erase(tmp.begin()+tmp.size()-1);
        float b=1000*stof(tmp);
        bar.push_back((int)b);
        
        int ss=ts-b+1;
        start.push_back(ss);
    }
    //cout<<start.size()<<endl;
    for(int i=0;i<start.size();i++){
        int tt=check(start[i],start[i]+999,i);
        if(answer<tt)
            answer=tt;
        tt=check(ended[i],ended[i]+999,i);
        if(answer<tt)
            answer=tt;
    }
    return answer;
} 
