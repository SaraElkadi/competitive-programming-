#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,t,r;
    cin>>n>>m;
    int a[n],b[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    vector<pair<int,int> > s;
    for(int i=0; i<m; i++)
    {
        cin>>t>>r;
        while(!s.empty()&&s.back().first<=r)
            s.pop_back();
        s.push_back(make_pair(r,t));
    }
    for(int i=s[0].first; i<n; i++)
        b[i]=a[i];
    sort(a,a+s[0].first);
    int R=s[0].first-1,L=0;
    s.push_back(make_pair(0,1));
    for(int i=0; i+1<s.size(); i++)
    {
        while(s[i].first>s[i+1].first)
        {
            s[i].first--;
            if(s[i].second==1) b[s[i].first]=a[R--];
            else b[s[i].first]=a[L++];
        }
    }
    for(int i=0; i<n; i++)
        cout<<b[i]<<" ";

    return 0;
}
