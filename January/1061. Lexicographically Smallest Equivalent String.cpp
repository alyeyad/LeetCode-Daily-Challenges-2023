class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int bucket_cnt = 0;
        vector<int> letters(26, -1);

        for (int i = 0; i < n; ++i) {
            int c1 = s1[i] - 'a', c2 = s2[i] - 'a';
            if (letters[c1] == -1 && letters[c2] == -1) {
                ++bucket_cnt;
                letters[c1] = letters[c2] = bucket_cnt - 1;
            } else if (letters[c1] == -1 || letters[c2] == -1) {
                letters[c1] = max(letters[c1], letters[c2]);
                letters[c2] = letters[c1];
            } else {
                if (letters[c2] != letters[c1]) {
                    int tmp = letters[c2];
                    for (int j = 0; j < 26; ++j) {
                        if (letters[j] == tmp)
                            letters[j] = letters[c1];

                    }
                }
            }
        }
        vector<int> min_char(bucket_cnt, 99);
        for (int i = 0; i < 26; ++i) {
            if (letters[i] > -1 && i < min_char[letters[i]]) min_char[letters[i]] = i;
        }

        string res = "";
        for (int i = 0; i < baseStr.size(); ++i) {
            if (letters[baseStr[i] - 'a'] == -1) res.push_back(baseStr[i]);
            else res.push_back(char('a' + min_char[letters[baseStr[i] - 'a']]));
        }
        return res;
    }
};