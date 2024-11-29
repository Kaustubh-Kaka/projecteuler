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

    int pcap = 7.5e3;
    int nc = 5e7;

    vector<bool> erat(pcap + 1, true);
    vector<ll> plist;

    for (int i = 2; i * i <= pcap; i++) {
        if (erat[i])
            for (int j = 2; i * j <= pcap; j++) erat[i * j] = false;
    }

    for (int i = 2; i <= pcap; i++)
        if (erat[i]) plist.push_back(i);

    vector<ll> lst = {}, lstr = {};
    for (int i = 0; i < plist.size(); i++)
        if (plist[i] * plist[i] <= nc) lst.push_back(plist[i] * plist[i]);

    for (int i = 0; i < lst.size(); i++) {
        for (int j = 0; j < plist.size(); j++) {
            if (lst[i] + plist[j] * plist[j] * plist[j] <= nc)
                lstr.push_back(lst[i] + plist[j] * plist[j] * plist[j]);
            else
                break;
        }
    }
    lst = lstr;
    lstr = {};
    for (int i = 0; i < lst.size(); i++) {
        for (int j = 0; j < plist.size(); j++) {
            if (lst[i] + plist[j] * plist[j] * plist[j] * plist[j] <= nc)
                lstr.push_back(lst[i] +
                               plist[j] * plist[j] * plist[j] * plist[j]);
            else
                break;
        }
    }
    lst = lstr;
    sort(lst.begin(), lst.end());

    int cnt = 1;
    for (int i = 1; i < lst.size(); i++)
        if (lst[i] != lst[i - 1]) cnt++;
    cout << cnt << '\n';
    return 0;
}