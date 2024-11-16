#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

template <typename T>
void Log(const T& message) {
    cout << message << endl;
}

double getValidatedNumber(const string& prompt) {
    double number;
    while (true) {
        Log(prompt);
        cin >> number;
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            Log("Invalid input. Please enter a valid number.");
        } else {
            return number;
        }
    }
}

int getOperation(const vector<char>& operations) {
    int operation = -1;
    while (operation < 0 || operation >= static_cast<int>(operations.size())) {
        Log("Pick the operation: ");
        for (size_t i = 0; i < operations.size(); ++i) {
            cout << i << ". " << operations[i] << endl;
        }
        cin >> operation;
        if (operation < 0 || operation >= static_cast<int>(operations.size())) {
            Log("Incorrect value! Please try again.");
        }
    }
    return operation;
}

int main() {
    Log("### Welcome to my calculator ###");
    vector<char> operations = {'+', '-', '*', '/'};
    bool quit = false;

    do {
        double a = getValidatedNumber("Enter the first number:");
        double b = getValidatedNumber("Enter the second number:");

        int operation = getOperation(operations);
        double result;

        switch (operations[operation]) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/':
                if (b == 0.0) {
                    Log("Division by zero is not supported!");
                    continue;
                }
                result = a / b;
                break;
        }

        Log("The result is: ");
        Log(result);

        Log("Do you want to start a new round? [y/N]");
        char q;
        cin >> q;

        quit = (q != 'y' && q != 'Y');
    } while (!quit);

    Log("Bye!");
    return 0;
}
