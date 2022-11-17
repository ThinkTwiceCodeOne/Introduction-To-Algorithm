#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<vector<int>> Cost;
	vector<vector<string>> CutSequence;
	int N,row,col,i,j,k,sum;
	vector<int> cuts;
	int l;
	cin>>N>>l;
	cuts.push_back(0);
	for(int i=0;i<N;i++)
	{
		int num;
		cin>>num;
		cuts.push_back(num);
	}
	cuts.push_back(l);
	sort(cuts.begin(),cuts.end());
	/*cuts.push_back(0); 
	cuts.push_back(1);
	cuts.push_back(2);
	cuts.push_back(50);
	cuts.push_back(100);*/
	N=cuts.size();
	for(int i=0;i<N;i++)
	{
		vector<int> temp;
		for(int j=0;j<N;j++)
		{
			temp.push_back(0);
		}
		Cost.push_back(temp);
	}
	for(int i=0;i<N;i++)
	{
		vector<string> temp;
		for(int j=0;j<N;j++)
		{
			temp.push_back("");
		}
		CutSequence.push_back(temp);
	}
	for(j=2;j<=N-1;j++)
	{
		for(i=j-2;i>=0;i--)
		{
			Cost[i][j]=INT_MAX;
			for(k=i+1;k<=j-1;k++)
			{
				sum=Cost[i][k]+Cost[k][j];
				if(sum<Cost[i][j])
				{
					Cost[i][j]=sum;
					CutSequence[i][j]=to_string(cuts[k])+","+CutSequence[i][k]+","+CutSequence[k][j];
				}
			}
			Cost[i][j]=Cost[i][j]+cuts[j]-cuts[i];
		}
	}
	cout<<Cost[0][N-1]<<endl;
	cout<<CutSequence[0][N-1]<<endl;
	return 0;
}
