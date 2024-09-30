#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string formula;
    vector<string> _operand;
    vector<char> _operator;
    string first, second;

    cin >> formula;
    for(char op: formula) {
        if(op == '(')
            _operator.push_back(op);
        else if(op == ')') {
            while(!_operator.empty() && _operator.back() != '(') {
                second = _operand.back();
                _operand.pop_back();
                first = _operand.back();
                _operand.pop_back();

                _operand.push_back(first + second + _operator.back());
                _operator.pop_back();
            }

            _operator.pop_back();
        }
        else if(op == '+' || op == '-') {
            while(!_operator.empty() && _operator.back() != '(') {
                second = _operand.back();
                _operand.pop_back();
                first = _operand.back();
                _operand.pop_back();

                _operand.push_back(first + second + _operator.back());
                _operator.pop_back();
            }

            _operator.push_back(op);
        }
        else if(op == '*' || op == '/') {
            if(_operator.empty() || _operator.back() == '(' || _operator.back() == '+' || _operator.back() == '-')
                _operator.push_back(op);
            else if(_operator.back() == '*' || _operator.back() == '/') {
                second = _operand.back();
                _operand.pop_back();
                first = _operand.back();
                _operand.pop_back();

                _operand.push_back(first + second + _operator.back());
                _operator.pop_back();

                _operator.push_back(op);
            }
        }
        else {
            string tmp(1, op);
            _operand.push_back(tmp);
        }
    }
    while(!_operator.empty() && _operator.back() != '(') {
        second = _operand.back();
        _operand.pop_back();
        first = _operand.back();
        _operand.pop_back();

        _operand.push_back(first + second + _operator.back());
        _operator.pop_back();
    }

    cout << _operand.back() << endl;
    return 0;
}