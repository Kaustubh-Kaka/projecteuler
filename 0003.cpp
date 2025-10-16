#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll lpf(ll n) {
    ll ans = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans = max(i, ans);
            while (n % i == 0) n /= i;
        }
    }
    if (n - 1) ans = max(ans, n);
    return ans;
}

int main() {
    // freopen("./input.txt", "r", stdin);

    cout << lpf(600851475143) << '\n';

    return 0;
}