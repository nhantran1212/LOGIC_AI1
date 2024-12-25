#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool evaluateExpression(const string& expr, vector<bool>& values) {
    // Implement logic to evaluate expression based on values
    // This should be similar to the evaluateExpression function above, 
    // but modified to handle a variety of inputs
    return true; // Placeholder return
}

int main() {
    string expr = "(A ∨ ¬B) ∧ C";
    vector<char> variables = {'A', 'B', 'C'};
    int n = variables.size();
    
    for (int i = 0; i < (1 << n); ++i) {
        vector<bool> values;
        for (int j = 0; j < n; ++j) {
            values.push_back((i >> j) & 1);
        }
        cout << "A B C Result" << endl;
        for (bool value : values) {
            cout << value << " ";
        }
        cout << evaluateExpression(expr, values) << endl;
    }
    return 0;
}
