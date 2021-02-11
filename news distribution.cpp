#include<iostream>
#include<vector>
using namespace std;

#define ll long long int
#define pb push_back

ll n,k,m,u,vis[500005],vis1[500005],dist[500005],cnt;
vector<ll>adj[500005];

void dfs1(ll s)
{
    vis1[s]=1;
	for(vector<ll>::iterator it = adj[s].begin();it!=adj[s].end();it++)
	{
		if(!vis1[*it])
		{
			vis1[*it]=1;
			dist[*it]=dist[s];
			dfs1(*it);

		}
	}

}

void dfs(ll s)
{
	vis[s]=1;
	for(vector<ll>::iterator it = adj[s].begin();it!=adj[s].end();it++)
	{
		if(!vis[*it])
		{
			vis[*it]=1;
			cnt++;
			dfs(*it);

		}
	}
	dist[s]=cnt;
}

int main(int argc, char *argv[])
{
	cin>>n>>m;
	ll t;
	for(int i=0;i<m;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>u;
			if(j==0)
			{
				t=u;
			}
			else
			{
				adj[u].pb(t);
				adj[t].pb(u);
				t=u;
			}
		}
	}
	for(int i=1;i<=n;i++)
    {

        if(!vis[i]){dist[i]=1;cnt=1;dfs(i);}
    }
    for(int i=1;i<=n;i++)
    {

        if(!vis1[i]){dfs1(i);}
    }
    for(int i=1;i<=n;i++)
    {
        cout<< dist[i] << " ";
    }

}
