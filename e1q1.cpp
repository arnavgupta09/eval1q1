#include <iostream>
#include <vector>
using namespace std;

vector<int> computeDerivative(vector<int>& coefficients) {
    vector<int> derivative;
    int degree = coefficients.size() - 1;

    for (int i = degree; i > 0; --i) {
        derivative.push_back(i * coefficients[i]);
    }

    return derivative;
}

void printPolynomial(vector<int>& coefficients) {
    int degree = coefficients.size() - 1;

    if (coefficients.empty()) {
        cout << "0" << endl;
        return;
    }

    for (int i = degree; i >= 0; --i) {
        if (coefficients[i] != 0) {
            if (i != degree && coefficients[i] > 0) {
                cout << "+";
            }
            if (i == 0 || coefficients[i] != 1) {
                cout << coefficients[i];
            }
            if (i > 0) {
                cout << "x";
                if (i > 1) {
                    cout << "^" << i;
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int degree;

    cout << "Enter the degree of the polynomial (0 to 5): ";
    cin >> degree;

    if (degree < 0 || degree > 5) {
        cerr << "Degree must be between 0 and 5." << endl;
        return 1;
    }

    vector<int> coefficients(degree + 1);

    cout << "Enter the coefficients from highest degree to lowest: " << endl;
    for (int i = degree; i >= 0; --i) {
        cout << "Coefficient of x^" << i << ": ";
        cin >> coefficients[i];
    }

    vector<int> derivative = computeDerivative(coefficients);

    cout << "The derivative of the polynomial is: ";
    printPolynomial(derivative);

    return 0;
}
