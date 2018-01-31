#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k=0,c[200005]= {0};
    cin>>n;
    int a[n];
    vector<vector<int> > v(n);
    vector<int> vv;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        v[a[i]].push_back(i+1);
    }
    bool f=1;
    while(k<n&&f)
    {
        for(int i=0; i<n&&k<n; i++)
        {
            if(v[i].size()>c[i])
            {
                vv.push_back(v[i][c[i]]);
                k++;
                c[i]++;
            }
            else
            {
                if(i>2)
                    i-=4;
                else
                {
                    f=0;
                    break;
                }
            }
        }
    }
    if(!f)
        cout<<"Impossible";
    else
    {
        cout<<"Possible"<<endl;
        for(int i=0; i<vv.size(); i++)
            cout<<vv[i]<<" ";
    }
    return 0;
}
