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
ll a[1000] = {0};
vector<string> res;

void Display(ll n)
{
    ll kt = 0;
    string ans = "(";
    FOR(i,1,n,1) 
    {
        if(kt) ans += " ";
        ans += to_string(a[i]);
        kt = 1;
    }
    ans += ")";
    res.pb(ans);
}

void Solve(ll i, ll st, ll sum)
{
    FORD(j,st,1,1)
    {   
        a[i] = j;
        ll tmp = a[i] + sum;

        if(tmp < n)  Solve(i+1,a[i],tmp);    
        else if(tmp == n) Display(i);
    }
}
    
int main()
{   
    fast_cin

    cin >> t;
    while(t--)
    {
        res.clear();
        cin >> n;
        Solve(1,n,0);
        cout << res.size() << '\n';
        for(auto it : res) cout << it << " ";
        cout << '\n';
    }
    
    return 0;
}