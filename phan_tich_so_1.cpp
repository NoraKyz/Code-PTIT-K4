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
ll a[1000] = {0};

void Display(ll n)
{
    ll kt = 0;
    cout << "(";
    FOR(i,1,n,1) 
    {
        if(kt) cout << " ";
        cout << a[i];
        kt = 1;
    }
    cout << ") ";
}

void Solve(ll i, ll st, ll sum)
{
    FORD(j,st,1,1)
    {   
        a[i] = j;
        ll tmp = a[i] + sum;

        if(tmp < n)  Solve(i+1,a[i],tmp);    
        else if(tmp == n) Display(i);
    }
}
    
int main()
{   
    fast_cin

    cin >> t;
    while(t--)
    {
        cin >> n;
        Solve(1,n,0);
        cout << '\n';
    }
    
    return 0;
}