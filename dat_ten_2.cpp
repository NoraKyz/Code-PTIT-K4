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
char x[] = {'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' ,'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
ll a[1000] = {0};
bool kt[1000] = {0};

void Solve(ll i, ll st)
{
    FOR(j,st,n,1)
    {
        if(kt[j] == 0) 
        {
            a[i] = j;
            
            if(i < k) 
            {
                kt[j] = 1;
                Solve(i+1,a[i]+1);
                kt[j] = 0;
            }
            else 
            {
                FOR(h,1,k,1) cout << x[a[h]];
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
        cin >> n >> k;
        Solve(1,1);
        cout << '\n';
    }
    
    return 0;
}