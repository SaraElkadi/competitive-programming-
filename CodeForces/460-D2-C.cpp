#include <bits/stdc++.h>

using namespace std;
const int MAX=400000;
int from,to;
long long a[100005];
pair<int,int>tree[MAX];
int lazy[MAX];

void build(int s , int e, int p = 1)
{
    if(s == e){
        tree[p]=make_pair(a[s],s);
     return ;
    }
    build(s, (s+e)/2, 2*p);
    build((s+e)/2+1, e, 2*p+1);
    if(tree[2*p].first<tree[2*p+1].first)
       tree[p]=tree[2*p];
    else if(tree[2*p].first>tree[2*p+1].first)
         tree[p]=tree[2*p+1];
    else
        tree[p]=make_pair(tree[2*p].first,min(tree[2*p].second,tree[2*p+1].second));
   // return tree[p]=min(build(s, (s+e)/2, 2*p) ,build((s+e)/2+1, e, 2*p+1));
}
void updateRange(int val,int s, int e, int p)
{
    if(lazy[p])
    {
        tree[p].first+=lazy[p];
        if(s!=e)
        {
            lazy[p*2]+= lazy[p];
            lazy[p*2+1]+= lazy[p];
        }
        lazy[p] = 0;
    }
    if(s>e||s>to||e<from)
        return;
    if(s>=from && e<= to)
    {
        tree[p].first+=val;
        if(s!=e)
        {
            lazy[p*2]+= val;
            lazy[p*2+1] += val;
        }
        lazy[p]=0;
        return;
    }
    int mid = (s + e) / 2;
    updateRange(val, s, mid,2*p);
    updateRange(val, mid+1, e,2*p+1);
   if(tree[2*p].first<tree[2*p+1].first)
       tree[p]=tree[2*p];
    else if(tree[2*p].first>tree[2*p+1].first)
         tree[p]=tree[2*p+1];
    else
        tree[p]=make_pair(tree[2*p].first,min(tree[2*p].second,tree[2*p+1].second));
}

pair<int,int> queryRange(int s,int e,int p)
{
    if(s>e||s>to||e<from)
        return make_pair(1e9+1e6,1e9+1e6);
    if(lazy[p])
    {
        tree[p].first += lazy[p];
        if(s!=e)
        {
            lazy[p*2]+= lazy[p];
            lazy[p*2+1] += lazy[p];
        }
        lazy[p] = 0;
    }
    if(s>=from&&e<= to)
        return tree[p];
    int mid = (s+ e) / 2;
    pair<int,int> p1 = queryRange(s, mid,p*2);
    pair<int,int> p2 = queryRange( mid + 1,e,p*2+1);
    if(p1.first<p2.first)
       return p1;
    else if(p1.first>p2.first)
         return p2;
    else
        return make_pair(p1.first,min(p1.second,p2.second));
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,n,1);
    for(int i=0;i<m;i++){
        from=1,to=n;
        int q=queryRange(1,n,1).second;
        from=q,to=q+k-1;
        updateRange(1,1,n,1);
    }
    from=1,to=n;
    cout<<queryRange(1,n,1).first;

    return 0;
}
