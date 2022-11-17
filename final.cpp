#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<vector<int>> Cost;
	vector<vector<string>> CutSequence;
	int N,row,col,leftpos,rightpos,cutpos,sum;
	vector<int> cuts;
	cuts.push_back(0);
	cuts.push_back(1);
	cuts.push_back(3);
	cuts.push_back(4);
	cuts.push_back(5);
	cuts.push_back(7);
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
			temp.push_back("0");
		}
		CutSequence.push_back(temp);
	}
	for(rightpos=2;rightpos<=N-1;rightpos++)
	{
		for(leftpos=rightpos-2;leftpos>=0;leftpos--)
		{
			Cost[leftpos][rightpos]=INT_MAX;
			for(cutpos=leftpos+1;cutpos<=rightpos-1;cutpos++)
			{
				sum=Cost[leftpos][cutpos]+Cost[cutpos][rightpos];
				if(sum<Cost[leftpos][rightpos])
				{
					Cost[leftpos][rightpos]=sum;
					CutSequence[leftpos][rightpos]=to_string(cuts[cutpos])+","+CutSequence[leftpos][cutpos]+","+CutSequence[cutpos][rightpos];
				}
			}
			Cost[leftpos][rightpos]=Cost[leftpos][rightpos]+cuts[rightpos]-cuts[leftpos];
		}
	}
	for(int i=0;i<Cost.size();i++)
	{
		for(int j=0;j<Cost[i].size();j++)
		{
			cout<<Cost[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"---------------------"<<endl;
	for(int i=0;i<CutSequence.size();i++)
	{
		for(int j=0;j<CutSequence[i].size();j++)
		{
			cout<<CutSequence[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<Cost[0][N-1]<<endl;
	cout<<CutSequence[0][N-1]<<endl;
	return 0;
}
