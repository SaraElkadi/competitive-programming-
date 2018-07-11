#include <bits/stdc++.h>

using namespace std;
const int MAX=400005;
int tree[MAX][3],lazy[MAX],from,to;
void build(int s,int e,int p)
{
    if(s==e)
    {
        tree[p][0]=1;
        tree[p][1]=tree[p][2]=0;
        return ;
    }
    build(s,(s+e)/2,2*p);
    build((s+e)/2+1,e,2*p+1);
    tree[p][0]=tree[2*p][0]+tree[2*p+1][0];
    tree[p][1]=tree[2*p][1]+tree[2*p+1][1];
    tree[p][2]=tree[2*p][2]+tree[2*p+1][2];
}

void updateRange(int s, int e, int p)
{
    if(lazy[p])
    {
        if(lazy[p]==2)
        {
            int temp0=tree[p][0],temp1=tree[p][1];
            tree[p][1]=tree[p][2];
            tree[p][0]=temp1;
            tree[p][2]=temp0;
        }
        else if(lazy[p]==1)
        {
            int temp0=tree[p][0],temp1=tree[p][1];
            tree[p][0]=tree[p][2];
            tree[p][2]=temp1;
            tree[p][1]=temp0;
        }
        if(s!=e)
        {
            lazy[2*p]+=lazy[p];
            lazy[2*p+1]+=lazy[p];
            lazy[2*p]%=3;
            lazy[2*p+1]%=3;
        }
        lazy[p] = 0;
    }
    if(s>e||s>to||e<from)
        return;
    if(s>=from && e<= to)
    {
        int temp0=tree[p][0],temp1=tree[p][1];
        tree[p][0]=tree[p][2];
        tree[p][2]=temp1;
        tree[p][1]=temp0;
        if(s!=e)
        {
            lazy[2*p]++;
            lazy[2*p+1]++;
            lazy[2*p]%=3;
            lazy[2*p+1]%=3;
        }
        lazy[p]=0;
        return;
    }
    int mid = (s + e) / 2;
    updateRange( s, mid,2*p);
    updateRange( mid+1, e,2*p+1);
    tree[p][0]=tree[2*p][0]+tree[2*p+1][0];
    tree[p][1]=tree[2*p][1]+tree[2*p+1][1];
    tree[p][2]=tree[2*p][2]+tree[2*p+1][2];
}
int queryRange(int s,int e,int p)
{

    if(s>e||s>to||e<from)
        return 0;
    if(lazy[p])
    {
        if(lazy[p]==2)
        {
            int temp0=tree[p][0],temp1=tree[p][1];
            tree[p][1]=tree[p][2];
            tree[p][0]=temp1;
            tree[p][2]=temp0;
        }
        else if(lazy[p]==1)
        {
            int temp0=tree[p][0],temp1=tree[p][1];
            tree[p][0]=tree[p][2];
            tree[p][2]=temp1;
            tree[p][1]=temp0;
        }
        if(s!=e)
        {
            lazy[2*p]+=lazy[p];
            lazy[2*p+1]+=lazy[p];
            lazy[2*p]%=3;
            lazy[2*p+1]%=3;
        }
        lazy[p] = 0;
    }
    if(s>=from&&e<= to)
        return tree[p][0];
    int mid = (s+ e) / 2;
    return queryRange(s, mid,p*2)+queryRange( mid + 1,e,p*2+1);

}
int main()
{
    int n,q,op;
    scanf("%d%d",&n,&q);
    build(1,n,1);
    for(int i=0; i<q; i++)
    {
        scanf("%d%d%d",&op,&from,&to);
        from++;
        to++;
        if(op==0)
            updateRange(1,n,1);
        else
            printf("%d\n",queryRange(1,n,1));
    }
    return 0;
}
