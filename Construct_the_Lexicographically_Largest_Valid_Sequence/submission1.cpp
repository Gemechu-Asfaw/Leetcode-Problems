class Solution {
public:
    bool solve(vector<int> &ans, vector<bool> &used, int index, int n){
        if (index == 2*n-1){
            return true;
        } else {
            if (ans[index] == 0){
                for (int i=n-1; i>=0; i--){
                    if (used[i] == false){
                        if (i!=0){
                            if (index+i+1<=2*n-2 && ans[index+i+1] == 0){
                                ans[index] = i+1;
                                ans[index+i+1] = i+1;
                                used[i] = true;
                                bool ans1 = solve(ans, used, index+1, n);
                                if (ans1){
                                    return true;
                                } else {
                                    ans[index] = 0;
                                    ans[index+i+1] = 0; 
                                    used[i] = false;
                                }
                            }
                        } else {
                            ans[index] = i+1;
                            used[i] = true;
                            bool ans1 = solve(ans, used, index+1, n);
                            if (ans1){
                                return true;
                            } else {
                                ans[index] = 0;
                                used[i] = false;
                            }
                        }
                    }
                }
                return false;
            } else {
                return solve(ans, used, index+1, n);
            }
        }
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1, 0);
        vector<bool> used(n, false);
        int index = 0;

        solve(ans, used, index, n);
        return ans;
    }
};