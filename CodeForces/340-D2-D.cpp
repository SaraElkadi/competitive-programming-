#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &v) {
    vector<int> tail(v.size(), 0);
    int length = 1; 
    tail[0] = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > tail[length-1])
            tail[length++] = v[i];
        else
           tail[lower_bound(tail.begin(),tail.begin()+length-1,v[i])-tail.begin()]=v[i];
    }
    return length;
}
 
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
       cin>>v[i];
    cout<<LIS(v);
    return 0;
}
