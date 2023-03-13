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
string s;

string Solve(string s)
{
    int n = s.length();
 
    string result(n+1, ' ');
 
    int count = 1; 

    FOR(i,0,n,1)
    {
        // Chi xu ly tai vi tri I (luon uu tien chu so nho nhat chua xuat hien)
        if (i == n || s[i] == 'I')
        {
            FORD(j,i-1,-1,1)
            {
                result[j + 1] = '0' + count++;

                if(j >= 0 && s[j] == 'I') break;
            }
        }
    }
    return result;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s;
        cout << Solve(s) << '\n';
    }
    
    return 0;
}