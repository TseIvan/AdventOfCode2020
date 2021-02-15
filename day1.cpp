#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <string>
#include <vector>

using namespace std;

int pair_array_sum(int sum, vector<int> vec) {
    unordered_set<int> us;
    int x;
    for (auto & element: vec) {
        x = sum - element;
        if (us.find(x) != us.end()) {
            cout << x*element << endl;
        }
        us.insert(element);
    }
    return -1;
}

int triple_array_sum(int sum, vector<int> vec) {
    for (int i = 0; i < vec.size() - 2; i++) {
        unordered_set<int> us;
        int partial_sum = sum - vec[i];
        int remaining;
        for (int j = i + 1; j < vec.size(); j++) {
            remaining = partial_sum - vec[j];
            if (us.find(remaining) != us.end()){
                cout << remaining * vec[j] * vec[i] << endl;
            }
            us.insert(vec[j]);
        }
    }
    return -1;
}

int main() {
    ifstream infile("day1.txt", ios_base::in);
        int line;

    int x;
    vector<int> vec;

    while (infile >> line) {
        vec.push_back(line);
    }
    pair_array_sum(2020, vec);
    triple_array_sum(2020, vec);
    return -1;
}
