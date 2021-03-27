#include<bits/stdc++.h>
using namespace std;
main()
{
	int t,t1=1;
	cin>>t;
	while(t--)
	{
		string s;
		int i,n,k,count=0;
		cin>>n>>k;
		cin>>s;
		for(i=0;i<n/2;i++) //visiting half of the string
		{
			if(s[i]!=s[n-i-1])
			{
				++count;
			}
		}
		cout<<"Case #"<<t1<<": "<<abs(k-count)<<endl;
        ++t1;
	}
}