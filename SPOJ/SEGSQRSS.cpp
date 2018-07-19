#include <bits/stdc++.h>

using namespace std;
const int MAX=100000;
pair<long long ,long long> tree[4*MAX],lazy[4*MAX];
int from,to,n,a[MAX];
void build(int s=1,int e=n,int p=1)
{
    if(s==e)
    {
        tree[p].first=a[s];
        tree[p].second=a[s]*a[s];
        return ;
    }
    build(s,(s+e)/2,2*p);
    build((s+e)/2+1,e,2*p+1);
    tree[p].first=tree[2*p].first+tree[2*p+1].first;
    tree[p].second=tree[2*p].second+tree[2*p+1].second;
}

void updateRange(int t,int val,int s=1, int e=n, int p=1)
{
    if(lazy[p].first||lazy[p].second)
    {
        if(lazy[p].first)
        {
            tree[p].first=(lazy[p].first+lazy[p].second)*(e-s+1);
            tree[p].second=(lazy[p].first+lazy[p].second)*(lazy[p].first+lazy[p].second)*(e-s+1);
        }
        else if(lazy[p].second)
        {
            tree[p].second+=(2*tree[p].first*lazy[p].second+(e-s+1)*lazy[p].second*lazy[p].second);
            tree[p].first+=(e-s+1)*lazy[p].second;

        }
        if(s!=e)
        {
            if(lazy[p].first)
            {
                lazy[2*p]=lazy[2*p+1]=lazy[p];
            }
            else
            {
                lazy[2*p].second+=lazy[p].second;
                lazy[2*p+1].second+=lazy[p].second;
            }
        }
        lazy[p] = make_pair(0,0);
    }
    if(s>e||s>to||e<from)
        return;
    if(s>=from && e<= to)
    {
        if(t==0)
        {
            tree[p].first=(e-s+1)*val;
            tree[p].second=(e-s+1)*val*val;
        }
        else if(t==1)
        {
            tree[p].second+=(2*tree[p].first*val+(e-s+1)*val*val);
            tree[p].first+=(e-s+1)*val;

        }
        if(s!=e)
        {
            if(t==0)
            {
                lazy[2*p].second=lazy[2*p+1].second=0;
                lazy[2*p].first=lazy[2*p+1].first=val;
            }
            else if(t==1)
            {
                lazy[2*p].second+=val;
                lazy[2*p+1].second+=val;
            }
        }
        lazy[p]=make_pair(0,0);
        return;
    }
    int mid = (s + e) / 2;
    updateRange(t,val, s, mid,2*p);
    updateRange(t,val, mid+1, e,2*p+1);
    tree[p].first = tree[p*2].first + tree[p*2+1].first;
    tree[p].second = tree[p*2].second + tree[p*2+1].second;
}

long long queryRange(int s=1,int e=n,int p=1)
{
    if(s>e||s>to||e<from)
        return 0;
    if(lazy[p].first||lazy[p].second)
    {
        if(lazy[p].first)
        {
            tree[p].first=(lazy[p].first+lazy[p].second)*(e-s+1);
            tree[p].second=(lazy[p].first+lazy[p].second)*(lazy[p].first+lazy[p].second)*(e-s+1);
        }
        else if(lazy[p].second)
        {
            tree[p].second+=(2*tree[p].first*lazy[p].second+(e-s+1)*lazy[p].second*lazy[p].second);
            tree[p].first+=(e-s+1)*lazy[p].second;

        }
        if(s!=e)
        {
            if(lazy[p].first)
            {
                lazy[2*p]=lazy[2*p+1]=lazy[p];
            }
            else
            {
                lazy[2*p].second+=lazy[p].second;
                lazy[2*p+1].second+=lazy[p].second;
            }
        }
        lazy[p] = make_pair(0,0);
    }
    if(s>=from&&e<= to)
        return tree[p].second;
    int mid = (s+ e) / 2;
    return queryRange(s, mid,p*2)+queryRange( mid + 1,e,p*2+1);
}
int main()
{
    int T,m,op,x;
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            scanf("%d",a+i);
        build();
        printf("Case %d:\n",t);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&op,&from,&to);
            if(op==0)
            {
                scanf("%d",&x);
                updateRange(0,x);
            }
            else if(op==1)
            {
                scanf("%d",&x);
                updateRange(1,x);
            }
            else
            {
                printf("%lld\n",queryRange());
            }
        }
    }
    return 0;
}
