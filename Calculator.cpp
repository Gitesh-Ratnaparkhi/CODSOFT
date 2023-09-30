#include <iostream>
#include <cmath>
using namespace std;

// Function to take input of number.
double input(){
    double num1;
    cout << "Enter the number : ";
    cin >> num1;
    return num1;
}

// Function to take input of the oprater.
char operation(){
    char operater;
    cout << "Enter an operator (+, -, *, /, = to quit): ";
    cin >> operater;
    return operater;
}

// This is the main function that gives us final calculated result.
double calculator()
{
    double result = 0;
    bool firstInput = true;
    double num1 = input();
    while (true) // While loop which runs until user enters '='
    {
        double num2;
        char operater = operation();

        // From here we will check different different opraters and according to that oprater we will perform different oprations.
        if (operater == '=') break; // If you enter = Then the loop will break.
        if (firstInput){
            result = num1;
            firstInput = false;
        }
        if (operater == '+'){
            num2 = input();
            result += num2;
        }
        else if (operater == '-'){
            num2 = input();
            result -= num2;
        }
        else if (operater == '*'){
            num2 = input();
            result *= num2;
        }
        else if (operater == '/'){
            num2 = input();
            if(num2 == 0){
                cout << "Error! Division by zero is not allowed." << endl;
                return 1;
            }
            result /= num2;
        }
        cout << "Result so far: " << result << endl;
    }
    if (!firstInput) cout << "Final result: " << result << endl;
    else cout << "No calculations performed. Exiting." << endl;
    return result;
}

int main(){
    // calling calculator function in main function.
    calculator();
    return 0;
}