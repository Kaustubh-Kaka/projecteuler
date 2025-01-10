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

int main() {
    fast();
    // freopen("./input.txt", "r", stdin);

    int n = 1e8;
    vector<ll> etf(n + 1);
    for (int i = 0; i <= n; i++) etf[i] = i;
    ll ans = 0;
    for (int i = 2; i <= n; i++) {
        if (etf[i] == i) {
            for (int j = 1; i * j <= n; j++) {
                etf[i * j] /= i;
                etf[i * j] *= (i - 1);
            }
        }
        ans += ll(i - etf[i]);
    }

    cout << 6 * ans << '\n';
    return 0;
}
