class Solution {
public:
    int sqrt(int k){
        
        int i = 1;
        while (i*i <= k){
            i++;
        }
        
        return i-1;
    }
    
    int minOperations(int k) {
        
        if (k==1){
            return 0;
        }
        
        int x = sqrt(k), ans = x-1;
        for (int i=x; i<k; i=i+x){
            ans++;
        }
        
        return ans;
    }
};