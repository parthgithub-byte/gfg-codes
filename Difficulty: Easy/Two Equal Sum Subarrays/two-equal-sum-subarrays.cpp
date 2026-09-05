class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int total = accumulate(arr.begin(), arr.end(), 0);
        int n=arr.size(), sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(2*sum==total) return true;
            if(2*sum>total) return false;
        }
        
        return false;
    }
};
