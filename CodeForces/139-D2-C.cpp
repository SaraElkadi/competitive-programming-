#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    bool f=1;
    string s[4],last="aaaa",ss="oeaui";
    int v[4]= {0};
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin>>s[j];
            int w=k,l;
            for( l=s[j].size()-1; l>=0&&f; l--)
            {
                if(ss.find(s[j][l])!=string :: npos)
                    w--;
                if(w==0)
                    break;
            }
            if(!w)
                v[j]=l;
            else
                f=0;
        }
        if(f)
        {
            if((s[0].substr(v[0])==s[1].substr(v[1]))&&(s[2].substr(v[2])==s[3].substr(v[3])))
            {
                if(s[0].substr(v[0])!=s[3].substr(v[3]))
                {
                    if(last!="aaaa"&&last!="aabb")
                        f=0;
                    else
                        last="aabb";

                }
            }
            else if((s[0].substr(v[0])==s[2].substr(v[2]))&&(s[1].substr(v[1])==s[3].substr(v[3])))
            {
                if(s[0].substr(v[0])!=s[1].substr(v[1]))
                {
                    if(last!="aaaa"&&last!="abab")
                        f=0;
                    else
                        last="abab";

                }
            }
            else if((s[0].substr(v[0])==s[3].substr(v[3]))&&(s[2].substr(v[2])==s[1].substr(v[1])))
            {
                if(s[0].substr(v[0])!=s[1].substr(v[1]))
                {
                    if(last!="aaaa"&&last!="abba")
                        f=0;
                    else
                        last="abba";

                }
            }
            else
                f=0;
        }
    }
    if(f)
        cout<<last;
    else
        cout<<"NO";

    return 0;
}
