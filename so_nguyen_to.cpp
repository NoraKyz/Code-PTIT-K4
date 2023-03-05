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

ll t, n, p, s, N;
vector<ll> v;
vector<string> res;
ll a[1001];
ll prime[10001] = {0};
void Sieve(ll n)
{
    prime[2] = 1;
    v.pb(2);
    FOR(i,3,n,2) prime[i] = 1;
    FOR(i,3,n,2)
    {
        if(prime[i]) 
        {
            v.pb(i);
            FOR(j,i*3,n,i*2) prime[j] = 0;
        }
    }
}

void Result()
{
    string ans = "";
    FOR(i,1,n,1) ans += to_string(a[i]) + " ";
    res.pb(ans);
}

void Solve(ll i, ll st, ll sumCurrent)
{
    FOR(j,st,N,1) 
    {
        a[i] = v[j]; 
        ll tmp = sumCurrent + v[j];
        if(i < n) 
        {
            if(tmp < s && st < N) Solve(i+1,j+1,tmp);
        }
        else 
        {
            if(tmp == s) Result();
        }
    }
}

    
int main()
{   
    fast_cin
    Sieve(201);

    N = v.size()-1;
    cin >> t;
    while(t--)
    {
        res.clear();
        cin >> n >> p >> s;
        ll d = upper_bound(all(v),p) - v.begin();
        Solve(1,d,0);
        cout << res.size() << '\n';
        for(auto it : res) cout << it << "\n";
    }
    
    return 0;
}