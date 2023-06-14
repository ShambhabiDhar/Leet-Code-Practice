class Solution {
public:
    vector<int> twoSum(vector<int> &arr, int target) {
        int n=arr.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            int moreNeeded = target - num;
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }
            mpp[num] = i;
        }
        return { -1, -1};
    }
};