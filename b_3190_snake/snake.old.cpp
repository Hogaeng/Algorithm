/*
   첫째 줄에 보드의 크기 N이 주어진다. (2 ≤ N ≤ 100) 다음 줄에 사과의 개수 K가 주어진다. (0 ≤ K ≤ 100)
   다음 K개의 줄에는 사과의 위치가 주어지는데, 첫 번째 정수는 행, 두 번째 정수는 열 위치를 의미한다. 사과의 위치는 모두 다르며, 맨 위 맨 좌측 (1행 1열) 에는 사과가 없다.

   다음 줄에는 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)
   다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데,  정수 X와 문자 C로 이루어져 있으며. X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. X는 10,000 이하의 양의 정수이며, 방향 전환 정보는 X가 증가하는 순으로 주어진다.

   첫째 줄에 게임이 몇 초에 끝나는지 출력한다.
*/
//
#include<iostream>
#include<vector>
enum {D,L,S};//tdir
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//ndir
struct Part{
	int curs[2];
	int tdir;
	int ndir;
	Part(int c1,int c2,int t, int n):ndir(n),tdir(t){
		curs[0] = c1;
		curs[1] = c2;
	}
};
using namespace std;
void roll(int curs[2],int &curdir, int tdir){
	if(tdir == D){
		curdir++;
		if(curdir>3)
			curdir=0;
	}
	else if(tdir==L){
		curdir--;
		if(curdir<0)
			curdir=3;
	}
	curs[0]+=dir[curdir][0];
	curs[1]+=dir[curdir][1];
	//cout<<dir[curdir][0]<<":"<<dir[curdir][1]<<endl;
	return;
}
void eatA(vector<Part> &snake){
	Part tpart= snake[snake.size()-1];
	snake.push_back(Part(tpart.curs[0],tpart.curs[1], tpart.tdir, tpart.ndir));
	return;
}
bool chekboarder(vector<Part> &snake,int bn){
	int curs[2];
	bool ret = false;
	curs[0] = snake[0].curs[0];
	curs[1] = snake[0].curs[1];
	if(curs[0]>bn-1||curs[1]>bn-1||curs[0]<0||curs[1]<0)
		ret = true;
	for(int i=1;i<snake.size();i++)
		if(snake[i].curs[0] == curs[0] && snake[i].curs[1]==curs[1])
			ret= true;
	return ret;
}
bool rollsnake(vector<Part> &snake,bool aflag){
	int sn = snake.size();
	if(aflag)
		eatA(snake);
	for(int i=0;i<sn;i++){
		;
	}
	int ttdir1, tndir1;
	int ttdir2, tndir2;
	ttdir1=snake[0].tdir;
	ttdir2=ttdir1;
	tndir1=snake[0].ndir;
	tndir2=tndir1;
	roll(snake[0].curs,snake[0].ndir,snake[0].tdir);
	if(chekboarder(snake,100))
		return true;
	for(int i=1;i<sn;i++){
		ttdir1 = snake[i].tdir;
		tndir1 = snake[i].ndir;
		roll(snake[i].curs,snake[i].ndir,snake[i].tdir);
		snake[i].tdir = ttdir2;
		snake[i].ndir = tndir2;
		ttdir2 = ttdir1;
		tndir2 = tndir1;
	}
	snake[0].tdir=S;
	return false;
}
void printsnake(vector<Part>&snake,int time){
			cout<<time+1<<'\n';
			for(int i=0;i<snake.size();i++){
				for(int j=0;j<i;j++)
					cout<<' ';
				cout<<snake[i].curs[0]<<":"<<snake[i].curs[1]<<snake[i].tdir<<snake[i].ndir<<'\n';
			}
}
int main(){
//	freopen("snake_input.txt","r",stdin);
//	int tmp;
//	cin>>tmp;
//	for(int z=0;z<tmp;z++){
		int bn;
		int an;
		cin >> bn;
		cin >> an;
		int apples[100][2]={0,};
		for(int i=0;i<an;i++){
			cin>>apples[i][0];
			cin>>apples[i][1];
		}
		int dn;
		cin >> dn;
		int dirinput[100][2]={0,};
		char tmp;
		for(int i=0;i<dn;i++){
			cin>>dirinput[i][0];
			cin>>tmp;
			if(tmp == 'D')
				dirinput[i][1]=D;
			else if(tmp == 'L')
				dirinput[i][1]=L;
		}
		int time = 0;
		int curs[2] = {0,0};
		int curdir = 0;
		vector<Part> snake;
		snake.push_back(Part(0,0,S,0));
		bool uroboros = false;
		for(;;time++){
			if(uroboros||chekboarder(snake,bn))
				break;
			//snake[0].tdir = S;
			bool aflag=false;
			for(int i=0;i<an;i++){
				if(snake[0].curs[0] == apples[i][0]-1 && snake[0].curs[1] == apples[i][1]-1)
					aflag=true;
			}
			for(int i=0;i<dn;i++){
				if(time==dirinput[i][0]){
					snake[0].tdir = dirinput[i][1];
					break;
				}
			}	
			uroboros=rollsnake(snake,aflag);
//			printsnake(snake,time);
		}
		cout<<time<<"\n";
//	}
	return 0;
}
