#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

// 1000 numbers from the input
const int N = 1000;

using namespace std;
int main(int argc, char *argv[]) {
    vector<int> l, r;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        l.push_back(x);
        r.push_back(y);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += abs(l[i] - r[i]);
    }

    cout << sum << endl;
    return 0;
}
