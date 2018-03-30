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
        for(int i=0; i<v1.size(); i++)
        {
            for(int j=0; j<v2.size(); j++)
            {
                if(v1[i]==v2[j])
                    f[i][j]=1;
                else
                    f[i][j]=0;
            }
        }
        for(int i=v1.size()-1; i>=0; i--)
        {
            for(int j=v2.size()-1; j>=0; j--)
            {
                if(f[i][j])
                    a[i][j]=1+a[i+1][j+1];
                else
                    a[i][j]=max(a[i+1][j],a[i][j+1]);
            }
        }
        cout<<"Length of longest match: "<<a[0][0]<<endl;
    }
    return 0;
}
