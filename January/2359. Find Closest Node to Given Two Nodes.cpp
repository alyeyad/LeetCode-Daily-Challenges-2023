class Solution {
public:
    void calc_distances(int n, int node, vector<vector<int>> &list, vector<bool> &visited, vector<int> &dist, int d = 0) {
        visited[node] = true;
        dist[node] = d;
        for (int &adj: list[node]) {
            if (!visited[adj])
                calc_distances(n, adj, list, visited, dist, d + 1);
        }
    }

    int closestMeetingNode(vector<int> &edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> list(n);
        for (int i = 0; i < n; ++i) {
            if (edges[i] == -1) continue;
            list[i].push_back(edges[i]);
        }
        vector<bool> vis1(n, false), vis2(n, false);
        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
        dist1[node1] = 0;
        dist2[node2] = 0;
        calc_distances(n, node1, list, vis1, dist1);
        calc_distances(n, node2, list, vis2, dist2);

        int res_distance = INT_MAX, res_ind = -1;
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX && max(dist1[i], dist2[i]) < res_distance) {
                res_distance = max(dist1[i], dist2[i]);
                res_ind = i;
            }
        }
        return res_ind;
    }
};