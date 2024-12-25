#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValidExpression(const string& expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(') s.push(ch);
        else if (ch == ')') {
            if (s.empty() || s.top() != '(') return false;
            s.pop();
        }
    }
    return s.empty();
}

bool evaluateExpression(const string& expr, const unordered_map<char, bool>& values) {
    stack<bool> s;
    for (char ch : expr) {
        if (ch == 'A' || ch == 'B' || ch == 'C') {
            s.push(values.at(ch));
        } else if (ch == '∧') {
            bool b = s.top(); s.pop();
            bool a = s.top(); s.pop();
            s.push(a && b);
        } else if (ch == '∨') {
            bool b = s.top(); s.pop();
            bool a = s.top(); s.pop();
            s.push(a || b);
        } else if (ch == '¬') {
            bool a = s.top(); s.pop();
            s.push(!a);
        }
    }
    return s.top();
}

int main() {
    string expr = "(A∧B)→¬C";
    unordered_map<char, bool> values = {{'A', true}, {'B', false}, {'C', true}};
    
    if (isValidExpression(expr)) {
        cout << "The expression is valid." << endl;
        cout << "Result: " << evaluateExpression(expr, values) << endl;
    } else {
        cout << "The expression is invalid." << endl;
    }
    
    return 0;
}
