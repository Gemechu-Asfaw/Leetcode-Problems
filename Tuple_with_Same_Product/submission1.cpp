class Solution {
public:
    int findnCk(int n , int k){
        int ans = 1;
        for (int i=1; i<=min(k, n-k); i++){
            ans = ans*(n-i+1)/i;
        }
        return ans;
    }

    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> product;

        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                product[nums[i]*nums[j]]++;
            }
        }

        for (auto prod : product){
            if (prod.second >= 2){
                ans = ans + (8 * findnCk(prod.second, 2));
            }
        }

        return ans;
    }
};