//  Aim of the program: Write a program in C to convert the first ‘n’ decimal numbers of a disc file to 
// binary using recursion. Store the binary value in a separate disc file. 
// Note# Read the value of ‘n’, source file name and destination file name from command line arguments. 
// Display the decimal numbers and their equivalent binary numbers from the output file. 


#include <stdio.h>

// Function to convert decimal to binary using recursion
void decimalToBinary(int n, FILE *inputFile, FILE *outputFile) {
    if (n <= 0) {
        return;
    }

    int decimal;
    fscanf(inputFile, "%d", &decimal);

    // Convert decimal to binary
    int binary[32]; // Assuming 32-bit integers
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    // Write the binary value to the output file
    for (int j = i - 1; j >= 0; j--) {
        fprintf(outputFile, "%d", binary[j]);
    }
    fprintf(outputFile, "\n");

    // Recursively convert the next decimal number
    decimalToBinary(n - 1, inputFile, outputFile);
}

int main() {
    int n;
    printf("Enter the value of 'n': ");
    scanf("%d", &n);

    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files!");
        return 1;
    }

    decimalToBinary(n, inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("Conversion complete! Check 'output.txt' for the binary values.\n");
    return 0;
}




// #include <stdio.h>

// // Function to find the GCD of two numbers using recursion
// int gcd(int a, int b) {
//     if (b == 0)
//         return a;
//     return gcd(b, a % b);
// }

// int main() {
//     FILE *inputFile, *outputFile;
//     int num1, num2, result;

//     // Open input and output files
//     inputFile = fopen("input1.txt", "r");
//     if (inputFile == NULL) {
//         printf("Error opening the input file.\n");
//         return 1;
//     }

//     outputFile = fopen("output1.txt", "w");
//     if (outputFile == NULL) {
//         printf("Error opening the output file.\n");
//         return 1;
//     }

//     // Read pairs of numbers from the input file and calculate GCD
//     int pairs_count = 0;
//     while (fscanf(inputFile, "%d %d", &num1, &num2) == 2) {
//         result = gcd(num1, num2);
//         fprintf(outputFile, "%d %d %d\n", num1, num2, result);
//         pairs_count++;

//         // Stop after handling at least 20 pairs
//         if (pairs_count >= 11)
//             break;
//     }

//     // Close files
//     fclose(inputFile);
//     fclose(outputFile);

//     printf("GCDs calculated and written to output.txt.\n");

//     return 0;
// }