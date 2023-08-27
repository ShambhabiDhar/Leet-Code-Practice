class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i=0;
        
        while(i<words.size()){
            int end=i;
            int space=0;
            int word=0;
            string s="";
            int word_length=0;
            for(int j=i; j<words.size(); j++){
                if(j==i){
                    word++;
                    word_length+=words[j].size();
                }
                else{
                    if(word_length+space+1+words[j].size() > maxWidth){
                        break;
                    }
                    else{
                        space++;
                        word++;
                        word_length+=words[j].size();
                        end=j;
                    }
                }
            }
            
            if(end!= words.size()-1){
                int extra=0;
                int spc=0;
                if(space){
                    spc= (maxWidth-word_length)/space ; // partition spaces need to be divivded into
                    extra= (maxWidth-word_length)%space ; //no. of spaces
                }
                for(int j=i; j<=end; j++){
                    s+=words[j];
                    for(int k=0; k<spc && j!=end; k++ ){
                        s+=" ";
                    }
                    if(extra){
                        extra--;
                        s+=" ";
                    }
                }
                if(space==0){
                    int k=s.size();
                    for(int j=1; j<= maxWidth-k; j++){
                        s+=" ";
                    }
                }
            }
            else{
                for(int j=i; j<=end; j++){
                    if(j==i){
                        s+=words[j];
                    }
                    else{
                        s+=" ";
                        s+=words[j];
                    }
                }
                int k=s.size();
                for(int j=1; j<= maxWidth-k ; j++){
                    s+=" ";
                }
            }
            i=end+1;
            ans.push_back(s);
        }
        return ans;
    }
};