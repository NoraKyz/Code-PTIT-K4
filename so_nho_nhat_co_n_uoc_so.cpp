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

ll prime[] = {2, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}, ans;
int n;

void Try(int i, ll a = 1, ll b = 1)
{
    if(b > n) return;

    if(b == n) ans = min(ans, a);

    ll j = 1;
    while(a * prime[i] <= ans)
    {
        a *= prime[i];
        Try(i + 1, a, b * (j + 1));
        ++j;
    }
}
    
int main()
{
    fast_cin;
    
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = 1e18;
        Try(1);
        cout << ans << endl;
    }
    return 0;
}