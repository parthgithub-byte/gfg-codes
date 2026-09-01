class Solution {
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n=arr.size();
        int start=1, end=arr[n-1]-arr[0];
        int ans=1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int count=1, index=0;
            for (int i=1; i<n; i++){
                if(arr[i]-arr[index]>=mid){
                    count++;
                    index=i;
                }
            }
            
            if(count>=k){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        return ans;
    }
};