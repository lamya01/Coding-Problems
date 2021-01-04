class Solution {
public:
    
    bool isBoundary(vector<vector<int>> &a, int i, int j)
    {
        int m = a.size();
        int n = a[0].size();
        if(i == 0 || i == m - 1 || j == 0 || j == n - 1)
            return true;
        return false;
    }
    bool isValid(vector<vector<int>> &a, int i, int j)
    {
        int m = a.size();
        int n = a[0].size();
        if(i < 0 || i > m - 1 || j < 0 || j > n - 1)
            return false;
        return true;
    }
    void dfs(vector<vector<int>> &a, int i, int j, int &count)
    {
        if(isBoundary(a, i, j))
        {
            count = 0;
        }
        a[i][j] = 1;
        // l up r down
        int i1[4] = {0, -1, 0, 1};
        int j1[4] = {-1, 0, 1, 0};
        
        for(int k = 0; k < 4; ++k)
        {
            int i_ = i + i1[k];
            int j_ = j + j1[k];
            if(isValid(a, i_, j_) && a[i_][j_] == 0)
                dfs(a, i_, j_, count);
        }
    }
    int closedIsland(vector<vector<int>>& a) 
    {
        int count = 1;
        int m = a.size();
        int n = a[0].size();
        int ans = 0;
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(a[i][j] == 0)
                {
                    dfs(a, i, j, count);
                    if(count)
                        ++ans;
                    else
                        count = 1;
                }
            }
        }
        
        return ans;
    }
};