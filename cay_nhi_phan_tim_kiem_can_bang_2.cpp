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

struct Node
{
    ll value;
    Node *left, *right;
};

typedef Node* binTree;

binTree createNode(ll c) 
{
    binTree res = new Node;
    res -> value = c;
    res -> left = res -> right = NULL;

    return res;
} 

void buildTree(binTree &root, ll l, ll r)
{
    if(l > r) return;

    ll mid = (l+r)/2;

    root = createNode(a[mid]);
    
    buildTree(root -> left, l, mid-1);
    buildTree(root -> right, mid+1, r);
}

void preOrder(binTree parent) 
{
    if(parent != NULL) 
    {
        cout << parent -> value << " ";
        preOrder(parent -> left);
        preOrder(parent -> right);
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,1,n,1) cin >> a[i];
        sort(a+1,a+1+n);

        binTree root = NULL;
        buildTree(root, 1, n);

        preOrder(root);
        cout << '\n';
    }
    
    return 0;
}