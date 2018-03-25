#include <bits/stdc++.h>

using namespace std;
bool e;
int add(string &s);
int sol(string &s)
{
    int x=0;
    if (s[0] >= '0' && s[0] <= '9')
    {
        string ss="";
        while(s[0]>='0'&&s[0]<='9')
        {
            ss+=s[0];
            s.erase(0,1);
        }
        stringstream sss(ss);
        sss>>x;
    }
    else if (s[0] == '(')
    {
        s.erase(0,1);
        x = add(s);
        if (s[0]!= ')') e = 1;
        s.erase(0,1);
    }
    else
    {
        e= 1;
    }
    return x;

}
int mult(string &s)
{
    int x=sol(s);
    if(s[0]=='*')
    {
        s.erase(0,1);
        x*=mult(s);
    }
    return x;
}
int add(string &s)
{
    int x=mult(s);
    if(s[0]=='+')
    {
        s.erase(0,1);
        x=x+add(s);
    }
    return x;
}
int main()
{
    int n;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s;
        e=0;
        int res=add(s);
        if (s.size()) e = 1;
        if (e)
            cout << "ERROR" << endl;
        else
            cout << res << endl;
    }
    return 0;
}
