#include<bits/stdc++.h>
using namespace std;
int find(vector<int> &parent,int x)
{
    while(parent[x]>=0)
    {
        x=parent[x];
    }
    return x;
}
main()
{
	ios_base::sync_with_stdio(false);
	int t,t1=1;
	cin>>t;
	while(t--)
	{
		int n,i,j,x,k,w,pi,pj;
		cin>>n;
		long long int ans=0;
		int a[n+3][n+3],b[n+3][n+3];
		priority_queue<pair<int,pair<int,int> > > pq;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>b[i][j];
				if(b[i][j]!=0)
				{
				    pq.push({b[i][j],{i,500+j}});
				}
			}
		}
		for(i=0;i<n;i++)
		{
			cin>>x;
		}
		for(i=0;i<n;i++)
		{
			cin>>x;
		}
		vector<int> parent(1005,-1);
		while(!pq.empty())//reverse kruskal
		{
		    w=pq.top().first;
		    i=pq.top().second.first;
		    j=pq.top().second.second;
		    pq.pop();
		    pi=find(parent,i);
		    pj=find(parent,j);
		    if(pi!=pj)
		    {
		        if(abs(parent[pi])>=abs(parent[pj]))//join by weight
		        {
		            parent[pi]+=parent[pj];
		            parent[pj]=pi;
		        }
		        else
		        {
		            parent[pj]+=parent[pi];
		            parent[pi]=pj;
		        }
		    }
		    else
		    {
		        ans+=w;
		    }
		}
		cout<<"Case #"<<t1<<": "<<ans<<endl;
        ++t1;
	}
}
