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
ll a[100001];
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll b[100001] = {0};
        cin >> n;
        FOR(i,1,n,1) cin >> a[i];

        stack<ll> st;

        FOR(i,1,n,1) 
        {
            while(!st.empty() && a[st.top()] < a[i]) 
            {
                b[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        FOR(i,1,n,1) 
        {
            if(b[i] == 0) cout << -1; else cout << a[b[i]];
            cout << " ";
        }

        cout << '\n';
    }
    
    return 0;
}