#include<bits/stdc++.h>
#define FOR(i,a,b,k) for (ll i=a;i<=b;i+=k)
#define FORD(i,a,b,k) for (ll i=a;i>=b;i-=k)
#define pb(i) push_back(i)
#define ll long long int
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll MOD=1e9+7;

ll t, n;
string s;

int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s;
        stack<string> st;
        n = s.size() - 1;
        
        FORD(i,n,0,1) 
        {   
            if(s[i] == '[') 
            {
                string tmp = "";

                while(!st.empty())
                {
                    string x = st.top();
                    st.pop();

                    if(x == "]") break;
                    tmp += x;
                }

                st.push(tmp);
            }

            else if(isdigit(s[i]))
            {
                string tmp = "";

                while(isdigit(s[i])) 
                {
                    tmp += s[i]; 
                    i--;                  
                    if(i < 0) break;                   
                }
                i++;

                reverse(all(tmp));
                ll cnt = stoll(tmp);

                tmp = "";
                string core = st.top();
                st.pop();
                FOR(j,1,cnt,1) tmp += core;
                st.push(tmp);
            }
            
            else 
            {
                string tmp = "";
                tmp += s[i];
                st.push(tmp);
            }
        }
        
        string res = "";
        while(!st.empty()) 
        {
            string x = st.top();
            st.pop();
            if(x != "]") res += x;
        }

        cout << res << '\n';
    }
    
    return 0;
}