#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    reverse(a,a+n);
    stack<pair<int,int>>st;
    for(int i=0;i<n;i++){
        pair<int,int> p=make_pair(a[i],0);
        while(!st.empty()){
            pair<int,int> q=st.top();
            if(q.first<p.first){
                st.pop();
                p.second=max(p.second+1,q.second);
            }
            else
                break;
        }
        st.push(p);
    }
    int res=0;
    while(!st.empty()){
        res=max(res,st.top().second);
        st.pop();
    }
    cout<<res;
    return 0;
}
