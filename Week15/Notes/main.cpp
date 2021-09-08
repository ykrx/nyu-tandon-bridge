#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void openFile(ifstream& inFile) {
    string fileName;
    cout << "What filename? ";
    cin >> fileName;

    inFile.open(fileName);

    while (!inFile) {
        cout << "Error: Failed to open." << endl;
        cout << "What filename? ";
        cin >> fileName;

        inFile.clear();
        inFile.open(fileName);
    }
}

int main() {
    ifstream inFile;
    openFile(inFile);

    vector<int> v;
    int temp;

    while (inFile >> temp) {
        v.push_back(temp);
    }

    double sum = 0;

    for (int i : v) {
        sum += i;
    }

    cout << "The average of all the numbers in the input file is ";
    cout << sum / v.size();

    return 0;
}