/* Use two priority queues to store elements 
   first queue stores the first i elements in non-decreasing order and answer of get query will be the top element in it.
   second queury stores the remaining elements in non-increasing order.
   */


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int a[n+1],b[m+1];
        for(int i=1; i<=n; i++)
            cin>>a[i];
        for(int i=0; i<m; i++)
            cin>>b[i];
        int k=0;
        priority_queue<int,vector<int>,less<int>> left;
        priority_queue<int,vector<int>,greater<int>> right;
        for(int i=1; i<=n; i++)
        {
            if(k>0)
            {
                if(a[i]>=left.top())
                {
                    right.push(a[i]);
                }
                else
                {
                    int tmp=left.top();
                    left.pop();
                    left.push(a[i]);
                    right.push(tmp);
                }
            }
            else
                right.push(a[i]);
            while(k<m&&b[k]==i)
            {
                left.push(right.top());
                right.pop();
                cout<<left.top()<<endl;
                k++;
            }
        }
        if(t!=0)
            cout<<endl;

    }
    return 0;
}
