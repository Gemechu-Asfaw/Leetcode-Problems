class Solution {
public:
    string largestGoodInteger(string num) {
        
        char digit = '\0';
        int n = num.size()-3;

        for (int i=0; i<=n; i++){
            if (num[i]==num[i+1] && num[i]==num[i+2] && (digit=='\0' || num[i]>digit)){
                digit = num[i];
            }
        }

        if (digit=='\0'){
            return "";
        }
        
        string ans;
        for (int i=0; i<3; i++){
            ans.push_back(digit);
        }

        return ans;
    }
};