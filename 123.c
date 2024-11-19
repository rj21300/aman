#include <iostream>
using namespace std;

void swap(int arr[],int size)
{
   for(int i=0;i<size-1;i+=2){
      
       int temp=arr[i];
       arr[i]=arr[i+1];
       arr[i+1]=temp;
   }
    
}

int main()
{
   int size;
   cout<<"enter the no of element"<<endl;
   cin>>size;
   cout<<"element"<<endl;
   int arr[size];
   for(int i=0;i<size;i++){
    cin>>arr[i];
   }
   cout<<"the array is "<<endl;
   for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
   }
swap(arr, size);
   cout<<"after sorting"<<endl;
   for(int i=0;i<size;i++){
   cout<<arr[i]<<" ";
   }

   return 0;
}