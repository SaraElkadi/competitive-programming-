/* XOR all numbers and result will be the number that occured odd numbers of times */

#include <bits/stdc++.h>

using namespace std;
struct triple
{
    long long x,y,z;
};

int main()
{
    string s;
    long long x,y,z;
    while(1)
    {
        vector<triple> t;
        long long ans=0;
        bool f=0;
        while(getline(cin, s) && (s.size() == 0 || s[0] < '0' || s[0] > '9'));
        if(s.size() == 0 || s[0] < '0' || s[0] > '9')break;
        while(1)
        {
            if(s.size()==0||s[0]<'0'||s[0]>'9')
                break;
            f=1;
            stringstream ss(s);
            ss>>x>>y>>z;
            t.push_back(triple {x,y,z});
            for(long long i=x; i<=y; i+=z)
            {
                ans^=i;
            }
            getline(cin,s);
        }
        if(!f) break;
        if(ans==0)
            puts("no corruption");
        else
        {
            long long cnt=0;
            for(int i=0; i<t.size(); i++)
            {
                if(ans>=t[i].x&&ans<=t[i].y&&(ans-t[i].x)%t[i].z==0)
                    cnt++;
            }
            printf("%lld %lld\n",ans,cnt);
        }
    }
    return 0;
}
