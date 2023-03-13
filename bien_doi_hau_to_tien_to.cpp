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

        for(auto it : s) 
        {
            if(it == '+' || it == '-' || it == '*' || it == '/' || it == '^') 
            {
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                string res = it + b + a;
                st.push(res);
            }
            else 
            {
                st.push(string(1,it));
            }
        }

        cout << st.top() << '\n';
    }
    
    return 0;
}