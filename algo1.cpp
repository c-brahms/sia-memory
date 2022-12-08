#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int sia(vector<pair<int,int>> points) {
    int n = points.size();
    sort(points.begin(), points.end());
    vector<pair<pair<int,int>,pair<int,int>>> pairs;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int d1 = points[j].first-points[i].first;
            int d2 = points[j].second-points[i].second;
            pairs.push_back({{d1,d2},{i,j}});
        }
    }
    sort(pairs.begin(), pairs.end());
    int count = 1;
    for (int i = 1; i < pairs.size(); i++) {
        if (pairs[i-1].first != pairs[i].first) count++;
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
