class Solution {
public:
    void plist(int n, std::string& s, std::vector<int>& nums, std::vector<std::string>& res, std::vector<bool>& freq) {
        if (s.size() == n) {
            res.push_back(s);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!freq[i]) {
                s.push_back('0' + nums[i]);
                freq[i] = true;
                plist(n, s, nums, res, freq);
                freq[i] = false;
                s.pop_back();
            }
        }
    }

    std::string getPermutation(int n, int k) {
        std::vector<int> nums(n);
        std::iota(nums.begin(), nums.end(), 1);
        std::vector<bool> freq(n, false);
        std::vector<std::string> res;
        std::string s;
        plist(n, s, nums, res, freq);
        return res[k - 1];
    }
};
