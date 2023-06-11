class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int e1, e2;
        
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && (cnt2 == 0 || nums[i] != e2)) {
                e1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0 && nums[i] != e1) {
                e2 = nums[i];
                cnt2 = 1;
            }
            else if (nums[i] == e1) {
                cnt1++;
            }
            else if (nums[i] == e2) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int> ans;
        cnt1 = 0;
        cnt2 = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == e1) cnt1++;
            if (nums[i] == e2) cnt2++;
        }

        int minCount = n / 3;
        
        if (cnt1 > minCount) {
            ans.push_back(e1);
            if (e1==e2){
                return ans;
            }
        }
        if (cnt2 > minCount) ans.push_back(e2);
        
        return ans;
    }
};
