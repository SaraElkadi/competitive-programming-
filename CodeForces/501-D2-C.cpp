#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int d[n],s[n];
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        cin>>d[i]>>s[i];
        if(d[i]==1)
            q.push(i);
    }
    vector<pair<int,int> >v;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(d[x]==0)
            continue;
        d[x]--;
        int to=s[x];
        s[x]=0;
        v.push_back(make_pair(x,to));
        d[to]--;
        s[to]^=x;
        if(d[to]==1)
            q.push(to);

    }
    cout<<v.size()<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}
