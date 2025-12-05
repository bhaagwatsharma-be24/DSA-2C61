#include<iostream>
using namespace std;
#include <climits>

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

static int f=1;
static bool x=true;
class binarysearchtree{
    private:

        node *successorhelper(int n,node *root){
            node* found=searchnorecur(n,root);
                if(found->right){
                    node *succ= minimumelement(found->right);
                    return succ;
                }
                else{
                    node *succ=nullptr;
                    while (true){
                        if (found->data<root->data){
                            succ=root;
                            root=root->left;
                        }
                        else if(found->data>root->data){
                            root=root->right;
                        }
                        else{
                            break;
                        }
                    }
                    return succ;
                }
        }
        node *predecessorhelper(int n,node *root){
            node* found=searchnorecur(n,root);
                if(found->left){
                    node *succ= maximumelement(found->left);
                    return succ;
                }
                else{
                    node *succ=nullptr;
                    while (true){
                        if (found->data<root->data){
                            root=root->left;
                        }
                        else if(found->data>root->data){
                            succ=root;
                            root=root->right;
                        }
                        else{
                            break;
                        }
                    }
                    return succ;
                }
        }

    node *searchnorecur(int n,node *x){
        while(x!=nullptr && x->data!=n){
            if(n<x->data){
                x=x->left;
            }
            else{
                x=x->right;
            }
        }
        if(x){
            return x;
        }
        return nullptr;
    
    }
    node *searchrecur(int n,node *x){
        if(x==nullptr || x->data==n){
            return x;
        }
        if(n<x->data){
            node *result=searchrecur(n,x->left);
            return result;
        }
        else{
            node *result=searchrecur(n,x->right);
            return result;
        }
    }

    void preorder(node *root){
    if(root==nullptr){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    }

    void inorder(node *root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    }

    node *maximumelement(node *root){
        while(root->right){
            root=root->right;
        }
        return root;
    }

    node *minimumelement(node *root){
        while(root->left){
            root=root->left;
        }
        return root;
    }

    void postorder(node *root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    
    }

    node* inserthelper(int n,node* x){
    if(x==nullptr){
        node *newnode= new node(n);
        return newnode;
    }
    if(n<x->data){
        x->left=inserthelper(n,x->left);
    }
    else if(n>x->data){
        x->right=inserthelper(n,x->right);
    }
    return x;

    }

    node *deletenode(int n,node* root){
        if(root){
            if(n<root->data){
                root->left=deletenode(n,root->left);
                
            }
            else if(n>root->data){
                root->right=deletenode(n,root->right);
                
            }
            else{
                if (root->left == nullptr && root->right == nullptr) {
                    delete root;
                    return nullptr;
                } 
                else if (root->left == nullptr) {
                    node* temp = root->right;
                    delete root;
                    return temp;
                } 
                else if (root->right == nullptr) {
                    node* temp = root->left;
                    delete root;
                    return temp;
                } 
                else {
                    node* replace = minimumelement(root->right);
                    root->data = replace->data;
                    root->right = deletenode(replace->data, root->right);
                }
            
            }
            return root;
        }
        else{
            f=0;
            return nullptr;
        }
    }
    int maxdepth(node *root){
        if(root==nullptr){
            return 0;
        }
        int left=maxdepth(root->left);
        int right=maxdepth(root->right);
        return 1+ (left>right ? left :right);
    }
    int mindepth(node *root){
        if(root==nullptr){
            return 0;
        }
        int left=mindepth(root->left);
        int right=mindepth(root->right);
        return 1+ (left<right ? left :right);
    }

    bool isBSTUtil(node* root, int minVal, int maxVal) {
        if (root == nullptr)
            return true;
        
        if (root->data <= minVal || root->data >= maxVal)
            return false;

        return isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal);
    }
    bool isBST(node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
    }
    node *root;

    public:

    void delnode(int n){
        node *x=deletenode(n,root);
        if(f){
            cout << "successfully deleted"<<endl;
            preorder(root);
        }
        else{
            cout << "not found" << endl;
        }
    }
    void successor(int n){
        node *ans=successorhelper(n,root);
        if(ans){
        cout << ans->data << " is the successor!"<<endl;}
        else{
            cout << "no successor"<<endl;
        }
    }

    void predecessor(int n){
        node *ans=predecessorhelper(n,root);
        if(ans){
        cout << ans->data << " is the predecessor!"<<endl;}
        else{
            cout << "no predecessor"<<endl;
        }
    }

