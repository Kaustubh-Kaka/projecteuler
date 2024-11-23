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

vector<int> kthperm(vector<int> a, int k) {
    int nfac = 1;
    for (int i = 1; i <= a.size(); i++) nfac *= i;

    for (int i = 0; i < a.size(); i++) {
        nfac /= int(a.size() - i);
        swap(a[i], a[i + (k - 1) / nfac]);
        sort(a.begin() + i + 1, a.end());
        k -= ((k - 1) / nfac) * nfac;
    }
    return a;
}

int main() {
    // freopen("./input.txt", "r", stdin);

    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, temp;

    temp = kthperm(a, int(1e6));

    for (int i = 0; i < a.size(); i++) cout << temp[i] << ' ';
    cout << '\n';

    return 0;
}