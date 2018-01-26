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
void update(int idx,int val,int s,int e,int p)
{
    if(s==e)
    {
         tree[p]=val;
    }
    else
    {
        if(idx<=(s+e)/2)
            update(idx,val,s,(s+e)/2,2*p);
        else
            update(idx,val,(s+e)/2+1,e,2*p+1);
        tree[p]=min(tree[2*p],tree[2*p+1]);
    }

}
int main()
{
    int n,q;
    string s;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    build(1,n,1);
    for(int i=0;i<q;i++){
        cin>>s;
        vector<int> v;
        int w=0;
        if(s[0]=='q'){
            for(int i=6;i<s.size();i++){
                if(s[i]!=','&&s[i]!=')'){
                    w=w*10+(s[i]-'0');
                }
                else{
                    v.push_back(w);
                    w=0;
                }
            }
            from=v[0],to=v[1];
            cout<<query(1,n,1)<<endl;
        }
        else{
           for(int i=6;i<s.size();i++){
                if(s[i]!=','&&s[i]!=')'){
                    w=w*10+(s[i]-'0');
                }
                else{
                    v.push_back(w);
                    w=0;
                }
            }
            int temp=a[v[0]];
            for(int i=1;i<v.size();i++){
                update(v[i-1],a[v[i]],1,n,1);
                a[v[i-1]]=a[v[i]];
            }
            update(v.back(),temp,1,n,1);
            a[v.back()]=temp;
        }
    }
    return 0;
}
