#include<iostream>
#include<fstream>
#define MAX 1000000
using namespace std;
int main(){

	ofstream outfile("superv_in2.txt");
	outfile<<1<<'\n';
	outfile<<MAX<<'\n';
	for(int i=0;i<MAX;i++){
		if(i==MAX-1)
			outfile<<MAX<<'\n';
		else
			outfile<<MAX<<' ';
	}
	outfile<<1<<' ';
	outfile<<1;
	outfile.close();
	return 0;
}
