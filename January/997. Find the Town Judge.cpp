class Solution {
public:
    int findJudge(int n, vector<vector<int>> &trust) {
        int m = trust.size();
        vector<int> trusts_cnt(n), is_trusted_cnt(n);
        for (int i = 0; i < m; ++i) {
            ++trusts_cnt[trust[i][0] - 1];
            ++is_trusted_cnt[trust[i][1] - 1];
        }
        for (int i = 0; i < n; ++i) {
            if (trusts_cnt[i] == 0 && is_trusted_cnt[i] == n - 1) return i + 1;
        }
        return -1;
    }
};