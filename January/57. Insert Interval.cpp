class Solution {
public:
    bool olap(vector<int> &intvl1, vector<int> &intvl2) {
        int a1 = intvl1[0], b1 = intvl1[1], a2 = intvl2[0], b2 = intvl2[1];
        return (a1 >= a2 && a1 <= b2) || (a2 >= a1 && a2 <= b1) || (b2 >= a1 && b2 <= b1) || (b1 >= a2 && b1 <= b2);
    }

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        vector<int> overlap(n, false);
        for (int i = 0; i < n; ++i) {
            if (olap(newInterval, intervals[i])) {
                overlap[i] = true;
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!overlap[i])
                res.push_back(intervals[i]);
        }
        res.push_back(newInterval);
        std::sort(res.begin(), res.end());
        return res;
    }
};