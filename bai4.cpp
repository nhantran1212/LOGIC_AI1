#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

// Hàm tính giá trị biểu thức logic
bool evaluateExpression(const string& expr, const unordered_map<char, bool>& values) {
    stack<bool> s;
    for (char ch : expr) {
        if (isalpha(ch)) s.push(values.at(ch));
        else if (ch == '¬') { bool a = s.top(); s.pop(); s.push(!a); }
        else if (ch == '∧') { bool b = s.top(); s.pop(); bool a = s.top(); s.pop(); s.push(a && b); }
        else if (ch == '∨') { bool b = s.top(); s.pop(); bool a = s.top(); s.pop(); s.push(a || b); }
        else if (ch == '→') { bool b = s.top(); s.pop(); bool a = s.top(); s.pop(); s.push(!a || b); }
    }
    return s.top();
}

// Hàm chứng minh phát biểu
bool prove(const vector<string>& premises, const string& conclusion, const vector<char>& variables) {
    int n = variables.size();
    for (int i = 0; i < (1 << n); ++i) {
        unordered_map<char, bool> values;
        for (int j = 0; j < n; ++j) values[variables[j]] = (i >> j) & 1;

        bool premisesTrue = true;
        for (const auto& premise : premises) premisesTrue &= evaluateExpression(premise, values);
        if (premisesTrue && !evaluateExpression(conclusion, values)) return false;
    }
    return true;
}

int main() {
    vector<string> premises = {"A→B", "B→C"};
    string conclusion = "A→C";
    vector<char> variables = {'A', 'B', 'C'};

    if (prove(premises, conclusion, variables))
        cout << "Conclusion is provable." << endl;
    else
        cout << "Conclusion is not provable." << endl;

    return 0;
}
