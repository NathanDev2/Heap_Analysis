
/* Purpose of this program is to Implement functions of a priority queue like structure using heap in an Binary Tree. It demonstrates the following...

    1) Insert and Deletion in a heap
    2) Display of the 100 smallest elements in a heap
    3) The time taken to use heap
    4) Performs Heap up and down functions
    5) Includes the following functions
        - computing the height
        - computing the # of leaves
        - looking up a value in a tree
*/


#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
using namespace std;

template<typename T>
struct Node{
    T data; // Data 
    Node* left; // Left child
    Node* right; // right child
};

template<typename T>
class MaxHeap {
public:
    MaxHeap(int size); // Constructor
    ~MaxHeap(); // Deconstructor
    void InitRandomTree(); // Make a random tree of x values
    void insert(T value); // Insert Value in the Tree
    void deleteMax(); // Delete Root
    void heapifyUp(int); // A general heapify function
    void heapifyDown(int); // A general heapify function
    void heapifyUpAtIndex(int index); // The required swim function
    void heapifyDownAtIndex(int index); // The required sink function
    void InOrderTraversal(); // Print the tree in asending order
    void inOrderTraversal(int root);
    int computeHeight(); // get height of the whole tree
    int computeLeaves(); // Compute the leaves of the whole tree
    bool lookupkey(T); // Look up a value in tree
    void HeapSort(); // Sort the Tree
    void display(); // Display current state of the tree
   
   private:
    Node<T>** heapArray; // Dereferenced pointer
    int size;
    int heapSize;

  // Made three functions to get parent node, left child and right child
    int getParent(int index) { return (index - 1) / 2; } 
    int getLeftChild(int index) { return (2 * index) + 1; }
    int getRightChild(int index) { return (2 * index) + 2; }

};

template<typename T>
MaxHeap<T>::MaxHeap(int size) {
        this->size = size; // Set size in the class
        heapArray = new Node<T>*[size]; // allocate memory for a node
        heapSize = 0;
    }


template<typename T>
MaxHeap<T>::~MaxHeap() {
        delete[] heapArray;
    }

template<typename T>
void MaxHeap<T>::InitRandomTree() {
    for (int i = 0; i < size; ++i) {
        T randomValue = static_cast<T>((1.0 * rand() / RAND_MAX) * size);
        insert(randomValue); // Insert the random value into the heap
    }
}

template<typename T>
void MaxHeap<T>::insert(T value) {
        if (heapSize == size) { // Check for if the tree is full first
            cout << "Heap overflow!" << endl;
            return;
        }

        Node<T>* newNode = new Node<T>; // Create a new Node
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;

        heapSize++; // Keep track of the heap size 
        int index = heapSize - 1;
        heapArray[index] = newNode; // Put newNode into the tree
        heapifyUp(index); // Heapify the tree as needed for the newNode
    }

template<typename T>
void MaxHeap<T>::deleteMax() {
        if (heapSize <= 0) { // Check if the tree is empty
            cout << "Heap underflow!" << endl;
            return;
        }

        delete heapArray[0];
        heapArray[0] = heapArray[heapSize - 1]; // Set the root to the last element and heapify down
        heapSize--;
        heapifyDown(0);
    }

template<typename T>
void MaxHeap<T>::heapifyUpAtIndex(int index) { // A function to call the swim function
        heapifyUp(index);
    }

template<typename T>
void MaxHeap<T>::heapifyDownAtIndex(int index) { // A function to call the sink function
        heapifyDown(index);
    }

template<typename T>
bool MaxHeap<T>::lookupkey(T key){
    Node<T>* current = new Node<T>; // Initialize a node to travel through the tree
    current->data = key;
    current->left = nullptr;
    current->right = nullptr;

for(int i = 0; i < heapSize; i++){
    if(current->data == heapArray[i]->data){ // If the data matches return true and break
        return true;
        break;
    }
}
return false;
}

