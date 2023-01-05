class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), cnt = 0;
    
        vector<bool> deleted(m, false);
        for(int i = 1; i < n; ++i) 
        {
            for(int j = 0; j < m; ++j)
            {
                if(!deleted[j] && strs[i][j] < strs[i-1][j])
                {
                    deleted[j] = true;
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};