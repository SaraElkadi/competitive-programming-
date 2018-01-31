#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],d[3]= {0};
    vector<vector<int> > v(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        d[a[i]%3]++;
        v[a[i]].push_back(i+1);
    }

    if(d[0]<d[1]||d[1]<d[2]||d[0]-d[1]>1||d[0]-d[2]>1)
    {
        cout<<"Impossible";
        return 0;
    }
    bool f=1;
    int q=0;
    int c[200005]= {0};
    vector<int> vv;
    while(q<n&&f)
    {
        for(int i=0;i<n&&q<n; i++)
        {
            if(v[i].size()>c[i])
            {
                vv.push_back(v[i][c[i]]);
                q++;
                c[i]++;
            }
            else{
             if(i>2)
                i-=4;
             else{
                f=0;
                break;
             }
            }

        }
    }
    if(!f)
        cout<<"Impossible";
    else{
       cout<<"Possible"<<endl;
       for(int i=0;i<vv.size();i++)
            cout<<vv[i]<<" ";
    }
    return 0;
}
