#include <bits/stdc++.h>

using namespace std;
int dp[(1<<20)];
int n;
bool canMakeMove(int a){
    for(int i=n-1; i>0; i--)
    {
        if(((a>>i)&1)&& (!((a>>(i-1))&1)||i-1==0))
        {
           return 1;
        }
        if(i-3>=0&&((a>>i)&1)&&((a>>(i-1))&1)&&((a>>(i-2))&1)&&((!((a>>(i-3))&1))||(i-3==0)))
        {
            return 1;
        }
    }
return 0;
}
bool isWinning(int a)
{
    int &ret=dp[a];
    if(ret!=-1)
        return ret;
        
    if(!canMakeMove(a)){
        ret=0;
        return ret;
    }
    
    for(int i=n-1; i>0; i--)
    {
        if(((a>>i)&1)&&(!((a>>(i-1))&1)||i-1==0))
        {
            int x=((1<<n)-1)-(1<<i);
            if(!isWinning((a&x)|(1<<(i-1))))
            {
                ret=1;
                return ret;
            }
        }
        if(i-3>=0&&((a>>i)&1)&&((a>>(i-1))&1)&&((a>>(i-2))&1)&&((!((a>>(i-3))&1))||(i-3==0)))
        {
            int x=((1<<n)-1)-(1<<i);
            if(!isWinning((a&x)|(1<<(i-3))))
            {
                ret=1;
                return ret;
            }
        }
    }
    
    ret=0;
    return ret;
}

class EllysCheckers
{
public:

    string getWinner(string s)
    {
        n=s.size();
        int a=0;
        for(int i=0; i<n-1; i++)
        {
            if(s[i]=='o')
                a|=(1<<(n-1-i));
        }
        memset(dp,-1,sizeof dp);
        if(isWinning(a))
            return "YES";
        return "NO";
    }
};

