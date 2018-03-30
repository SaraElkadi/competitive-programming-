 /* solved by bfs 
    use array to save the number of mirrors at each cell and initalize it by Max_Value
    from any cell, try to go to all possible cells by using one mirror if this minimize the number of mirrors to go from source node to this cell
    after finish bfs , the array store(the minimum number of mirriors to go from source cell to this cell - 1) 
    as at source node we don't need any mirror to go to other adjcant cell*/


#include <bits/stdc++.h>

using namespace std;
int n,m,y2,x2;
string a[105];
int mir[105][105];
void bfs(pair<int,int> p)
{
    queue<pair<int,int> > q;
    q.push(p);
    mir[p.first][p.second]=0;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        int u=x,v=y;
        while(u<n-1&&a[u+1][y]!='*'){
            if(mir[u+1][y]>mir[x][y]+1){
                q.push(make_pair(u+1,y));
                mir[u+1][y]=mir[x][y]+1;
            }
            u++;
        }
        u=x;
        while(u>0&&a[u-1][y]!='*'){
            if(mir[u-1][y]>mir[x][y]+1){
                q.push(make_pair(u-1,y));
                mir[u-1][y]=mir[x][y]+1;
            }
            u--;
        }
        while(v<m-1&&a[x][v+1]!='*'){
            if(mir[x][v+1]>mir[x][y]+1){
                q.push(make_pair(x,v+1));
                mir[x][v+1]=mir[x][y]+1;
            }
            v++;
        }
        v=y;
         while(v>0&&a[x][v-1]!='*'){
            if(mir[x][v-1]>mir[x][y]+1){
                q.push(make_pair(x,v-1));
                mir[x][v-1]=mir[x][y]+1;
            }
            v--;
        }
    }
}
int main()
{
    scanf("%d %d",&m,&n);
    for(int i=0; i<104; i++)
    {
        for(int j=0; j<104; j++)
            mir[i][j]=1e9;
    }
    char x[104];
    vector<pair<int,int> > p;
    for(int i=0; i<n; i++)
    {
        scanf("%s",x);
        a[i]=x;
        for(int j=0; j<m&&p.size()<2; j++)
        {
            if(a[i][j]=='C')
                p.push_back(make_pair(i,j));
        }
    }
    bfs(p[0]);
    printf("%d\n",mir[p[1].first][p[1].second]-1);
    return 0;
}
