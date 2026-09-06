class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int repeated=-1, missing=-1;
        sort(arr.begin(), arr.end());
        int n=arr.size();
        for(int i=1; i<n; i++){
            if(arr[i]==arr[i-1]){
                repeated=arr[i];
                break;
            }
        }
        
        for(int i=0; i<n-1; i++){
            if(arr[i+1]!=arr[i]+1 && arr[i+1]!=arr[i]){
                missing=arr[i]+1;
                break;
            }
        }
        
        if(missing == -1){
            if(arr[0] != 1)
                missing = 1;
            else
                missing = n;
        }
        return {repeated, missing};
    }
};