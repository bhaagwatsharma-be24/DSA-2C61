#include<iostream>
using namespace std;
void bubbleSort(int *array, int size){
   for(int i = 0; i<size; i++) {
      int swaps = 0; 
      for(int j = 0; j<size-i-1; j++) {
         if(array[j] > array[j+1]) { 
            int temp;
            temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            swaps = 1; 
         }
      }
      if(!swaps)
         break; 
   }
}
int main(){
   int n;
   n = 5;
   int arr[5] = {67, 44, 82, 17, 20}; 
   cout << "Array before Sorting: ";
   for(int i = 0; i<n; i++)
      cout << arr[i] << " ";
   cout << endl;
   bubbleSort(arr, n);
   cout << "Array after Sorting: ";
   for(int i = 0; i<n; i++)
      cout << arr[i] << " ";
   cout << endl;
}