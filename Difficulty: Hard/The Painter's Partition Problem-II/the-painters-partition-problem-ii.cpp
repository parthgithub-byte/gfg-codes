class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        int start=*max_element(arr.begin(), arr.end());
        int end=accumulate(arr.begin(), arr.end(), 0);
        int n=arr.size();
        int ans=end;
        while(start<=end){
            int mid=start+(end-start)/2;
            int partition=0, count=1;
            for(int i=0; i<n; i++){
                partition+=arr[i];
                if(partition>mid){
                    count++;
                    partition=arr[i];
                }
            }
            if(count<=k){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};