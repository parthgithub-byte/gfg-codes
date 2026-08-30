class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        long long n=arr.size();
        long long end=accumulate(arr.begin(), arr.end(), 0LL);
        long long start=end/k;
        if (end<=k) return 1;
        long long ans=end;
        while(start<=end){
            long long mid=start+(end-start)/2;
            long long total=0;
            for(long long i=0; i<n; i++){
                total+=(arr[i]/mid);
                if(arr[i]%mid) total++;
            }

            if(total<=k){
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