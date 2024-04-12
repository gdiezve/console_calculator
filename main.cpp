#include <iostream>

using namespace std;

string op;
int x,y;
string allowedOperations[] = {"+","-", "*", "/"};

void checkValidOperation() {
    string *checkOperation = find(begin(allowedOperations), end(allowedOperations), op);
    if (checkOperation == end(allowedOperations)) {
        throw invalid_argument("Operation no allowed. Allowed operations are: +,-,*,/");
    }
}

void getInput() {
    cout << "Which arithmetic operation you want to perform? (Write +, -, * or / and press enter)" << endl;
    cin >> op;
    checkValidOperation();

    cout << "Enter the first number" << endl;
    cin >> x;
    cout << "Enter the second number" << endl;
    cin >> y;
}

int calculate() {
    int result;
    if (op == "+") {
        result =  x + y;
    } else if (op == "-") {
        result = x - y;
    } else if (op == "*") {
        result = x * y;
    } else if (op == "/") {
        result = x / y;
    }

    return result;
}

int main() {
    try
    {
        getInput();
        int result = calculate();
        cout << "Result is: " << result << endl;
    }

    catch (std::invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }
}