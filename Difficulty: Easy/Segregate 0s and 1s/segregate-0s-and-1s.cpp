class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int first=0, second=arr.size()-1;
        while(first<second){
            if(arr[first]==1){
                if(arr[second]==0){
                    swap(arr[first], arr[second]);
                    first++;
                }
                second--;
            }
            else{
                first++;
            }
        }
    }
};