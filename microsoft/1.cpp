class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                stringstream st(tokens[i]);
                int x = 0;
                st >> x;
                s.push(x);
            }
            else{
                int ans;
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                if(tokens[i]=="/"){
                    ans=b/a;
                }
                if(tokens[i]=="-"){
                    ans=b-a;
                }
                if(tokens[i]=="+"){
                    ans=b+a;
                }
                if(tokens[i]=="*"){
                    ans=b*a;
                }
                s.push(ans);
            }
        }
        return s.top();
    }
};