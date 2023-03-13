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

ll Priority(char x)
{
    if(x == '^') return 3;
    if(x == '*' || x == '/') return 2;
    if(x == '+' || x == '-') return 1;
    return 0;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s;
        string res = "";
        stack<char> sign;
        n = s.size() - 1;

        FOR(i,0,n,1) 
        {

            if(!Priority(s[i]) && s[i] != '(' && s[i] != ')') res+= s[i];
            
            if(s[i] == '(') sign.push(s[i]);
            else if(s[i] == ')') 
            {
                while(!sign.empty() && sign.top() != '(') 
                {
                    res += sign.top();
                    sign.pop();
                }

                sign.pop();
            }
            else if(Priority(s[i]) >= 1) 
            {
                while(!sign.empty() && Priority(sign.top()) >= Priority(s[i])) 
                {
                    res += sign.top();
                    sign.pop();
                }

                sign.push(s[i]);
            }
        }

        while(!sign.empty()) 
        {
            res += sign.top();
            sign.pop();
        }

        cout << res << '\n';
    }
    
    return 0;
}