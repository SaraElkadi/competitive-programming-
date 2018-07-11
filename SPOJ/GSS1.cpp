#include <bits/stdc++.h>

using namespace std;
const int MAX=50005;
struct node{
long long pref,suf,sum,maxsum;
};
node tree[4*MAX];
int a[MAX],from,to;

void build(int s,int e,int p)
{
    if(s==e)
    {
        tree[p].pref=tree[p].suf=tree[p].sum=tree[p].maxsum=a[s];
        return ;
    }
    build(s,(s+e)/2,2*p);
    build((s+e)/2+1,e,2*p+1);
    tree[p].pref=max(tree[2*p].pref,tree[2*p].sum+tree[2*p+1].pref);
    tree[p].suf=max(tree[2*p+1].suf,tree[2*p].suf+tree[2*p+1].sum);
    tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
    tree[p].maxsum=max(tree[2*p].suf+tree[2*p+1].pref,max(tree[2*p].maxsum,tree[2*p+1].maxsum));
}

node query(int s , int e , int p)
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
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    build(1,n,1);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&from,&to);
        printf("%d\n",query(1,n,1).maxsum);
    }
    return 0;
}
