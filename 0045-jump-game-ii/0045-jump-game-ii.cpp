class Solution
{
public:
// This function calculates the minimum number of jumps required to reach the last index 
// of the input vector.

int jump(vector<int>& nums) {
    
    // Store the size of the input vector.
    int n = nums.size();
    
    // Declare and initialize variables for jumps, current end index, and current farthest index.
    int jumps = 0, currEnd = 0, currFarthest = 0;
    
    // Loop through the vector until the second to last element.
    for(int i = 0; i < n - 1; i++) {
        
        // Calculate the farthest index we can reach from the current index.
        currFarthest = max(currFarthest, i + nums[i]);
        
        // If we reach the current end index, we need to jump to the next furthest index.
        if(i == currEnd) {
            jumps++;
            currEnd = currFarthest;
        }
    } 
    
    // Return the number of jumps required to reach the last index.
    return jumps;
}
};