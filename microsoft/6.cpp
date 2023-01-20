class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if(rectangles.size()==1)return true;
        map<pair<int,int>, int> mp;
        for(auto& rect: rectangles){
            mp[{rect[0], rect[1]}]++;
            mp[{rect[2], rect[3]}]++;
            mp[{rect[0], rect[3]}]--;
            mp[{rect[2], rect[1]}]--;
        }   
        int count=0;  
        for(auto it=mp.begin(); it!=mp.end(); it++){
            if(it->second!=0){
                if(abs(it->second)!=1)return false;
                count++;
            }
        }  
        if(count==4)return true;
        else return false;
    }
};