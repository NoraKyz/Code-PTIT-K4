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

ll n;
ll x[100] = {0};

/*
    Xet 1 xau x[]: n/2 + n%2 la vi tri chinh giua cua xau
Cach 1:
    Duyet tu n/2 + n%2 -> 1, tim i dau tien ma x[i] = 0, neu khong ton tai, ket thuc lap
    Gan x[i] = 1, x[n-i+1] = 1
    Gan tat ca cac x[j] = 0 va x[n-j+1] voi j tu i+1 -> n/2 + n%2 
Cach 2:
    Sinh xau nhi phan do dai n/2 + n%2 va lay doi xung
*/

void Solve()
{  
    while(1) 
    {
        FOR(i,1,n,1) cout << x[i] << " ";
        cout << '\n';

        ll i = n/2 + n%2;
        while(i > 0) 
        {
            if(x[i] == 0) break;
            i--;
        }

        if(i == 0) return;
        
        x[i] = 1;
        x[n-i+1] = 1;

        FOR(j,i+1,n/2+n%2,1) 
        {
            x[j] = 0; 
            x[n-j+1] = 0;
        }      
    }
}
    
int main()
{   
    fast_cin
    cin >> n;
    Solve();
    
    return 0;
}