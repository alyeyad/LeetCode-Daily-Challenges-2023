class Solution {
public:
    vector<int> res;

    vector<int> countLetters(vector<vector<int>> &list, int nodeInd, int parent, string &labels) {
        int letter = labels[nodeInd] - 'a';
        vector<int> letter_cnt(26);
        for (int &adj: list[nodeInd]) {
            if (parent != -1 && adj == parent) continue;

            vector<int> adj_cnt = countLetters(list, adj, nodeInd, labels);

            for (int i = 0; i < 26; ++i) letter_cnt[i] += adj_cnt[i];
        }
        res[nodeInd] = ++letter_cnt[letter];
        return letter_cnt;
    }

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
        vector<vector<int>> list(n);
        for (vector<int> &edge: edges) {
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
        }
        res.resize(n);
        countLetters(list, 0, -1, labels);
        return res;
    }
};