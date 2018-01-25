#include <bits/stdc++.h>

using namespace std;
const int MAX=40000;
int from,to;
int a[10005];
int tree[MAX],lazy[MAX];
vector<bool> isprime(1000005,1);
void sieve()
{
    isprime[0]=isprime[1]=0;
    for(int i=2; i*i<=1000000; i++)
    {
        if(isprime[i])
        {
            for(int j=i*i; j<=1000000; j+=i)
                isprime[j]=0;
        }
    }
}
int build(int s , int e, int p = 1)  	// O(nlogn)
{
    if(s == e&&isprime[a[s]])	return  tree[p]=1;
    else if(s==e) return 0;
    return tree[p] = build(s, (s+e)/2, 2*p) + build((s+e)/2+1, e, 2*p+1);
}


void updateRange(int val,int s, int e, int p)
{
    if(lazy[p])
    {
        if(isprime[lazy[p]])
            tree[p]=e-s+1;
        else
            tree[p]=0;
        if(s!=e)
        {
            lazy[p*2]= lazy[p];
            lazy[p*2+1]= lazy[p];
        }
        lazy[p] = 0;
    }
    if(s>e||s>to||e<from)
        return;
    if(s>=from && e<= to)
    {
        if(isprime[val])
            tree[p]=e-s+1;
        else
            tree[p]=0;
        if(s!=e)
        {
            lazy[p*2] = val;
            lazy[p*2+1] = val;
        }
        lazy[p]=0;
        return;
    }
    int mid = (s + e) / 2;
    updateRange(val, s, mid,2*p);
    updateRange(val, mid+1, e,2*p+1);
    tree[p] = tree[p*2] + tree[p*2+1];
}

long long queryRange(int s,int e,int p)
{
    if(s>e||s>to||e<from)
        return 0;
    if(lazy[p])
    {
        if(isprime[lazy[p]])
            tree[p] = e-s+1;
        else
            tree[p]=0;
        if(s!=e)
        {
            lazy[p*2] = lazy[p];
            lazy[p*2+1] = lazy[p];
        }
        lazy[p] = 0;
    }
    if(s>=from&&e<= to)
        return tree[p];
    int mid = (s+ e) / 2;
    long long p1 = queryRange(s, mid,p*2);
    long long p2 = queryRange( mid + 1,e,p*2+1);
    return (p1 + p2);
}
int main()
{
    sieve();
    int t,n,q,k=1,w,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        printf("Case %d:\n",k++);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        build(0,n,1);
        for(int i=0; i<q; i++)
        {
            scanf("%d",&w);
            if(w)
            {
                scanf("%d %d",&from,&to);
                printf("%d\n",queryRange(0,n,1));
            }
            else
            {
                scanf("%d %d %d",&from,&to,&x);
                updateRange(x,0,n,1);
            }
        }
    }

    return 0;
}
