
#include "..\..\std_lib_facilities.h"
#include <chrono>

using namespace std::chrono;


template<typename T>
void shellSort(T arr[], int size) {
    int jumpSize = size;
    while (jumpSize > 1) {
        jumpSize *= 0.999999;
        for (int i = 0; i + jumpSize < size; i += jumpSize) {
            if (arr[i + jumpSize] < arr[i]) {
                swap(arr[i], arr[i + jumpSize]);
                for (int n = i; arr[n] < arr[abs(n - jumpSize)] && n - jumpSize >= 0; n -= jumpSize)
                    swap(arr[n], arr[n - jumpSize]);
            }
        }

    }
}


template <typename T>
void selectionSort(T arr[], int size) {
    int minIndex;

    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        //finn minste
        for (int n = i + 1; n < size; n++) {
            if (arr[n] < arr[minIndex]) minIndex = n;
        }
        swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void indexedSelectionSort(T arr[], int startIndex, int endIndex) {
    int minIndex;

    for (int i = startIndex; i < endIndex; i++) {
        minIndex = i;
        //finn minste
        for (int n = i + 1; n <= endIndex; n++) {
            if (arr[n] < arr[minIndex]) minIndex = n;
        }
        swap(arr[i], arr[minIndex]);
    }
}


//template<typename T>
//void mergeSort(T arr[], long size) {
//   if (size <= 10) {
//        selectionSort(arr, size);
//    }
//    else {
//
//        int size1 = size / 2 + size % 2;
//        int size2 = size / 2;
//        T* arr1 = new T[size1];
//        T* arr2 = new T[size2];
//        for (int i = 0; i < size1; i++) {
//            arr1[i] = arr[i];
//        }
//        for (int i = 0; i < size2; i++) {
//            arr2[i] = arr[i + size1];
//        }
//
//        if (size1 > 1) mergeSort(arr1, size1);
//        if (size2 > 1) mergeSort(arr2, size2);
//
//
//        /*if (size1 <= 5) {
//            selectionSort(arr1, size1);
//            selectionSort(arr2, size2);
//        }*/
//
//        int arr1Index = 0;
//        int arr2Index = 0;
//        for (int i = 0; i < size; i++) {
//            if (arr1Index == size1) {
//                arr[i] = arr2[arr2Index];
//                arr2Index++;
//            }
//            else if (arr2Index == size2) {
//                arr[i] = arr1[arr1Index];
//                arr1Index++;
//            }
//            else if (arr1[arr1Index] < arr2[arr2Index]) {
//                arr[i] = arr1[arr1Index];
//                arr1Index++;
//            }
//            else {
//                arr[i] = arr2[arr2Index];
//                arr2Index++;
//            }
//        }
//        delete[] arr1;
//        delete[] arr2;
//    }
//    
//}



template<typename T>
void merge(T arr[], long sI1, long eI1, long sI2, long eI2) {
    long size = eI2 - sI1 + 1;
    long size1 = eI1 - sI1 + 1;
    long size2 = eI2 - sI2 + 1;
    T* tempArr = new T[size];
    long index1 = sI1;
    long index2 = sI2;
    for (long i = 0; i < size; i++) {
        if (index1 == sI1+size1) {
            tempArr[i] = arr[index2];
            index2++;
        }
        else if (index2 == sI2+size2) {
            tempArr[i] = arr[index1];
            index1++;
            }
        else if (arr[index1] < arr[index2]) {
            tempArr[i] = arr[index1];
            index1++;
        }
        else {
            tempArr[i] = arr[index2];
            index2++;
        }
    }
    for (long i = 0; i < size;i++) {
        arr[sI1 + i] = tempArr[i];
    }
    delete[] tempArr;
}



template<typename T>
void mergeSort(T arr[], long startIndex, long endIndex) {
    long size = endIndex - startIndex+1;
    long size1 = size / 2 + size % 2;
    long size2 = size / 2;
    if (size1 <= 1) {}
    //else if (size1 <= 5)indexedSelectionSort(arr, startIndex,startIndex + size1 - 1);
    else {
        mergeSort(arr, startIndex, startIndex + size1 - 1);
    }
    if (size2 <= 1) {}
    //else if (size2 <= 5)indexedSelectionSort(arr, startIndex + size1, endIndex);
    else {
        mergeSort(arr,startIndex + size1,startIndex + size - 1);
    }

    merge(arr, startIndex,startIndex + size1 - 1,startIndex + size1,startIndex + size - 1);
    
}




//template<typename T>
//T getPivot(vector<T>& list) {
//
//    srand(int(time(NULL)));
//    int size = list.size();
//    int* randomIndexArr;
//    int randomIndexArrSize;
//    if (size < 10) {
//        randomIndexArrSize = size;
//    }
//    else if (size < 100) {
//        randomIndexArrSize = 20;
//    }
//    else if (size < 1000) {
//        randomIndexArrSize = 40;
//    }
//    else {
//        randomIndexArrSize = 100;
//    }
//    randomIndexArr = new T[randomIndexArrSize];
//    int max = 0;
//    int min = 1000000000;
//    for (int i = 0; i < randomIndexArrSize; i++) {
//        int randomNumber = rand() % size;
//        randomIndexArr[i] = randomNumber;
//        int numberAtIndex = list[randomNumber];
//        if (max < numberAtIndex)max = numberAtIndex;
//        if (min > numberAtIndex)min = numberAtIndex;
//    }
//
//    int mid = (max - min) / 2;
//    int offSide = (max - min) / 2;
//    int pivotIndex = randomIndexArr[0];
//    for (int i = 0; i < randomIndexArrSize; i++) {
//        int index = randomIndexArr[i];
//        if ((list[index] > mid&& max - list[index] >= offSide)
//            || (list[index] < mid && list[index] - min >= offSide)) {
//            pivotIndex = index;
//            srand(1);
//            break;
//        }
//    }
//    delete[] randomIndexArr;
//    return list[pivotIndex];
//}
//
//template<typename T>
//void quickSortStep(vector<T>& toSort) {
//    if (toSort.size() <= 1)return;
//    int pivot = getPivot(toSort);
//    vector<T> lesser;
//    vector<T> equal;
//    vector<T> greater;
//
//    while (!toSort.empty()) {//empy list into vectors greater, lesser or equal
//        T back = toSort.back();
//        toSort.pop_back();
//        if (back < pivot) lesser.push_back(back);
//        else if (back == pivot) equal.push_back(back);
//        else greater.push_back(back);
//    }
//    if (lesser.size() <= 1) {}
//    else if (lesser.size() < 3) {
//        if (lesser[1] < lesser[0])swap(lesser[0], lesser[1]);
//    }
//    else {
//        quickSortStep(lesser);
//    }
//    if (greater.size() <= 1) {}
//    else if (greater.size() < 3) {
//        if (greater[1] < greater[0])swap(greater[0], greater[1]);
//    }
//    else {
//        quickSortStep(greater);
//    }
//
//    while (!lesser.empty()) {
//        T first = lesser.front();
//        lesser.erase(lesser.begin());
//        toSort.push_back(first);
//    }
//
//    while (!equal.empty()) {
//        T first = equal.front();
//        equal.erase(equal.begin());
//        toSort.push_back(first);
//    }
//    while (!greater.empty()) {
//        T first = greater.front();
//        greater.erase(greater.begin());
//        toSort.push_back(first);
//    }
//
//
//
//
//
//}
//
//
//template <typename T>
//void quickSort(T arr[], int size) {
//    if (size <= 1)return;
//    vector<T> toSort;
//    for (int i = 0; i < size; i++) {
//        toSort.push_back(arr[i]);
//    }
//    quickSortStep(toSort);
//    for (int i = 0; i < size; i++) {
//        arr[i] = toSort[i];
//    }
//
//
//
//
//}

//template<typename T>
//T getPivot(T* list[],int size) {
//
//    srand(int(time(NULL)));
//    
//    int* randomIndexArr;
//    int randomIndexArrSize;
//    if (size < 10) {
//        randomIndexArrSize = size;
//    }
//    else if (size < 100) {
//        randomIndexArrSize = 20;
//    }
//    else if (size < 1000) {
//        randomIndexArrSize = 40;
//    }
//    else {
//        randomIndexArrSize = 100;
//    }
//    randomIndexArr = new int[randomIndexArrSize];
//    int max = 0;
//    int min = 1000000000;
//    for (int i = 0; i < randomIndexArrSize; i++) {
//        int randomNumber = rand() % size;
//        randomIndexArr[i] = randomNumber;
//        int numberAtIndex = *list[randomNumber];
//        if (max < numberAtIndex)max = numberAtIndex;
//        if (min > numberAtIndex)min = numberAtIndex;
//    }
//
//    int mid = (max - min) / 2;
//    int offSide = (max - min) / 2;
//    int pivotIndex = randomIndexArr[0];
//    for (int i = 0; i < randomIndexArrSize; i++) {
//        int index = randomIndexArr[i];
//        if ((*list[index] > mid&& max - *list[index] >= offSide)
//            || (*list[index] < mid && *list[index] - min >= offSide)) {
//            pivotIndex = index;
//            srand(1);
//            break;
//        }
//    }
//    delete[] randomIndexArr;
//    return *list[pivotIndex];
//}


//template<typename T>
//void quickSortStep(T* arr[], int size) {
//    if (size <= 1)return;
//    
//    T** lesser;
//    T** equal;
//    T** greater;
//    int lBackIndex=0;
//    int eBackIndex = 0;
//    int gBackIndex = 0;
//    int lesserSize = 0;
//    int equalSize = 0;
//    int greaterSize = 0;
//    T pivot = *arr[size-1];
//
//    if (size > 1) {
//        for (int i = 0; i < size; i++) {
//            if (*arr[i] < pivot) {
//                lesserSize++;
//            }
//            else if (*arr[i] == pivot) {
//                equalSize++;
//            }
//            else {
//                greaterSize++;
//            }
//        }
//        if (lesserSize > 0) lesser = new T * [lesserSize];
//        else lesser = new T * [1];
//        if (equalSize > 0)equal = new T * [equalSize];
//        else equal = new T * [1];
//        if (greaterSize > 0)greater = new T * [greaterSize];
//        else greater = new T * [1];
//    }
//    else {
//        lesser = new T * [size];
//        equal = new T * [size];
//        greater = new T * [size];
//    }
//
//
//    for (int i = 0; i < size; i++) {
//        if (*arr[i] < pivot) {
//            lesser[lBackIndex] = arr[i];
//            lBackIndex++;
//        }
//        else if (*arr[i] == pivot) {
//            equal[eBackIndex] = arr[i];
//            eBackIndex++;
//        }
//        else {
//            greater[gBackIndex] = arr[i];
//            gBackIndex++;
//        }
//    }
//
//    lesserSize = lBackIndex;
//    equalSize = eBackIndex;
//    greaterSize = gBackIndex;
//
//    if (lesserSize < 10 && lesserSize>0) selectionSort(lesser, lesserSize);
//    else quickSortStep(lesser, lesserSize);
//    if (equalSize < 10 && equalSize>0) selectionSort(equal, equalSize);
//    else quickSortStep(equal, equalSize);
//    if (greaterSize < 10 && greaterSize>0) selectionSort(greater, greaterSize);
//    else quickSortStep(greater, greaterSize);
//
//    if (lesserSize > 0) {
//        for (int i = 0; i < lesserSize; i++)
//            arr[i] = lesser[i];
//    }
//    if (equalSize > 0) {
//        for (int i = lesserSize; i < lesserSize + equalSize; i++)
//            arr[i] = equal[i - lesserSize];
//    }
//    if (greaterSize > 0) {
//        for (int i = lesserSize + equalSize; i < lesserSize + equalSize + greaterSize; i++)
//            arr[i] = greater[i - equalSize - lesserSize];
//    }
//    if(lesserSize>0)delete[] lesser;
//    if(equalSize>0)delete[] equal;
//    if(greaterSize>0)delete[] greater;
//}
//
//template <typename T>
//void quickSort(T arr[], int size) {
//    if (size <= 1)return;
//    T** arrPointers = new T * [size];
//    for (int i = 0; i < size; i++) {
//        arrPointers[i] = &arr[i];
//    }
//    quickSortStep(arrPointers,size);
//    for (int i = 0; i < size; i++)
//    {
//        arr[i] = *arrPointers[i];
//    }
//    delete[] arrPointers;
//}


template<typename T>
int getPivotIndex(T arr[], int startIndex,int backIndex) {
    if (backIndex - startIndex + 1 <= 2) {
        return startIndex;
    }
    int index1 = startIndex;
    int index2 = startIndex + 1;
    int index3 = backIndex;

    if (arr[index1] < arr[index2] && arr[index3] < arr[index1] || arr[index1] < arr[index3] && arr[index2] < arr[index1])
        return index1;
    if (arr[index2] < arr[index1] && arr[index3] < arr[index2] || arr[index2] < arr[index3] && arr[index1] < arr[index2])
        return index2;
    if (arr[index3] < arr[index1] && arr[index2] < arr[index3] || arr[index1] < arr[index3] && arr[index3] < arr[index2])
        return index3;

    return backIndex;
}




template<typename T>
void quickSort(T arr[], int startIndex, int endIndex) {
    int size = endIndex - startIndex + 1;
    if (size <= 1) return;
    if (size <= 10) {
        indexedSelectionSort(arr, startIndex,endIndex);
        return;
    }
    int pivotIndex = getPivotIndex(arr,startIndex,endIndex); //bruk getPivot og sett pivoten bakerst i arrayet
    swap(arr[pivotIndex], arr[endIndex]);
    pivotIndex = endIndex;
    //int pivotIndex = endIndex;
    int finalPivotIndex = 0;
    T pivot = arr[pivotIndex];
    //cout << "Pivot = " << pivot << endl;
    int lessIndex = startIndex;
    int greatIndex = endIndex;
    //bool didSwap;
    while (lessIndex+1<greatIndex) {
        //didSwap = false;
        while (arr[lessIndex] < arr[pivotIndex]&&lessIndex+1<greatIndex) {
            lessIndex++;
        }
        while (arr[pivotIndex] <= arr[greatIndex]&&greatIndex-1>lessIndex) {
            greatIndex--;
        }
        if (arr[greatIndex] < arr[lessIndex]) {
            swap(arr[lessIndex], arr[greatIndex]);
            //didSwap = true;
            
        } 
    }
    /*if (!didSwap) {
        greatIndex = lessIndex;
        lessIndex--;
    }
    if (arr[pivotIndex] < arr[greatIndex]&&didSwap)
        swap(arr[pivotIndex], arr[greatIndex]);*/
    if (arr[pivotIndex] < arr[lessIndex]) {
        swap(arr[pivotIndex], arr[lessIndex]);
        finalPivotIndex = lessIndex;
    }
    else {
        swap(arr[pivotIndex], arr[greatIndex]);
        finalPivotIndex = greatIndex;
    }
    quickSort(arr, startIndex, finalPivotIndex-1);
    quickSort(arr, finalPivotIndex + 1, endIndex);

}

int main()
{
    
    long size = 1000000;

    int preTime = 0;
    int postTime = 0;
   
    for (int n = 0; n < 1;n++) {
        srand(int(time(NULL)));
        int* arrM = new int[size];
        int* arrQ = new int[size];
        /*int* arrSh = new int[size];
        int* arrS = new int[size];*/
        
        for (int i = 0; i < size; i++) {
            char rNumber = rand() % 25+65;
            arrM[i] = rNumber;
            arrQ[i] = rNumber;
            /*arrSh[i] = rNumber;
            arrS[i] = rNumber;*/
        }
        

        /*for (int i = 0; i < size; i++) {
            cout << arrM[i] << " ";
        }*/
        cout << endl;
        auto start = high_resolution_clock::now();
        mergeSort(arrM, 0,size-1);
        auto finish = high_resolution_clock::now();
        
        duration<long double> elapsed = finish - start;
        long double elap = elapsed.count();
        /*for (int i = 0; i < size; i++) {
        cout << arrM[i]<< " ";
        }*/
        cout << endl;
        cout << "Merge sort took " << elap*1000 << " ms" << endl;

        preTime = clock();
        quickSort(arrQ, 0,size-1);
        postTime = clock();
        /*for (long i = 0; i < size; i++) {
            cout << arrQ[i] << " ";
        }
        cout << endl;*/

        cout << "Quick sort took " << postTime - preTime << " ms" << endl;
        delete[]arrM;
        delete[]arrQ;
        srand(1);
    }
    
   /* preTime = clock();
    selectionSort(arrS, size);
    postTime = clock();
    cout << "Selection sort took " << postTime - preTime << " ms" << endl;*/

    

    /*preTime = clock();
    shellSort(arrSh, size);
    postTime = clock();
    cout << "Shell sort took " << postTime - preTime << " ms" << endl;*/

    
}

