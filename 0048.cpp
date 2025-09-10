#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<double> cd;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    fast();

    auto binexp = [](__uint128_t a, __uint128_t x, __uint128_t M) {
        __uint128_t ans = 1, mult = a;
        while (x) {
            if (x & 1) ans = (ans * mult) % M;
            mult = (mult * mult) % M;
            x >>= 1;
        }

        return ans;
    };

    __uint128_t ans = 0, M = 1e10;
    for (int i = 1; i <= 1000; i++) ans += binexp(i, i, M);

    cout << ll(ans % M) << '\n';
    return 0;
}