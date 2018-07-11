#include <bits/stdc++.h>

using namespace std;
const int MAX=20005;
int tree[4*MAX],a[MAX],n,k,t;
void build(int s,int e,int p)
{
    if(s==e)
    {
        tree[p]=a[s];
        return ;
    }
    build(s,(s+e)/2,2*p);
    build((s+e)/2+1,e,2*p+1);
    tree[p]=tree[2*p]&tree[2*p+1];
}
int query(int s , int e , int p,int from,int to)
{
    if (from <= s && to >= e)
    {
        return tree[p];
    }
    int mid = (s + e) / 2;
    if (to <= mid)
        return query(s, (s + e) / 2, 2 * p,from,to);
    if (from > mid)
        return query((s + e) / 2 + 1, e, 2 * p + 1,from,to);
    return query(s, (s + e) / 2, 2 * p,from,to)&query((s + e) / 2 + 1, e, 2 * p + 1,from,to);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(int i=1; i<=n; i++)
            scanf("%d",a+i);
        build(1,n,1);
        for(int i=1; i<=n; i++)
        {
            int ans=query(1,n,1,max(1,i-k),i)&query(1,n,1,i,min(n,i+k));
            if(i-k<1)
                ans&=query(1,n,1,max(1,n+(i-k)),n);
            if(i+k>n)
                ans&=query(1,n,1,1,min((i+k)-n,n));
            printf("%d ",ans);
        }
        puts("");
    }
    return 0;
}
