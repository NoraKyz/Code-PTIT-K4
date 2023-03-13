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
ll a[100001];
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
ll Solve(ll n, ll f[], ll k)
{
	if(n == 1) return 1;
	if(k == f[n/2] + 1) return (f[n/2] + n%2);

	if (k <= f[n/2]) return Solve(n/2, f, k);
	else return f[n/2] + n%2 + Solve(n/2, f, k-f[n/2]-1);
}
 
ll t, n, k, f[100];
 
int main()
{
    	fast_cin 	

	f[1] = 1;
	FOR(i,2,50,1) 
    {
        ll x = round(log2(i))
    }
 
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cout << tim(n,f,k) << '\n';
	}
 
	return 0;
}