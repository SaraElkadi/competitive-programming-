/*
  use dp function that return if the player who make the first move could win or not. 
  this function have two parameters ,the first the sum of numbers until now 
  and the second is a mask that indicate each number is taken or not
  (reserve four bits for each number in the mask as each number have four cards). 
  This function stop when is the sum of numbers exceed 31 and this means the player which should played next is the winner
  (because he is the one put the last card that make the sum doesn't exceed 31).
  
  To find answer, after get the input, calculate the sum of numbers and indicate in the mask the cards taken and
  find which player should make the second move,Then call the function to know if this player could win or not.
*/

#include <bits/stdc++.h>

using namespace std;
bool isWinning(int sum,int mask)
{
    if(sum>31)
        return 1;
    for(int i=1; i<=6; i++)
    {
        for(int j=4; j>0; j--)
        {
            if(!((mask>>(4*i-j))&1))
            {
                if(!isWinning(sum+i,mask|(1<<(4*i-j))))
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
        int sum=0,p=0,mask=0;
        for(int i=0; i<s.size(); i++)
        {
            sum+=(s[i]-'0');
            p^=1;
            for(int j=0; j<4; j++)
            {
                if(!((mask>>((s[i]-'1')*4+j))&1))
                {
                    mask|=(1<<((s[i]-'1')*4+j));
                    break;
                }
            }
        }
        if(isWinning(sum,mask))
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
