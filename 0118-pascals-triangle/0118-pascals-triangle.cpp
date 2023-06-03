class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ptri;
        ptri.resize(numRows);
        for(int i = 1; i <= numRows; i++){
            if(i == 1){
                ptri[0] = {1};
            }
            else if(i == 2){
                ptri[1] = {1, 1};
            }
            else{
                ptri[i - 1].push_back(1);
                for(int j = 1; j < i - 1; j++){
                    int val = ptri[i - 2][j - 1] + ptri[i - 2][j];
                    ptri[i - 1].push_back(val);
                }
                ptri[i - 1].push_back(1);
            }
        }
        return ptri;
    }
};
