#include <bits/stdc++.h>

using namespace std;
#define EPS 1e-6

int main()
{
    double n,w,m;
    cin>>n>>w>>m;
    double Q=n*w/m;
    double rem=0;
    bool f=1;
    for(int i=0; i<m; i++)
    {
        double q=Q;
        if(fabs(rem-q)<EPS)
        {
            q=0;
            rem=0;
        }
        else if(rem>q-EPS)
        {
            f=0;
            break;
        }
        q-=rem;
        rem=0;
        while(q+EPS>w)
            q-=w;
        if(q>EPS)
            rem=w-q;
    }
    if(!f)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    int idx=1;
    for(int i=0; i<m; i++)
    {
        double q=Q;
        if(rem>EPS)
        {
            cout<<idx++<<" "<<fixed<<setprecision(6)<<rem<<" ";
            q-=rem;
            rem=0;
        }

        while(q+EPS>w)
        {
            q-=w;
            cout<<idx++<<" "<<fixed<<setprecision(6)<<w<<" ";
        }
        if(q>EPS)
        {
            cout<<idx<<" "<<fixed<<setprecision(6)<<q<<" ";
            rem=w-q;
        }
        cout<<endl;
    }
    return 0;
}
