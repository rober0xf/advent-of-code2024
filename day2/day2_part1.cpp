#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool is_increasing(const vector<int> &nums) {
    for (size_t i = 0; i < nums.size() - 1; i++) {
        int diff = nums[i + 1] - nums[i];
        if (diff < 1 || diff > 3) {
            return false;
        }
    }
    return true;
}

bool is_decreasing(const vector<int> &nums) {
    for (size_t i = 0; i < nums.size() - 1; i++) {
        int diff = nums[i] - nums[i + 1];
        if (diff < 1 || diff > 3) {
            return false;
        }
    }
    return true;
}

bool valid_row(const vector<int> &nums) {
    return is_increasing(nums) || is_decreasing(nums);
}

int main(int argc, char *argv[]) {
    int count = 0;
    vector<vector<int>> inp;

    ifstream infile(argv[1]);
    if (!infile) {
        cerr << "error" << argv[1] << endl;
        return -1;
    }

    string line;
    while (getline(infile, line)) {
        vector<int> row;
        stringstream ss(line);
        int num;

        while (ss >> num) {
            row.push_back(num);
        }

        inp.push_back(row);
    }

    infile.close();

    for (const auto &row : inp) {
        if (valid_row(row)) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
