#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#define FILE_CIN
#define FILE_NAME "baby_in7.txt"
using namespace std;

int N;
int arr[20][20];
int ck[20][20];
int r_d[4] = { -1, 0, 0, 1 };
int c_d[4] = { 0, -1, 1, 0 };
pair<int, int> baby;
int resTime;

int range(int r, int c) {
	if (r >= 0 && r < N && c >= 0 && c < N) return 1;
	return 0;
}

void getBest(queue<pair<int,int> > q, int size) {
	vector<pair<int, int> > v;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		if (arr[cur.first][cur.second] > 0 &&arr[cur.first][cur.second] < size) v.push_back(cur);
		q.pop();
	}

	sort(v.begin(), v.end());

	arr[baby.first][baby.second] = 0;
	baby = pair<int,int>(v[0].first , v[0].second);
	arr[baby.first][baby.second] = 9;
}

bool bfs(int size) {
	int time = 0;
	memset(ck, 0, sizeof(ck));
	queue<pair<int, int> > q;

	q.push(pair<int,int>(baby.first, baby.second));
	ck[baby.first][baby.second] = 1;

	while (!q.empty()) {
		bool flag = false;
		int sz = q.size();

		while (sz--) {
			pair<int,int> pos = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int rr = pos.first + r_d[i];
				int cc = pos.second + c_d[i];

				if (!range(rr, cc) || ck[rr][cc]) continue;
				if (arr[rr][cc] > size) continue;
				if (arr[rr][cc] > 0 && arr[rr][cc] < size) flag = true;

				q.push(pair<int,int>(rr,cc));
				ck[rr][cc] = 1;
			}
		}

		time++;

		if (flag) {
			getBest(q, size);
			resTime += time;
			return true;
		}
	}

	return false;
}

int main() {
#ifdef FILE_CIN
	freopen(FILE_NAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
	cin >> N;
	resTime = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) baby = pair<int,int>( i, j );
		}
	}

	int size = 2;
	int food = 0;
	int ret = true;
	while (ret) {
		ret = bfs(size);
		if (ret) food++;
		if (food == size) {
			food = 0;
			size++;
		}
	}

	cout << resTime << '\n';

#ifdef FILE_CIN
	}
#endif
	return 0;
}
