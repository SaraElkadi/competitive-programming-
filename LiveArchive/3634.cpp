 /*Represent each string as a set of numbers refer to sets that consist this string and use two maps
   to represent each set as a number , for push , push a number that refer to empty set in the stack ,
   for intersect and union ,use set functions to do that ,
   for add ,get the number that refer to the set at the top of the stack and add it to the set of the second element .*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n;
    char c[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int cnt=1;
        stack<int> st;
        map<set<int>,int> mp1;
        map<int,set<int>> mp2;
        while(n--)
        {
            scanf("%s",c);
            string s=c;
            if(s=="PUSH")
            {
                if(mp1[set<int>()])
                    st.push(mp1[set<int>()]);
                else
                {
                    mp1[set<int>()]=cnt;
                    mp2[cnt]=set<int>();
                    st.push(cnt);
                    cnt++;
                }
            }
            else if(s=="DUP")
            {
                st.push(st.top());
            }
            else if(s=="UNION")
            {
                set<int> s1=mp2[st.top()];
                st.pop();
                set<int> s2=mp2[st.top()];
                st.pop();
                set<int> s3;
                set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.begin()));
                if(mp1[s3])
                    st.push(mp1[s3]);
                else
                {
                    mp1[s3]=cnt;
                    mp2[cnt]=s3;
                    st.push(cnt);
                    cnt++;
                }
            }
            else if(s=="INTERSECT")
            {
                set<int> s1=mp2[st.top()];
                st.pop();
                set<int> s2=mp2[st.top()];
                st.pop();
                set<int> s3;
                set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.begin()));
                if(mp1[s3])
                    st.push(mp1[s3]);
                else
                {
                    mp1[s3]=cnt;
                    mp2[cnt]=s3;
                    st.push(cnt);
                    cnt++;
                }
            }
            else if(s=="ADD")
            {
                int s1=st.top();
                st.pop();
                set<int> s2=mp2[st.top()];
                st.pop();
                s2.insert(s1);
                if(mp1[s2])
                    st.push(mp1[s2]);
                else
                {
                    mp1[s2]=cnt;
                    mp2[cnt]=s2;
                    st.push(cnt);
                    cnt++;
                }
            }
            printf("%d\n",mp2[st.top()].size());
        }
        puts("***");
    }
    return 0;
}
