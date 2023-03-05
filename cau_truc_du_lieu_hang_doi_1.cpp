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

ll t, n, x, N;
deque<ll> d;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        d.clear();
        cin >> N;
        while(N--)
        {
            cin >> n;
            switch(n) 
            {
                case 1: 
                {
                    cout << d.size() << '\n';
                    break;
                }

                case 2:
                {
                    if(d.empty()) cout << "YES";
                    else cout << "NO";
                    cout << '\n';
                    break;
                }

                case 3: 
                {
                    cin >> x;
                    d.push_back(x);
                    break;
                }

                case 4:
                {
                    if(!d.empty()) d.pop_front();
                    break;
                }

                case 5: 
                {
                    if(!d.empty()) cout << d.front();
                    else cout << -1;

                    cout << '\n';
                    break;
                }

                case 6:
                {
                    if(!d.empty()) cout << d.back();
                    else cout << -1;

                    cout << '\n';
                    break;
                }
            }
        }
    }
    
    return 0;
}