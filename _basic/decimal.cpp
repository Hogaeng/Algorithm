//uipath에선 long double이 
#include<iostream>
using namespace std;
int main(void){
    double d=2152559.82;
    long double ld=2152559.82;
    cout.precision(17);
    cout<<fixed<<d<<endl;
    cout<<fixed<<ld<<endl;
    return 0;
}