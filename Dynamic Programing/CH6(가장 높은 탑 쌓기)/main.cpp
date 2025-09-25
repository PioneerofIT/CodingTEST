#include <iostream>
#include <algorithm>

using namespace std;

struct Obj
{
	int s; // 넓이 
	int z; // 높이 
	int g; // 무게
	

	Obj(int s, int z, int g)
	{
		this->s = s;
		this->z = z;
		this->g = g;	
	}
	
	bool operator< (const Obj &arg) const
	{
		return s > arg.s;	
	}	
		
}; 

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	vector<Obj> vO;
	int maxTop = -2147000000;
	int dy[100] = {0};
	
	
	for(int i=0; i<n; i++)
	{
		int a,b,c;
		
		cin >> a >> b >> c;
		
		vO.push_back(Obj(a,b,c));
	}
	sort(vO.begin(), vO.end());
	
	dy[0] = vO[0].z;
	for(int i=1; i < vO.size(); i++)
	{
		dy[i] = vO[i].z;
		
		for(int j=i-1; j>=0; j--)
		{
			if(vO[i].s < vO[j].s && vO[i].g < vO[j].g )
			{
				dy[i] = max(dy[i] , dy[j] + vO[i].z); 
			}
		}
		maxTop = max(maxTop, dy[i]);
			
	}
	
	
	cout << maxTop;
	
	
	return 0;
}
