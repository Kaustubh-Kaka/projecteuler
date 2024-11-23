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

    int plim = int(1e6);

    vector<bool> erat(plim, true);

    for (int i = 2; i * i <= plim; i++)
        for (int j = 2; i * j <= plim; j++) erat[i * j] = false;

    int it, bit = 0, ba = 0, bb = 0;

    for (int b = 1; b <= 1000; b++)
        for (int a = 1 - b; a <= 1000; a++) {
            it = 0;
            while (erat[it * it + a * it + b]) it++;
            if (it > bit) {
                bit = it;
                ba = a;
                bb = b;
            }
        }

    cout << ba * bb << '\n';
    return 0;
}