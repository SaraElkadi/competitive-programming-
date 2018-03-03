#include <bits/stdc++.h>

using namespace std;
const int MAX=100100;
vector<bool> pri(MAX+5,1);
vector<int> v;
void sieve()
{
    pri[0]=pri[1]=0;
    for(int i=2; i*i<MAX; i++)
    {
        if(pri[i])
        {
            for(int j=i*i; j<MAX; j+=i)
                pri[j]=0;
        }
    }
    for(int i=0;i<MAX;i++){
        if(pri[i])
            v.push_back(i);
    }
}
int a[MAX],pos[MAX];
int main()
{
    sieve();
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    vector<pair<int,int> > ans;
    for(int i=1; i<=n; i++)
    {
        while(pos[i]!=i)
        {
            int s=lower_bound(v.begin(),v.end(),pos[i]-i+1)-v.begin();
            while(v[s]>pos[i]-i+1)
                s--;
            int x1=pos[i],x2=pos[i]-v[s]+1;
            if(x1>x2)
                swap(x1,x2);
            swap(a[x1],a[x2]);
            swap(pos[a[x1]],pos[a[x2]]);
            ans.push_back(make_pair(x1,x2));

        }
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
