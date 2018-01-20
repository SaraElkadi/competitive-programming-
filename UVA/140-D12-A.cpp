#include <bits/stdc++.h>

using namespace std;
#define PI acos(-1.0)
#define EPS 1e-9
int main()
{
    double n,R,r;
    cin>>n>>R>>r;
    double theta=2*PI/n;
    double rr=R*sin(theta)/(2*cos(theta/2)+sin(theta));
    if(n==1)
    {
        if(r<=R)
            cout<<"YES";
        else
            cout<<"NO";
    }
    else
    {
        if(r<=rr+EPS)
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}
