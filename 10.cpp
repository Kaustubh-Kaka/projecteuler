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

typedef long long ll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    // freopen("./input.txt", "r", stdin);

    int n = 2e6;

    vector<bool> erat(n + 1, true);

    for (int i = 2; i * i <= n; i++)
        if (erat[i])
            for (int j = 2; i * j <= n; j++) erat[i * j] = false;

    ll ans = 0;

    for (int i = 2; i <= n; i++)
        if (erat[i]) ans += ll(i);

    cout << ans << '\n';

    return 0;
}