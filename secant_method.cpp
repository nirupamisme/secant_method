// Author: Nirupam Pal
// Date: 04/08/2023
// Description: This program is used for claculating the root using secant method

#include <iostream>
#include <math.h>
using namespace std;
#define ERROR 0.001

// float y(float x) {
//     return (sqrt(x) - 7);
// }

float y(float x) {
    return pow(x, 2) -1;
}

int main() {

    cout << "*-----------------------------------------*-----------------------------------------*" << endl;
    cout << "|                                 Author: Nirupam Pal                               |" << endl;
    cout << "|                                   Date: 06/08/2023                                |" << endl;
    cout << "|   Description: This program is used for calculating the root using secant method  |" << endl;
    cout << "*-----------------------------------------*---------------------------------------- *" << endl;

    float x0 = 0, x1 = 0, x2 = 0;
    cout << "The initial guesses should bound the root." << endl;
    cout << "Enter the first guess : ";
    cin >> x0;
    cout << "Enter the second guess : ";
    cin >> x1;

    if (y(x0) == 0) {
        cout << "\nThe root for the function is : " << x0 << endl;
        if (y(x1) == 0) {
            cout << "\nThe root for the function is : " << x1 << endl;
            return 0;
        }
        return 0;
    }
    if (y(x1) == 0) {
        cout << "\nThe root for the function is : " << x1 << endl;
        if (y(x0) == 0) {
            cout << "\nThe root for the function is : " << x0 << endl;
            return 0;    
        }
        return 0;
    }
    if (y(x0) == y(x1)) {
        cout << "The guesses are not valid" << endl;
        return 0;
    }
    if ((y(x0) < 0 && y(x1) < 0) || (y(x0) > 0 && y(x1) > 0)) {
        cout << "The guesses are not valid" << endl;
        return 0;
    }
    else {
        for (int i = 0; i >= 0; i++) {
            x2 = (x0 * y(x1) - x1 *  y(x0)) / (y(x1) - y(x0));
            cout << "Iteration - " << i+1 << ": " << x2 << endl;
            if (abs(y(x2)) <= ERROR) {
                cout << "\nThe solution has converged!" << endl;
                break;
            }
            else {
                if ((y(x0) > 0 && y(x2) > 0) || (y(x0) < 0 && y(x2) < 0)) {
                    x0 = x2;
                }
                else {
                    x1 = x2;
                }
            }
        }
    }
    cout << "\nThe root for the function is : " << x2 << endl;
    return 0;
}