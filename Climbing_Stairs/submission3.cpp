class Solution {
public:
    int solve(int n, unordered_map<int,int> &mapping){
        if (n==-1 || n==0){
            return n+1;
        }
        else if (mapping.find(n)!=mapping.end()){
            return mapping[n];
        }

        int oneStep = solve(n-1, mapping);
        int twoStep = solve(n-2, mapping);

        mapping[n] = oneStep+twoStep;
        return mapping[n];
    }

    int climbStairs(int n) {
        
        unordered_map<int,int> mapping;
        int ans = solve(n,mapping);
        return ans;
    }
};