#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int TURNEL_GOAL = 44, GOAL = 21;

enum turnel
{
	center = 40,
	rs = 26, re = 28,
	ls = 50, le = 52
};
unordered_map<int,int> corner({
	{5, 26}, {10, 38}, {15, 50}
});
unordered_map<int,int> board_score({
	{26, 13}, {27, 16}, {28, 19},
	{50, 28}, {51, 27}, {52, 26},
	{38, 22}, {39, 24}, {40, 25}, {41, 30}, {42, 35}, {43, 40}
});
int ans, dice[10], h[4], score[4];
bool visited[53];

int gain_score(int p)
{
	if (p < GOAL) return p * 2;
	if (p == GOAL) return 0;
	return board_score[p];
}
int move(int start, int cnt)
{
	int next = start + cnt;

	// 코너에 진입한 경우
	if (start == 5 || start == 10 || start == 15)
		next = move(corner[start], cnt - 1);
	// 오른 통로
	else if (turnel::rs <= start && start <= turnel::re)
	{
		if (next > turnel::re) next = turnel::center + next - turnel::re - 1;
	}
	// 왼 통로
	else if (turnel::ls <= start && start <= turnel::le)
	{
		if (next > turnel::le) next = turnel::center + next - turnel::le - 1;
	}
    // 종료 지점
	if ((GOAL <= next && next <= GOAL + 4) || (TURNEL_GOAL <= next && next <= TURNEL_GOAL + 4))
		next = GOAL;
	else if (next == TURNEL_GOAL - 1)
		next = GOAL-1;
	return next;
}
void dfs(int n)
{
	if (n == 10)
	{
		ans = max(ans, score[0] + score[1] + score[2] + score[3]);
		return;
	}
	register int i, next, s, pos;
	// 1. 말 4개를 차례대로 진행
	for (i = 0; i < 4; ++i)
	{
		// 완주한 것이 아니면 이동 가능
		if (h[i] != GOAL)
		{
			// 2. 이동
			next = move(h[i], dice[n]);

			// 3. 이동한 위치에 다른 말이 존재
			if (next != GOAL && visited[next]) 
				continue;
			
			pos = h[i];
			visited[pos] = false;
			visited[next] = true;
			h[i] = next;
			s = gain_score(next);
			score[i] += s;
			dfs(n + 1);

			visited[pos] = true;
			visited[next] = false;
			h[i] = pos;
			score[i] -= s;
		}
	}
}

int main()
{
	freopen("yut_in4.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
	    register int i;
	    for (i = 0; i < 10; ++i)
		    cin >> dice[i];
	    dfs(0);
	    cout << ans <<'\n';
	}
	return 0;
}
