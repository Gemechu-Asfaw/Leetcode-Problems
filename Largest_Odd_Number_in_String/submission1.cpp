class Solution {
public:
    string largestOddNumber(string nums) {
        int i = nums.size()-1;
        string ans = "";
        while (i>=0 && (nums[i]-'0')%2==0){
            i--;
        }

        for (int j=0; j<=i; j++){
            ans.push_back(nums[j]);
        }

        return ans;
    }
};