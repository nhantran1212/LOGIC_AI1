#include <iostream>
#include <functional>
#include <vector>

using namespace std;

bool checkFormula(const function<bool(int)>& P, const function<bool(int)>& Q, const vector<int>& domain) {
    for (int x : domain) {
        if (!(P(x) && Q(x))) {
            return false;
        }
    }
    return true;
}

int main() {
    function<bool(int)> P = [](int x) { return x > 1; };
    function<bool(int)> Q = [](int x) { return x % 2 == 0; };
    vector<int> domain = {1, 2, 3};

    cout << (checkFormula(P, Q, domain) ? "True" : "False") << endl;

    return 0;
}
