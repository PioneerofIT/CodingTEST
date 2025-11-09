/* 구조체를 이용한 벡터 정렬 매우 중요 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int x, y, z;
	
	Node(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;	
	}	
	bool operator<(const Node &arg) const
	{
		if(x != arg.x) return x < arg.x; // 오름차순
		if(y != arg.y) return y < arg.y;
		if(z != arg.z) return z < arg.z; 
		
	}
}; 

int main(int argc, char** argv) 
{
	vector<Node> XY;
	
	XY.push_back(Node(2,3,5));
	XY.push_back(Node(3,6,7));
	XY.push_back(Node(2,3,1));
	XY.push_back(Node(5,2,3));
	XY.push_back(Node(3,1,6));
	
	sort(XY.begin(), XY.end());
	for(Node tmp : XY)
	{
		cout << tmp.x << " " << tmp.y << " " << tmp.z << endl;
	}
	return 0;
}
