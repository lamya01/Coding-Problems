class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // from the left, min length of array with sum = target
        vector<int> left = minLen(arr, target);

        // from the right, min length of array with sum = target
        vector<int> arrReverse(arr.begin(), arr.end());
        reverse(arrReverse.begin(), arrReverse.end());
        vector<int> right = minLen(arrReverse, target);
        
        // consider each position to find the min sum of length of the two array with target sum
        int min_val = arr.size() + 1;
        int n = arr.size();
        for(int i = 0; i < arr.size() - 1; ++i) {
            min_val = min(min_val, left[i] + right[n-1-i-1]);
        }
        return min_val == arr.size() + 1 ? -1 : min_val;
    }
    
    // at each position, i, find the min length of array with target sum 
    vector<int> minLen(vector<int> &arr, int target) {
        int n = arr.size();
        vector<int> presum(n, 0);
        unordered_map<int, int> idx;
        vector<int> ans(n, n + 1);
        idx[0] = -1;
        for(int i = 0; i < arr.size(); ++i) {
            presum[i] = i == 0 ? arr[i] : arr[i] + presum[i-1];
            int len = arr.size() + 1;
            if(idx.find(presum[i] - target) != idx.end()) {
                len = i - idx[presum[i]-target];
            }
            idx[presum[i]] = i;
            ans[i] = i == 0 ? len : min(ans[i-1], len);    
        }
        return ans;
    }
    
};