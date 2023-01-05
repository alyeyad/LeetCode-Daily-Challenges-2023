class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        int cnt = 1, n = points.size();
        sort(points.begin(), points.end(), [](const auto &a1, const auto &a2) {
            if (a1[1] == a2[1]) return a1[0] < a2[0];
            return a1[1] < a2[1];
        });

        int start_ind = 0, ind = 1;

        while (ind < n) {
            if (points[start_ind][1] < points[ind][0]) {
                ++cnt;
                start_ind = ind;
            }
            ++ind;
        }
        return cnt;
    }
};