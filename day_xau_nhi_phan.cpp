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

ll t, n, k, f[100];

char tim(ll n, ll k)
{
	if(n == 1) return '0';
    if(n == 2) return '1';
	
	if (k <= f[n-2]) return tim(n-2,k);
	else return tim(n-1,k-f[n-2]);
}
 
int main()
{
    	fast_cin 	

	f[1] = 1;
    f[2] = 1;
    FOR(i,3,92,1) f[i] = f[i-1] + f[i-2]; 
 
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cout << tim(n,k) << '\n';
	}
 
	return 0;
}