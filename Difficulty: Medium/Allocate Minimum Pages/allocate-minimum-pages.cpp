class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        long long n=arr.size();
        if (k>n) return -1;
        long long start=*max_element(arr.begin(), arr.end());
        long long end=accumulate(arr.begin(), arr.end(), 0LL);
        long long ans=end;
        
        while(start<=end){
            long long mid=start+(end-start)/2;
            long long count=1, pages=0;
            for(long long i=0; i<n; i++){
                pages+=arr[i];
                if(pages>mid){
                    count++;
                    pages=arr[i];
                }
            }
            
            if (count<=k){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
         
        return (int)ans;
    }
};