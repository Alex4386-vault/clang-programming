#include <iostream>

/**
 * implementation of bubblesort
 */

template <class T>
void swap(T *a, T *b) {
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template <class T>
void bubbleSort(T* array, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if (array[i] > array[j]) {
                swap<T>(&array[i], &array[j]);
            }
        }
    }
}

int main() {
    double a[10] = {10,9.823,8,7,6.0002,5,4,3.273,2.283,1};

    bubbleSort<double>(a, 10);

    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}