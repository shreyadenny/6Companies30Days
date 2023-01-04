class Solution {
public:
    void solve(int ind, int sum, int k, int n, vector<int>& v, vector<vector<int>>& ans){
        if(k==0 && sum==n){
            ans.push_back(v);
            return;
        }
        if(sum>n){
            return;
        }
        for(int i=ind; i<10; i++){
            if(i>n){
                break;
            }
            v.push_back(i);
            solve(i+1, sum+i, k-1, n, v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        vector<vector<int>> ans;
        solve(1, 0, k, n, v, ans);
        return ans;
        }
};