class Solution {
public:
    int solve(int n){

        if (n==2) return -1;
        else if ((n & (n+1)) == 0) return n/2;

        int bitFlag = 1;
        while (bitFlag<=n){
            if (bitFlag & n){
                while ((bitFlag*2) & n){
                    bitFlag = bitFlag*2;
                }
                n = n - bitFlag;
                break;
            } else {
                bitFlag = bitFlag * 2;
            }
        }

        return n;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i=0; i<n; i++){
            int element = nums[i];
            ans.push_back(solve(element));
        }

        return ans;
    }
};