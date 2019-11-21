#include <bits/stdc++.h>

using namespace std;
const int N=101;
string g[N];
bool vis[N][N];
int dx[]= {0,0,-1,1};
int dy[]= {1,-1,0,0};
int n;

bool vaild(int x,int y)
{
    if(x<0||x>=n||y<0||y>=n||vis[x][y]||g[x][y]=='.')
        return 0;
    return 1;
}
void markShip(int x,int y)
{
    if(!vaild(x,y))
        return ;
    vis[x][y]=1;
    for(int i=0; i<4; i++)
    {
        markShip(x+dx[i],y+dy[i]);
    }
}
int countLiveShips()
{
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(g[i][j]=='x'&&!vis[i][j])
            {
                markShip(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>g[i];
            for(int j=0; j<n; j++)
                vis[i][j]=0;
        }
        cout<<"Case "<<i<<": "<<countLiveShips()<<endl;
    }
    return 0;
}
