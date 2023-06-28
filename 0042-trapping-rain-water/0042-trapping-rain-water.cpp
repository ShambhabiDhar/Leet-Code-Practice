class Solution {
public:
    int trap(vector<int>& height) {
        int total=0;
        int n=height.size();
        int left=0, right=n-1;
        int maxleft=0, maxright=0;
        //col=min(left_max,right_max)-height[i];
        //total=total+col;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft){
                    maxleft=height[left];
                } else {
                    total+=maxleft-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=maxright){
                    maxright=height[right];
                } else {
                    total+=maxright-height[right];
                }
                right--;
            }
        }
        return total;
    }
};