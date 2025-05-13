class Solution {
public:
    int findRoot(int n){
        long long s = 0, e = n, mid;
        while (s<=e){
            mid = s + (e-s)/2;
            if (mid*mid == n) break;
            else if (mid*mid > n) e = mid-1;
            else s = mid+1;
        }
        return mid;
    }

    int nonSpecialCount(int l, int r) {

        int root = findRoot(r), ans = r-l+1;
        vector<bool> nums(root+1, true);

        for (int i=2; i*i<=root; i++){
            if (nums[i] == true){
                for (int j=2*i; j<=root; j=j+i){
                    nums[j] = false;
                }
            }
        }

        for (int i=2; i<=root; i++){
            if (nums[i] && i*i>=l && i*i<=r) ans--;
        }

        return ans;
    }
};