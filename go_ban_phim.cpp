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

void Solve()
{
    stack<char> a, b;

    for(auto it : s) 
    {
        if(it == '<') 
        {
            if(a.empty()) continue;
            b.push(a.top());
            a.pop();
        }
        else if(it == '>') 
        {
            if(b.empty()) continue;
            a.push(b.top());
            b.pop();
        }
        else if(it == '-') 
        {
            if(a.empty()) continue;
            a.pop();
        }
        else a.push(it);
    }

    string res = "";
    while(!a.empty()) 
    {
        res += a.top();
        a.pop();
    }
    reverse(all(res));

    while(!b.empty()) 
    {
        res += b.top();
        b.pop();
    }

    cout << res << '\n';
}
    
int main()
{   
    fast_cin
    
        cin >> s;
        Solve();
    
    
    return 0;
}