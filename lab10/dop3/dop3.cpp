#include <iostream>
#include <vector>
using namespace std;

// Function to generate permutations
void generatePermutations(int n, int index, vector<int>& currentPermutation, vector<vector<int>>& allPermutations) {
    if (index == n) {
        // If the end of the permutation is reached, add the current permutation to the list of all permutations
        allPermutations.push_back(currentPermutation);
        return;
    }

    for (int i = 1; i <= n; i++) {
        // Check if number i has already been used in the current permutation
        if (find(currentPermutation.begin(), currentPermutation.end(), i) == currentPermutation.end()) {
            currentPermutation[index] = i; // Add number i to the current position
            generatePermutations(n, index + 1, currentPermutation, allPermutations); // Generate permutations for the remaining numbers
        }
    }
}

int main() {
    int n = 5; // Number of numbers
    vector<vector<int>> allPermutations;
    vector<int> currentPermutation(n);

    generatePermutations(n, 0, currentPermutation, allPermutations);

    // Print all permutations
    for (const auto& permutation : allPermutations) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
