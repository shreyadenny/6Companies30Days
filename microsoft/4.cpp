class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long int ans=0;
        if(nums.size()<2)return 0;
        else{
            long long int sum=0;
            for(int i=0; i<nums.size(); i++){
                sum=sum+(i*nums[i]);
            }
            int to=0;
            for(int i=0; i<nums.size(); i++){
                to=to+nums[i];
            }
            ans=sum;
            int n=nums.size();
            for(int i=nums.size()-1; i>=0; i--){
                sum=sum+to-(n*nums[i]);
                ans=max(ans, sum);
            }
        }
        return ans;
    }
};