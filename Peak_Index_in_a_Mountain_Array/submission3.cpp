class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int size = arr.size();
        int i=0, j=size-1;
        int mid;

        while (i<=j){
            mid = i + (j-i)/2;
            
            // Cases for mountain foot
            if (i==0){
                i++;
            }
            else if (j==size-1){
                j--;
            }

            // Cases to set indices for mountain peak
            if (arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if (arr[mid]>arr[mid-1]){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }

        return mid;
    }
};