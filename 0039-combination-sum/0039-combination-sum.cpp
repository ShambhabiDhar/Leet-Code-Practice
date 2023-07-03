class Solution {
public:
    void uniquesub(int id, int n, int target, vector<vector<int>> &ans, vector<int> &candidates, vector<int> &sub){
        if(id==n){
            if(target==0){
                ans.push_back(sub);
            }
            return;
        }
        if (candidates[id]<=target){
            sub.push_back(candidates[id]);
            uniquesub(id, n, target-candidates[id], ans, candidates, sub );
            sub.pop_back();
        }
        uniquesub(id+1, n, target, ans, candidates, sub );
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n=candidates.size();
        vector<int> sub;
        uniquesub(0, n , target, ans, candidates, sub);
        return ans;
    }
};