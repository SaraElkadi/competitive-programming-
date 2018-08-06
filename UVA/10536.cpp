#include <bits/stdc++.h>

using namespace std;
int dp[(1<<16)];
bool isWinning(int a)
{
    if(a>=((1<<16)-1))
        return 1;
    int &ret=dp[a];
    if(ret!=-1)
        return ret;
    for(int i=0; i<16; i++)
    {
        int x=i/4,y=i%4;
        if(!((a>>i)&1))
        {
            if(!isWinning(a|(1<<i)))
                return ret=1;
            if(x==0&&(!((a>>(1*4+y))&1)))
            {
                if(!isWinning(a|(1<<i)|(1<<(1*4+y))))
                    return ret=1;
                if((!((a>>(2*4+y))&1))&&(!isWinning(a|(1<<i)|(1<<(1*4+y))|(1<<(2*4+y)))))
                    return ret=1;
            }
            else if(x==3&&(!((a>>(2*4+y))&1)))
            {
                if(!isWinning(a|(1<<i)|(1<<(2*4+y))))
                    return ret=1;
                if((!((a>>(1*4+y))&1))&&(!isWinning(a|(1<<i)|(1<<(2*4+y))|(1<<(1*4+y)))))
                    return ret=1;
            }
            if(y==0&&(!((a>>(x*4+1))&1)))
            {
                if(!isWinning(a|(1<<i)|(1<<(x*4+1))))
                    return ret=1;
                if((!((a>>(x*4+2))&1))&&(!isWinning(a|(1<<i)|(1<<(x*4+1))|(1<<(x*4+2)))))
                    return ret=1;
            }
            else if(y==3&&(!(a&(1<<(x*4+2)))))
            {
                if(!isWinning(a|(1<<i)|(1<<(x*4+2))))
                    return ret=1;
                if((!((a>>(x*4+1))&1))&&(!isWinning(a|(1<<i)|(1<<(x*4+2))|(1<<(x*4+1)))))
                    return ret=1;
            }
        }
    }
    return ret=0;
}
int main()
{
    int n;
    string s;
    cin>>n;
    memset(dp,-1,sizeof dp);
    while(n--)
    {
        int x=0;
        for(int i=0; i<4; i++)
        {
            cin>>s;
            for(int j=0; j<4; j++)
            {
                if(s[j]=='X')
                {
                    x|=(1<<(i*4+j));
                }
            }
        }
        if(isWinning(x))
            cout<<"WINNING"<<endl;
        else
            cout<<"LOSING"<<endl;
    }
    return 0;
}
