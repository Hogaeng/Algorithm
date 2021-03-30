#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct balls {
	balls(int d, int rx, int ry, int bx,int by):depth(d),rx(rx),ry(ry),bx(bx),by(by){}
	int depth;
	int rx, ry, bx, by;
};
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
void move(int& x, int& y, int d,int map[10][10]) {
	while (1) {
		x += dir[d][0]; y += dir[d][1];
		if (map[x][y] == 1) {
			x -= dir[d][0]; y -= dir[d][1];
			break;
		}
		else if (map[x][y] == 2)
			break;
	}
}
void printboard(int map[10][10]){
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				switch (map[i][j]) {
					case 0:
						cout<<"."; break;
					case 1:
						cout<<"#"; break;
					case 2:
						cout<<"O"; break;
					case 3:
						cout<<"R"; break;
					case 4:
						cout<<"B"; break;
					default:
						cout<<"-"; break;
				}
			}
		cout<<endl;
		}
}

int main() {
	int tmp;
	cin>>tmp;
	for(int z = 0; z<tmp;z++){
		int map[10][10]={-1,};
		bool visit[10][10][10][10]={0,};
		char str[11];//={0,};
		int n, m, ans = -1;
		int irx, iry, ibx, iby, hx, hy;

		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%s", str);
			for (int j = 0; j < m; ++j) {
				switch (str[j]) {
					case '.':
						map[i][j] = 0; break;
					case '#':
						map[i][j] = 1; break;
					case 'O':
						map[i][j] = 2; hx = i, hy = j; break;
					case 'R':
						irx = i, iry = j;map[i][j] = 3; break;
					case 'B':
						ibx = i, iby = j;map[i][j] = 4; break;
				}
			}
		}
		//printboard(map);
		queue<balls> q;
		q.push(balls(0,irx,iry,ibx,iby));
		visit[irx][iry][ibx][iby] = true;

		while (!q.empty()) {
			balls cur = q.front(); q.pop();

			if (cur.depth > 10)
				break;
			if (cur.rx == hx && cur.ry == hy) {
				ans = cur.depth;
				break;
			}

			for (int i = 0; i < 4; ++i) {
				int rx = cur.rx, ry = cur.ry;
				int bx = cur.bx, by = cur.by;
				move(rx, ry, i,map), move(bx, by, i,map);

				if (bx == hx && by == hy)
					continue;

				if (rx == bx && ry == by) {
					switch (i) {
						case 0:
							cur.rx < cur.bx ? rx-- : bx--; break;
						case 2:
							cur.rx < cur.bx ? bx++ : rx++; break;
						case 1:
							cur.ry < cur.by ? ry-- : by--; break;
						case 3:
							cur.ry < cur.by ? by++ : ry++; break;
					}
				}

				if (!visit[rx][ry][bx][by]) {
					balls next( cur.depth + 1,rx,ry,bx,by );
					q.push(next);
					visit[rx][ry][bx][by] = true;
				}
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}

