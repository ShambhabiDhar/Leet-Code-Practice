class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string temp="";
        
        int left=0;
        while(s[left]==' ') left++;
        
        int right=s.size()-1;
        while(s[right]==' ') right-- ;
        
        while(left<=right){
            if(s[left] !=' '){
                temp+=s[left];
            }
            else{
                if(s[left-1]==' '){
                    left++;
                    continue;
                }
                else{
                    ans=temp+' '+ans;
                    temp="";
                }
            }
            left++;
        }
        ans=temp+' '+ans;
        ans.erase(ans.begin()+ans.size()-1); //to erase extra space at end
        return ans;
    }
};