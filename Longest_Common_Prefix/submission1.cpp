class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        bool flag = true;
        int index = 0;
        while (flag){
            int n = strs.size();
            for (int i=0; i<n; i++){
                if (index==strs[i].size()){
                    flag = false;
                    break;
                } else if (strs[i][index] != strs[0][index]){
                    flag = false;
                    break;
                }
            }

            if (flag){
                ans.push_back(strs[0][index]);
                index++;
            }
        }

        return ans;
    }
};