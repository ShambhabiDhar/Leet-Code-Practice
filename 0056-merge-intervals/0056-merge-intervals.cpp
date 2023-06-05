class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end());
        for(int i=0; i<n; i++){
            if (merged.empty() || intervals[i][0] > merged.back()[1]){
                merged.push_back(intervals[i]);
            }
            else{
                merged.back()[1]=max(merged.back()[1],intervals[i][1]);
            }
        }
        return merged;
    }
};