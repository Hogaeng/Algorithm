#include<iostream>
using namespace std;
int d[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
int count2(int r, int c, int *map){
	int cnt=0;
	int tmp=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			tmp=*(map+i*c+j);
			if(tmp ==2)
				cnt++;
		}
	}
	return cnt;
}
struct Robot{
	//int buf[4];
	int d;
	int x;
	int y;
	Robot(int x, int y, int d):x(x),y(y),d(d){}//for(int i=0;i<4;i++) buf[i]=0;}
};
void printrobot(Robot &robot){
	cout<<robot.x<<" "<<robot.y<<endl;
}
bool move(Robot &robot,int r, int c, int *map)
{
	*(map+robot.x*c+robot.y)=2;
	int i;
	for(i=0;i<4;i++){
		robot.d--;
		if(robot.d<0)
			robot.d=3;
		int nx = *(map+(robot.x+d[robot.d][1])*c+robot.y+d[robot.d][0]);
		if(nx == 0){
			break;
		}
	}
	if(i!=4)
	{
	  robot.x = robot.x+d[robot.d][1];
	  robot.y = robot.y+d[robot.d][0];
	  return true;
  }
	else{
		int nd;
		if(robot.d>1)
			nd=robot.d-2;
		else
			nd=robot.d+2;
		int nx = *(map+(robot.x+d[nd][1])*c+robot.y+d[nd][0]);
		if(nx==2){
			robot.x = robot.x+d[nd][1];
			robot.y = robot.y+d[nd][0];
			return true;
		}
		else
			return false;
	}
}
int main(){
	int tmp;
	cin >>tmp;
	int *map;
	for(int z=0;z<tmp;z++)
	{
	  int r;
	  int c;
	  int d;
	  int x,y;
	  int ans=0;
	  cin>>r;
	  cin>>c;
	  cin>>x;
	  cin>>y;
	  cin>>d;
	  map=(int *)malloc(sizeof(int)*r*c);
	  for(int i=0;i<r;i++)
		  for(int j=0;j<c;j++)
			  cin>>*(map+i*c+j);
	  /*for(int i=0;i<r;i++){
		  for(int j=0;j<c;j++){
			  cout<<*(map+i*sizeof(int)*c+j);
		  }
		  cout<<endl;
	  }
	  */
	  Robot robot(x,y,d);
	  
	  while(true)
			  if(!move(robot,r,c,map))
					  break;
	  cout<<count2(r,c,map)<<endl;
	  free(map);
  }
	return 0;
}
