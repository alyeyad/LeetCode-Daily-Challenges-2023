class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        int n = points.size();
        if (n <= 2) return n;
        int cnt, mx_cnt = 2;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cnt = 2;
                if (points[j][0] == points[i][0]) {
                    for (int k = j + 1; k < n; ++k)
                    {
                        if(points[j][0] == points[k][0]) ++cnt;
                    }
                } else {
                    double m = double(points[j][1] - points[i][1]) / double(points[j][0] - points[i][0]),
                            b = double(points[j][1]) - m * double(points[j][0]);
                    for (int k = j + 1; k < n;++k)
                    {
                        if(abs(m * double(points[k][0]) + b - double(points[k][1])) < 1e-10)
                            ++cnt;
                    }
                }
                if (cnt == n) return n;
                if (cnt > mx_cnt) mx_cnt = cnt;
            }
        }
        return mx_cnt;

    }
};