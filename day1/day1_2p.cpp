#include <iostream>
#include <unordered_map>
#include <vector>

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

    unordered_map<int, int> times;
    long long sum = 0;
    for (int x : l) {
        times[x]++;
    }
    for (int y : r) {
        sum += y * times[y];
    }

    cout << sum << endl;

    return 0;
}
