#include<bits/stdc++.h>
#define FOR(i,a,b,k) for (ll i=a;i<=b;i+=k)
#define FORD(i,a,b,k) for (ll i=a;i>=b;i-=k)
#define pb(i) push_back(i)
#define ll long long int
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define I(a) cin >> a
using namespace std;
const ll MOD=1e9+7;

ll tim(ll n, ll f[], ll k)
{
	if(n == 1) return 1;
	if(k == f[n-1] + 1) return n;
	else if (k <= f[n-1]) return tim(n-1,f,k);
	else return tim(n-1,f,k-f[n-1]-1);
}
 
ll t, n, k, f[100];
 
int main()
{
    	fast_cin 	

	f[1] = 1;
	FOR(i,2,50,1) f[i] = f[i-1]*2+1;
 
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cout << (char) (tim(n,f,k) + 'A' - 1) << '\n';
	}
 
	return 0;
}