template<typename T>
void MaxHeap<T>::display() {

     cout << fixed << setprecision(2); // Set the precision to 2 decimal places for float values
    
    if (heapSize >= 100) { // For when displaying the 100k values
        int Display100 = 100;
        for (int i = 0; i < Display100; ++i) {
            cout << heapArray[i]->data << "\t\t";
            if ((i + 1) % 10 == 0) {
                cout << endl;
            }
        }
    } else {
        for (int i = 0; i < heapSize; i++) { // For displaying the smaller trees less than 100
            cout << heapArray[i]->data;
            if (i != heapSize - 1) {
                cout << ", ";
            }
        }
    }
    cout << endl;
}

template<typename T>
  void MaxHeap<T>::heapifyUp(int index) { // Heapify up function
        int parent = getParent(index); 
        while (index > 0 && heapArray[index]->data > heapArray[parent]->data) {
            swap(heapArray[index], heapArray[parent]);
            index = parent;
            parent = getParent(index);
        }
    }

template<typename T>
    void MaxHeap<T>::heapifyDown(int index) { // Heapify down function
        int largest = index;
        int left = getLeftChild(index);
        int right = getRightChild(index);

        if (left < heapSize && heapArray[left]->data > heapArray[largest]->data) {
            largest = left;
        }

        if (right < heapSize && heapArray[right]->data > heapArray[largest]->data) {
            largest = right;
        }

        if (largest != index) {
            swap(heapArray[index], heapArray[largest]);
            heapifyDown(largest);
        }
    }

template<typename T>
void MaxHeap<T>::HeapSort() {
    if (heapSize == 0) { // Check if the heap is empty
        cout << "Heap is empty!" << endl;
        return;
    }
    int originalSize = heapSize;

    // Extract elements from the heap in descending order (sorting the heap)
    for (int i = heapSize - 1; i >= 0; --i) {
        swap(heapArray[0], heapArray[i]);
        heapSize--;
        heapifyDown(0);
    }

    heapSize = originalSize; // Reset heap size
}

template<typename T>
int MaxHeap<T>::computeHeight() {
    return floor(log2(heapSize)); // assuming heapSize contains the number of elements in the heap
}

template<typename T>
int MaxHeap<T>::computeLeaves(){
    return ((heapSize+1)/2); // This formula provides the amount of leaves in a binary tree
}



