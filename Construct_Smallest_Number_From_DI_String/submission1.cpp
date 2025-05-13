class Solution {
public:
    bool solve(string &pattern, vector<int> &isUsed, string &current, string &ans, int index, int n){

        if (index==n){
            ans = current;
            return true;
        }

        for (int i=0; i<9; i++){
            if (isUsed[i] == false){
                if ((pattern[index] == 'I' && current[index]<'1'+i) || (pattern[index]=='D' && current[index]>'1'+i)){
                    current.push_back('1'+i);
                    isUsed[i] = true;
                    if (solve(pattern, isUsed, current, ans, index+1, n)){
                        current.pop_back();
                        isUsed[i] = false;
                        return true;
                    } else {
                        current.pop_back();
                        isUsed[i] = false;
                    }
                }
            }
        }

        return false;
    }

    string smallestNumber(string pattern) {
        int index = 0, n = pattern.size();
        vector<int> isUsed(9, 0);
        string current = "", ans="";
        for (int i=0; i<9; i++){
            current.push_back('1'+i);
            isUsed[i] = true;
            if (solve(pattern, isUsed, current, ans, index, n)){
                return ans;
            } else {
                isUsed[i] = false;
                current.pop_back();
            }
        }
        return ans;
    }
};