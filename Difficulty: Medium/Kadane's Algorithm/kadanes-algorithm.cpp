class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int ans=arr[0], n=arr.size(), sum=0;
        for (int i=0; i<n; i++){
            sum+=arr[i];
            ans=max(ans, sum);
            if(sum<0){
                sum=0;
            }
        }
        
        return ans;
    }
};