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

    ll a = 1, b = 2, c = 0, ans = 2;
    while (1) {
        c = a + b;
        if (c >= ll(4e6)) break;
        if (c % 2 == 0) ans += c;
        a = b;
        b = c;
    }

    cout << ans << '\n';

    return 0;
}