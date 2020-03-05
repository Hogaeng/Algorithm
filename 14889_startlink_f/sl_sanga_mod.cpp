#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int arr[20][20];
int ck [20];
vector<int> team1;
vector<int> team2;
int res;

void init(){
	N=0;
	fill(arr[0],arr[0]+20,0);
	fill(ck,ck+20,0);
	team1.clear();
	team2.clear();
	res=10000;
}
int subAbility(){
	int ability1=0;
	int ability2=0;
	for(int i=0; i<(N/2)-1; i++){
		for(int j=i; j<N/2; j++){
			ability1 += arr[team1.at(i)][team1.at(j)];
			ability1 += arr[team1.at(j)][team1.at(i)];
			ability2 += arr[team2.at(i)][team2.at(j)];
			ability2 += arr[team2.at(j)][team2.at(i)];
		}
	}

	return abs(ability1 - ability2);
}

void putRest(){
	for(int i=0; i<N; i++){
		if (ck[i] == true) continue;
		team2.push_back(i);
	}
}

void combination(int num){
	ck[num] = true;
	team1.push_back(num);

	if(team1.size() == N/2){
		vector<int> newTeam;
		putRest();
		int k=subAbility();
		//cout<<k<<'\n';
		res = min(res, k);
		
		team2 = newTeam;
		return;
	}

	for(int i = num + 1; i <N; i++){
		if(ck[i] == true) continue;
		combination(i);
		team1.pop_back();
		ck[i] = false;
	}
}

int main(){
	freopen("sl_input.txt","r",stdin);
	int z;
	cin>>z;
	for(int k=0;k<z;k++){
	//res = 10000;
	init();
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> arr[i][j];
		}
	}

	for(int i=0; i<N; i++){
		combination(i);
	}
	
	cout << res << '\n';
	}
	return 0;
}

