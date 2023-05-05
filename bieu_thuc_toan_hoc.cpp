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
ll a[10], x[10];
bool kt = 0;

ll tinh(ll a, ll b, ll c) 
{
    if(c == 1) return a+b;
    if(c == 2) return a-b;
    if(c == 3) return a*b;
    return -1;
}

void Display() 
{
    ll tmp = a[1];

    FOR(i,2,5,1) 
    {
        tmp = tinh(tmp,a[i],x[i-1]);
    }

    if(tmp == 23) kt = 1;
}

void Solve(ll i) 
{
    if(kt) return;

    FOR(j,1,3,1) 
    {
        x[i] = j;
        if(i == 4) Display();
        else Solve(i+1);
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        kt = 0;
        FOR(i,1,5,1) cin >> a[i];
        sort(a+1,a+6);
        
        do 
        {
            Solve(1);
        }
        while(next_permutation(a+1,a+6));

        if(kt) cout << "YES";
        else cout << "NO";

        cout << '\n';
    }
    
    return 0;
}