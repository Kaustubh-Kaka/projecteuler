#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<vector<ll>> vvi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const ll M = 1e9 + 7;

ll binexp(ll a, ll x) {
    if (x == 0)
        return 1;
    else if (x == 1)
        return a;
    else {
        ll ans = binexp(a, x / 2);
        ans = (ans * ans) % M;
        if (x % 2) ans = (ans * a) % M;
        return ans;
    }
}

ll S(ll n) {
    ll r = n / 9, s = n % 9;
    return (((6 + (s + 1) * (s + 2) / 2 - 1) * binexp(10, r) - n - 6) % M + M) %
           M;
}

ll ids(ll n) { return (n % 9 + 1) * binexp(10, n / 9) - 1; }

int main() {
    fast();
    // freopen("./input.txt", "r", stdin);

    int n = 90;

    vector<ll> fib(n + 1);
    fib[0] = 0, fib[1] = 1;
    for (int i = 2; i <= n; i++) fib[i] = fib[i - 1] + fib[i - 2];

    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        ans = (ans + S(fib[i])) % M;
    }
    cout << ans << '\n';

    return 0;
}
