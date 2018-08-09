#include <bits/stdc++.h>

using namespace std;

bool oneWin(vector<string> &s)
{
    for(int i=0; i<4; i++)
    {
        if(s[i][0]==s[i][1]&&s[i][1]==s[i][2]&&s[i][2]==s[i][3]&&s[i][3]!='.')
            return 1;
        if(s[0][i]==s[1][i]&&s[1][i]==s[2][i]&&s[2][i]==s[3][i]&&s[3][i]!='.')
            return 1;
    }
    if(s[0][0]==s[1][1]&&s[1][1]==s[2][2]&&s[2][2]==s[3][3]&&s[3][3]!='.')
        return 1;
    if(s[0][3]==s[1][2]&&s[1][2]==s[2][1]&&s[2][1]==s[3][0]&&s[3][0]!='.')
        return 1;
    return 0;
}

int isWinning(vector<string> &s,int p)
{
    if(oneWin(s))
        return 0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {

            if(s[i][j]=='.')
            {
                if(p)
                    s[i][j]='o';
                else
                    s[i][j]='x';
                bool f=isWinning(s,p^1);
                s[i][j]='.';
                if(!f)
                    return 1;
            }

        }
    }
    return 0;
}

int main()
{
    char c;
    vector<string> s(4);
    while(cin>>c&&c!='$')
    {
        for(int i=0; i<4; i++)
        {
            cin>>s[i];
        }
        bool ans=0;
        for(int i=0; i<4&&!ans; i++)
        {
            for(int j=0; j<4&&!ans; j++)
            {
                if(s[i][j]=='.')
                {
                    s[i][j]='x';
                    if(!isWinning(s,1))
                    {
                        cout<<"("<<i<<","<<j<<")"<<endl;
                        ans=1;
                    }
                    s[i][j]='.';
                }
            }
        }
        if(!ans)
            cout<<"#####"<<endl;
    }
    return 0;
}
