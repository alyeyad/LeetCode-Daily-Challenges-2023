class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        if(n == 1)
        {
            if(gas[0] - cost[0] >= 0) return 0;
            return -1;
        }
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = gas[i] - cost[i];
        }
        for (int i = 0; i < n; ++i) {
            if (diff[i] > 0) {
                int total = 0, ind = i;
                for (int j = 0; j < n && total >= 0; ++j) {
                    total += diff[ind];
                    ++ind;
                    if (ind == n) ind = 0;
                }
                if(total >= 0) return ind;
            }
        }
        return -1;
    }
};