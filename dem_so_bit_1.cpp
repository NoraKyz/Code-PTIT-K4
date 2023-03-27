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

ll t, n, l, r;
unordered_map<ll,ll> m;
/*
    10
    5 0 5
    2 1 2 0 2 1 2
    1 0 1 1 1 0 1 0 1 0 1 0 1 0 1

    k = log2(n)

    => dua ve bai toan dem so bit 1 tu vi tri 1 -> k

    4 => 1 0 1 0 1 0 1

    100
    10 => 1010
    

    1 => 1
    2 => 2
    3 => 3
    4 => f[4/2] * 2 + 4%2
    5 => f[2] * 2 + 1
    10 => f[5] * 2 + 0

    2 ^ (k+1) - 1
*/

ll numberOf1(ll x) 
{
    if(x == 1) return 1;
    
    if(m[x] == 0) m[x] = numberOf1(x/2) * 2 + x%2;

    return m[x];
}

ll lenOfLastArray(ll x)
{
    ll cnt = 0;
    while(x > 0) 
    {
        x /= 2;
        cnt++;
    }

    ll res = 1;
    FOR(i,1,cnt,1) res *= 2;

    return res - 1;
}

ll Solve(ll n, ll k)
{
    if(k == 0) return 0;
    
	if(n == 1) return 1;

    ll len = lenOfLastArray(n/2);

	if(k == len + 1) return (numberOf1(n/2) + n%2);

	if (k <= len) return Solve(n/2, k);
	else return numberOf1(n/2) + n%2 + Solve(n/2, k-len-1);
}
 
int main()
{
    fast_cin 	
 
	cin >> t;
	while (t--)
	{
		cin >> n >> l >> r;
        cout << Solve(n,r) - Solve(n,l-1) << '\n';
	}
 
	return 0;
}