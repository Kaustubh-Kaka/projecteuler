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

bool ispal(int n) {
    string s = to_string(n);
    bool good = true;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != s[s.size() - 1 - i]) {
            good = false;
            break;
        }
    return good;
}

int main() {
    // freopen("./input.txt", "r", stdin);

    int ans = 0;
    for (int i = 100; i < 1000; i++)
        for (int j = i; j < 1000; j++)
            if (ispal(i * j)) ans = max(ans, i * j);

    cout << ans << '\n';
    return 0;
}