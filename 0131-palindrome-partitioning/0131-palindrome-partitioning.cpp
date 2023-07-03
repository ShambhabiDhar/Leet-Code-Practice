class Solution {
public:
    bool ispalindrome(string s, int start, int end){
        while(start<=end){
            if (s[start++]!=s[end--]) return false;
        }
        return true;
    }
    
    void partition(int id, int n, string s, vector<string> &sub, vector<vector<string>> &ans){
        if(id==n){
            ans.push_back(sub);
            return;
        }
        for(int i=id; i<n; i++){
            if (ispalindrome(s,id,i)){
                sub.push_back(s.substr(id,i-id+1));
                partition(i + 1, n, s, sub, ans);
                sub.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sub;
        int n=s.size();
        partition(0, n, s, sub, ans);
        return ans;
    }
};