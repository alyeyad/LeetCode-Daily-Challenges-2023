class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int total_shifts = std::count_if(s.begin(), s.end(), [](char x) { return x == '0'; });
        int n = s.size(), mn = total_shifts;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++total_shifts;
            } else {
                --total_shifts;
            }
            mn = min(mn, total_shifts);
        }
        return mn;
    }
};