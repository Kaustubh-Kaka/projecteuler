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

ll collatzLength(ll n) {
    ll sz = 0;
    while (1) {
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
        sz++;
        if (n == 1) break;
    }
    return sz + 1;
}

int main() {
    // freopen("./input.txt", "r", stdin);

    int bval = 1, bi = 1;
    ll temp = 0;
    for (int i = 2; i <= int(1e6); i++) {
        temp = collatzLength(i);
        if (temp > bval) {
            bi = i;
            bval = temp;
        }
    }

    cout << bi << '\n';

    return 0;
}