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
unordered_map<ll,ll> m;

// Phép duyệt levelOrder cho ta biết lần lượt vị trí của gốc => gốc cây con trái => gốc cây con phải
// Phép duyệt inOrder khi biết gốc => các phần tử bên trái gốc thuộc cây con trái, và ngược lại

/*
    - Sử dụng mảng kt[] để đánh dấu các node thuộc cây con trái/phải
    - Tìm kiếm phần tử đầu tiên kt[] = 1 trong mảng levelOrder, đó chính là gốc cây con cần tìm
*/

void postOrder(ll st, ll en, bool kt[], ll cnt) 
{
    if(st > en) return;

    ll id = -1, x;

    FOR(i,cnt,n,1) if(kt[b[i]]) 
    {
        id = i;
        break;
    }

    if(id == -1) return;

    x = id;
    id = m[b[id]];

    bool left[1005] = {0};
    FOR(i,st,id-1,1) left[a[i]] = 1;
    postOrder(st,id-1,left,x+1);

    bool right[1005] = {0};
    FOR(i,id+1,en,1) right[a[i]] = 1;
    postOrder(id+1,en,right,x+1);

    cout << a[id] << " ";
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cnt = 1;
        m.clear();

        cin >> n;
        FOR(i,1,n,1) 
        {
            cin >> a[i];
            m[a[i]] = i;
        }

        FOR(i,1,n,1) cin >> b[i];

        bool kt[1005];
        kt[b[1]] = 1;

        postOrder(1,n,kt,1);

        cout << '\n';
    }
    
    return 0;
}