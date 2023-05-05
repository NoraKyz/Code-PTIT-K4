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

ll t, n, cnt;
ll a[1005], b[1005];
// Phép duyệt preOrder cho ta biết lần lượt vị trí của gốc => cây con trái => cây con phải
// Phép duyệt inOrder khi biết gốc => các phần tử bên trái gốc thuộc cây con trái, và ngược lại

void postOrder(ll st, ll en, unordered_map<ll,ll> m) 
{
    if(st > en) return;

    ll id = m[b[cnt++]];

    postOrder(st, id-1, m);

    postOrder(id+1, en, m);

    cout << a[id] << " ";
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cnt = 1;
        unordered_map<ll,ll> m;
        cin >> n;
        FOR(i,1,n,1) 
        {
            cin >> a[i];
            m[a[i]] = i;
        }

        FOR(i,1,n,1) cin >> b[i];

        postOrder(1,n,m);
        cout << '\n';
    }
    
    return 0;
}