int main() {
    int size = 10;
    int root = 0;

    MaxHeap<int> maxHeap(size); // Create maxHeap to test 3 out of the 5 functions
    maxHeap.InitRandomTree();

    cout << "Max Heap: ";
    maxHeap.display(); 

    maxHeap.deleteMax();
    cout << "After deleting the maximum element: ";
    maxHeap.display(); 

    maxHeap.insert(50);
    cout << "Inserting 50 into the Max Heap: ";
    maxHeap.display();

    int height = maxHeap.computeHeight();
    cout << "Height of the tree: " << height << endl;

    int leaves = maxHeap.computeLeaves();
    cout << "Number of leaves: " << leaves << endl;

    int key = 1;
    bool found = maxHeap.lookupkey(1);
    cout << "Is " << key << " in the tree?" << endl;
    cout << (found ? "Found" : "Not Found") << endl; 




    cout << endl << endl;
 
    cout << "Press any key to continue..." << endl;
    cin.ignore();


    system("cls");
//-------------------------------------------------------------------------
clock_t startTime, endTime;

    size = 100000;
    MaxHeap<int> maxHeapINT(size);
    maxHeapINT.InitRandomTree();
    cout << "\t\t\t\t\t\tMax Heap Tree with INTEGERS" << endl;
    maxHeapINT.display();
    cout << "After Heap sort..." << endl << endl;
    // Print first 100 smallest elements in Tree
    cout << "\t\t\t\t\t100 smallest elements in the tree" << endl;
    startTime = clock();
    maxHeapINT.HeapSort();
    endTime = clock();
    maxHeapINT.display();
cout << "Time Takened: " << fixed << setprecision(2) << static_cast<double>(endTime-startTime)*1000/CLOCKS_PER_SEC<< "ms" << endl;


cout << endl << endl;

    MaxHeap<long int> maxHeapLONGINT(size);
    maxHeapLONGINT.InitRandomTree();
    cout << "\t\t\t\t\t Max Heap Tree with LONG INTEGERS" << endl;
    maxHeapLONGINT.display();
    cout << "After Heap sort..." << endl << endl;
    // Print first 100 smallest elements in Tree
    cout << "\t\t\t\t\t100 smallest elements in the tree" << endl;
    startTime = clock();
    maxHeapLONGINT.HeapSort();
    endTime = clock();
    maxHeapLONGINT.display();
cout << "Time Takened: " << fixed << setprecision(2) << static_cast<double>(endTime-startTime)*1000/CLOCKS_PER_SEC<< "ms" << endl;

cout << endl << endl;

    MaxHeap<long long> maxHeapLONGLONGINT(size);
    maxHeapLONGLONGINT.InitRandomTree();
    cout << "\t\t\t\t\t Max Heap Tree with LONG LONG INTEGERS" << endl;
    maxHeapLONGLONGINT.display();
    cout << "After Heap sort..." << endl << endl;
    // Print first 100 smallest elements in Tree
    cout << "\t\t\t\t\t100 smallest elements in the tree" << endl ;
    startTime = clock();
    maxHeapLONGLONGINT.HeapSort();
    endTime = clock();
    maxHeapLONGLONGINT.display();
cout << "Time Takened: " << fixed << setprecision(2) << static_cast<double>(endTime-startTime)*1000/CLOCKS_PER_SEC<< "ms" << endl;

cout << endl << endl;

    MaxHeap<float> maxHeapFLOAT(size);
    maxHeapFLOAT.InitRandomTree();
    cout << "\t\t\t\t\t Max Heap Tree with FLOATS" << endl;
    maxHeapFLOAT.display();
    cout << "After Heap sort..." << endl << endl;
    // Print first 100 smallest elements in Tree
    cout << "\t\t\t\t\t100 smallest elements in the tree" << endl;
    startTime = clock();
    maxHeapFLOAT.HeapSort();
    endTime = clock();
    maxHeapFLOAT.display();
cout << "Time Takened: " << fixed << setprecision(2) << static_cast<double>(endTime-startTime)*1000/CLOCKS_PER_SEC<< "ms" << endl;

cout << endl << endl;
    MaxHeap<double> maxHeapDOUBLE(size);
    maxHeapDOUBLE.InitRandomTree();
    cout << "\t\t\t\t\t Max Heap Tree with DOUBLES" << endl;
    maxHeapDOUBLE.display();
    cout << "After Heap sort..." << endl << endl;
    // Print first 100 smallest elements in Tree
    cout << "\t\t\t\t\t100 smallest elements in the tree" << endl;
    startTime = clock();
    maxHeapDOUBLE.HeapSort();
    endTime = clock();
    maxHeapDOUBLE.display();
cout << "Time Takened: " << fixed << setprecision(2) << static_cast<double>(endTime-startTime)*1000/CLOCKS_PER_SEC<< "ms" << endl;
cout << endl << endl;

        MaxHeap<long double> maxHeapLONGDOUBLE(size);
    maxHeapLONGDOUBLE.InitRandomTree();
    cout << "\t\t\t\t\t Max Heap Tree with LONG DOUBLES" << endl;
    maxHeapLONGDOUBLE.display();
    cout << "After Heap sort..." << endl << endl;
    // Print first 100 smallest elements in Tree
    cout << "\t\t\t\t\t100 smallest elements in the tree" << endl;
    startTime = clock();
    maxHeapLONGDOUBLE.HeapSort();
    endTime = clock();
    maxHeapLONGDOUBLE.display();
cout << "Time Takened: " << fixed << setprecision(2) << static_cast<double>(endTime-startTime)*1000/CLOCKS_PER_SEC<< "ms" << endl;


cout << "Press any key to continue..." << endl;
cin.ignore();

    return 0;
}

