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
string a[100001];

struct Node
{
    string value;
    Node *left, *right;
};

typedef Node* binTree;

binTree createNode(string c) 
{
    binTree res = new Node;
    res -> value = c;
    res -> left = res -> right = NULL;

    return res;
}

binTree buildTree(binTree parent, ll i) 
{
    if(i < n)
    {
        parent = createNode(a[i]);
        parent -> left = buildTree(parent -> left, i*2 + 1);
        parent -> right = buildTree(parent -> right, i*2 + 2);
    }
    return parent;
}

ll calc(binTree parent) 
{
    if(parent -> value != "+" && parent -> value != "-" && parent -> value != "*" && parent -> value != "/")
        return stoll(parent -> value);
    else if(parent -> value == "+") 
        return calc(parent -> left) + calc(parent -> right);
    else if(parent -> value == "-") 
        return calc(parent -> left) - calc(parent -> right);
    else if(parent -> value == "*") 
        return calc(parent -> left) * calc(parent -> right);
    else
        return calc(parent -> left) / calc(parent -> right);
    
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,0,n-1,1) cin >> a[i];

        binTree root;
        root = buildTree(root, 0);
        cout << calc(root) << '\n';       
    }
    
    return 0;
}