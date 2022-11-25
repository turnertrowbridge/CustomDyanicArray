#include <iostream>
using namespace std;

class myDynamicArray {
    int *array; // pointer to array
    int maxSize; // max sizeOfArray
    int curSize; // current sizeOfArray

public:
    myDynamicArray() {
        array = new int[1];
        maxSize = 1;
        curSize = 0;
    }

    void push(int data) {

        // double maxSize if curSize is equal to max size
        // due to running out of space
        if(curSize == maxSize) {
            int *temp = new int[2 * maxSize]; // create temp variable
            for (int i = 0; i < maxSize; i++){
                temp[i] = array[i];
            }
            delete[] array; // delete contents of previous array
            maxSize *=2;  // increase max size
            array = temp;  // store the temp data in array
        }

        // insert the data into the array
        array[curSize] = data;
        curSize++;
    }

    int pop(){
        int lastValue = array[curSize-1];
        curSize--;
        return lastValue;
    }

    void remove(int indexToRemove){
        if(indexToRemove >= 0 && indexToRemove <= curSize){ // check if valid part of array
            for(int i = indexToRemove; i < curSize - 1; i ++){
                array[i] = array[i + 1];
            }
            curSize--;
        }
    }

    // get the size of the array
    int size() const {
        return curSize;
    }

    //get the max space allocated for array
    int getMaxSize() const{
        return maxSize;
    }


    // print contents of array to console
    void print() {
        for(int i = 0; i < curSize; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }


};



int main() {
    myDynamicArray dynamicArray; // create instance of myDynamicArray

    // check curSize and maxSize of array
    cout << "Array's starting current size: " << dynamicArray.size() << endl;
    cout << "Array's starting max size: " << dynamicArray.getMaxSize() << endl;

    dynamicArray.push(15); // push 15 to back
    dynamicArray.push(20); // push 20 to back
    dynamicArray.push(40); // push 40 to back
    dynamicArray.push(75); // push 75 to back
    dynamicArray.push(30); // push 30 to back

    // check curSize and maxSize of array
    cout << "Array's current size after pushing contents: " << dynamicArray.size() << endl;
    cout << "Array's max size after pushing contents: " << dynamicArray.getMaxSize() << endl;
    dynamicArray.print();

    int poppedValue = dynamicArray.pop();
    cout << "Popped: " << poppedValue << endl;
    dynamicArray.print();


    dynamicArray.remove(2);
    cout << "Removed index 2" << endl;
    dynamicArray.print();

    dynamicArray.push(99); // push 99 to back
    dynamicArray.push(105); // push 105 to back
    dynamicArray.push(304); // push 304 to back
    cout << "Pushed more values" << endl;
    dynamicArray.print();

    return 0;
}
