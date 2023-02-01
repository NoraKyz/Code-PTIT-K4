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

ll t, n, c;
ll a[1000] = {0}, x[1000];
bool kt[1000] = {0};

bool Check()
{
    FOR(i,1,n,1) if(a[i] != x[i]) return 0;
    return 1;
}

void Solve(ll i)
{
    FOR(j,1,n,1)
    {
        if(kt[j] == 0) 
        {
            a[i] = j;
            
            if(i < n) 
            {
                kt[j] = 1;
                Solve(i+1);
                kt[j] = 0;
            }
            else 
            {
                c++;
                if(Check()) cout << c;
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
        c = 0;
        cin >> n;
        FOR(i,1,n,1) cin >> x[i];

        Solve(1);
        cout << '\n';
    }
    
    return 0;
}