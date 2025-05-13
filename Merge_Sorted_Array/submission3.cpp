class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int pt = m+n-1, i=m-1, j=n-1;

        while (i>=0 && j>=0){
            if (nums2[j]>=nums1[i]){
                nums1[pt] = nums2[j];
                j--;
            }
            else{
                nums1[pt] = nums1[i];
                i--;
            }
            pt--;
        }

        while (j>=0){
            nums1[pt] = nums2[j];
            pt--;
            j--;
        }
    }
};