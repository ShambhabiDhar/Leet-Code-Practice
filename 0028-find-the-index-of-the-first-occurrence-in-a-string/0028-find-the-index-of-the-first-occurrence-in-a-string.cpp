class Solution {
public:
    int strStr(string haystack, string needle) {
        int nn=needle.length(), nh=haystack.length();
        for(int i=0; i<nh; i++){
            if(haystack[i]==needle[0]){
                if(haystack.substr(i,nn)==needle){
                    return i;
                }
            }
        }
        return -1;
    }
};