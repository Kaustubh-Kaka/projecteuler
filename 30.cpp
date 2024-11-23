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

int p5(int n) { return n * n * n * n * n; }

int dps(int n) {
    int ans = 0;
    while (n) {
        ans += p5(n % 10);
        n /= 10;
    }
    return ans;
}

int main() {
    // freopen("./input.txt", "r", stdin);

    int ans = 0;

    for (int i = 2; i < int(1e6); i++)
        if (i == dps(i)) ans += i;

    cout << ans << '\n';

    return 0;
}