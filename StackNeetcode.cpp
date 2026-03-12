#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 1. Valid Parenthesis
bool isValid(string s) {
    stack<char> st;
    for(char c : s){
        if(c == '(' || c == '[' || c == '{'){
            st.push(c);
        }else{
            if(st.empty()) return false;
            char t = st.top();
            if((t == '(' && c == ')') || (t == '{' && c == '}') || (t == '[' && c == ']')){
                st.pop();
            }else{
                return false;
            }
        }
    }
    return st.empty();
}

// 2. Min Stack
class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {
        st.empty();
        minSt.empty();
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty()) minSt.push(val);
        else minSt.push(min(val, minSt.top()));
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

// 3. Evaludate reverse polish notation
 int convert(string number){
        int num = 0;
        int neg = 1;
        int i = 0;
        if(number[0] == '-'){
            i++;
            neg=-1;
        }
        for(i; i < number.size(); i+=1){
            num*=10;
            num+=number[i] - '0';
        }
        return num*neg;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token : tokens){
            if(token == "+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1 + num2);
            }else if(token == "*"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num1 * num2);
            }else if(token == "-"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 - num1);
            }else if(token == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2 / num1);
            }else{
                st.push(convert(token));
            }
        }
    return st.top();
}

int main(){
    
}