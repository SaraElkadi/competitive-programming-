#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n,k,a;
    cin>>n>>k;
    set<unsigned long long> s;
    for(int i=0;i<n;i++){
        cin>>a;
        s.insert(a);
    }
    for(auto c:s){
        auto it= s.lower_bound(c*k);
        if(*it==c*k&&*it!=c)
            s.erase(it);
    }
    cout<<s.size()<<endl;
    return 0;
}
