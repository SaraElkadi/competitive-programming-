#include <bits/stdc++.h>

using namespace std;
int dx[]={1,-1,-1,1,0,0,1,-1};
int dy[]={1,-1,1,-1,1,-1,0,0};
int main()
{
    int x1,x2,y1,y2,n,r,a,b;
    cin>>x1>>y1>>x2>>y2>>n;
    map<pair<int,int>,int> mp;
    while(n--)
    {
        cin>>r>>a>>b;
        for(int i=a; i<=b; i++)
        {
            mp[make_pair(r,i)]=1;
        }
    }
    queue<pair<int,int> >q;
    q.push(make_pair(x1,y1));
    int sz=1,dep=0,ans=-1;
    for(;!q.empty()&&ans==-1;dep++,sz=q.size())
    {
      //  cout<<"Y"<<endl;
        while(sz--)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==x2&&y==y2)
            {
                ans=dep;
                break;
            }
            for(int i=0; i<8; i++)
            {
                if(mp[make_pair(x+dx[i],y+dy[i])]==1)
                {
                    q.push(make_pair(x+dx[i],y+dy[i]));
                    mp[make_pair(x+dx[i],y+dy[i])]=2;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
