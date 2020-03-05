#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;

int n;
int arr[20][20] = { 0, };
int check[20] = { 0 };
int small = 1000000000;
int num = 0;

void init(){
	n=0;
	fill(arr[0],arr[0]+20,0);
	fill(check,check+20,0);
	small=1000000000;
	num=0;
}
int ability(int arr2[]) {
	vector<int> start;
	int srab = 0;
	vector<int> link;
	int linkab = 0;
	for (int i = 0; i < n; i++) {
		if (arr2[i] == 1) {
			start.push_back(i);
		}
		else {
			link.push_back(i);
		}
	}
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			srab += arr[start[i]][start[j]];
			linkab += arr[link[i]][link[j]];
		}
	}
	int mini = abs(srab - linkab);
	return mini;
}

void devide(int index, int size) {
	num += 1;
	check[index] = 1;
	if (num < size / 2) {
		for (int i = index + 1; i < size; i++) {
			devide(i, size);
			check[i] = 0;
		}
        num -= 1;
	}
	else {
		int temp = ability(check);
		if (temp < small) {
			small = temp;
		}
		num -= 1;
		return;
	}
}

int main() {
	freopen("sl_input.txt","r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
	init();
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		devide(i, n);
		check[i] = 0;
		num = 0;
	}
	cout << small;
	}
	return 0;
}
