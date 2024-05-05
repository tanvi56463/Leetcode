class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int longest = 1, cntCurr = 0, last_smaller = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]-1 == last_smaller){
                cntCurr += 1;
                last_smaller = nums[i];
            }
            else if(nums[i]!=last_smaller){
                cntCurr = 1;
                last_smaller = nums[i];
                
            }
            longest = max(longest,cntCurr);
        }
        return longest;
    }
    
};