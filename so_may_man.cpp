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

string Solve() 
{
    string res = "";

    ll numOf7 = n/7, currentSum = 0, numOf4 = 0;
    currentSum = 7*numOf7;
    FOR(i,1,numOf7,1) res+="7";  

    ll need = n - currentSum;

    if(need == 0) return res;

    if(need == 4) return "4"+res;

    while(currentSum < n) 
    {       
        numOf7--;
        numOf4+=2;
        currentSum++;
        need--;  

        if(numOf7 < 0) return "-1";   

        if(need == 4) 
        {
            numOf4+=1;
            currentSum+=4;
            break;
        }  
    }

    if(currentSum == n) 
    {
        res = "";
        FOR(i,1,numOf4,1) res+="4";
        FOR(i,1,numOf7,1) res+="7";
        return res;
    }

    return "-1";
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << Solve() << '\n';
    }
    
    return 0;
}