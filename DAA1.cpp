// #include <iostream>
// #include <fstream>
// using namespace std;
// int arr[100];
// void readArrayFromFile(int arr[], int n)
// {
//     ifstream inFile;
//     inFile.open("INPUT.TXT");
//     for (int i = 0; i < n; ++i)
//     {
//         inFile >> arr[i];
//     }
//     inFile.close();
// }

// int secondSmall=0,secondLarge=0;
// int secondLargest(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; ++i)
//     {
//         for (int j = 0; j < n - i - 1; ++j)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 // Swap the elements
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
//     secondSmall=arr[1];
//     secondLarge=arr[n-2];
//     return arr[n - 2];
// }

//     int main()
//     {
//         int n;
//         cout << "Enter the size of the array: ";
//         cin >> n;
//         readArrayFromFile(arr, n);
//         secondLargest(arr, n);
//         cout << "Second Largest Element in the array is: " << secondLarge << endl;
//         cout << "Second Smallest Element in the array is: " << secondSmall << endl;
        
//         return 0;
//     }



#include <iostream>
using namespace std;

int prefixSumArr[100];
int prefixSum(int arr[], int n)
{
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        prefixSumArr[i] = prefixSum;
    }
    return prefixSum;
}

int main(){
    int arr[100]={3,4,5,1,2};
    int n=5;
    prefixSum(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<prefixSumArr[i]<<" ";
    }
    
    return 0;
}