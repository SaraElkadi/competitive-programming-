#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string,int> mp;
    vector<string >v;
    string s;
    cin>>s;
    string c="";
    int ans=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
            c+=s[i];
        else
        {
            if(c.size())
            {
                mp[c]++;
                v.push_back(c);
                c="";
            }
            if(s[i]=='.')
            {
                mp[v[v.size()-1]]--;
                ans+=mp[v[v.size()-1]];
                v.pop_back();
            }
        }
    }
    cout<<ans;
    return 0;
}
