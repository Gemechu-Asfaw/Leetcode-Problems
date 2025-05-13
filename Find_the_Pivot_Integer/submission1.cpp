class Solution {
public:
    int pivotInteger(int n) {
        
        if (n==1){
            return 1;
        }

        int left = 1, right = n*(n+1)/2;
        for (int i=2; i<=n; i++){
            if (left==right){
                return i-1;
            }
            right = right - (i-1);
            left = left + i;
        }

        return -1;
    }
};