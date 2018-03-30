#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1,s2,s;
    int k=1;
    while(getline(cin,s1))
    {
        getline(cin,s2);
        cout<<setw(2)<<k++<<". ";
        if(!s1.size()||!s2.size())
        {
            cout<<"Blank!"<<endl;
            continue;
        }
        for(int i=0; i<s1.size(); i++)
        {
            if((!isdigit(s1[i]))&&(!isupper(s1[i]))&&(!islower(s1[i])))
                s1[i]=' ';
        }
        for(int i=0; i<s2.size(); i++)
        {
            if((!isdigit(s2[i]))&&(!isupper(s2[i]))&&(!islower(s2[i])))
                s2[i]=' ';
        }
        vector<string> v1,v2;
        stringstream ss1(s1),ss2(s2);
        int a[505][505]= {0};
        bool f[505][505]= {0};
        while(ss1>>s) v1.push_back(s);
        while(ss2>>s) v2.push_back(s);
        for(int i=1; i<=v1.size(); i++)
        {
            for(int j=1; j<=v2.size(); j++)
            {
                if(v1[i-1]==v2[j-1])
                    a[i][j]=1+a[i-1][j-1];
                else
                    a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
        cout<<"Length of longest match: "<<a[v1.size()][v2.size()]<<endl;
    }
    return 0;
}
