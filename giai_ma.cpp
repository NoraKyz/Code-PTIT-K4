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

ll Solve(string s)
{
    ll n = s.size(), dp[10001] = {0};

    if(s[0] == '0') return 0;

    dp[0] = 1;
    dp[1] = 1;

    FOR(i,2,n,1) 
    {
        if(s[i-1] > '0') dp[i] = dp[i-1];
        if(s[i-2] == '1'  || (s[i-1] < '7' && s[i-2] == '2')) dp[i]+=dp[i-2];
        //if(s[i-1] == 0 && s[i-2] > '2') return 0;
    }

    return dp[n];
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