    binarysearchtree(){
        root=nullptr;
    }
    void insert(int n){
        root=inserthelper(n,root);
    }
    void displaypre(){
        preorder(root);
    }
    void displayin(){
        inorder(root);
    }
    void displaypost(){
        postorder(root);
    }
    void searchitem(int val){
        node *item=searchrecur(val,root);
        if(item){
            cout << "item found" << endl;
        }
        else{
            cout << "not found" << endl;
        }
    }
    void searchitemnr(int val){
        node *item=searchnorecur(val,root);
        if(item){
            cout << "item found" << endl;
        }
        else{
            cout << "not found" << endl;
        }
    }
    void maxelement(){
        node *x=maximumelement(root);
        cout << x->data << " is maximum"<< endl;
    }
    void minelement(){
        node *x=minimumelement(root);
        cout << x->data << " is minimum"<< endl;
    }
    void findmaxdepth(){
        int x=maxdepth(root);
        cout << x << " is max depth"<< endl;
    }
    void findmindepth(){
        int x=mindepth(root);
        cout << x << " is min depth"<< endl;
    }
    bool isBinarysearchtree() {
    return isBSTUtil(root, INT_MIN, INT_MAX);
    }

};
//Q1
// int main(){
//     binarysearchtree b1;
//     b1.insert(70);
//     b1.insert(90);
//     b1.insert(85);
//     b1.insert(100);
//     b1.insert(30);
//     b1.insert(60);
//     b1.insert(10);
//     b1.displaypre();
//     cout << endl;
//     b1.displayin();
//     cout << endl;
//     b1.displaypost();
//     cout << endl;
// }
// Q2
// int main(){
//     binarysearchtree b1;
//     b1.insert(70);
//     b1.insert(90);
//     b1.insert(85);
//     b1.insert(100);
//     b1.insert(30);
//     b1.insert(60);
//     b1.insert(10);
//     b1.displaypre();
//     cout << endl;
//     // b1.searchitem(70);
//     // b1.searchitemnr(100);
//     // b1.maxelement();
//     // b1.minelement();
//     b1.successor(100);
//     b1.predecessor(10);
// }
//Q3
// int main(){
//     binarysearchtree b1;
//     b1.insert(100);
//     b1.insert(10);
//     b1.insert(110);
//     b1.insert(105);
//     b1.insert(140);
//     b1.insert(125);
//     b1.insert(135);
//     b1.insert(120);
//     b1.displaypre();
//     cout << endl;
//     b1.delnode(190);
//     b1.findmaxdepth();
//     b1.findmindepth();
// }
//Q4
// int main(){
//     binarysearchtree b1;
//     b1.insert(100);
//     b1.insert(200);
//     b1.insert(150);
//     b1.insert(50);
//     b1.insert(250);
//     b1.insert(170);
//     b1.insert(10);
//     b1.insert(90);
//     if(b1.isBinarysearchtree()){
//         cout << "yes"<<endl;
//     }
//     else{
//         cout << "no"<<endl;
//     }

// }
//Q5 and Q6

class Heap {
private:
    int *arr;
    int size;
    int capacity;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    
    void maxHeapify(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && arr[l] > arr[largest]) largest = l;
        if (r < size && arr[r] > arr[largest]) largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
        }
    }

    void minHeapify(int i) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && arr[l] < arr[smallest]) smallest = l;
        if (r < size && arr[r] < arr[smallest]) smallest = r;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

public:
    Heap(int cap = 100) {
        arr = new int[cap];
        size = 0;
        capacity = cap;
    }

    void insert(int val) {
        if (size == capacity) {
            cout << "Heap full!\n";
            return;
        }
        arr[size] = val;
        size++;

        int i = size - 1;
        while (i > 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int extractMax() {
        if (size <= 0) return -1;
        if (size == 1) return arr[--size];

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;

        maxHeapify(0);
        return root;
    }

    void buildMaxHeap() {
        for (int i = size / 2 - 1; i >= 0; i--)
            maxHeapify(i);
    }

    void buildMinHeap() {
        for (int i = size / 2 - 1; i >= 0; i--)
            minHeapify(i);
    }

    void heapSortDecreasing() {
        int originalSize = size;

        buildMaxHeap();   
        cout << "Sorted Decreasing: ";

        for (int i = size - 1; i >= 0; i--) {
            cout << arr[0] << " ";  
            swap(arr[0], arr[size - 1]);
            size--;
            maxHeapify(0);
        }
        cout << endl;

        size = originalSize;
        buildMaxHeap(); 
    }

    void heapSortIncreasing() {
        int originalSize = size;

        buildMinHeap();  

        cout << "Sorted Inreasing: ";

        for (int i = size - 1; i >= 0; i--) {
            cout << arr[0] << " "; 
            swap(arr[0], arr[size - 1]);
            size--;
            minHeapify(0);
        }
        cout << endl;

        size = originalSize;
        buildMinHeap(); 
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {

    Heap pq;

    pq.insert(40);
    pq.insert(10);
    pq.insert(30);
    pq.insert(80);
    pq.insert(50);

    cout << "Heap: ";
    pq.printHeap();

    cout << "Extracted from PQ: " << pq.extractMax() << endl;

    Heap sorter;
    sorter.insert(40);
    sorter.insert(10);
    sorter.insert(30);
    sorter.insert(80);
    sorter.insert(50);

    sorter.heapSortIncreasing();  
    sorter.heapSortDecreasing();  

    return 0;
}
