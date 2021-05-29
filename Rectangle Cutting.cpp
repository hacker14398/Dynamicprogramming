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
    ll l, b; cin >> l >> b;
    vector<vector<ll> > dp(l+1, vl(b+1, INT_MAX));
    repin(i, 0, l){
        repin(j, 0, b){
            if(i == j) dp[i][j] = 0;
            else{
                //for vertical cutting
                repin(k, 1, i-1){
                    dp[i][j] = min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);
                }
                //for horizontal cutting
                repin(k, 1, j-1){
                    dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
                }
            }
        }
    }
    cout<<dp[l][b];
    return 0;
}