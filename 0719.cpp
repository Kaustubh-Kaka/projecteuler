#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll cnt = 0;

bool posrep(ll n, ll fsum) {
    cnt++;
    if (n == fsum)
        return true;
    else {
        bool ans = false;
        ll m = 10;
        while (1) {
            if (m > n || (n % m) > fsum) break;
            ans |= posrep(n / m, fsum - n % m);
            m *= 10L;
        }
        return ans;
    }
}

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fast();
    ll ans = 0;
    for (ll i = 2; i <= ll(1e6); i++)
        if (posrep(i * i, i)) {
            // cout << i << ' ' << i * i << '\n';
            ans += i * i;
        }
    cout << ans << '\n';

    return 0;
}