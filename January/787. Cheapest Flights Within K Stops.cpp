class Solution {
public:

    vector<vector<pair<int, int>>> G;
    queue<pair<int, int>> q;

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        ++k;
        int m = flights.size(), cnt = 0;
        vector<int> costs(n, INT_MAX);
        G.resize(n);
        for (int i = 0; i < m; ++i)
            G[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));

        q.push({src, 0});
        while (!q.empty() && cnt < k) {
            int level_size = q.size();
            for(int c=0;c<level_size;++c) {
                pair<int, int> cur = q.front();q.pop();
                for (auto &adj: G[cur.first]) {
                    if (cur.second + adj.second < costs[adj.first]) {

                        costs[adj.first] = cur.second + adj.second;
                        q.push({adj.first, costs[adj.first]});
                    }
                }
            }
            ++cnt;
        }

        if (costs[dst] == INT_MAX) return -1;
        return costs[dst];
    }
};