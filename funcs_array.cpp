#include <iostream>
using namespace std;

void printArray(int* arr, int n){
    cout << endl << "current array:";
    cout << endl << "total elements - " << n << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertFirst(int* arr, int &n){
    for (int i=n; i>0; i--){
        arr[i] = arr[i-1];
    }
 
    cout << endl << "element to add at beginning - ";
    cin >> arr[0];
    n += 1;
}

void insertFirst(int* arr, int &n, int ele){
    for (int i=n; i>0; i--){
        arr[i] = arr[i-1];
    }
 
    arr[0] = ele;
    n += 1;
}

void insertLast(int* arr, int &n){
    cout << endl << "element to add at end - ";
    cin >> arr[n];
    n += 1;
}

void insertLast(int* arr, int &n, int ele){
    arr[n] = ele;
    n += 1;
}

void insertPosition(int* arr, int &n){
    int pos;
    cout << endl << "position to add element at - ";
    cin >> pos;

    if (pos>n+1 | pos<1){
        cout << "invalid position";
    }
    else{
        for (int i=n; i>pos-1; i--){
        arr[i] = arr[i-1];
        }
 
        cout << "element to add at position - ";
        cin >> arr[pos-1];
        n += 1;
    }
}

void insertPosition(int* arr, int &n, int pos){
    if (pos>n+1 | pos<1){
        cout << "invalid position";
    }
    else{
        for (int i=n; i>pos-1; i--){
        arr[i] = arr[i-1];
        }
 
        cout << "element to add at position - ";
        cin >> arr[pos-1];
        n += 1;
        cout << endl;
    }
}

void insertPosition(int* arr, int &n, int pos, int ele){
    if (pos>n+1 | pos<1){
        cout << "invalid position";
    }
    else{
        for (int i=n; i>pos-1; i--){
        arr[i] = arr[i-1];
        }
 
        arr[pos-1] = ele;
        n += 1;
        cout << endl;
    }
}

void deleteFirst(int* arr, int &n){
    if (n <= 0){
        cout << endl << "array empty, cannot delete";
    }
    else{
        for (int i=0; i<n; i++){
            arr[i] = arr[i+1];
        }
        n -= 1;
    }
}

void deleteLast(int* arr, int &n){
    if(n <= 0){
        cout << endl << "array empty, cannot delete";
    }
    else{
        n -= 1;
    }
}

void deletePosition(int* arr, int &n){
    if (n <= 0){
        cout << endl << "array empty, cannot delete";
    }
    else{
        int pos;
        cout << endl << "position to delete element at - ";
        cin >> pos;

        if (pos>n | pos<1){
            cout << endl << "invalid position";
        }
        else{
            for (int i=pos-1; i<n; i++){
                arr[i] = arr[i+1];
            }
            n -= 1;
        }
    }
}

void deletePosition(int* arr, int &n, int pos){
    if (n <= 0){
        cout << endl << "array empty, cannot delete";
    }
    else{
        if (pos>n | pos<1){
            cout << endl << "invalid position";
        }
        else{
            for (int i=pos-1; i<n; i++){
                arr[i] = arr[i+1];
            }
            n -= 1;
        }
    }
}

void removeDuplicates(int* arr, int &n){
    if (n<2){
        cout << endl << "less than 2 elements in array, no changes made";
    }
    else{
        bool dupes = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i==j){
                    continue;
                }
                else{
                    if (arr[i] == arr[j]){
                        deletePosition(arr, n, j);
                        dupes = 1;
                    }
                }
            }
        }
        if (dupes){
            cout << endl << "duplicates removed";
        }
        else{
            cout << endl << "no duplicates found";
        }
    }
}

void reverseArray(int* arr, int &n){
    if (n == 0){
        cout << endl << "array empty, cannot reverse";
    }
    if (n == 1){
        cout << endl << "only one element found, cannot reverse";
    }
    else{
        int beg=0;
        int end=n-1;
        while (beg<end){
            int temp = arr[beg];
            arr[beg] = arr[end];
            arr[end] = temp;
            beg++;
            end--;
        }
    }
}

void swapPosition(int* arr, int &n){
    if (n<2){
        cout << endl << "less than 2 elements in array, no changes made";
    }
    else{
        int pos1, pos2;
        cout << endl << "first postition for swap - ";
        cin >> pos1;
        cout << "second postition for swap - ";
        cin >> pos2;

        if (pos1<0 | pos2<0 | pos1>n | pos2>n){
            int temp;
            temp = arr[pos1-1];
            arr[pos1-1] = arr[pos2-1];
            arr[pos2-1] = temp;
        }
        else{
            cout << endl << "invalid position";
        }
    }
}

void swapPosition(int* arr, int &n, int pos1, int pos2){
    if (n<2){
        cout << endl << "less than 2 elements in array, no changes made";
    }
    else{
        if (pos1<0 | pos2<0 | pos1>n | pos2>n){
            int temp;
            temp = arr[pos1-1];
            arr[pos1-1] = arr[pos2-1];
            arr[pos2-1] = temp;
        }
        else{
            cout << endl << "invalid position";
        }
    }
}

void swapEle(int* arr, int &n){
    if (n<1){
        cout << endl << "array empty, cannot swap";
    }
    else{
        int pos;
        cout << endl << "position to swap - ";
        cin >> pos;

        if (pos>n | pos<1){
            cout << endl << "invalid position";
        }
        else{
            int x;
            cout << "element to swap with - ";
            cin >> x;
            arr[pos-1] = x;
        }
    }
}