#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,a,b;
    cin>>n;
    vector<pair<pair<int,int> ,int> > v1,v2;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        v1.push_back(make_pair(make_pair(a,b),i+1));
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        v2.push_back(make_pair(make_pair(a,b),i+1));
    }
    sort(v1.begin(),v1.end(),greater<pair<pair<int,int> ,int>>());
    sort(v2.begin(),v2.end(),greater<pair<pair<int,int> ,int>>());
    set<pair<int,int> >s;
    int i=0,j=0;
    bool f=1;
    int ans[n+5];
    while(i<n)
    {
        while(j<m&&v2[j].first.first>=v1[i].first.first)
        {
            s.insert(make_pair(v2[j].first.second,v2[j].second));
            j++;
        }
        auto it= s.lower_bound(make_pair(v1[i].first.second,-1));
        if(it!=s.end())
        {
            ans[v1[i].second]=(*it).second;
            s.erase(it);
        }
        else
        {
            f=0;
            break;
        }
        i++;
    }
    if(!f)
        cout<<-1;
    else
    {
        for(int i=1; i<=n; i++)
            cout<<ans[i]<<" ";
    }
    return 0;
}
