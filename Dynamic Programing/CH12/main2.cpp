#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m; // input : ���� ��, ���� ��
	
	vector<vector<int> > distance(n+1, vector<int>(n+1, 5000)); // distance Dynamic Table
	
	for(int i=1; i<=n; i++) distance[i][i] = 0; // �ڱ��ڽ� ���0 init
	
	for(int i=1; i<=m; i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		
		distance[x][y] = z;
	} 
	
	for(int k=1; k<=n; k++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]); // ��� ��� ���� �� ���� 
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(distance[i][j] == 5000) 
				cout << "M" << " ";
			else
				cout << distance[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
