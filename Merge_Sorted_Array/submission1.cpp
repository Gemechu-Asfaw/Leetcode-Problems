class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = (m+n)/2 + (m+n)%2;
        while (gap > 0){
            int first = 0, second = gap;
            while (second < m+n){
                if (second<m){
                    if (nums1[first] > nums1[second]){
                        swap(nums1[first], nums1[second]);
                    }
                } else if (first>=m){
                    if (nums2[first-m] > nums2[second-m]){
                        swap(nums2[first-m], nums2[second-m]);
                    }
                } else {
                    if (nums1[first] > nums2[second-m]){
                        swap(nums1[first], nums2[second-m]);
                    }
                }

                first++;
                second++;
            }

            if (gap == 1){
                gap = 0;
            } else {
                gap = (gap/2) + (gap%2);
            }
        }

        for (int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
    }
};