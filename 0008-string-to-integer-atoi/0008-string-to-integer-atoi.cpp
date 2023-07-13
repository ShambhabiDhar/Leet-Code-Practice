class Solution {
public:
    int myAtoi(string s) {
        int len=s.size();
        int i=0;
        int sign=1;
        while(s[i]==' ')i++;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            sign=1;
            i++;
        }
        long long number=0;
        while(i<len && isdigit(s[i])){
            number=(number*10)+(s[i]-'0');
            if(sign*number>INT_MAX)return INT_MAX;
            else if(sign*number<INT_MIN)return INT_MIN;
            i++;
        }
        return number*sign;
        
    }
};