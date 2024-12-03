#include <iostream>
#include <fstream>
#include <vector>
#include <cmath> 
using namespace std;

void bubbleSort(vector<int>& vec) {
    size_t n = vec.size();
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}
int main() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "error opening the file" << endl;
        return 1;
    }

    vector<int> left, right;
    int leftNum, rightNum, sum;


    while (file >> leftNum >> rightNum) {
        left.push_back(leftNum);
        right.push_back(rightNum);
    }

    file.close(); 

    bubbleSort(left);
    bubbleSort(right);

    for (size_t i = 0; i < left.size(); i = i+1) {
        int diferencia = abs(left[i] - right[i]);
        sum = sum + diferencia;
    }

    cout << "The sum is: " << sum << endl;

    return 0;
}
