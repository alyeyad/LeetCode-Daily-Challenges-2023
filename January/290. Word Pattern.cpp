class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int sz_pattern = pattern.size(), sz_str = s.size();
        unordered_map<char, string> map;
        vector<string> strs;
        string cur = "";
        for (int i = 0; i < sz_str; ++i) {
            if (s[i] == ' ') {
                strs.push_back(cur);
                cur = "";
            } else cur.push_back(s[i]);
        }
        strs.push_back(cur);

        if(strs.size()!=sz_pattern) return false;
        for (int i = 0; i < sz_pattern; ++i)
        {
            if (map.find(pattern[i]) == map.end())
            {
                auto it = map.begin();
                bool flag = false;
                while(it!=map.end())
                {
                    if(it->second == strs[i])
                    {
                        return false;
                    }
                    ++it;
                }
                map[pattern[i]] = strs[i];
            }
            else
            {
                if (map[pattern[i]] != strs[i])
                {
                    return false;
                }

            }
        }
        return true;
    }
};