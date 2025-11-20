#include <iostream>
using namespace std;

int heapArr[100];
int heapSize = 0;

void insertPQ(int val){
    heapArr[heapSize] = val;
    int i = heapSize;
    heapSize++;

    while(i > 0 && heapArr[i] > heapArr[(i-1)/2]){
        swap(heapArr[i], heapArr[(i-1)/2]);
        i = (i-1)/2;
    }
}

int getMaxPQ(){
    if(heapSize == 0) return -1;
    return heapArr[0];
}

void deleteMaxPQ(){
    if(heapSize == 0) return;

    heapArr[0] = heapArr[heapSize-1];
    heapSize--;

    int i = 0;

    while(1){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if(left < heapSize && heapArr[left] > heapArr[largest])
            largest = left;

        if(right < heapSize && heapArr[right] > heapArr[largest])
            largest = right;

        if(largest == i) break;

        swap(heapArr[i], heapArr[largest]);
        i = largest;
    }
}

 int main() {
    int choice, val;

    while(true) {
        cout << "\nPriority Queue using Max Heap";
        cout << "\n1. Insert";
        cout << "\n2. Get Max";
        cout << "\n3. Delete Max";
        cout << "\n4. Display Heap";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                insertPQ(val);
                cout << "Inserted.\n";
                break;

            case 2:
                if(heapSize == 0)
                    cout << "Heap is empty.\n";
                else
                    cout << "Maximum element: " << getMaxPQ() << endl;
                break;

            case 3:
                if(heapSize == 0)
                    cout << "Heap is empty.\n";
                else {
                    cout << "Deleting max: " << getMaxPQ() << endl;
                    deleteMaxPQ();
                }
                break;

            case 4:
                cout << "Heap elements: ";
                for(int i = 0; i < heapSize; i++)
                    cout << heapArr[i] << " ";
                cout << endl;
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
