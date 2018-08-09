#include <bits/stdc++.h>

using namespace std;
int isWinning(int sum,int f)
{
    if(sum>31)
        return 1;
    for(int i=1; i<=6; i++)
    {
        for(int j=4; j>0; j--)
        {
            if(!((f>>(4*i-j))&1))
            {
                if(!isWinning(sum+i,f|(1<<(4*i-j))))
                    return 1;
                break;
            }
        }
    }
    return 0;
}

int main()
{
    string s;
    while(cin>>s)
    {
        int sum=0,p=0,f=0;
        for(int i=0; i<s.size(); i++)
        {
            sum+=(s[i]-'0');
            p^=1;
            for(int j=0; j<4; j++)
            {
                if(!((f>>((s[i]-'1')*4+j))&1))
                {
                    f|=(1<<((s[i]-'1')*4+j));
                    break;
                }
            }
        }
        if(isWinning(sum,f))
        {
            if(p)
                cout<<s<<" B"<<endl;
            else
                cout<<s<<" A"<<endl;
        }
        else
        {
            if(!p)
                cout<<s<<" B"<<endl;
            else
                cout<<s<<" A"<<endl;
        }
    }
    return 0;
}
