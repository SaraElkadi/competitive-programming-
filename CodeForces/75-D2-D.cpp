#include <bits/stdc++.h>

using namespace std;
const int MAX=250005;
struct node
{
    long long pref,suf,sum,maxsum;
};
node tree[4*MAX];
int from=1,to,n;
vector<node> a;
void build(int s=1,int e=n,int p=1)
{
    if(s==e)
    {
        tree[p]=a[s];
        return ;
    }
    build(s,(s+e)/2,2*p);
    build((s+e)/2+1,e,2*p+1);
    tree[p].pref=max(tree[2*p].pref,tree[2*p].sum+tree[2*p+1].pref);
    tree[p].suf=max(tree[2*p+1].suf,tree[2*p].suf+tree[2*p+1].sum);
    tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
    tree[p].maxsum=max(tree[2*p].suf+tree[2*p+1].pref,max(tree[2*p].maxsum,tree[2*p+1].maxsum));
}

node query(int s=1 , int e=n , int p=1)
{
    if (from <= s && to >= e)
    {
        return tree[p];
    }
    int mid = (s + e) / 2;
    if (to <= mid)
        return query(s, (s + e) / 2, 2 * p);
    if (from > mid)
        return query((s + e) / 2 + 1, e, 2 * p + 1);
    node a = query(s, (s + e) / 2, 2 * p);
    node b = query((s + e) / 2 + 1, e, 2 * p + 1);
    node nd;
    nd.pref=max(a.pref,a.sum+b.pref);
    nd.suf=max(b.suf,a.suf+b.sum);
    nd.sum=a.sum+b.sum;
    nd.maxsum=max(a.suf+b.pref,max(a.maxsum,b.maxsum));
    return nd;
}

int main()
{
    long long N,m,x;
    scanf("%lld%lld",&N,&m);
    vector<node> vv;
    for(int i=0; i<N; i++)
    {
        a.clear();
        a.push_back({0,0,0,0});
        scanf("%d",&n);
        for(int j=0; j<n; j++)
        {
            scanf("%lld",&x);
            a.push_back(node {x,x,x,x});
        }
        build();
        to=n;
        vv.push_back(query());
    }
    n=m;
    a.clear();
    a.push_back(node {0,0,0,0});
    for(int i=0; i<n; i++)
    {
        scanf("%lld",&x);
        x--;
        a.push_back(vv[x]);
    }
    build();
    to=n;
    printf("%lld",query().maxsum);
    return 0;
}
