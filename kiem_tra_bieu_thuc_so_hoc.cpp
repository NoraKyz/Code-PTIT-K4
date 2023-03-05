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

string Solve()
{
    stack<char> st;
    for(auto it : s) 
    {
        if(it != ')' && it != ' ') st.push(it);
        else if(it == ')') 
        {
            bool isCoDau = 0;
            while(!st.empty()) 
            {
                char x = st.top();
                st.pop();

                if(x == '(') 
                {
                    if(isCoDau == 0) return "Yes";
                    else break;
                }
                else if(x == '+' || x == '-' || x == '/' || x == '*') isCoDau = 1;
            }
        }
    }

    return "No";
}
    
int main()
{   
    cin >> t;
    while(t--)
    {
        
        scanf("\n");
        getline(cin,s);

        cout << Solve() << '\n';
    }
    
    return 0;
}