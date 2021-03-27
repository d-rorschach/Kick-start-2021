#include<bits/stdc++.h>
using namespace std;
main()
{
	ios_base::sync_with_stdio(false);
	int t,t1=1;
	cin>>t;
	while(t--)
	{
		int r,c,i,j,cnt,k,start,end;
		long long int ans=0;
		cin>>r>>c;
		int mat[r+3][c+3];
		memset(mat,0,sizeof(mat));
		int right[r+3][c+3], left[r+3][c+3], down[r+3][c+3], up[r+3][c+3];
		memset(right,0,sizeof(right));
		memset(left,0,sizeof(left));
		memset(down,0,sizeof(down));
		memset(up,0,sizeof(up));
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				cin>>mat[i][j];
			}
		}
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				if(mat[i][j]==1 && mat[i][j+1]==1)
				{
					start=j;cnt=2;
					for(k=j+2;k<=c;k++)
					{
						if(mat[i][k]==1)
						{
							++cnt;
						}
						else
						{
							break;
						}
					}
					end=k-1;
					for(k=start;k<=end;k++)
					{
						if(mat[i+1][k]==1 || mat[i-1][k]==1)
						{
							right[i][k]=cnt+start-k;
							left[i][k]=k-start+1;
						}
					}
					j=end;
				}
			}
		}
		////////////////
		for(j=1;j<=c;j++)
		{
			for(i=1;i<=r;i++)
			{
				if(mat[i][j]==1 && mat[i+1][j]==1)
				{
					start=i;cnt=2;
					for(k=i+2;k<=r;k++)
					{
						if(mat[k][j]==1)
						{
							++cnt;
						}
						else
						{
							break;
						}
					}
					end=k-1;
					for(k=start;k<=end;k++)
					{
						if(mat[k][j+1]==1 || mat[k][j-1]==1)
						{
							down[k][j]=cnt+start-k;
							up[k][j]=k-start+1;
							ans+=max((min(right[k][j]/2,down[k][j])-1),0);
							ans+=max((min(right[k][j],down[k][j]/2)-1),0);
							
							ans+=max((min(right[k][j]/2,up[k][j])-1),0);
							ans+=max((min(right[k][j],up[k][j]/2)-1),0);
							
							ans+=max((min(left[k][j]/2,down[k][j])-1),0);
							ans+=max((min(left[k][j],down[k][j]/2)-1),0);
							
							ans+=max((min(left[k][j]/2,up[k][j])-1),0);
							ans+=max((min(left[k][j],up[k][j]/2)-1),0);
						}
					}
					i=end;
				}
			}
		}
		cout<<"Case #"<<t1<<": "<<ans<<endl;
        ++t1;
	}
}