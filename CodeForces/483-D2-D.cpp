#include <bits/stdc++.h>

using namespace std;
const int MAX=100005;
int tree[4*MAX],a[MAX],n,m;
void build(int s=1,int e=n,int p=1)
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
int query(int from ,int to ,int s=1 , int e=n , int p=1)
{
    if (from <= s && to >= e)
    {
        return tree[p];
    }
    int mid = (s + e) / 2;
    if (to <= mid)
        return query(from ,to,s, (s + e) / 2, 2 * p);
    if (from > mid)
        return query(from,to,(s + e) / 2 + 1, e, 2 * p + 1);
    return query(from,to,s, (s + e) / 2, 2 * p)&query(from,to,(s + e) / 2 + 1, e, 2 * p + 1);
}

int main()
{
    cin>>n>>m;
    int l[m],r[m],q[m];
    for(int i=0; i<m; i++)
    {
        cin>>l[i]>>r[i]>>q[i];
    }
    for(int i=0; i<30; i++)
    {
        int b[100005]= {0};
        for(int j=0; j<m; j++)
        {
            if(q[j]&(1<<i))
            {
                b[l[j]]++;
                b[r[j]+1]--;
            }
        }
        for(int j=1; j<=n; j++)
        {
            b[j]+=b[j-1];
            if(b[j]>0)
                a[j]|=(1<<i);
        }
    }
    build();
    for(int i=0; i<m; i++)
    {

        if(query(l[i],r[i])!=q[i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    return 0;
}
