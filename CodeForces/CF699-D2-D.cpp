#include <bits/stdc++.h>

using namespace std;
const int MAX=200005;
int parent[200005];
int find_set (int v)
{
    if (v == parent[v])
        return v;
    return parent[v]=find_set (parent[v]);
}

void union_sets (int a, int b)
{
    a = find_set (a);
    b = find_set (b);
    if (a != b)
        parent[b] = a;
}
int main()
{
    int n,cnt=0;
    cin>>n;
    bool f[MAX]={0},r=0;
    int root,a[MAX];
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==i&&!r){
            root=i;
            r=1;
        }
        else if(a[i]==i){
            f[i]=1;
            cnt++;
        }
        else if(find_set(i)!=find_set(a[i])){
            union_sets(i,a[i]);
        }
        else{
            f[i]=1;
            cnt++;
        }
    }
    if(!r){
        for(int i=1;i<=n;i++){
            if(f[i]==1){
                root=i;
                a[i]=i;
                f[i]=0;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(f[i]){
            a[i]=root;
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}
