class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++){
            swap(nums1[m+n-1-i] , nums2[n-1-i]);
        }
        sort(nums1.begin(),nums1.end());
    }
};