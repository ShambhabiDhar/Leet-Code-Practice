class Solution {
private:
    void backTrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int index) {
        ans.push_back(curr);  // Add current subset to the answer vector

        // Generate subsets by including elements starting from the given index
        for (int i = index; i < nums.size(); i++) {
            // Skip duplicate elements to avoid generating duplicate subsets
            if (i != index && nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);  // Include the current element in the current subset
            backTrack(ans, nums, curr, i + 1);
            curr.pop_back();  // Remove the current element to backtrack
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;  // Vector to store the current subset

        backTrack(ans, nums, curr, 0);
        return ans;
    }
};
