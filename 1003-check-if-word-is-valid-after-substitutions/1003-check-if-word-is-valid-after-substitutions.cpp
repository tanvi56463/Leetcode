// class Solution {
// public:
//     bool isValid(string s) {
//         if(s.size()==0){
//             return true;
//         }
//         int fnd = s.find("abc");
//         if(fnd != string::npos){
//             //string mil gayi hai
//             string tl = s.substr(0,fnd);
//             string tr = s.substr(fnd+3,s.size());
//             return isValid(tl+tr);
//         }
//         return false;
//     }
// };


 class Solution {
 public:
      bool isValid(string s) {
          if(s[0] != 'a') return false;
          stack<char> st;
          for(char ch:s){
              if(ch == 'a')
                  st.push(ch);  
              else if(ch == 'b'){
                  if(!st.empty() && st.top() == 'a'){
                      st.push(ch);
                  }
                  else{
                      return false;
                  }
              }
              else{
                  //ch = 'c'
                  //pop 'b' and 'a'
                  if(!st.empty() && st.top()=='b'){
                      st.pop();
                      if(!st.empty()&& st.top()=='a'){
                          st.pop();
                      }
                      else
                          return false;                   
                  }
                  else
                      return false; 
                  

              }
          }
          return st.empty();
           }
    };
