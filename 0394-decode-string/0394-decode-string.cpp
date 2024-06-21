class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto ch:s){
            if(ch==']'){
                string StrToRepeat = "";
                while(!st.empty() && !isdigit(st.top()[0])){
                    string top = st.top();
                    StrToRepeat += top =="[" ? "" : top;
                    st.pop();
                }
                string NumericTimes = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    NumericTimes += st.top();
                    st.pop();
                    
                }
                reverse(NumericTimes.begin(),NumericTimes.end());
                int n = stoi(NumericTimes); //str to int
                
                //final decoding
                string currDecode ="";
                while(n--){
                    currDecode += StrToRepeat;
                    
                }
                st.push(currDecode);
                
            }
            else {
                string temp(1,ch); //convert string to char
                st.push(temp);
                
            }
        }
        
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};