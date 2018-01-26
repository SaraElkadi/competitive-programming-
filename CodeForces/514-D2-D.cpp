#include <bits/stdc++.h>

using namespace std;
int n,m,k;
int a[100005][10];
vector<vector<int> >tree(400000,vector<int>(10,0));
int from,to;
void build(int s,int e,int p)
{
    if(s==e)
    {
        for(int i=0; i<m; i++)
            tree[p][i]=a[s][i];
        return ;
    }
    build(s,(s+e)/2,2*p);
    build((s+e)/2+1,e,2*p+1);
    for(int i=0; i<m; i++)
        tree[p][i]=max(tree[2*p][i],tree[2*p+1][i]);
}
vector<int> query(int s,int e,int p)
{
    if(from<=s&&to>=e)
        return tree[p];
    int mid=(s+e)/2;
    if(to<=mid)
        return query(s,mid,2*p);
    if(from>mid)
        return query(mid+1,e,2*p+1);
    vector<int> a=query(s,mid,2*p);
    vector<int> b=query(mid+1,e,2*p+1);
    vector<int> ans(m);
    for(int i=0; i<m; i++)
        ans[i]=max(a[i],b[i]);
    return ans;
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<m; j++)
            scanf("%d",&a[i][j]);
    }
    build(1,n,1);
    from=1,to=1;
    int mx=0,mxr=0,mxl=0,mxs=0;
    while(to<=n)
    {
        if(to<from)
            break;
        vector<int> w=query(1,n,1);
        int sum=0;
        for(int j=0; j<m; j++)
        {
            sum+=w[j];
        }
        if(sum<=k)
        {
            if(mx<to-from+1)
            {
                mx=to-from+1;
                mxr=to;
                mxl=from;
                mxs=sum;
            }
            to++;
        }
        else from++;
    }
    if(mxr!=0&&mxl!=0)
    {
        from=mxl;
        to=mxr;
        vector<int> w=query(1,n,1);
        for(int j=0; j<m-1; j++)
            printf("%d ",w[j]);
        printf("%d ",w[m-1]+(k-mxs));
    }
    else
    {
        printf("%d",k);
        for(int i=1; i<m; i++)
            printf(" 0");
    }
    return 0;
}
