#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct person {
    int id;
    string name;
    int age;
    int height;
    int weight;
};

struct MinHeap {
    person *arr;
    int capacity;
    int size;
};

MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = new MinHeap;
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->arr = new person[capacity];
    return minHeap;
}

void swap(person& a, person& b) {
    person temp = a;
    a = b;
    b = temp;
}

void heapify(MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->arr[left].age < minHeap->arr[smallest].age)
        smallest = left;

    if (right < minHeap->size && minHeap->arr[right].age < minHeap->arr[smallest].age)
        smallest = right;

    if (smallest != index) {
        swap(minHeap->arr[index], minHeap->arr[smallest]);
        heapify(minHeap, smallest);
    }
}

void insert(MinHeap* minHeap, person p) {
    if (minHeap->size == minHeap->capacity) {
        cout << "Heap is full. Cannot insert." << endl;
        return;
    }

    minHeap->size++;
    int i = minHeap->size - 1;
    minHeap->arr[i] = p;

    while (i != 0 && minHeap->arr[(i - 1) / 2].age > minHeap->arr[i].age) {
        swap(minHeap->arr[i], minHeap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    cout << "Person inserted into Min-Heap." << endl;
}

person extractMin(MinHeap* minHeap) {
    if (minHeap->size <= 0) {
        person p;
        p.id = -1; // Indicates an empty heap
        return p;
    }

    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->arr[0];
    }

    person root = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
    minHeap->size--;
    heapify(minHeap, 0);

    return root;
}

void displayYoungestWeight(MinHeap* minHeap) {
    if (minHeap->size <= 0) {
        cout << "Min-Heap is empty. No youngest person." << endl;
        return;
    }

    cout << "Youngest person's weight: " << minHeap->arr[0].weight << " kg." << endl;
}

void freeMemory(MinHeap* minHeap) {
    delete[] minHeap->arr;
    delete minHeap;
}

int main() {
    MinHeap* minHeap = nullptr;
    int n = 0;
    int choice;

    do {
        cout << "MAIN MENU (HEAP)" << endl;
        cout << "1. Create Min-Heap and Input Data" << endl;
        cout << "2. Insert a new person into the Min-Heap" << endl;
        cout << "3. Display weight of the youngest person" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the capacity of the Min-Heap: ";
                cin >> n;
                minHeap = createMinHeap(n);
                cout << "Min-Heap created." << endl;
                break;
            case 2:
                if (minHeap == nullptr) {
                    cout << "Min-Heap is not created. Please create it first." << endl;
                } else {
                    person p;
                    cout << "Enter details for the new person:" << endl;
                    cout << "Name: ";
                    cin.ignore();
                    getline(cin, p.name);
                    cout << "Age: ";
                    cin >> p.age;
                    cout << "Height (in cm): ";
                    cin >> p.height;
                    cout << "Weight (in kg): ";
                    cin >> p.weight;
                    insert(minHeap, p);
                }
                break;
            case 3:
                if (minHeap == nullptr) {
                    cout << "Min-Heap is not created. Please create it first." << endl;
                } else {
                    displayYoungestWeight(minHeap);
                }
                break;
            case 4:
                if (minHeap != nullptr) {
                    freeMemory(minHeap);
                }
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}