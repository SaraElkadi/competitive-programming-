#include <bits/stdc++.h>

using namespace std;

int dx[]= {1,-1,1,-1,1,-1,0,0};
int dy[]= {0,0,1,-1,-1,1,1,-1};

const int N=26;
bool vis[N][N];
string grid[N];
int n;

bool vaild(int x,int y)
{
    if(x<0||x>=n||y<0||y>=n||grid[x][y]=='0'||vis[x][y])
        return 0;
    return 1;
}

void WarMark(int x,int y)
{
    if(!vaild(x,y))
        return ;
    vis[x][y]=1;
    for(int i=0; i<8; i++)
    {
        WarMark(x+dx[i],y+dy[i]);
    }
}

int WarsCount()
{
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(vaild(i,j))
            {
                WarMark(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    int t=1;
    while(cin>>n){
      for(int i=0;i<n;i++){
            cin>>grid[i];
            for(int j=0;j<n;j++)
                vis[i][j]=0;
      }
      cout<<"Image number "<<t<<" contains "<<WarsCount()<<" war eagles."<<endl;
      t++;
    }
    return 0;
}
