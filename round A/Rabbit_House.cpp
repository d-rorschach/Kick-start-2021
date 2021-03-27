#include<bits/stdc++.h>
using namespace std;
main()
{
    int t,t1=1;
    cin>>t;
    while(t--)
    {
        int r,c,i,j,h;
        long long int ans=0;
        cin>>r>>c;
        int mat[r+3][c+3],viz[r+3][c+3];
        memset(mat,0,sizeof(mat));
        memset(viz,0,sizeof(viz));
        priority_queue<pair<int,pair<int,int> > > pq;
        for(i=1;i<=r;i++)          // 1 based indexing
        {
            for(j=1;j<=c;j++)
            {
                cin>>mat[i][j];
                pq.push({mat[i][j],{i,j}});
            }
        }
        while(!pq.empty())
        {
            i=pq.top().second.first;
            j=pq.top().second.second;
            if(viz[i][j]==1)  // if already visited
            {
                pq.pop();
                continue;
            }
            viz[i][j]=1;
            h=pq.top().first;
            pq.pop();
            // now visit its smaller unvisited neighbours
            if(i-1>0 && mat[i-1][j]<h-1 && viz[i-1][j]==0)
            {
                ans+=h-1-mat[i-1][j];
                mat[i-1][j]=h-1;
                pq.push({h-1,{i-1,j}});
            }
            if(i+1<=r && mat[i+1][j]<h-1 && viz[i+1][j]==0)
            {
                ans+=h-1-mat[i+1][j];
                mat[i+1][j]=h-1;
                pq.push({h-1,{i+1,j}});
            }
            if(j-1>0 && mat[i][j-1]<h-1 && viz[i][j-1]==0)
            {
                ans+=h-1-mat[i][j-1];
                mat[i][j-1]=h-1;
                pq.push({h-1,{i,j-1}});
            }
            if(j+1<=c && mat[i][j+1]<h-1 && viz[i][j+1]==0)
            {
                ans+=h-1-mat[i][j+1];
                mat[i][j+1]=h-1;
                pq.push({h-1,{i,j+1}});
            }
        }
        cout<<"Case #"<<t1<<": "<<ans<<endl;
        ++t1;
    }
}