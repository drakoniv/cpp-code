#include <iostream> /* File: toh.cpp */
#include <cstring>

using namespace std;

void hat(int height) {
    int counter1 = height-1, counter2 = height-1;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j <(2*height-1); j++) {
            if ( j == counter1 || j == counter2) {
                cout << '*';
            } else {
                cout << '#';
            }
        }
        counter1--;
        counter2++;
        cout << endl;
    }
}
int test;
int array_max (int array[], int n) {

    if(n<0){
        return 0;
    }

    return (array_max(array, n-1) < array[n]) ? array[n] : array_max(array,n-1);


//    return (array_max(array,n-1) > array[n])? array_max(array,n-1):array[n];
}

int matrix_max (int array[][5], int r, int c ) {
    if(r <0) {
        return 0;
    }
    return (matrix_max(array, r-1, c) < array_max(array[r], c))? array_max(array[r], c) : matrix_max(array, r-1, c);
}

//int x = 10;
//void mystery(int x, int& y){
//    for (; y <10; y++) {
//
//        int z = 1;
//        z++;
//    }
//    x++;
//}
bool recursive_check(const int x[], int size) {
    if ( size == 1) {
        return 1;
    }
    if ( x[size-1] < x[size-2]) {
        return 0* recursive_check(x, size-1);
    }
    return  1* recursive_check(x, size-1);
}
void ruler (int n) {
    if(n>1) {
        ruler(n - 1);
    }
    for(int i =0; i < n; i++) {
        cout << '-';
    }
    cout<<endl;
    if(n>1){
        ruler(n-1);
    }
}
int cstring_length(char str[], int posi) {
    if(str[posi] == '\0'){
        return 0;
    }
    return 1+cstring_length(str, posi+1);
}
void cstring_copy(const char source[], char target[], int pos) {

    if(source[pos] == '\0') {
        return;
    } else {
        target[pos] = source[pos];
        cstring_copy(source,target, pos+1);
    }

}
int miauw ( int incom) {
    return static_cast<int>(incom*0.25);
}

int mgoi ( int asu) {

}
int mgoi(int ass, bool aww = 0) {

}

int main() {
//    hat(3);
//    char asu[32];
//    strcpy(asu, "mgoi");
//    cout << array_max(array, 5) << endl;
//    int array2d[2][5] = {{2,5,21,23,12}, {2,4,1,2,45}};
//    cout << matrix_max(array2d, 2,5) << endl;
//    int array3d[3][4][2] = {{1,2,3,4},{5,6,7}};
//    ruler(4);
//    cout<< recursive_check(array, 5);
//    int mgooi=  array3d[0][1][1];
//    int y = 3;
//    x++;
//    mystery(x, y);
//    cout << x <<endl;
//    cout << y <<endl;
//cout << cstring_length("mgo", 1) << endl;
//    char mgo[100] = "mgoi";
//    char so[100];
//    char m[3][4][2][2] = {{1,2,3,4,5,6,7}};
//    cstring_copy(mgo,so,0);
//    cout<<so;
//cout << miauw(2101);
float x = 2.1;
double a = 7.5;
float& y = x;
int& m = a;
mgoi (2);
//    return 0;
};