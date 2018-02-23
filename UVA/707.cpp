#include <bits/stdc++.h>

using namespace std;
int g[130][130][130];
int dx[]= {0,0,1,-1,0};
int dy[]= {1,-1,0,0,0};
int w,h,T,n,t,r,l,u,d,k=1;
void dfs1(int t,int x,int y)
{
    if(t==T||g[t][x][y]==2)
    {
        g[t][x][y]=2;
        return ;
    }
    for(int i=0; i<5; i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx>0&&yy>0&&xx<=w&&yy<=h&&g[t+1][xx][yy]!=1)
        {
            g[t][x][y]=2;
            dfs1(t+1,xx,yy);
        }

    }
}

void dfs2(int t,int x,int y)
{
    if(t==1||g[t][x][y]==3)
    {
        g[t][x][y]=3;
        return ;
    }
    for(int i=0; i<5; i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx>0&&yy>0&&xx<=w&&yy<=h&&(g[t-1][xx][yy]==2||g[t-1][xx][yy]==3))
        {
            g[t][x][y]=3;
            dfs2(t-1,xx,yy);
        }

    }
}

int main()
{
    while(cin>>w>>h>>T&&(w||h||T))
    {
        cin>>n;
        memset(g,0,sizeof g);
        while(n--)
        {
            cin>>t>>l>>d>>r>>u;
            for(int i=l; i<=r; i++)
            {
                for(int j=d; j<=u; j++)
                    g[t][i][j]=1;
            }

        }
        for(int i=1;i<=w;i++){
            for(int j=1;j<=h;j++){
                if(g[1][i][j]!=1)
                    dfs1(1,i,j);
            }
        }
        for(int i=1;i<=w;i++){
            for(int j=1;j<=h;j++){
                if(g[T][i][j]==2)
                    dfs2(T,i,j);
            }
        }
        cout<<"Robbery #"<<k++<<":"<<endl;
        int f=1;
        for(int i=1; i<=T; i++)
        {
            int q=0,x,y;
            for(int j=1; j<=w; j++)
            {
                for(int k=1; k<=h; k++)
                {
                    if(g[i][j][k]==3)
                        q++,x=j,y=k;
                }
            }
            if(q==0)
            {
                cout<<"The robber has escaped."<<endl;
                f=0;
                break;
            }
            if(q==1)
            {
                cout<<"Time step "<<i<<": The robber has been at "<<x<<","<<y<<"."<<endl;
                f=0;
            }
        }
        if(f)
            cout<<"Nothing known."<<endl;
        cout<<endl;
    }
    return 0;
}
