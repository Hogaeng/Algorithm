#include<iostream>
#include<vector>
#define debug
#define FILENAME "17780_yabdrone/yabdrone_in.txt"
#define FILE_CIN
using namespace std;
const int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int board[12][12]={0,};
vector<int> drone_stack[12][12];
vector<pair<int,int> > drone_coord;
vector<int> drone_dir;
int n,k;
int cnt=1;

bool check(int t){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(drone_stack[i][j].size()>=4){
				return true;
			}
	return false;
}

bool moveit(int i){
	int d=drone_dir[i],x=drone_coord[i].first,y=drone_coord[i].second;
	int dx=dir[d][0],dy=dir[d][1];
	vector<int> stack=drone_stack[x][y];
	if(stack[0]==i){
		if(x+dx>-1&&x+dx<n&&y+dy>-1&&y+dy<n){
			if(board[x+dx][y+dy]==0){//하양
				for(int i=0;i<stack.size();i++){
					drone_coord[stack[i]].first=x+dx;
					drone_coord[stack[i]].second=y+dy;
					drone_stack[x+dx][y+dy].push_back(stack[i]);
				}
				drone_stack[x][y].clear();
			}
			else if(board[x+dx][y+dy]==2){//파랑
				int rev_d;
				if(d==0)
					rev_d=1;
				else if(d==1)
					rev_d=0;
				else if(d==2)
					rev_d=3;
				else if(d==3)
					rev_d=2;
				dx=dir[rev_d][0];dy=dir[rev_d][1];
				drone_dir[i]=rev_d;
				if(x+dx>-1&&x+dx<n&&y+dy>-1&&y+dy<n){
					if(board[x+dx][y+dy]==0){
						for(int i=0;i<stack.size();i++){
							drone_coord[stack[i]].first=x+dx;
							drone_coord[stack[i]].second=y+dy;
							drone_stack[x+dx][y+dy].push_back(stack[i]);
						}
						drone_stack[x][y].clear();
					}
					else if(board[x+dx][y+dy]==1){
						vector<int> rev_stack;
						for(int i=stack.size()-1;i>-1;i--)
							rev_stack.push_back(stack[i]);

						for(int i=0;i<rev_stack.size();i++){
							drone_coord[rev_stack[i]].first=x+dx;
							drone_coord[rev_stack[i]].second=y+dy;
							drone_stack[x+dx][y+dy].push_back(rev_stack[i]);
						}
						drone_stack[x][y].clear();
					}
				}
			}
			else{//빨강
				vector<int> rev_stack;
				for(int i=stack.size()-1;i>-1;i--)
					rev_stack.push_back(stack[i]);

				for(int i=0;i<rev_stack.size();i++){
					drone_coord[rev_stack[i]].first=x+dx;
					drone_coord[rev_stack[i]].second=y+dy;
					drone_stack[x+dx][y+dy].push_back(rev_stack[i]);
				}
				drone_stack[x][y].clear();
			}
		}
		else{//벽넘어감
			int rev_d;
			if(d==0)
				rev_d=1;
			else if(d==1)
				rev_d=0;
			else if(d==2)
				rev_d=3;
			else if(d==3)
				rev_d=2;
			dx=dir[rev_d][0];dy=dir[rev_d][1];
			drone_dir[i]=rev_d;
			if(x+dx>-1&&x+dx<n&&y+dy>-1&&y+dy<n){
				if(board[x+dx][y+dy]==0){
					for(int i=0;i<stack.size();i++){
						drone_coord[stack[i]].first=x+dx;
						drone_coord[stack[i]].second=y+dy;
						drone_stack[x+dx][y+dy].push_back(stack[i]);
					}
					drone_stack[x][y].clear();
				}
				else if(board[x+dx][y+dy]==1){
					vector<int> rev_stack;
					for(int j=stack.size()-1;j>-1;j--)
						rev_stack.push_back(stack[j]);

					for(int i=0;i<rev_stack.size();i++){
						drone_coord[rev_stack[i]].first=x+dx;
						drone_coord[rev_stack[i]].second=y+dy;
						drone_stack[x+dx][y+dy].push_back(rev_stack[i]);
					}
					drone_stack[x][y].clear();
				}
			}
		}
	}
	return check(i);
}
int main(){
#ifdef FILE_CIN
	freopen(FILENAME,"r",stdin);
	int tmp;
	cin>>tmp;
	for(int z=0;z<tmp;z++){
#endif
		cin>>n>>k;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>board[i][j];
		for(int i=0;i<k;i++){
			int d,x,y;
			cin>>x>>y>>d;
			x--;
			y--;
			d--;
			drone_dir.push_back(d);
			drone_coord.push_back(make_pair(x,y));
			drone_stack[x][y].push_back(i);
		}
		while(cnt<1001){
			bool t=false;
			for(int i=0;i<k;i++){
				t=moveit(i);
				if(t)
					break;
			}
			if(t)
				break;
			cnt++;
		}
		if(cnt==1001)
			cnt=-1;
		cout<<cnt<<endl;
#ifdef FILE_CIN
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				drone_stack[i][j].clear();
		drone_coord.clear();
		drone_dir.clear();
		cnt=1;
	}
#endif
	return 0;
}