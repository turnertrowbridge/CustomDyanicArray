#include <iostream>
using namespace std;

class myDynamicArray {
    int *array; // pointer to array
    int maxSize; // max sizeOfArray
    int curSize; // current sizeOfArray

public:
    // set default values
    myDynamicArray() {
        array = new int[1];
        maxSize = 1;
        curSize = 0;
    }

    // add a value to array
    void push(int value) {

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

        // insert the value into the array
        array[curSize] = value;
        curSize++;
    }

    // remove last value on array and return it
    int pop(){
        int lastValue = array[curSize-1];
        curSize--;
        return lastValue;
    }

    // remove a selected array at the index provided
    void remove(int index){
        if(index >= 0 && index <= curSize){ // check if valid part of array
            for(int i = index; i < curSize - 1; i ++){
                array[i] = array[i + 1];
            }
            curSize--;
        }
    }

    // get the size of the array
    int size() const {
        return curSize;
    }

    // get the max space allocated for array
    int getMaxSize() const{
        return maxSize;
    }

    // get a value at index
    int at(int index){
        if(index >= 0 && index <= curSize){ // check if valid part of array
                return array[index];
        }
        return 0;
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
    cout << endl;


    dynamicArray.push(15); // push 15 to back
    dynamicArray.push(20); // push 20 to back
    dynamicArray.push(40); // push 40 to back
    dynamicArray.push(75); // push 75 to back
    dynamicArray.push(30); // push 30 to back
    cout << "Pushed 15, 20, 40, 75, 30 to array" << endl;
    cout << endl;

    // check curSize and maxSize of array
    cout << "Array's current size after pushing contents: " << dynamicArray.size() << endl;
    cout << "Array's max size after pushing contents: " << dynamicArray.getMaxSize() << endl;
    dynamicArray.print();
    cout << endl;

    int poppedValue = dynamicArray.pop();
    cout << "Popped: " << poppedValue << endl;
    dynamicArray.print();


    dynamicArray.remove(2);
    dynamicArray.remove(-4); // won't remove anything
    cout << "Removed value at index 2" << endl;
    dynamicArray.print();
    cout << endl;

    dynamicArray.push(99); // push 99 to back
    dynamicArray.push(105); // push 105 to back
    dynamicArray.push(304); // push 304 to back
    cout << "Pushed 99, 105, 304 to array" << endl;
    dynamicArray.print();
    cout << endl;

    for(int i = -1; i < dynamicArray.size()+2; i++){
        int foundValue = dynamicArray.at(i);
        cout << "Value at index "<< i << ": " << foundValue << endl;

    }

    return 0;
}
