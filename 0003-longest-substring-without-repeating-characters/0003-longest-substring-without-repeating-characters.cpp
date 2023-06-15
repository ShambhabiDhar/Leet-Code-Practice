class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<int> set;
        if (n==0){
            return 0;
        }
        int len = INT_MIN; //length of longest substring
        int left=0;
        for(int right=0; right<n; right++){
            if (set.find(s[right]) != set.end()){ // to check for duplicate elements in set
                while ( left<right && set.find(s[right]) != set.end() ){
                    set.erase(s[left]);
                    left++ ;
                }
            }
            set.insert(s[right]);
            len = max(len, right-left+1);
        }
        return len;
    }
};