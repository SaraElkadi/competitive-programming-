#include <bits/stdc++.h>

using namespace std;
const int MAX=200005;
int tree[524290];
int a[MAX],from,to,pos;
int build(int s,int e,int p)
{
    if(s==e)
        return tree[p]=a[s];
    return tree[p]=build(s,(s+e)/2,2*p)+build((s+e)/2+1,e,2*p+1);
}
int update(int num,int s,int e,int p)
{
    if(s==e)
        tree[p]=num;
    else
    {
        if(pos<=(s+e)/2)
            update(num,s,(s+e)/2,2*p);
        else
            update(num,(s+e)/2+1,e,2*p+1);
        tree[p]=tree[2*p]+tree[2*p+1];
    }
}
int query(int s = 0, int e = MAX, int p = 1)
{
    if (from <= s && to >= e)
        return tree[p];
    int mid = (s + e) / 2;
    if (to <= mid)
        return query(s, (s + e) / 2, 2 * p);
    if (from > mid)
        return query((s + e) / 2 + 1, e, 2 * p + 1);
    int a = query(s, (s + e) / 2, 2 * p);
    int b = query((s + e) / 2 + 1, e, 2 * p + 1);
    return a+b;
}

int main()
{
    int n,k=1,x;
    bool f=0;
    string s;
    while(cin>>n&&n!=0)
    {
        if(f)
            cout<<endl;
        f=1;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        build(0,n,1);
        cin>>s;
        cout<<"Case "<<k++<<":"<<endl;
        while(s!="END")
        {
            if(s=="S")
            {
                cin>>pos>>x;
                update(x,0,n,1);
            }
            else
            {
                cin>>from>>to;
                cout<<query(0,n,1)<<endl;
            }
            cin>>s;
        }
    }
    return 0;
}
