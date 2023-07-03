class Solution {
public:
    void uniquesub2(int id, int n, int target, vector<int> &candidates, vector<int> &sub, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(sub);
            return;
        }
        for(int i=id; i<n; i++){
            if (i > id && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            sub.push_back(candidates[i]);
            uniquesub2(i + 1, n, target - candidates[i], candidates, sub, ans);
            sub.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> sub;
        int n=candidates.size();
        uniquesub2(0, n, target, candidates, sub, ans);
        return ans;
    }
}; 