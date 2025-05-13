class Solution {
public:
    void merge(vector<int>& arr, int s, int mid, int e, unordered_map<int,int> &mapping){

        int* newArr = new int[e-s+1];
        int index = 0, index1 = s, index2 = mid+1;

        while (index1 <= mid || index2 <= e){

            if (index1 <= mid && index2 <= e){

                if ( (mapping.find(arr[index1]) != mapping.end()) && (mapping.find(arr[index2]) != mapping.end()) ){
                    if (mapping[arr[index1]] <= mapping[arr[index2]]){
                        newArr[index++] = arr[index1++];
                    } else {
                        newArr[index++] = arr[index2++];
                    }
                } else if (mapping.find(arr[index1]) != mapping.end()){
                    newArr[index++] = arr[index1++];
                } else if (mapping.find(arr[index2]) != mapping.end()){
                    newArr[index++] = arr[index2++];
                } else {
                    if (arr[index1] <= arr[index2]){
                        newArr[index++] = arr[index1++];
                    } else {
                        newArr[index++] = arr[index2++];
                    }
                }
            } else if (index1 <= mid){
                newArr[index++] = arr[index1++];
            } else {
                newArr[index++] = arr[index2++];
            }
        }

        for (int i=0; i<=e-s; i++){
            arr[s+i] = newArr[i];
        }

        delete[] newArr;

    }

    void sort(vector<int>& arr, int s, int e, unordered_map<int,int> &mapping){

        if (s>=e){
            return;
        }

        int mid = s + (e-s)/2;
        sort(arr, s, mid, mapping);
        sort(arr, mid+1, e, mapping);
        merge(arr, s, mid, e, mapping);
    }

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {    

        unordered_map<int, int> mapping;
        int n = arr1.size(), m = arr2.size();

        for (int i = 0; i < arr2.size(); i++) {
            mapping[arr2[i]] = i+1;
        }

        sort(arr1, 0, n-1, mapping);
        return arr1;
    }
};