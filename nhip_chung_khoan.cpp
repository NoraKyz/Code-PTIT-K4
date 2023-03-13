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
        FOR(i,1,n,1) cin >> a[i];

        stack<ll> st;
        // tim phan tu dau tien lon hon no
        FOR(i,1,n,1) 
        {
            ll cnt;

            while(!st.empty() && a[i] >= a[st.top()]) 
            {
                st.pop();
            }  

            if(!st.empty()) cnt = i - st.top();
            else cnt = i;

            st.push(i);

            cout << cnt << " ";
        }

        cout << '\n';
    }
    
    return 0;
}