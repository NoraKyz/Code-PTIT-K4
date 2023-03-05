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
ll a[10001];

/*
    Duyet tu cuoi len dau, neu tim duoc a[i] thoa man a[i] != a[i-1] + 1 =>
        a[i]--;
        neu a[k] != n giam tu a[i+1] -> a[k] 1 don vi
    Khong tim duoc i => in ra tap con cuoi
*/
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        FOR(i,1,k,1) cin >> a[i];

        ll i = k;
        while(i > 1) 
        {
            if(a[i] != a[i-1] + 1) break;
            i--;
        }

        if(i == 1) 
        {
            FOR(i,k,n,1) cout << i << " ";
        }
        else 
        {
            a[i]--;

            if(a[k] != n) FOR(j,i+1,k,1) a[j]++;
            
            FOR(i,1,k,1) cout << a[i] << " ";
        }

        

        cout << '\n';
    }
    
    
    return 0;
}