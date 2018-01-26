#include <bits/stdc++.h>

using namespace std;
const int MAX=120000;
pair<int,int> tree[MAX];
char a[30005];
void build(int s,int e,int p)
{
    if(s==e)
    {
        if(a[s]=='(')
        {
            tree[p].first=1;
            tree[p].second=0;
        }
        else if(a[s]==')')
        {
            tree[p].second=1;
            tree[p].first=0;
        }
        return ;
    }
    build(s,(s+e)/2,2*p);
    build((s+e)/2+1,e,2*p+1);
    tree[p].first=tree[2*p+1].first;
    tree[p].second=tree[2*p].second;
    if(tree[2*p].first>=tree[2*p+1].second)
        tree[p].first+=tree[2*p].first-tree[2*p+1].second;
    else
        tree[p].second+=tree[2*p+1].second-tree[2*p].first;
}
void update(int idx,int s,int e,int p)
{
    if(s==e)
    {
         if(a[idx]=='(')
        {
            tree[p].first=1;
            tree[p].second=0;
        }
        else if(a[idx]==')')
        {
            tree[p].second=1;
            tree[p].first=0;
        }
    }
    else
    {
        if(idx<=(s+e)/2)
            update(idx,s,(s+e)/2,2*p);
        else
            update(idx,(s+e)/2+1,e,2*p+1);

        tree[p].first=tree[2*p+1].first;
        tree[p].second=tree[2*p].second;
        if(tree[2*p].first>=tree[2*p+1].second)
            tree[p].first+=tree[2*p].first-tree[2*p+1].second;
        else
            tree[p].second+=tree[2*p+1].second-tree[2*p].first;
    }
}

int main()
{
    //freopen("out.txt","w",stdout);
    int n,m,k;
    for(int t=1;t<=10;t++)
    {
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        cout<<"Test "<<t<<":"<<endl;
        build(1,n,1);
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>k;
            if(!k)
            {
                if(tree[1].first==0&&tree[1].second==0)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
            else
            {
                if(a[k]==')')
                  a[k]='(';
                else
                    a[k]=')';
                update(k,1,n,1);
            }
        }
    }
    return 0;
}
