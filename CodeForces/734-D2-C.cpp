#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k,x,s;
    cin>>n>>m>>k>>x>>s;
    vector<int> a,b,c,d;
    int q;
    for(int i=0;i<m;i++){
        cin>>q;
        a.push_back(q);
    }
     for(int i=0;i<m;i++){
        cin>>q;
        b.push_back(q);
    }
     for(int i=0;i<k;i++){
        cin>>q;
        c.push_back(q);
    }
     for(int i=0;i<k;i++){
        cin>>q;
        d.push_back(q);
    }
    long long ans=(long long)n*x;
     int w=upper_bound(d.begin(),d.end(),s)-d.begin();
    ans=min(ans,(long long)(n-(w>0?c[w-1]:0))*x);
    for(int i=0;i<m;i++){
        if(b[i]<=s){
             w=upper_bound(d.begin(),d.end(),s-b[i])-d.begin();
            ans=min(ans,(long long)(n-(w>0?c[w-1]:0))*a[i]);
        }
    }
    if(ans>0)
        cout<<ans;
    else
        cout<<0;
    return 0;
}
