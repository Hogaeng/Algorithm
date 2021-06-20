#include<iostream>
using namespace std;
/*
class Mystring{
	public:
		Mystring(Mystring&& other);
};
*/
int tt(int &t){
	t--;
	return t;
}
int main(){
	int t=0;
	cout<<tt(t)<<endl;
	cout<<t<<endl;
	t++;
	cout<<tt(t)<<endl;
	cout<<t<<endl;
	return 0;
}
