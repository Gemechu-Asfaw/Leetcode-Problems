class Solution {
public:
    int maxElement(vector<int> &nums){
        int n = nums.size(), maxi = -1;
        for (int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    bool isValid(vector<int> &nums, int m, int maxOperations){

        int n = nums.size();

        for (int i=0; i<n; i++){
            if (nums[i] > m){

                int requiredOperations = nums[i]/m - 1;
                if ( (nums[i]%m) != 0) requiredOperations++;

                if (requiredOperations > maxOperations){
                    return false;
                } else {
                    maxOperations = maxOperations - requiredOperations;
                }
            }
        }

        return true;

    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int s = 1, e = maxElement(nums), m;
        int n = nums.size();
        int ans = e;

        while (s<=e){
            m = s + (e-s)/2;
            cout << m << " ";
            if (isValid(nums, m, maxOperations)){
                e = m-1;
                ans = m;
            } else {
                s = m+1;
            }
        }

        return ans;
    }
};