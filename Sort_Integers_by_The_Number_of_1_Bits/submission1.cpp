class Solution {
public:

    void merge(vector<int>& arr, unordered_map<int,int>& setBits, int s, int e, int mid){

        int left = s, right = mid+1, index = 0;
        int tempSize = e-s+1;

        int* temp = new int[tempSize];

        while (left<=mid && right<=e){

            if (setBits[arr[left]] < setBits[arr[right]]){
                temp[index++] = arr[left++];
            }
            else if (setBits[arr[right]] < setBits[arr[left]]){
                temp[index++] = arr[right++];
            }
            else{
                if (arr[left]<=arr[right]){
                    temp[index++] = arr[left++];
                }
                else{
                    temp[index++] = arr[right++];
                }
            }
        }

        while (left<=mid){
            temp[index++] = arr[left++];
        }

        while (right<=e){
            temp[index++] = arr[right++];
        }

        for (int i=0; i<tempSize; i++){
            arr[s+i] = temp[i];
        }
        
        delete[]temp;
    }

    void mergeSort(vector<int>& arr, unordered_map<int,int>& setBits, int s, int e){

        if (s>=e){
            return;
        }

        int mid = s + (e-s)/2;
        mergeSort(arr, setBits, s, mid);
        mergeSort(arr, setBits, mid+1, e);

        merge(arr, setBits, s, e, mid);
        return;
    }

    int findSetBits(int n){

        int count = 0;
        while (n){
            if (n&1){
                count++;
            }
            n = n>>1;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        
        unordered_map<int,int> setBits;
        int n = arr.size();

        // Storing no of bits in the mapping of number
        for (int i=0; i<n; i++){
            setBits[arr[i]] = findSetBits(arr[i]);
        }

        mergeSort(arr, setBits, 0, n-1);
        return arr;
    }
};