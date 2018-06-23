#include <bits/stdc++.h>
using namespace std;
#define eps       1e-9
#define inf       (ll) 9e18
#define pii       pair <int, int>
#define ALL(x)    x.begin(), x.end()
#define clr(x)    memset(x, 0, sizeof(x))
#define clrDp(x)  memset(x, -1, sizeof(x))
typedef long long ll;

template <typename T> T mmul(T a, T b, T m) {a %= m; T s = 0; while (b) {if (b & 1) s = (s + a) % m; a = (a + a) % m; b >>= 1;} return s;}
template <typename T> T big_mod(T a, T b, T m) {a %= m; T s = 1; while (b) {if (b & 1) s = mmul(s, a, m); b >>= 1; a = mmul(a, a, m);} return s;}

const int maxi = 5111;
const ll mod = 1000000007;
ll n, a, b, l;

ll nC2(ll n) {
	ll ret = (n*(n-1))%mod;
	ret = (ret*big_mod(2LL, mod-2, mod))%mod;
	return ret;
}

ll lol(int pos, int cnt) {
	if (pos > 3) {
		if(cnt == 2) return 1LL;
		else return 0LL;
	}

	ll ret = 1LL, o1 = 0LL, o2 = 0LL, o3 = 0LL;
	if (pos == 1) {
		ret = (big_mod(n-1, a - 1, mod) * lol(pos + 1, cnt)) % mod;
	}
	else if (pos == 2) {
		o1 = (big_mod(n-1, b - a - 1, mod) * lol(pos + 1, cnt + 1)) % mod;
		o1 = (o1*(b-a))%mod;
		o2 = (big_mod(n-1, b - a, mod) * lol(pos + 1, cnt)) % mod;
		ret = (o1 + o2) % mod;
	}
	else {
		if (!cnt && (l - b - 2 >= 0)) o1 = (big_mod(n-1, l - b - 2, mod) * lol(pos + 1, cnt + 2)) % mod;
		o1 = (o1*nC2(l-b))%mod;

		if(cnt==1)  o2 = (big_mod(n-1, l - b - 1, mod) * lol(pos + 1, cnt + 1)) % mod;
		o2 = (o2*(l-b))%mod;
		
		ret = (o1 + o2) % mod;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, caseno = 1;
	cin >> T;

	while (T--) {
		cin >> n >> a >> b >> l;
		cout<<"Case "<<caseno++<<": "<<lol(1, 0)<<endl;
	}

	return 0;
}
