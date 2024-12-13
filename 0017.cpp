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

vector<string> swords = {"zero",    "one",       "two",      "three",
                         "four",    "five",      "six",      "seven",
                         "eight",   "nine",      "ten",      "eleven",
                         "twelve",  "thirteen",  "fourteen", "fifteen",
                         "sixteen", "seventeen", "eighteen", "nineteen"};

vector<string> tens = {"ten",   "twenty",  "thirty", "forty", "fifty",
                       "sixty", "seventy", "eighty", "ninety"};

string wordrep(int n) {
    if (n < 20) {
        return swords[n];
    } else if (n < 100) {
        return tens[n / 10 - 1] + ((n % 10) ? (swords[n % 10]) : (""));
    } else if (n < 1000) {
        return swords[n / 100] + "hundred" +
               ((n % 100) ? ("and" + wordrep(n % 100)) : (""));
    } else {
        return wordrep(n / 1000) + "thousand" +
               ((n % 1000) ? (wordrep(n % 1000)) : (""));
    }
}

int main() {
    // freopen("./input.txt", "r", stdin);

    int ans = 0;
    for (int i = 1; i <= 1000; i++) ans += wordrep(i).size();
    cout << ans << '\n';
    return 0;
}