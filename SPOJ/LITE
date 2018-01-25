#include <bits/stdc++.h>

using namespace std;
const int MAX=400000;
int from,to;
int tree[MAX],lazy[MAX];

void updateRange(int s, int e, int p)
{
    if(lazy[p])
    {
        tree[p]=(e-s+1)-tree[p];
        if(s!=e)
        {
            lazy[p*2] =(lazy[p*2]+lazy[p])%2;
            lazy[p*2+1] = (lazy[p*2+1]+lazy[p])%2;
        }
        lazy[p] = 0;
    }
    if(s>e||s>to||e<from)
        return;
    if(s>=from && e<= to)
    {
        tree[p]=(e-s+1)-tree[p];
        if(s!=e)
        {
            lazy[p*2] = !lazy[p*2];
            lazy[p*2+1] = !lazy[p*2+1];
        }
        lazy[p]=0;
        return;
    }
    int mid = (s + e) / 2;
    updateRange(s, mid,2*p);
    updateRange(mid+1, e,2*p+1);
    tree[p] = tree[p*2] + tree[p*2+1];
}

long long queryRange(int s,int e,int p)
{
    if(s>e||s>to||e<from)
        return 0;
    if(lazy[p])
    {
            tree[p] = (e-s+1)-tree[p];
        if(s!=e)
        {
            lazy[p*2] =(lazy[p*2]+lazy[p])%2;
            lazy[p*2+1] = (lazy[p*2+1]+lazy[p])%2;
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
    int n,m,op;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&op,&from,&to);
        if(op==0){
            updateRange(0,n,1);
        }
        else
            printf("%d\n",queryRange(0,n,1));
    }
    return 0;
}
