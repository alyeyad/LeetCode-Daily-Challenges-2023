class Solution {
public:
    bool is_valid(string &s) {
        int num = stoi(s);
        if (num < 0 || num > 255) return false;
        string s2 = to_string(num);
        return s.size() == s2.size();
    }


    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.size();
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3 && i + j < n; ++j) {
                for (int k = 1; k <= 3 && i + j + k < n; ++k) {
                    if (n - i - j - k <= 0 || n - i - j - k > 3) continue;
                    string part[4];
                    for (int c = 0; c < i; ++c) part[0].push_back(s[c]);
                    for (int c = 0; c < j; ++c) part[1].push_back(s[i + c]);
                    for (int c = 0; c < k; ++c) part[2].push_back(s[i + j + c]);
                    for (int c = i + j + k; c < n; ++c) part[3].push_back(s[c]);
                   

                    if (is_valid(part[0]) && is_valid(part[1]) && is_valid(part[2]) && is_valid(part[3])) {
                        string full = part[0] + "." + part[1] + "." + part[2] + "." + part[3];
                        res.push_back(full);
                    }
                }
            }
        }
        return res;
    }
};