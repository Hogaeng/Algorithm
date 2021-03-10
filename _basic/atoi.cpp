#include<iostream>
#include<string>
using namespace std;
int main(){
    char a='9';
    //atoi 테스트
    int j=atoi(&a);
    cout<<j<<endl;
    //itoa 테스트
    int i=a-'0';
    string s=to_string(i);
    cout<<s<<endl;
}

