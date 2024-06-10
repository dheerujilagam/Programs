#include <bits/stdc++.h>

using namespace std;

int main() {
    string exp;
    getline(cin, exp);
    istringstream iss(exp);
    string word;
    vector<string> exp_vec;
    
    while (iss >> word) {
        exp_vec.push_back(word);
    }

    unordered_map<string, char> operators = {{"add", '+'}, {"sub", '-'}, {"mul", '*'}, {"rem", '%'}, {"pow", '**'}};
    unordered_map<string, int> digits = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    
    int flag = 0;
    vector<string> updated;
    int cntOperands = 0, cntOperators = 0;
    
    for (const auto &word : exp_vec) {
        if (operators.find(word) != operators.end()) {
            updated.push_back(string(1, operators[word]));
            cntOperands++;
        } else {
            cntOperators++;
            string digit = "";
            int num = 0;
            for (char ch : word) {
                digit += ch;
                if (digits.find(digit) != digits.end()) {
                    num = num * 10 + digits[digit];
                    digit = "";
                } else if (digit == "c") {
                    digit = "";
                }
            }
            if (!digit.empty()) {
                flag = 1;
                break;
            } else {
                updated.push_back(to_string(num));
            }
        }
    }
    
    if (flag) {
        cout << "expression evaluation stopped invalid words present" << endl;
    } else if (cntOperands + 1 != cntOperators) {
        cout << "expression is not complete or invalid" << endl;
    } else {
        stack<int> st;
        for (auto it = updated.rbegin(); it != updated.rend(); ++it) {
            if (isdigit((*it)[0])) {
                st.push(stoi(*it));
            } else {
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                if (*it == "+") {
                    st.push(op1 + op2);
                } else if (*it == "-") {
                    st.push(op1 - op2);
                } else if (*it == "*") {
                    st.push(op1 * op2);
                } else if (*it == "%") {
                    st.push(op1 % op2);
                } else if (*it == "**") {
                    int result = 1;
                    for (int i = 0; i < op2; ++i) {
                        result *= op1;
                    }
                    st.push(result);
                }
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}
