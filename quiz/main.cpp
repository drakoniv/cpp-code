#include <iostream>
void fun( int a[], int size) {
    int sum [size];
    int res = 0 ;
    for (int i=0; i<size; i++) {
        for (int j = 0; j<i; j++) {
            res += a[j];
        }
        sum [i] = res;
    }
}

int main() {
    int arr[5] = {1,2,3,4,5};
    fun( arr , 5);
    for(int k = 0; k< 5 ; k++) {
        std::cout << arr[k] <<std::endl;
    }

    return 0;
}