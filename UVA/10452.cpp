#include <bits/stdc++.h>

using namespace std;

const int N=9;
string g[N];
int parent[N][N];
string s="IEHOVA";
vector<string> v;
int n,m;

bool vaild(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m||parent[x][y]!=-1)
        return 0;
    for(int i=0; i<s.size(); i++)
        if(g[x][y]==s[i])
            return 1;
    if(g[x][y]=='#'||g[x][y]=='@')
        return 1;
    return 0;
}

void go(int x,int y,int p=-1)
{
    if(!vaild(x,y))
        return ;
    parent[x][y]=p;
    if(g[x][y]=='@')
        return ;
    go(x+1,y,x*100+y);
    go(x,y-1,x*100+y);
    go(x,y+1,x*100+y);
}

void path(int x,int y)
{
    if(parent[x][y]==-1||g[x][y]=='#')
    {
        if(!v.empty())
            cout<<v[0];
        for(int i=1; i<v.size(); i++)
            cout<<" "<<v[i];
        cout<<endl;
        return ;
    }
    int px=parent[x][y]/100,py=parent[x][y]%100;
    if(x==px+1)
        v.push_back("forth");
    else if(y==py-1)
        v.push_back("right");
    else if(y==py+1)
        v.push_back("left");
    path(px,py);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int s,e;
        for(int i=0; i<n; i++)
        {
            cin>>g[i];
            if(i==0)
            {
                for(int j=0; j<m; j++)
                {
                    if(g[i][j]=='#')
                    {
                        s=j;
                        break;
                    }
                }
            }
            if(i==n-1)
            {
                for(int j=0; j<m; j++)
                {
                    if(g[i][j]=='@')
                    {
                        e=j;
                        break;
                    }
                }
            }
        }
        memset(parent,-1,sizeof parent);
        v.clear();
        go(0,s);
        path(n-1,e);
    }
    return 0;
}
