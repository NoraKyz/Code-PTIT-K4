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

ll t;
string s;
unordered_map<char,ll> m;

ll Priority(char x)
{
    if(x == '*' || x == '/') return 2;
    if(x == '+' || x == '-') return 1;
    return 0;
}

ll Tinh(ll a, ll b, char dau) 
{
    if(dau == '+') return a+b;
    if(dau == '-') return a-b;
    if(dau == '*') return a*b;
    return a/b;
}

ll Solve(string s) 
{
    stack<ll> so;
    stack<char> dau;
    
    ll n = s.size() - 1;
    FOR(i,0,n,1) 
    {
        if(isdigit(s[i])) 
        {
            string tmp = "";
            while(isdigit(s[i]))
            {
                tmp += s[i];
                i++;
                if(i > n) break;
            }
            i--;

            so.push(stoll(tmp));
        }
        else if(Priority(s[i]) > 0)
        {
            if(dau.empty()) 
            {
                dau.push(s[i]);
                continue;
            }

            while(Priority(dau.top()) >= Priority(s[i])) 
            {
                ll y = so.top(); so.pop();
                ll x = so.top(); so.pop();

                so.push(Tinh(x,y,dau.top()));

                dau.pop();

                if(dau.empty()) break;
            }

            dau.push(s[i]);
        }
        else if(s[i] == '(')
        {
            dau.push(s[i]);
        }
        else if(s[i] == ')') 
        {
            while(dau.top() != '(') 
            {
                ll y = so.top(); so.pop();
                ll x = so.top(); so.pop();

                so.push(Tinh(x,y,dau.top()));

                dau.pop();
            }

            dau.pop();
        }
    }

    while(!dau.empty()) 
    {
        ll y = so.top(); so.pop();
        ll x = so.top(); so.pop();

        so.push(Tinh(x,y,dau.top()));

        dau.pop();
    }

    return so.top();
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s;
        cout << Solve(s) << '\n';
    }
    
    return 0;
}