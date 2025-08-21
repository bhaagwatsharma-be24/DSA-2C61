#include<iostream>
#include<string>
#include<array>
using namespace std;

// int arr[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
// int main(){
//     int n;
//     cout << "enter number to search(1 to 15)"<<endl;
//     cin >> n;
//     for(int i=0;i<15;i++){
//         if (arr[i]==n){
//             cout << "element found at " << i+1 <<"th position"<<endl;
//         }
//     }
//     int low=0;
//     int high=14;
    
//     while(low<high){
//         int mid=low+(high-low)/2;
//         if(arr[mid]==n){
//             cout << "element found at " << mid+1 <<"th position";
//             return 1;
//         }
//         else if(arr[mid]>n){
//             high=mid;
//         }
//         else if(arr[mid]<n){
//             low=mid;
//         }
//     }
//     return 0;

// }

// int arr[7]={90,34,25,12,22,11,64};
// int main(){
//     for(int i=0;i<6;i++){
//         for(int j=0;j<7-i-1;j++){
//             if (arr[j]>arr[j+1]){
//                 int temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//             }
//         }
//     }
//     for(int i=0;i<7;i++){
//         cout << arr[i] << " ";
//     }
// }
// int arr[10]={1,2,4,5,6,7,8,9,10};
// int high=8;
// int low=0;
// int main(){
// for(int i=0;i<7;i++){                                           
//     if((i+1)!=arr[i]){
//         cout << i+1 <<" is missing"<<endl;
//         return 1;                                     
//     }
// }
//     int x;
//     while (low<high){
//         int mid=low+(high-low)/2;
        // if(high==low+2){
//     cout << mid+1;
//     return 1;
// }
// else if(high==low+1){
//     cout << mid+2;
//     return 1;
// }
//         if(mid+1==arr[mid]){
//             low=mid;
//         }
//         else if(mid+1<arr[mid]){
//             high=mid-1;
//         }
//         x=mid;


//     }
//     cout << x+1;
// }
string x="hello";
string y="bye";
string vowels="aeiouAEIOU";

// string toLowercase(string s) {
//     for (int i = 0; i < s.length(); i++) {
//         if (s[i] >= 'A' && s[i] <= 'Z') {
//             s[i] = s[i] - 'A' + 'a';
//         }
//     }
//     return s;
// }
int main(){
    // x=x+" "+y;
    // cout << x << endl;
    // cout << y << endl;
    // int n=x.length();
    // for(int i=0;i<n/2;i++){
    //     swap(x[i],x[n-i-1]);
    // }
    // cout << x<<endl;
    // string arr[] = {"football","cricket","Cricket","FOOTBALL"};;
    // int n = sizeof(arr) / sizeof(arr[0]);

    
    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = 0; j < n - i - 1; j++) {
    //         if (toLowercase(arr[j]) > toLowercase(arr[j + 1])) {
    //             string temp = arr[j];
    //             arr[j] = arr[j + 1];
    //             arr[j + 1] = temp;
    //         }
    //     }
    // }

    // cout << "Sorted strings (case-insensitive):\n";
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << endl;
    // }
    // for(int i=0;i<x.length();i++){
    //     for(int j=0;j<vowels.length();j++){
    //         if(x[i]==vowels[j]){
    //             x.erase(i,1);
    //         }
    //     }
    // }
    // cout << x;
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

        // Check if arr[i] appeared before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        // If not duplicate, increase count
        if (!isDuplicate) {
            distinctCount++;
        }
    }

    cout << "Number of distinct elements: " << distinctCount << endl;
    return 0;

}


