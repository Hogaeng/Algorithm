#include<iostream>
#include<vector>
using namespace std;
int main(void){
    vector<int> vir;
    vector<int> vir_raw;
    vir.push_back(1);
    vir.push_back(2);
    vir.push_back(3);
    vir.push_back(4);
    vir_raw=vir;
    vir.erase(vir.begin());
    vir=vir_raw;
    cout<<vir[0]<<endl;;
}

