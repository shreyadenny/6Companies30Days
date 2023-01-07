class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()==0)return ans;
        vector<int> dp;
        for(int i=0; i<nums.size(); i++){
            dp.push_back(1);
        }
        sort(nums.begin(), nums.end());
        int ma=1;
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=dp[j]+1;
                    ma=max(ma, dp[i]);
                }
            }
        }
        int prev=-1;
        for(int i=nums.size()-1; i>=0; i--){
            if(dp[i]==ma && (prev==-1||prev%nums[i]==0)){
                prev=nums[i];
                ans.push_back(prev);
                ma--;
               }
        }
        return ans;
    }
};