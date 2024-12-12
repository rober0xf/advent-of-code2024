#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
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

bool valid_row(const vector<int> &nums) { return is_increasing(nums) || is_decreasing(nums); }

bool removing_value(vector<int> row) {
    vector<int> new_row;
    for (size_t i = 0; i < row.size(); i++) {
        for (size_t j = 0; j < row.size(); j++) {
            if (j == i) {
                continue;
            }
            new_row.push_back(row[j]);
        }
        if (valid_row(new_row)) {
            new_row.clear();
            return true;
        }
        new_row.clear();
    }
    return false;
}

int main(int argc, char *argv[]) {
    int count = 0;
    ifstream file("./input.txt");
    string line;
    vector<int> row;

    while (getline(file, line)) {
        stringstream ss(line);
        int num;
        while (ss >> num) {
            row.push_back(num);
        }
        if (valid_row(row)) {
            count++;
        } else if (removing_value(row)) {
            count++;
        }
        row.clear();
    }

    cout << count << endl;
    file.close();
    return 0;
}
