#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define ll long long int
#define repin(i, x, n) for(ll i = x; i <= n; i++)
#define rep(i,n) for(ll i = 0; i < n; i++)
#define repp(i, x) for(ll i = 1; i <= x; i++)
#define reprev(i, x, n) for(ll i = x; i >= n; i--)
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
    vector<vector<int>> a(n, vector<int>(n, 0));
    char s;
    repin(i, 0, n-1){
        repin(j, 0, n-1){
            cin >> s;
            a[i][j] = (s == '.') ? 1 : 0;
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if(a[n-1][n-1] == 1) dp[n-1][n-1] = 1;
    reprev(i, n-2, 0){ // for row
        if(a[i][n-1] == 0) dp[i][n-1] = 0;
        else{
            dp[i][n-1] += dp[i+1][n-1];
        }
    }
    reprev(i, n-2, 0){ //for coloumn
        if(a[n-1][i] == 0) dp[n-1][i] = 0;
        else{
            dp[n-1][i] += dp[n-1][i+1];
        }
    }
    reprev(i, n-2, 0){
        reprev(j, n-2, 0){
            if(a[i][j] == 0) dp[i][j] = 0;
            else{
                dp[i][j] += (dp[i+1][j]%mod + dp[i][j+1]%mod)%mod;
            }
        }
    }
    cout<<dp[0][0];
    return 0;
}