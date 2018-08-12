/*
As the number of teams is 16, then there are 4 stages. at each stage the teams divide into groups 
in first stage, every group consist of (2^1) team  and In the second stage, every group consist of (2^2) team ,
and so on, (2^3),(2^4) in third and forth stage.

apply the same idea in the solution, get the probability of winning for each team in the first stage, 
Then in the second stage calculate the probability of winning if he played with all teams in his group 
except teams that already played with in the previous stages (used bool visit array to handle this),
and so on untill finish the four stages.

P.S: To calculate the probability of winning in any stage, we need the probabilities of previous stage only,
So I used array of two rows only to store probabilities of this and previous stage.
*/

#include <bits/stdc++.h>

using namespace std;
const int N=17;
double w[N][2];
int pro[N][N];
bool vis[N][N];
string s[N];
int k=1,p=1;

int main()
{
    for(int i=1; i<N; i++)
        cin>>s[i];
    for(int i=1; i<N; i++)
    {
        for(int j=1; j<N; j++)
            cin>>pro[i][j];
    }

    for(int i=0; i<N; i++)
        w[i][0]=1;

    while(k<=4)
    {
        for(int i=1; i<N; i++)
        {
            int r=pow(2,k);
            int st=((i-1)/r)*r+1;
            double temp=0;
            for(int j=st; j<st+r; j++)
            {
                if(i!=j&&!vis[i][j])
                {
                    temp+=w[j][p^1]*((double)pro[i][j]/100);
                    vis[i][j]=1;
                }
            }
            w[i][p]=w[i][p^1]*temp;
        }
        k++,p^=1;
    }

    for(int i=1; i<N; i++)
    {
        cout<<s[i];
        for(int j=0; j<10-s[i].size(); j++)
            cout<<" ";
        cout<<" p="<<fixed<<setprecision(2)<<w[i][0]*100<<"%\n";
    }
    return 0;
}
