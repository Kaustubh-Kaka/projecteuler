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

ll gcd(ll a, ll b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {
    // freopen("./input.txt", "r", stdin);

    int ans = 1;

    for (ll i = 1; i <= 20; i++) ans = lcm(ans, i);

    cout << ans << '\n';

    return 0;
}