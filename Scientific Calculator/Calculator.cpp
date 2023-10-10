#include <iostream>
#include <cmath>
#include <limits> // Include the limits header for clearing input buffer

using namespace std;

int main() {
    char choice;
    
    do {
        double num1, num2, result;
        char operation;

        cout << "Scientific Calculator" << endl;
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter an operation (+, -, *, /, ^, sin, cos, tan, log for logarithm, e for exponential): ";
        cin >> operation;
        
        // Clear the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (operation) {
            case '+':
                cout << "Enter second number: ";
                cin >> num2;
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;
            case '-':
                cout << "Enter second number: ";
                cin >> num2;
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;
            case '*':
                cout << "Enter second number: ";
                cin >> num2;
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;
            case '/':
                cout << "Enter second number: ";
                cin >> num2;
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Division by zero is not allowed." << endl;
                }
                break;
            case '^':
                cout << "Enter second number (exponent): ";
                cin >> num2;
                result = pow(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 's':
                result = sqrt(num1);
                cout << "Result: " << result << endl;
                break;
            case 'c':
                result = cos(num1);
                cout << "Result: " << result << endl;
                break;
            case 't':
                result = tan(num1);
                cout << "Result: " << result << endl;
                break;
            case 'l':
                result = log(num1);
                cout << "Result: " << result << endl;
                break;
            case 'e':
                result = exp(num1);
                cout << "Result: " << result << endl;
                break;
            default:
                cout << "Invalid operation." << endl;
                break;
        }
        
        cout << "Do you want to continue (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
