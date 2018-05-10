#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;
vector<pair<int,int>> legs;
vector<int> eng(205,0);
int engup[N];
int main()
{
    int n;
    cin>>n;
    int l[n],d[n];
    for(int i=0; i<n; i++)
        cin>>l[i];
    for(int i=0; i<n; i++)
        cin>>d[i];
    for(int i=0; i<n; i++)
        legs.push_back({l[i],d[i]});
    sort(legs.begin(),legs.end());
    for(int i=n-1; i>=0; i--)
        engup[i]=engup[i+1]+legs[i].second;
    int ans=engup[0];
    for(int i=0,j=0; i<n; i=j)
    {
        while(j<n&&legs[i].first==legs[j].first)
            j++;
        int sum=0,nd=i-((j-i)-1);
        for(int k=1; nd>0; k++)
        {
            int x=min(nd,eng[k]);
            sum+=x*k;
            nd-=x;
        }
        ans=min(ans,sum+engup[j]);
        for(int k=i; k<j; k++)
            eng[legs[k].second]++;
    }
    cout<<ans;
    return 0;
}
