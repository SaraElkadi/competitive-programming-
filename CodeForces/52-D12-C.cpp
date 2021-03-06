#include <bits/stdc++.h>

using namespace std;
const int MAX=800000;
int from,to;
long long a[200005];
long long tree[MAX],lazy[MAX];

long long build(int s , int e, int p = 1)
{
    if(s == e)	return  tree[p]=a[s];
    return tree[p]=min(build(s, (s+e)/2, 2*p) ,build((s+e)/2+1, e, 2*p+1));
}
void updateRange(int val,int s, int e, int p)
{
    if(lazy[p])
    {
        tree[p]+=lazy[p];
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
        tree[p]+=val;
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
    tree[p] = min(tree[p*2] ,tree[p*2+1]);
}

long long queryRange(int s,int e,int p)
{
    if(s>e||s>to||e<from)
        return 1e18;
    if(lazy[p])
    {
        tree[p] += lazy[p];
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
    long long p1 = queryRange(s, mid,p*2);
    long long p2 = queryRange( mid + 1,e,p*2+1);
    return min(p1,p2);
}
int main()
{
    int n,q,x,y,val;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%lld",&a[i]);
    build(1,n,1);
    scanf("%d",&q);
    string s;
    getline(cin,s);
    for(int i=0; i<q; i++)
    {
        getline(cin,s);
        istringstream ss(s);
        int cnt=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==' ')
                cnt++;
        }
        if(cnt==1)
        {
            ss>>x>>y;
            x++,y++;
            if(x<=y)
            {
                from=x,to=y;
                printf("%lld\n",queryRange(1,n,1));
              //cout<<queryRange(1,n,1)<<endl;
            }
            else
            {
                from=x,to=n;
                long long a=queryRange(1,n,1);
                from=1,to=y;
                long long b=queryRange(1,n,1);
                printf("%lld\n",min(a,b));
               // cout<<min(a,b)<<endl;
            }
        }
        else
        {
            ss>>x>>y>>val;
            x++,y++;
            if(x<=y)
            {
                from=x,to=y;
                updateRange(val,1,n,1);
            }
            else
            {
                from=x,to=n;
                updateRange(val,1,n,1);
                from=1,to=y;
                updateRange(val,1,n,1);
            }
        }
    }
    return 0;
}
