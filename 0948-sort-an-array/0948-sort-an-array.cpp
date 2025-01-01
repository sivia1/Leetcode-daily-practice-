class Solution {
public:
//Merge Sort is applicable as TC is O(n log n)
    void merge(vector<int>& arr, int left, int mid, int right, vector<int> &tempArr) {
        //calculate the start and sizes of two halves
        int start1 = left;
        int start2 = mid + 1;
        int n1= mid-left+1;
        int n2 = right - mid;

        //copy elements of both halves into temp array
        for(int i = 0; i < n1; i++) {
            tempArr[start1 + i] = arr[start1 + i];
        }
        for(int i = 0; i < n2; i++) {
            tempArr[start2 + i] = arr[start2 + i];
        }

        //Merge subarrays in temp array back into the original array in sorted order
        int i = 0, j = 0, k = left;
        while(i < n1 && j < n2) {
            if(tempArr[start1 + i] <= tempArr[start2 + j]) {
                arr[k] = tempArr[start1 + i];
                i += 1;
            } else {
                arr[k] = tempArr[start2 + j];
                j += 1;
            }
            k += 1;
        }

        //copy remaining elements
        while(i < n1) {
            arr[k] = tempArr[start1 + i];
            i += 1;
            k += 1;
        }
        while(j < n2) {
            arr[k] = tempArr[start2 + j];
            j += 1;
            k += 1;
        }
    }

    //Recursive function to sort an array using merge sort
    void mergeSort(vector<int> &arr, int left, int right, vector<int> &tempArr) {
        if(left >= right) {
            return;
        }
        int mid = (left + right) / 2;
        //sort first and second halves recursively
        mergeSort(arr, left, mid, tempArr);
        mergeSort(arr, mid+1, right, tempArr);
        //merge the sorted halves
        merge(arr, left, mid, right, tempArr);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tempoArr(nums.size());
        mergeSort(nums, 0, nums.size()-1, tempoArr);
        return nums;
    }
};