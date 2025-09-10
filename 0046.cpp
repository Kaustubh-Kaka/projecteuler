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

    auto soe = [](int n) {
        vector<bool> a(n + 1, true);
        for (int i = 2; i * i < n; i++)
            if (a[i])
                for (int j = i; i * j <= n; j++) a[i * j] = false;
        set<int> primes;
        for (int i = 2; i <= n; i++)
            if (a[i]) primes.insert(i);
        return primes;
    };

    int n = 1e5;

    set<int> plist = soe(2 * n);

    int tval;
    bool good;
    for (int i = 2; i < n; i++) {
        if (plist.find(2 * i - 1) == plist.end()) {
            tval = 2 * i - 1;
            good = false;
            for (int j = 1; 2 * j * j < tval; j++)
                if (plist.find(tval - 2 * j * j) != plist.end()) {
                    good = true;
                    break;
                }
            if (!good) {
                cout << tval << '\n';
                break;
            }
        }
    }
    return 0;
}