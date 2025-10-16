#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fast();

    // freopen("./input.txt", "r", stdin);

    auto start = high_resolution_clock::now();

    const int n = 500000000;
    ll ans = 0;
    vector<int> primes;
    vector<int> ephi(n + 1);
    for (int i = 0; i <= n; i++) ephi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (ephi[i] == i) {
            primes.push_back(i);
            ephi[i]--;
        }
        for (int j = 0; j < primes.size() && primes[j] * i <= n; j++) {
            ephi[primes[j] * i] = (primes[j] - 1) * ephi[i];
            if (i % primes[j] == 0) {
                ephi[primes[j] * i] = primes[j] * ephi[i];
                break;
            }
        }
        if (i % 2) ans += ll(ephi[i] % (i + 1));
    }

    cout << ans + 1 << '\n';

    auto stop = high_resolution_clock::now();
    auto dur = duration_cast<microseconds>(stop - start);
    cout << dur.count() << "µs\n";
    return 0;
}