#include <iostream>
using namespace std;

// 1. Index = 부모 인덱스 unf[]값은 부모 노드를 저장 
int unf[1001];
 

//원소 v가 속한 집합의 대표(루트 노드)를 찾는 함수
int Find(int v)
{
	//2. v가 자기 자신을 부모로 가진다면 v는 루트이다. 루트 반환 
	if( v == unf[v] ) return v;
	//3. 루트가 아니면 부모를 따라가서 루트를 찾는다.
	//돌아오면서 unf[v]에 저장하면서 경로 압축을 실시한다. (트리가 납작해짐) 
	else return unf[v] = Find(unf[v]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	//4... 서로의 부모 노드를 찾고 서로 부모 노드가 다르다면 부모노드를 하나로 합친다. 
	if(a != b) unf[a]=b;
}


int main(int argc, char** argv) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, a, b;
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		unf[i] = i;	
	} 
	
	for(int i=1; i<=m; i++)
	{
		cin >> a >> b;
		Union(a,b); //원소 a가 속한 집합과 b가 속한 집합을 합치는 함수
	}
	
	int p1, p2;
	cin >> p1 >> p2; 
	if(Find(p1) == Find(p2) )
	{
		cout << "YES";
		
	}
	else cout << "NO"; 
	
	return 0;
}
