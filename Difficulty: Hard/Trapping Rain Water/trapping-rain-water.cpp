class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int index=0, maxi=arr[0];
        for (int i=0; i<n; i++){
            if (arr[i]>maxi){
                index=i;
                maxi=arr[i];
            }
        }
        
        int water=0, leftMax=arr[0], rightMax=arr[n-1];
        
        for (int i=1; i<index; i++){
            if (leftMax>arr[i]){
                water+=(leftMax-arr[i]);
            }
            else{
                leftMax=arr[i];
            }
        }
        
        for (int i=n-2; i>index; i--){
            if (rightMax>arr[i]){
                water+=(rightMax-arr[i]);
            }
            else{
                rightMax=arr[i];
            }
        }
        
        return water;
        
    }
};