class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end()); // Using unordered_set for O(1) average case lookup
        int longestStreak = 0;
        
        for (int num : nums) {
            // Only process if num is the starting element of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;
                
                // Find the length of the consecutive subsequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }
                
                // Update the longest streak if necessary
                longestStreak = std::max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};
