#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n;
    pair<pair<int,int>,int> c[n];
    for(int i=0; i<n; i++)
    {
        cin>>c[i].first.first>>c[i].first.second;
        c[i].second=i;
    }
    cin>>m;
    pair<int,int> p[m];
    for(int i=0; i<m; i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    sort(c,c+n);
    int cnt=0,ans[n];
    memset(ans,-1,sizeof ans);
    for(int i=0; i<m; i++)
    {
        int l=0,h=n-1,q=1e6;
        while(l<=h)
        {
            int mid=(l+h)/2;
            double d=sqrt((c[mid].first.first-p[i].first)*(c[mid].first.first-p[i].first)+p[i].second*p[i].second);
            if(d<=c[mid].first.second&&ans[c[mid].second]==-1)
            {
                ans[c[mid].second]=i+1;
                cnt++;
            }
            if(c[mid].first.first-c[mid].first.second>=p[i].first)
                h=mid-1;
            else if(c[mid].first.first+c[mid].first.second<=p[i].first)
                l=mid+1;
            else
                break;
        }
    }
    cout<<cnt<<endl;
    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";
    return 0;
}
