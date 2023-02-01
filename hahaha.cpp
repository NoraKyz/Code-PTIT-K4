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
ll x[1000] = {0,1};

void Display()
{
    FOR(i,1,n,1) if(x[i]) cout << 'H'; else cout << 'A';
    cout << '\n';
}

bool Check()
{
    if(x[n] != 0) return 0;
    FOR(i,1,n-1,1) if(x[i] == x[i+1] && x[i] == 1) return 0;
    return 1;
}

void Solve(ll i)
{
    FOR(j,0,1,1)
    {
        x[i] = j;
        if(i < n) Solve(i+1);
        else 
        {
            if(Check()) Display();           
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
        Solve(2);
    }
    
    return 0;
}