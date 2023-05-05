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
ll a[100001];

struct Node
{
    ll value;
    Node *left, *right;
};

typedef Node* binTree;

binTree createNode(ll value)
{
    binTree parent = new Node;

    parent -> value = value;
    parent -> left = parent -> right = NULL;

    return parent;
}

void buildTree(binTree &parent, ll value)
{
    if(parent == NULL) 
    {
        parent = createNode(value);
    }
    else 
    {
        if(parent -> value < value)
            buildTree(parent -> right, value);
        else 
            buildTree(parent -> left, value);
    }
}

void preOrder(binTree root) 
{
    if(root != NULL) 
    {
        if(root -> left == NULL && root -> right == NULL) cout << root -> value << " ";
        preOrder(root -> left);       
        preOrder(root -> right);     
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;

        binTree root = NULL;

        FOR(i,1,n,1)
        {
            cin >> a[i];
            buildTree(root, a[i]);
        }

        preOrder(root);

        cout << '\n';
    }
    
    return 0;
}