#include <bits/stdc++.h>

using namespace std;
int parent[200005],color[200005];
int n,m,k,x,y;
map<int,map<int,int> > mp;

int find_set (int v)
{
    if (v == parent[v])
        return v;
    return parent[v]=find_set (parent[v]);
}

void union_sets (int a, int b)
{
    a = find_set (a);
    b = find_set (b);
    if (a != b)
        parent[b] = a;
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&color[i]);
        parent[i]=i;
    }
    while(m--)
    {
        scanf("%d %d",&x,&y);
        union_sets(x,y);
    }
    for(int i=1; i<=n; i++)
        mp[find_set(i)][color[i]]++;
    int ans=0;
    for(auto i=mp.begin(); i!=mp.end(); i++)
    {
        int mx=0,sum=0;
        for(auto j=i->second.begin(); j!=i->second.end(); j++)
        {
            mx=max(mx,j->second);
            sum+=j->second;
        }
        ans+=sum-mx;
    }
    printf("%d",ans);
    return 0;
}
