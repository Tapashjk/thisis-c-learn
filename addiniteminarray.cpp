//simply i will add item in  the array; process to add array

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Step 1: Define the original array with a fixed size
    const int MAX_SIZE = 10; // Maximum size of the static array
    string array1[MAX_SIZE] = {"tapuu", "sangu", "riyo", "sulav"}; // Initialize array with 4 elements
    int array_size = 4; // Current number of elements in the array

    int current_size=0;
    for(int i =0 ;i<MAX_SIZE;i++){
        if(!array1[i].empty()){
            current_size++;
        }else{
            break;
        }
        
    }
    cout<<current_size<<endl;

    // Step 2: Print the original array
    cout << "Original array: ";
    for (int i = 0; i < array_size; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    // Step 3: Add a new element to the array
    if (array_size < MAX_SIZE) { // Check if there's space in the array
        array1[array_size] = "arayn"; // Add the new element
        array_size++; // Increase the size of the array
    } else {
        cout << "Array is full, cannot add more elements!" << endl;
    }

    // Step 4: Print the updated array
    cout << "Updated array: ";
    for (int i = 0; i < array_size; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    return 0;
}

