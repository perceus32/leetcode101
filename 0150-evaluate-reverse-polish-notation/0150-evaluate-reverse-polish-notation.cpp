class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string str : tokens){
            if(str=="+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
                //cout<<a<<"+"<<b<<"="<<a+b<<endl;
            }else if(str=="-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
                //cout<<b<<"-"<<a<<"="<<b-a<<endl;
            }else if(str=="*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a*b);
                //cout<<a<<"*"<<b<<"="<<a*b<<endl;
            }else if(str=="/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
                //cout<<b<<"/"<<a<<"="<<b/a<<endl;
            }else{
                s.push(stoi(str));
                //cout<<stoi(str)<<endl;
            }
        }
        return s.top();  
    }
};