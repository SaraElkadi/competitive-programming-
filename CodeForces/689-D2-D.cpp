#include <bits/stdc++.h>

using namespace std;
const int MAX=200005;
int treea[4*MAX],treeb[4*MAX];
int a[MAX],b[MAX],n;
void builda(int s,int e,int p)
{
    if(s==e)
    {
        treea[p]=a[s];
        return ;
    }
    builda(s,(s+e)/2,2*p);
    builda((s+e)/2+1,e,2*p+1);
    treea[p]=max(treea[2*p],treea[2*p+1]);
}
void buildb(int s,int e,int p)
{
    if(s==e)
    {
        treeb[p]=b[s];
        return ;
    }
    buildb(s,(s+e)/2,2*p);
    buildb((s+e)/2+1,e,2*p+1);
    treeb[p]=min(treeb[2*p],treeb[2*p+1]);
}
int queryMax(int from ,int to ,int s=1 , int e=n , int p=1)
{
    if (from <= s && to >= e)
    {
        return treea[p];
    }
    int mid = (s + e) / 2;
    if (to <= mid)
        return queryMax(from ,to,s, (s + e) / 2, 2 * p);
    if (from > mid)
        return queryMax(from,to,(s + e) / 2 + 1, e, 2 * p + 1);
    return max(queryMax(from,to,s, (s + e) / 2, 2 * p),queryMax(from,to,(s + e) / 2 + 1, e, 2 * p + 1));
}
int queryMin(int from ,int to ,int s=1 , int e=n , int p=1)
{
    if (from <= s && to >= e)
    {
        return treeb[p];
    }
    int mid = (s + e) / 2;
    if (to <= mid)
        return queryMin(from ,to,s, (s + e) / 2, 2 * p);
    if (from > mid)
        return queryMin(from,to,(s + e) / 2 + 1, e, 2 * p + 1);
    return min(queryMin(from,to,s, (s + e) / 2, 2 * p),queryMin(from,to,(s + e) / 2 + 1, e, 2 * p + 1));
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",a+i);
    for(int i=1; i<=n; i++)
        scanf("%d",b+i);
    builda(1,n,1);
    buildb(1,n,1);
    long long l1,r1,r2,l2,m,ans=0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > b[i]) continue;

        l1 = i, r1 = n ;

        while (l1 < r1)
        {
            m = (l1 + r1) / 2;

            if (queryMax(i, m) >= queryMin(i, m))
                r1 = m;
            else
                l1 = m + 1;
        }

        if (queryMax(i, r1) != queryMin(i, r1)) continue;

        l2 = l1, r2 = n - 1;

        while (l2 < r2)
        {
            m = (l2 + r2 + 1) / 2;

            if (queryMax(i, m) <= queryMin(i, m))
                l2 = m;
            else
                r2 = m - 1;
        }

        ans += r2 - r1 + 1;
    }

    printf("%lld\n", ans);
    return 0;
}
