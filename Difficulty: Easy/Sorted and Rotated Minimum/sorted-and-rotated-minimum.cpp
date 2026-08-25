class Solution {
  public:
    int findMin(vector<int>& arr) {
        // code here
        int n=arr.size();
        if (n<=3){
            auto it = min_element(arr.begin(), arr.end());
            return *it;
        }
        int start=1, end=n-2;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]){
                return arr[mid];
            }
            else if(arr[mid-1]<arr[mid] && arr[mid]>arr[n-1]){  // on the left part
                start++;
            }
            else{   //on the right part
                end--;
            }
        }
        // 2 missed cases:

        if (arr[n-1]<arr[n-2]) return arr[n-1];
        return arr[0];
    }
};