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
        cin >> n;
        ll up[n+5] = {0}, low[n+5] = {0};
        FOR(i,1,n,1) cin >> a[i];

        stack<ll> st;

        ll i = 1;
        while(i <= n) 
        {
            while(st.empty() == 0 && a[i] > a[st.top()]) 
            { 
                up[st.top()] = i;
                st.pop();               
            }

            st.push(i);
            i++;
        }
        FOR(i,1,n,1) if(up[i] == 0) up[i] = -1;

        // clear stack
        while(st.empty() == 0) st.pop();

        i = 1;
        while(i <= n) 
        {
            while(st.empty() == 0 && a[i] < a[st.top()]) 
            { 
                low[st.top()] = i;
                st.pop();               
            }

            st.push(i);
            i++;
        }

        FOR(i,1,n,1) if(low[i] == 0) low[i] = -1;


        FOR(i,1,n,1) 
        {
            if(up[i] == -1) cout << -1 << " ";
            else if(low[up[i]] == -1) cout << -1 << " ";
            else cout << a[low[up[i]]] << " ";
        }

        cout << '\n';
    }
    
    return 0;
}