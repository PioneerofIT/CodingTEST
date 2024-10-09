#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	
	int s, n;
	cin >> s; // ĳ���� ũ��
	cin >> n; //�۾��� ����
	
	vector<int> ch(s);
	vector<int> job(n);
	
	int i,j;
	int pos;
	
	
	for(int i=0; i<n; i++)
	{
		cin >> job[i];	
	}
	
	for(i=0; i<job.size(); i++)
	{
		pos = -1;
		for(j=0; j<ch.size(); j++)
		{
			if(job[i] == ch[j])
			{
				pos = j; // Cache Hit ������ ���� 
			}
				
		}
		
		// 1) Cache Miss : Cache�� ���� �۾��� ���� ������ ��� �۾� �а� ù��°��	 
		if(pos == -1)
		{
			for(j=(ch.size()-1); j>=1; j-- )
			{
				ch[j] = ch[j-1]; // �� ĭ�� �ڷ� �а� 
			}
			ch[0] = job[i]; // ���� ���� ù��° ĳ�÷� 
		}
		// 2) Cache Hit : 
		else
		{
			for(j=pos; j>=1; j--)
			{
				ch[j] = ch[j-1];
			}
			ch[0] = job[i];
		}		
	} 
	
	for(i=0; i<ch.size(); i++)
	{
		cout << ch[i] << " ";
	}
	
	
	return 0;
}
