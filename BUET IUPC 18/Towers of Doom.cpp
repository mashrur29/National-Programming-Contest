#include <bits/stdc++.h>
using namespace std;
#define eps       1e-9
#define inf       (ll) 9e18
#define pii       pair <int, int>
#define ALL(x)    x.begin(), x.end()
#define clr(x)    memset(x, 0, sizeof(x))
#define clrDp(x)  memset(x, -1, sizeof(x))
typedef long long ll;

template <typename T> T gcd(T a,T b){if(a<0)a=-a;if(b<0)b=-b;while(b!=0){a%=b;if(a==0)return b;b%=a;}return a;}
template <typename T> T lcm(T a,T b){return (a/gcd(a,b))*b;}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

const int maxi = 111;
int n, ns;
ll a[maxi], s[13];

ll inclusion_exclusion(ll num) {
	ll ret = 0;
	int lim = (1<<ns);

	for(int ind = 0; ind < lim; ind++) {
		std::vector<ll> v;
		for(int j=0; j<ns; j++) {
			if(check(ind, j)) {
				v.push_back(s[j]);
			}
		}

		if(!v.size()) continue;
		
		ll llcm = v[0];
		for(int j=0; j<v.size(); j++) {
			llcm = lcm(llcm, v[j]);
		}

		if(v.size()&1) ret += (num / llcm) + 1;
		else ret -= ((num / llcm) + 1);
	}

	return ret;
}

int main() {
	int T, caseno = 1;
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &n, &ns);

		for(int i=0; i<n; i++) scanf("%lld", &a[i]);
		ll tmp;

		for(int i=0; i<ns; i++) {
			scanf("%lld", &s[i]);
		}

		ll res = 0;

		for(int i=0; i<n; i++) {
			res = res ^ inclusion_exclusion(a[i]);
		}

		if(res) printf("Case %d: Alice\n", caseno++);
		else printf("Case %d: Bob\n", caseno++);
	}

	return 0;
}
