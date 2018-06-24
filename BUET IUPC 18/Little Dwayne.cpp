#include <bits/stdc++.h>
using namespace std;
#define eps       1e-9
#define inf       (ll) 9e18
#define pii       pair <int, int>
#define ALL(x)    x.begin(), x.end()
#define clr(x)    memset(x, 0, sizeof(x))
#define clrDp(x)  memset(x, -1, sizeof(x))
typedef long long ll;

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int n, k, tmp, res = 0;
		scanf("%d %d", &n, &k);

		for(int i=1; i<=n; i++) {
			scanf("%d", &tmp);
			res += max(0, tmp - k);
		}

		printf("%d\n", res);
	}

	return 0;
}
