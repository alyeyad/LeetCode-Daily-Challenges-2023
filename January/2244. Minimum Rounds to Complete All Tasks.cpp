class Solution {
public:
    int minimumRounds(vector<int> &tasks) {
        int n = tasks.size(), cnt = 0;
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m[tasks[i]]++;
        }
        auto it = m.begin();
        while (it != m.end()) {
            int curFreq = it->second;
            if (curFreq == 1) return -1;
            else
                cnt += curFreq / 3 + (curFreq % 3 > 0);
            ++it;
        }
        return cnt;
    }
};