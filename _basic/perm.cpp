#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//순열. nPr
void perm(int n, int r){
    vector<int> vec;
    for(int i=0;i<n;i++) vec.push_back(i);
    do{
        for(int i=0;i<r;i++) cout<<vec[i]<<' ';
        cout<<endl;
        //뒷 순열을 제일 높은 순열의 값으로 '뒤집어놓아' 앞의 r개가 다음 순열을 나타내기 위함임.
        reverse(vec.begin()+r,vec.end());
        //ascending
    }while(next_permutation(vec.begin(),vec.end()));
}
//조합. nPr
void comb(int n, int r){
    vector<int> vec;
    vector<bool> vec_check;
    for(int i=0;i<n;i++) vec.push_back(i);
    for(int i=0;i<n;i++) vec_check.push_back(false);
    for(int i=0;i<r;i++) vec_check[i]=true;
    do{
        for(int i=0;i<n;i++) if(vec_check[i]) cout<<vec[i]<<' ';
        cout<<endl;
    }while(prev_permutation(vec_check.begin(),vec_check.end()));
}
//중복순열. n파이r
void pi(int n, int r){
    vector<int> vec;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) vec.push_back(i);
    do{
        for(int i=0;i<r;i++) cout<<vec[i]<<' ';
        cout<<endl;
        //뒷 순열을 제일 높은 순열의 값으로 '뒤집어놓아' 앞의 r개가 다음 순열을 나타내기 위함임.
        reverse(vec.begin()+r,vec.end());
        //ascending
    }while(next_permutation(vec.begin(),vec.end()));
    
}
//중복조합. nHr
void homo(int n, int r){
    vector<int> vec;
    vector<bool> vec_check;
    for(int i=0;i<n;i++) vec.push_back(i);
    for(int i=0;i<n;i++) vec_check.push_back(false);
    for(int i=0;i<r;i++) vec_check[i]=true;
    do{
        for(int i=0;i<n;i++) if(vec_check[i]) cout<<vec[i]<<' ';
        cout<<endl;
    }while(prev_permutation(vec_check.begin(),vec_check.end()));
}
int main(void){
    int n=4,r=2;
    //perm(n,r);
    //comb(n,r);
    //pi(n,r);
    homo(n,r);
}