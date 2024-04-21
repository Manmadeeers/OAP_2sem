#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if the remaining countries can be divided into two groups
bool canDivide(vector<vector<int>>& adjMatrix, int groupSize, int currentGroup, int currentGroupSize) {
    if (currentGroupSize == groupSize) {
        // If the current group has reached the required size, check if the remaining countries can be divided
        for (int i = 0; i < adjMatrix.size(); i++) {
            if (i != currentGroup && any_of(adjMatrix[i].begin(), adjMatrix[i].end(), [&](int j) { return adjMatrix[currentGroup][j] == 1; })) {
                return false; // Found a pair of adjacent countries from opposite groups
            }
        }
        return true; // All countries have been successfully divided
    }

    for (int i = 0; i < adjMatrix.size(); i++) {
        if (i != currentGroup && adjMatrix[currentGroup][i] == 1) {
            // Check if country i can be added to the current group
            if (canDivide(adjMatrix, groupSize, i, currentGroupSize + 1)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n; // Number of countries
    cout << "Enter the number of countries: ";
    cin >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
    // Fill the adjacency matrix adjMatrix here

    // Check if the countries can be divided into two groups
    bool canBeDivided = canDivide(adjMatrix, n / 2, 0, 1);

    if (canBeDivided) {
        cout << "The countries can be divided into two groups with the minimum number of adjacent country pairs." << endl;
    }
    else {
        cout << "The countries cannot be divided into two groups with the minimum number of adjacent country pairs." << endl;
    }

    return 0;
}
