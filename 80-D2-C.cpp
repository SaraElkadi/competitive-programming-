#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,q=0;
    bool f[10][10]= {0};
    map<string,int> mp;
    mp["Anka"]=0;
    mp["Chapay"]=1;
    mp["Cleo"]=2;
    mp["Troll"]=3;
    mp["Dracul"]=4;
    mp["Snowy"]=5;
    mp["Hexadecimal"]=6;
    string s1,s2,s;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>s1>>s>>s2;
        f[mp[s1]][mp[s2]]=1;
    }
    int a,b,c,d=2000000005,w=0;
    cin>>a>>b>>c;
    vector<pair<int,int> > v;
    for(int i=1; i<6; i++)
    {
        for(int j=1; i+j<7; j++)
        {
            int k=7-i-j;
            if(k>0)
            {
                int mx=max(a/i,max(b/j,c/k));
                int mn=min(a/i,min(b/j,c/k));
                if(mx-mn>d)
                    continue;
                vector<int> q;
                for(int l=0; l<i; l++)
                    q.push_back(1);
                for(int l=0; l<j; l++)
                    q.push_back(2);
                for(int l=0; l<k; l++)
                    q.push_back(3);
                int p=0,m=0;
                do
                {
                    p=0;
                    for(int i=0; i<7; i++)
                    {
                        for(int j=0; j<7; j++)
                        {
                            if(i!=j&&q[i]==q[j]&&f[i][j])
                                p++;
                        }
                    }
                    m=max(p,m);
                }
                while(next_permutation(q.begin(),q.end()));
                if(mx-mn<d)
                {
                    d=mx-mn;
                    w=m;
                }
                else if(mx-mn==d)
                    w=max(w,m);

            }
        }
    }
    cout<<d<<" "<<w;
    return 0;
}
