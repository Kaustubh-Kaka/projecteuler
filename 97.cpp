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
typedef __int128_t lll;
typedef pair<ll, ll> pii;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

lll binexp(lll a, lll x, lll M) {
    if (x == 1)
        return a % M;
    else if (x == 0)
        return 1L;
    else {
        lll t = binexp(a, x / 2L, M);
        t *= t;
        t %= M;
        if (x % 2) t *= a;
        return t % M;
    }
}

int main() {
    // freopen("./input.txt", "r", stdin);

    ll M = 10000000000L;

    cout << ll((28433L * binexp(2L, 7830457, M) + 1L) % M) << '\n';

    return 0;
}