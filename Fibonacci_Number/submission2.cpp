class Solution {
public:
    int solve(int n, unordered_map<int,int>& mapping){

        // Base Case
        if (n==0 || n==1){
            return n;
        }
        else if (mapping.find(n)!=mapping.end()){
            return mapping[n];
        }

        // Memoizing and returning the value
        mapping[n] = solve(n-1, mapping) + solve(n-2, mapping);
        return mapping[n];

    }

    int fib(int n) {
        unordered_map<int,int> mapping;
        return solve(n, mapping);
    }
};