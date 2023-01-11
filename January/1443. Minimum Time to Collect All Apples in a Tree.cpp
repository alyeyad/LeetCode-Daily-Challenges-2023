class Solution {
public:
    int dfs(vector<vector<int>> &list, vector<bool> &hasApple, int nodeInd, int parent) {
        int tmp = 0;
        for (int adj: list[nodeInd]) {
            if(adj == parent) continue;
            int cur_time = dfs(list, hasApple, adj, nodeInd);
            if (hasApple[adj]) {
                if (parent != -1) hasApple[nodeInd] = true;
                tmp += cur_time;
            }
        }

        if (hasApple[nodeInd]) {
            return 2 * (nodeInd != 0) + tmp;
        } else
            return tmp;
    }

    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
        vector<vector<int>> list(n);
        for (vector<int> &edge: edges)
            {
                list[edge[0]].push_back(edge[1]);
                list[edge[1]].push_back(edge[0]);
            }
        return dfs(list, hasApple, 0, -1);
    }
};