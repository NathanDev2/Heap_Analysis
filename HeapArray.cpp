/* Purpose of this program is to Implement functions of a priority queue like structure using heap in an array/vector. It demonstrates the following...

    1) Insert and Deletion in a heap
    2) Display of the 100 smallest elements in a heap
    3) The time taken to use heap and display elements

*/

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;


template <typename T>
class MaxHeap { // Changed class name
public:
MaxHeap(); // Constructor
~MaxHeap(); // Destructor
void InitArray(T);
void InitHeap(T n); // Initialize a max heap from the array
void BuildMaxHeap(); // Build a max heap with the root being the largest number
bool IsSorted(); // Check if sorted
void MaxHeapify(int i, int size); // Maintain max heap property
void HeapSort(); // Spam the Poll(delete) function until the heap is sorted
void Display(); // Show current state of the object
void Insert(T item, T priority); // Insert item into the max heap
int Poll(); // Delete and root and Heapify to maintain max heap property
int Peek(); // Check the root of the max heap
private:
T* a;
long long size;
};

template <typename T>
MaxHeap<T>::MaxHeap() {
a = nullptr;
size = 0;
}

template <typename T>
MaxHeap<T>::~MaxHeap() {
delete[] a;
}

template <typename T>
void MaxHeap<T>::InitArray(T n) {
size = n + 1;
a = new T[size];
for (int i = 1; i < size; i++) {
a[i] = static_cast<T>((1.0 * rand() / RAND_MAX) * size); // Gets random values of the type of which T is from 1-size
}
}

template <typename T>
void MaxHeap<T>::BuildMaxHeap() {
for (int i = size / 2; i >= 1; i--) {
MaxHeapify(i, size - 1); 
}
}

template <typename T>
void MaxHeap<T>::InitHeap(T n) {
size = n + 1;
InitArray(n); // Take an array and form into a heap
BuildMaxHeap();
}

template <typename T>
void MaxHeap<T>::Display() {
    int Display100 = 100; // Display 100 values only
if(size > 100){
for (int i = 1; i <= Display100; i++) {
cout << a[i] << "\t\t";
if (i%10==0){
    cout << endl;
}
}
}
else{
    for(int i = 1; i<=10;i++){
        cout << a[i];
    if(i!=size){
        cout << ", ";
    }
    }
}
cout << endl;
}

template <typename T>
void MaxHeap<T>::MaxHeapify(int i, int size) {
int left, right, largest;
left = 2 * i;
right = 2 * i + 1;
largest = i;
if (left <= size && a[left] > a[i]) // Check left
largest = left;
if (right <= size && a[right] > a[largest]) // Check right
largest = right;
if (largest != i) {
swap(a[i], a[largest]); // Check and swap with parent nodes starting from the bottom up
MaxHeapify(largest, size);
}
}

template <typename T>
void MaxHeap<T>::HeapSort() {
BuildMaxHeap();
for (int i = size - 1; i >= 2; i--) {
swap(a[1], a[i]);
MaxHeapify(1, i-1);
}
}

template <typename T>
void MaxHeap<T>::Insert(T item, T priority) {
size++; // Increase our size by 1
T* newArray = new T[size]; // allocate memory
for (int i = 1; i < size; ++i) { // add new value to the end of the tree
newArray[i] = a[i];
}
newArray[size - 1] = item; // set item and delete
delete[] a;
a = newArray;
a[size - 1] = priority;
BuildMaxHeap();
}

template <typename T>
int MaxHeap<T>::Poll() {
if (size < 2) { // check if tree had no children
cout << "Priority queue is empty." << endl;
return -1;
}
int maxItem = a[1]; // set current max item
swap(a[1], a[size - 1]); // swap current max item with new max item
size--; // Delete old max item
 MaxHeapify(1, size - 1);
return maxItem;
}

template <typename T>
int MaxHeap<T>::Peek() {
if (size < 2) {
cout << "Priority queue is empty." << endl;
return -1;
}
return a[1];
}

