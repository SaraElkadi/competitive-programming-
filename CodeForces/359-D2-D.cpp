#include <bits/stdc++.h>

using namespace std;
const int MAX=300005;
pair<int,int> tree[4*MAX];
int a[MAX],from,to,n;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void build(int s,int e,int p)
{
    if(s==e)
    {
        tree[p].second=a[s];
        tree[p].first=a[s];
        return ;
    }
    build(s,(s+e)/2,2*p);
    build((s+e)/2+1,e,2*p+1);
    tree[p].first=min(tree[2*p].first,tree[2*p+1].first);
    tree[p].second=gcd(tree[2*p].second,tree[2*p+1].second);
}

pair<int,int> query(int s , int e , int p)
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
    pair<int,int> a = query(s, (s + e) / 2, 2 * p);
    pair<int,int> b = query((s + e) / 2 + 1, e, 2 * p + 1);
    return make_pair(min(a.first,b.first),gcd(a.second,b.second));
}
bool solve(int x)
{
    for(from=1,to=1+x; to<=n; from++,to++)
    {
        pair<int,int> p=query(1,n,1);
        if(p.first==p.second)
            return 1;
    }
    return 0;
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    build(1,n,1);
    int l=0,r=n,ans=0;
    while(r>l+1)
    {
        int mid=(l+r)>>1;
        if(solve(mid))
        {
            ans=max(mid,ans);
            l=mid;
        }
        else
            r=mid;
    }
    vector<int> v;
    for(from=1,to=1+ans; to<=n; from++,to++)
    {
        pair<int,int> p=query(1,n,1);
        if(p.first==p.second)
            v.push_back(from);
    }
    cout<<v.size()<<" "<<ans<<endl;
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
}
