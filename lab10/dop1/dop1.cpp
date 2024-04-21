#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void generateNumbers(int A, vector<int>& currentNumber, int currentLength, ofstream& file) {
    if (currentLength == A) {
        for (int digit : currentNumber) {
            file << digit;
        }
        file << endl;
        return;
    }

    for (int i = 0; i <= A; ++i) {
        currentNumber.push_back(i);
        generateNumbers(A, currentNumber, currentLength + 1, file);
        currentNumber.pop_back(); // Remove the last digit for the next call
    }
}

int main() {
    int A;
    cout << "Enter the number A: ";
    cin >> A;

    ofstream file("numbers.txt");
    if (!file) {
        cerr << "Failed to open the file for writing." << endl;
        return 1;
    }

    vector<int> currentNumber;
    generateNumbers(A, currentNumber, 0, file);

    file.close();
    cout << "Numbers successfully written to the file numbers.txt." << endl;

    return 0;
}
