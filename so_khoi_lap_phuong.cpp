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

ll t, n, res, N;
string s;

void Solve(ll i, string currentStr) 
{
    FOR(j,0,1,1) 
    {
        string tmp = "";

        if(j == 1) tmp = currentStr + s[i];        
        else tmp = currentStr;
        

        if(i < N) Solve(i+1,tmp);
        else 
        {
            if(tmp != "")
            {
                ll ans = stoll(tmp);
                ll x = pow(ans, 1.0/3);
                FOR(h,x-2,x+2,1) if(h*h*h == ans) res = max(res,ans);
            }    
        }
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        res = -1;
        cin >> n;
        s = to_string(n);
        N = s.size()-1;
        Solve(0,"");
        cout << res << '\n';
    }
    
    return 0;
}