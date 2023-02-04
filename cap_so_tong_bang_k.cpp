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

ll t, n, k;
ll a[10000];
unordered_map<ll,ll> m;

int main()
{   
    
    cin >> t;
    while(t--)
	{
		ll res = 0;
		cin >> n >> k;
		FOR(i,1,n,1) 
		{
			cin >> a[i];
			m[a[i]]++;
		}

		FOR(i,1,n,1) if(a[i] * 2 != k) res += m[k-a[i]];
		res /= 2;

		if(k%2 == 0) res += m[k/2] * (m[k/2] - 1) / 2;

		cout << res << '\n';

		m.clear();
	}
    
	return 0;
}