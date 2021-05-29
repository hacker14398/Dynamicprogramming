#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define ll long long int
#define repin(i, x, n) for(ll i = x; i <= n; i++)
#define rep(i,n) for(ll i = 0; i < n; i++)
#define repp(i, x) for(ll i = 1; i <= x; i++)
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<char> vc;
typedef vector<ll>   vl;
typedef vector<pii>  vpii;
typedef vector<pl>   vpl;
ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll n; cin >> n; 
    vl a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(n, vl(n, 0));

    repin(k, 1, n){
        for(ll i = 0; i+k <= n; i++){
            ll j = i+k-1;
            ll x = (i+2 <= j) ? dp[i+2][j] : 0;
            ll y = (i+1 <= j-1) ? dp[i+1][j-1] : 0;
            ll z = (i <= j-2) ? dp[i][j-2] : 0;
            dp[i][j] = max(a[i]+min(x,y), a[j]+min(y,z));
        }
    }
    cout<<dp[0][n-1];
    return 0;
}