int main() {
MaxHeap<int>testHeap;
testHeap.InitHeap(10);
cout << "Using Delete Max Function with: ";
testHeap.Display();
testHeap.Poll();
cout << "Result: ";
testHeap.Display();
cout << endl;


cout << "Using Insert Operation with: ";
testHeap.Display();
cout << "Inserting 50..." << endl;
testHeap.Insert(50, 50);
cout << "Result: ";
testHeap.Display();
cout << endl;


cout << "Press any key to continue..." << endl;
cin.ignore();

system("cls");

/*=========================================================================================================*/
srand(time(NULL)); // Generate a random seed
clock_t startTime, endTime; // Get time of HeapSort and printing the first 100 smallest elements
int size = 100000; // Size of the heap
/*=========================================================================================================*/
                                    /*Testing with 6 data types*/
/*=========================================================================================================*/
MaxHeap<int> intHeap; // Initialize a heap with type
intHeap.InitHeap(size);
cout << "100 Smallest elements in an array with integers" << endl;
startTime = clock();
intHeap.HeapSort();
intHeap.Display();
endTime = clock();
cout << "Time Takened: " << fixed << setprecision(2) << static_cast<double>(endTime-startTime)*1000/CLOCKS_PER_SEC<< "ms" << endl;
cout << endl;
/*=========================================================================================================*/

/*=========================================================================================================*/
MaxHeap<long int> longIntHeap; // Initialize a heap with type
longIntHeap.InitHeap(size);
cout << "100 Smallest elements in an array with long integers" << endl;
startTime = clock();
longIntHeap.HeapSort();
longIntHeap.Display();
endTime = clock();
cout << "Time Takened: " << fixed << setprecision(2) << static_cast<double>(endTime-startTime)*1000/CLOCKS_PER_SEC << "ms" << endl;
cout << endl;
/*=========================================================================================================*/

/*=========================================================================================================*/
MaxHeap<long long int> longLongIntHeap; // Initialize a heap with type
longLongIntHeap.InitHeap(size);
cout << "100 Smallest elements in an array with long long integers" << endl;
startTime = clock();
longLongIntHeap.HeapSort();
longLongIntHeap.Display();
endTime = clock();
cout << "Time Takened: " << fixed << setprecision(2) << static_cast<double>(endTime-startTime)*1000/CLOCKS_PER_SEC << "ms" << endl;
cout << endl;
/*=========================================================================================================*/

/*=========================================================================================================*/
MaxHeap<float> floatHeap; // Initialize a heap with type
floatHeap.InitHeap(size);
cout << "\t\t\t\t100 Smallest elements in an array with floats" << endl;
startTime = clock();
floatHeap.HeapSort();
floatHeap.Display();
endTime = clock();
cout << "Time Takened: " << fixed << setprecision(2) << static_cast<double>(endTime-startTime)*1000/CLOCKS_PER_SEC << "ms" << endl;
cout << endl;
/*=========================================================================================================*/

/*=========================================================================================================*/
MaxHeap<double> doubleHeap; // Initialize a heap with type
doubleHeap.InitHeap(size);
cout << "\t\t\t\t100 Smallest elements in an array with doubles" << endl;
startTime = clock();
doubleHeap.HeapSort();
doubleHeap.Display();
endTime = clock();
cout << "Time Takened: " << fixed << setprecision(2) << static_cast<double>(endTime-startTime)*1000/CLOCKS_PER_SEC << "ms" << endl;
cout << endl;
/*=========================================================================================================*/

/*=========================================================================================================*/
MaxHeap<long double> longDoubleHeap; // Initialize a heap with type
longDoubleHeap.InitHeap(size);
cout << "\t\t\t\t100 Smallest elements in an array with long doubles" << endl;
startTime = clock();
longDoubleHeap.HeapSort();
longDoubleHeap.Display();
endTime = clock();
cout << "Time Takened: " << fixed << setprecision(2) << static_cast<double>(endTime-startTime)*1000/CLOCKS_PER_SEC << "ms" << endl;
/*=========================================================================================================*/



cout << "Press any key to continue..." << endl;
cin.ignore();
return 0;

}
