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
char x[1000];

void Solve(ll i)
{
    FOR(j,'A','B',1)
    {
        x[i] = j;
        if(i < n) Solve(i+1);
        else 
        {
            FOR(k,1,n,1) cout << x[k];
            cout << " ";
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
        Solve(1);
        cout << '\n';
    }
    
    return 0;
}