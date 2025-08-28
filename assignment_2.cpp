#include<iostream>
#include<string>
#include<array>
using namespace std;

int arr[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int main(){
    int n;
    cout << "enter number to search(1 to 15)"<<endl;
    cin >> n;
    for(int i=0;i<15;i++){
        if (arr[i]==n){
            cout << "element found at " << i+1 <<"th position"<<endl;
        }
    }
    int low=0;
    int high=14;

    while(low<high){
        int mid=low+(high-low)/2;
        if(arr[mid]==n){
            cout << "element found at " << mid+1 <<"th position";
            return 1;
        }
        else if(arr[mid]>n){
            high=mid;
        }
        else if(arr[mid]<n){
            low=mid;
        }
    }
    return 0;

}

int arr[7]={90,34,25,12,22,11,64};
int main(){
    for(int i=0;i<6;i++){
        for(int j=0;j<7-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<7;i++){
        cout << arr[i] << " ";
    }
}
int arr[10]={1,2,4,5,6,7,8,9,10};
int high=8;
int low=0;
int main(){
for(int i=0;i<7;i++){
    if((i+1)!=arr[i]){
        cout << i+1 <<" is missing"<<endl;
        return 1;
    }
}
    int x;
    while (low<high){
        int mid=low+(high-low)/2;
        if(high==low+2){
    cout << mid+1;
    return 1;
}
else if(high==low+1){
    cout << mid+2;
    return 1;
}
        if(mid+1==arr[mid]){
            low=mid;
        }
        else if(mid+1<arr[mid]){
            high=mid-1;
        }
        x=mid;

    }
    cout << x+1;
}
string x="hello";
string y="bye";
string vowels="aeiouAEIOU";

string toLowercase(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}
int main(){
    x=x+" "+y;
    cout << x << endl;
    cout << y << endl;
    int n=x.length();
    for(int i=0;i<n/2;i++){
        swap(x[i],x[n-i-1]);
    }
    cout << x<<endl;
    string arr[] = {"football","cricket","Cricket","FOOTBALL"};;
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (toLowercase(arr[j]) > toLowercase(arr[j + 1])) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted strings (case-insensitive):\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    for(int i=0;i<x.length();i++){
        for(int j=0;j<vowels.length();j++){
            if(x[i]==vowels[j]){
                x.erase(i,1);
            }
        }
    }
    cout << x;
int main()
{
    int n;
    cout << "enter size of matrix"<<endl;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout << "enter " << i <<"th number(row number):  "<<endl;
        cin >>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout << arr[i] << " ";
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    int n;
    cout << "enter size of array:  " << endl;
    cin >>n;
    int arr[3*n-2];
    for(int i=1;i<=(3*n-2);i++){
        arr[i-1]=i;
    }
    int k=0;
    int tri[4][4]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i-j==0 || i-j==1 || i-j==-1){
                cout << arr[k] << " ";
                k++;
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    int n;
    cout << "enter size of array:  " << endl;
    cin >> n;
    int arr[n*(n+1)/2];
    int k=0;
    for(int i=1;i<=(n*(n+1)/2);i++){
        arr[i-1]=i;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i>=j){
                cout << arr[k] << " ";
                k++;
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    int n;
    cout << "enter size of array:  " << endl;
    cin >> n;
    int arr[n*(n+1)/2];
    int k=0;
    for(int i=1;i<=(n*(n+1)/2);i++){
        arr[i-1]=i;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i<=j){
                cout << arr[k] << " ";
                k++;
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    int n;
    cout << "enter size of array:  " << endl;
    cin >> n;
    int arr[n*(n+1)/2];
    int k=0;
    for(int i=1;i<=(n*(n+1)/2);i++){
        arr[i-1]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i >= j){
                int index = (i*(i+1))/2 + j;
                cout << arr[index] << " ";
            } else {
                int index = (j*(j+1))/2 + i;
                cout << arr[index] << " ";
            }
        }
        cout << endl;
    }

    int arr1[7][3]={
        {4,4,6},
        {0,0,13},
        {0,3,17},
        {1,2,78},
        {2,1,90},
        {3,0,10},
        {3,1,190}
    };
    int arr2[9][3]={
        {4,4,8},
        {0,2,13},
        {1,1,17},
        {1,2,20},
        {1,3,88},
        {2,1,70},
        {3,0,110},
        {3,2,200}

    };
    int trans[4][4]={0};
    int trans1[4][4]={0};
    for(int i=1;i<7;i++){
        int row=arr1[i][0];
        int col=arr1[i][1];
        int val=arr1[i][2];
        trans[col][row]=val;
    }
    for(int i=1;i<9;i++){
        int row=arr2[i][0];
        int col=arr2[i][1];
        int val=arr2[i][2];
        trans1[col][row]=val;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << trans[i][j]<<" ";
        }
        cout << endl;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << trans1[i][j]<<" ";
        }
        cout << endl;
    }
    int add[4][4]={0};
    for(int i=1;i<7;i++){
        int row1=arr1[i][0];
        int row2=arr2[i][0];
        int col1=arr1[i][1];
        int col2=arr2[i][1];
        int val1=arr1[i][2];
        int val2=arr2[i][2];
        add[row1][col1]+=val1;
        add[row2][col2]+=val2;
    }

    for(int i=7;i<9;i++){
        int row=arr2[i][0];
        int col=arr2[i][1];
        int val=arr2[i][2];
        add[row][col]+=val;
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << add[i][j]<<" ";
        }
        cout << endl;
    }
    int multiply[4][4]={0};
    for(int i=1;i<7;i++){
        int row=arr1[i][0];
        int col=arr1[i][1];
        int value=arr1[i][2];
        for(int j=1;j<9;j++){
            if (arr2[j][0]==col){
                int col1=arr2[j][1];
                int val=arr2[j][2];
                multiply[row][col1]+=value*val;
            }
        }
        }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << multiply[i][j]<<" ";
        }
        cout << endl;
    }

    int x[10]={1,2,13,4,5,6,217,8,9,10};
    int count=0;
    for(int i=0;i<9;i++){
        for(int j=i+1;j<10;j++){
            if(x[i]>x[j]){
                count++;
            }
        }
    }
    cout << count;
    }
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
