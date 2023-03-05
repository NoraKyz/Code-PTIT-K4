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

ll t, n, a, b;

void Solve(ll nr, ll dr) { 
    //neu mau so hoac tu so la 0
    if (dr == 0 || nr == 0) 
        return;   
    // neu mau so chia het cho tu so
    if (dr%nr == 0) { //vi du 2/4
        cout << "1/" << dr/nr; //ket qua la 1/2
        return; 
    }   
    // neu tu so chia het cho mau so
    if (nr%dr == 0) { 
        cout << nr/dr; //ket qua la mot so nguyen
        return; 
    }   
    // neu tu so lon hon mau so 
    if (nr > dr) { 
        cout << nr/dr << " + ";// lay so mot so nguyen 
        Solve(nr%dr, dr); //cong voi phan du con lai
        return; 
    }   
    // hien tai chi con truong hop dr>nr va dr%nr khac 0
	// gia tri tham lam dau tien la 1/(dr/nr +1) 
    ll n = dr/nr + 1; //1/n la gia tri tham lam dau tieno
    cout << "1/" << n << " + ";   
    // de qui tiep phan con lai: (nr/dr -1/n) 
    ll new_nr = nr*n-dr; 
    ll new_dr = dr*n;
    Solve(new_nr, new_dr); 
 }   

int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        Solve(a,b);
        cout << '\n';
    }
    
    return 0;
}