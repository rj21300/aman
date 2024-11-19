// // 3.1 Aim of the program: Write a program to implement Binary Search to give the position of 
// // leftmost appearance of the element in the array being searched. Display the number of comparisons 
// // made while searching. 

// // Input:
// // Enter size of array: 10
// // Enter elements of the array: 2 3 7 7 7 11 12 12 20 50 
// // Enter the key to be searched: 7
// // Output:
// // 7 found at index position 2 
// // Number of comparisons: 3

// #include <iostream>
// using namespace std;

// int BinarySearch(int arr[], int size, int key, int &comparisons) {
//     int left = 0;
//     int right = size - 1;
//     int result = -1;

//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         // int mid = size / 2;

//         if (arr[mid] == key) {
//             result = mid;
//             right = mid - 1;  
//         } else if (arr[mid] < key) {
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//         comparisons++;
//     }

//     return result;
// }

// int main() {
//     int size, key;
//     cout << "Enter size of array: ";
//     cin >> size;

//     int arr[size];
//     cout << "Enter elements of the array: ";
//     for (int i = 0; i < size; i++) {
//         cin >> arr[i];
//     }

//     cout << "Enter the key to be searched: ";
//     cin >> key;

//     int comparisons = 0;
//     int position = BinarySearch(arr, size, key, comparisons);

//     if (position != -1) {
//         cout << key << " found at number at position " << position << endl;
//     } else {
//         cout << key << " not found in the array" << endl;
//     }

//     cout << "Number of comparisons: " << comparisons << endl;

//     return 0;
// }



// /*Write a menu driven program to sort a list of elements in ascending order using Insertion Sort technique. The nature of the input data is choice based and a distinct file is considered for each choice. The sorted elements can be stored in a separate output file. After sorting display the content of the output file along with number of comparisons. Based on the number of comparisons, conclude the input scenario is either best or worst case. 

// Note# 
// ●Number of elements in each input file should vary from 300 to 500 entries. 
// ●For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40 ….., Store the result in “outInsAsce.dat”.
// ●For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60…., Store the result in “outInsDesc.dat”.
// ●For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …, Store the result in “outInsRand.dat”
// Sample Input from file:
// MAIN MENU (INSERTION SORT)
// 1. Ascending Data
// 2. Descending Data
// 3. Random Data
// 4. ERROR (EXIT)

// Output:
// Enter option: 1
// Before Sorting: Content of the input file
// After Sorting: Content of the output file
// Number of Comparisons: Actual*/

#include <iostream>
#include <fstream>
#include <vector>

// Function to perform insertion sort and return the number of comparisons
int insertionSort(std::vector<int>& arr) {
    int comparisons = 0;
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

// Function to read input data from a file
std::vector<int> readInputFile(const std::string& filename) {
    std::vector<int> data;
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        int value;
        while (inputFile >> value) {
            data.push_back(value);
        }
        inputFile.close();
    }
    return data;
}

// Function to write output data to a file
void writeOutputFile(const std::string& filename, const std::vector<int>& data) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (int value : data) {
            outputFile << value << " ";
        }
        outputFile.close();
    }
}

int main() {
    while (true) {
        std::cout << "MAIN MENU (INSERTION SORT)" << std::endl;
        std::cout << "1. Ascending Data" << std::endl;
        std::cout << "2. Descending Data" << std::endl;
        std::cout << "3. Random Data" << std::endl;
        std::cout << "4. ERROR (EXIT)" << std::endl;

        int choice;
        std::cout << "Enter option: ";
        std::cin >> choice;

        if (choice == 4) {
            std::cout << "Exiting the program." << std::endl;
            break;
        }

        std::string inputFilename, outputFilename;
        if (choice == 1) {
            inputFilename = "input.txt";
            outputFilename = "out1.csv";
        } else if (choice == 2) {
            inputFilename = "input.txt";
            outputFilename = "out2.csv";
        } else if (choice == 3) {
            inputFilename = "input.txt";
            outputFilename = "out3.csv";
        } else {
            std::cout << "Invalid option. Please try again." << std::endl;
            continue;
        }

        std::vector<int> inputData = readInputFile(inputFilename);
        if (inputData.empty()) {
            std::cout << "Error: Input file not found or empty." << std::endl;
            continue;
        }

        std::cout << "Before Sorting: ";
        for (int value : inputData) {
            std::cout << value << " ";
        }
        std::cout << std::endl;

        int comparisons = insertionSort(inputData);
        std::cout << "After Sorting: ";
        for (int value : inputData) {
            std::cout << value << " ";
        }
        std::cout << std::endl;

        std::cout << "Number of Comparisons: " << comparisons << std::endl;

        // Determine if the input scenario is best or worst case based on the number of comparisons
        if (comparisons == 0) {
            std::cout << "Input scenario is the best case." << std::endl;
        } else if (comparisons >= (inputData.size() * (inputData.size() - 1)) / 2) {
            std::cout << "Input scenario is the worst case." << std::endl;
        } else {
            std::cout << "Input scenario is average." << std::endl;
        }

        writeOutputFile(outputFilename, inputData);
    }

    return 0;
}