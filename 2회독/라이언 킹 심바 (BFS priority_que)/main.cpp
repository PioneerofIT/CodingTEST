#include <iostream>
#include <queue>
using namespace std;

int map[26][26];
int ch[26][26];
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct State
{
	int X;
	int Y;
	int distance;
	
	State(int x, int y, int dist)
	{
		X = x;
		Y = y;
		distance = dist;
	}
	
	//거리 -> 위(x) -> 왼(y)
	bool operator< (const State &arg ) const
	{
		if( distance != arg.distance) return distance > arg.distance;
		if( X != arg.X) return X > arg.X;
		if( Y != arg.Y) return Y > arg.Y;
	}
	
	 
};

struct Simba
{
	int x;
	int y;
	int ate;
	int size;
	
	void SizeUp()
	{
		ate = 0;
		size ++;
	}
};


int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	Simba simba;
	priority_queue<State> pQ;
	int res = 0;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 9)
			{
				simba.x = i;
				simba.y = j;
			}
			
		}		
	}
	
	simba.ate = 0;
	simba.size = 2;
	
	pQ.push(State(simba.x, simba.y, 0));
	
	while(!pQ.empty())
	{
		State state = pQ.top();
		pQ.pop();
		
		//현재 위치 먹을 수 있나?
		int x = state.X;
		int y = state.Y;
		int z = state.distance;
		
		if(map[x][y] != 0 && map[x][y] < simba.size)
		{
			simba.x = x;
			simba.y = y;
			simba.ate ++;
			if(simba.size <= simba.ate) simba.SizeUp();
			map[x][y] = 0;
			for(int i=1; i<=n; i++)
			{
				for(int j=1; j<=n; j++)
				{
					ch[i][j] = 0;	
				}	
			}
			while(!pQ.empty()) pQ.pop();
			res = state.distance;	
		}
		for(int i=0; i<4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			if(xx >=1 && xx <=n && yy>=1 && yy<=n && ch[xx][yy] == 0 && map[xx][yy] <= simba.size)
			{
				pQ.push(State(xx, yy, z+1));
				ch[xx][yy] = 1;	
			}	
		}	
	 
	}
	
	
	cout << res;
	
	return 0;
}
