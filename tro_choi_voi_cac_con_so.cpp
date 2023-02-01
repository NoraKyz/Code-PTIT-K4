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
ll a[100], kt[100] = {0};

void Solve(ll i, ll st)
{
    FOR(j,1,n,1) 
    {
        if(kt[j] == 0 && j != st+1 && j != st-1)
        {
            a[i] = j;
            if(i < n) 
            {
                kt[j] = 1;
                Solve(i+1,j);
                kt[j] = 0;
            }
            else 
            {
                FOR(h,1,n,1) cout << a[h];
                cout << '\n';
            }
        }
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        Solve(1,-1);
    }
    
    return 0;
}