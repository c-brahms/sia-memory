#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int sia(vector<pair<int,int>> points) {
    int n = points.size();
    sort(points.begin(), points.end());
    using pp = array<int,4>;
    priority_queue<pp,vector<pp>,greater<pp>> queue;
    for (int i = 0; i < n-1; i++) {
        int d1 = points[i+1].first-points[i].first;
        int d2 = points[i+1].second-points[i].second;
        queue.push({d1, d2, i, i+1});
    }
    int count = 0;
    pair<int,int> prev = {-1,-1};
    while (!queue.empty()) {
        auto entry = queue.top(); queue.pop();
        pair<int,int> cur = {entry[0], entry[1]};
        if (prev != cur) {
            prev = cur;
            count++;
        }
        if (entry[3] < n-1) {
            entry[3]++;
            entry[0] = points[entry[3]].first-points[entry[2]].first;
            entry[1] = points[entry[3]].second-points[entry[2]].second;
            queue.push(entry);
        }
    }
    return count;
}

int main() {
    vector<pair<int,int>> data;
    data.push_back({2,1});
    data.push_back({3,4});
    data.push_back({4,2});
    data.push_back({5,5});
    cout << sia(data) << "\n";
}
