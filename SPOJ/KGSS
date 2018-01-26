#include <bits/stdc++.h>

using namespace std;
const int MAX=400000;
pair<int,int> tree[MAX];
int a[100005],from,to,pos;
void build(int s,int e,int p)
{
    if(s==e)
    {
        tree[p].second=a[s];
        tree[p].first=0;
        return ;
    }
    build(s,(s+e)/2,2*p);
    build((s+e)/2+1,e,2*p+1);
    if(tree[2*p].second>=tree[2*p+1].second)
    {
        tree[p].second=tree[2*p].second;
        if(tree[2*p+1].second>=tree[2*p].first)
            tree[p].first=tree[2*p+1].second;
        else
            tree[p].first=tree[2*p].first;
    }
    else
    {
        tree[p].second=tree[2*p+1].second;
        if(tree[2*p].second>=tree[2*p+1].first)
            tree[p].first=tree[2*p].second;
        else
            tree[p].first=tree[2*p+1].first;
    }
}
void update(int num,int s,int e,int p)
{
    if(s==e)
    {
        tree[p].second=num;
    }
    else
    {
        if(pos<=(s+e)/2)
            update(num,s,(s+e)/2,2*p);
        else
            update(num,(s+e)/2+1,e,2*p+1);

        if(tree[2*p].second>=tree[2*p+1].second)
        {
            tree[p].second=tree[2*p].second;
            if(tree[2*p+1].second>=tree[2*p].first)
                tree[p].first=tree[2*p+1].second;
            else
                tree[p].first=tree[2*p].first;
        }
        else
        {
            tree[p].second=tree[2*p+1].second;
            if(tree[2*p].second>=tree[2*p+1].first)
                tree[p].first=tree[2*p].second;
            else
                tree[p].first=tree[2*p+1].first;
        }
    }
}

pair<int,int> query(int s , int e , int p)
{
    if (from <= s && to >= e)
    {
        return tree[p];
    }
    pair<int,int> res(0,0);
    int mid = (s + e) / 2;
    if (to <= mid)
        return query(s, (s + e) / 2, 2 * p);
    if (from > mid)
        return query((s + e) / 2 + 1, e, 2 * p + 1);
    pair<int,int> a = query(s, (s + e) / 2, 2 * p);
    pair<int,int >b = query((s + e) / 2 + 1, e, 2 * p + 1);
    pair<int,int> pp;
    if(a.second>=b.second)
    {
        pp.second=a.second;
        if(b.second>=a.first)
            pp.first=b.second;
        else
            pp.first=a.first;
    }
    else
    {
        pp.second=b.second;
        if(a.second>=b.first)
            pp.first=a.second;
        else
            pp.first=b.first;
    }
    return res=make_pair(max(min(pp.second,res.second),max(res.first,pp.first)),max(pp.second,res.second));
}
int main()
{
    int n,m,x,y;
    char c;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    build(0,n,1);
    scanf("%d",&m);
    for(int i=0; i<m; i++)
    {
        cin>>c>>x>>y;
        if(c=='Q')
        {
            from=x,to=y;
            pair<int,int> p=query(0,n,1);
            printf("%d\n",p.first+p.second);
        }
        else if(c=='U')
        {
            pos=x;
            update(y,0,n,1);
        }
    }
    return 0;
}
