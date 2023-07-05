class Solution {
public:
    void plist(int n, vector<int> &nums, vector<int> &sub, vector<vector<int>> &ans, vector<int> &freq){
        if (sub.size()==n){
            ans.push_back(sub);
            return;
        }
        for(int i=0; i<n; i++){
            if(freq[i]==0){
                sub.push_back(nums[i]);
                freq[i]=1;
                plist(n, nums, sub, ans, freq);
                freq[i]=0;
                sub.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        vector<int> freq(nums.size(), 0);  // Initialize freq with zeros
        int n = nums.size();
        plist(n, nums, sub, ans, freq);
        return ans;
    }
};
