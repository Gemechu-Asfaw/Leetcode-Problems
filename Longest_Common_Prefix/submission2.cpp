class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = strs[0];
        int ansSize = ans.length();
        int size = strs.size();

        for (int i=1; i<size; i++){
            
            if (ans == ""){
                return ans;
            }

            string element = strs[i];
            int elementSize = strs[i].length();
            string current = "";

            int j=0;
            while (j < min(ansSize,elementSize)){
                if (element[j]!=ans[j]){
                    break;
                }
                current.push_back(ans[j]);
                j++;
            }

            ans = current;
            ansSize = ans.length();
        }

        return ans;

    }
};