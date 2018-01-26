#include <bits/stdc++.h>

using namespace std;
int tree[400000],a[100005];
int from ,to;
int build (int s,int e,int p)
{
    if(s==e)
    {
        return  tree[p]=a[s];
    }
    return tree[p]=min(build(s,(s+e)/2,2*p),build((s+e)/2+1,e,2*p+1));
}
int query(int s,int e,int p)
{
    if(from<=s&&to>=e)
        return tree[p];
    int mid=(s+e)/2;
    if(to<=mid)
        return query(s,mid,2*p);
    if(from>mid)
        return query(mid+1,e,2*p+1);
    return min( query(s,mid,2*p),query(mid+1,e,2*p+1));
}
int main()
{
    int n,k=1;
    while(cin>>n)
    {
        for(int i=1; i<=n; i++)
            cin>>a[i];
        memset(tree,0,sizeof tree);
        build(1,n,1);
        int ans=0;
        map<int,int> mp;
        for(int i=1; i<=n; i++)
        {
            if(!mp[a[i]]&&a[i]!=0)
            {
                ans++;
                mp[a[i]]=i;
            }
            else if(a[i]!=0)
            {
                from=mp[a[i]],to=i;
                int x=query(1,n,1);
                if(x<a[i])
                    ans++;
                mp[a[i]]=i;
            }
        }
        cout<<"Case "<<k++<<": "<<ans<<endl;
    }
    return 0;
}
