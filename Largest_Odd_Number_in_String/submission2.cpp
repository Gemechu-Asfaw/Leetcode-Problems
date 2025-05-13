class Solution {
public:
    string largestOddNumber(string num) {
        
        int i = num.size()-1;
        while (i>=0 && int(num[i]) % 2 == 0){
            i--;
        }

        string ans;
        for (int j=0; j<=i; j++){
            ans.push_back(num[j]);
        }

        return ans;
    }
};