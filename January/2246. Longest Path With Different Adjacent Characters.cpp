class Solution {
public:

    int dfs(vector<vector<int>> &list, int nodeInd, string &s, int& mx) {
        int largest = 0, sec_largest = 0;
        for (int &adj: list[nodeInd]) {
            int cur = dfs(list, adj, s, mx);
            
            if(s[adj] == s[nodeInd]) continue;

            if (cur > largest) {
                sec_largest = largest;
                largest = cur;
            }
            else if(cur > sec_largest)
                sec_largest = cur;
            
        }
        int path_len = largest + sec_largest + 1;
        mx = max(mx, path_len);
        return largest + 1;
    }

    int longestPath(vector<int> &parent, string s) {
        int n = parent.size();
        vector<vector<int>> list(n);
        for (int i = 1; i < n; ++i) {
            list[parent[i]].push_back(i);
        }
        int mx = 1;
        dfs(list, 0, s, mx);
        return mx;
    }
};