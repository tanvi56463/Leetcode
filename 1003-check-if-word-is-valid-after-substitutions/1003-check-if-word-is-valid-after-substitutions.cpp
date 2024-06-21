class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0){
            return true;
        }
        int fnd = s.find("abc");
        if(fnd != string::npos){
            //string mil gayi hai
            string tl = s.substr(0,fnd);
            string tr = s.substr(fnd+3,s.size());
            return isValid(tl+tr);
        }
        return false;
    }
};