#include <iostream.>
#include <fstream>
using namespace std;

int decimalToBinary(int decimalNum, ofstream &outFile) {
    if (decimalNum > 0) {
        decimalToBinary(decimalNum / 2, outFile);
        outFile << decimalNum % 2;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <n> <input_file> <output_file>\n";
        return 1;
    }

    int n = atoi(argv[1]);
    ifstream inFile(argv[2]);
    ofstream outFile(argv[3]);

    if (!inFile || !outFile) {
        cout << "Error opening files.\n";
        return 1;
    }

    int decimalNum;
    for (int i = 0; i < n && inFile >> decimalNum; i++)
    {
        outFile << "The binary equivalent of " << decimalNum << " is ";
        decimalToBinary(decimalNum, outFile);
        outFile << endl;
    
    }

    inFile.close();
    outFile.close();
    return 0;
}