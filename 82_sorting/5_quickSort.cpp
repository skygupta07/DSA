#include <iostream>
using namespace std;

int partition(int arr[], int si, int ei)
{
    //                  starting index , ending index
    int pivotElement = arr[(si + ei) / 2]; // choosing randomised pivot element to improve t.c.
                                           // initially first element will be considered as pivotElement
    int count = 0;

    for (int i = si + 1; i <= ei; i++)
    { // si+1 wale element se leke last tak jaaege
        if (i == (si + ei) / 2)
            continue;
        if (arr[i] <= pivotElement)
        {
            count++; // counting dekhi ki pivotElement se kitne chote elements present hai..
        }
    }
    // declaring pivot index
    int pivotidx = count + si;               // imp
    swap(arr[(si + ei) / 2], arr[pivotidx]); // pivot index ko initially sahi index pe place kiya
    int i = si;
    int j = ei;

    while (i < pivotidx && j > pivotidx)
    {
        if (arr[i] <= pivotElement)
            i++; // matlab theek hai filhaal apni jagah pe, now next index dekho..
        if (arr[j] > pivotElement)
            j--;
        else if (arr[i] > pivotElement && arr[j] < pivotElement)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotidx;
}

void quicksort(int arr[], int si, int ei)
{
    if (si >= ei)
        return; // base case..

    int pi = partition(arr, si, ei); // kaam
    // partition index

    // 5,1,8,2,7,6,3,4
    // 4,1,3,2,5,7,8,6

    quicksort(arr, si, pi - 1); // array ka division kar diya hai do parts me
                                // then un parts ko individually sort kardo...
    quicksort(arr, pi + 1, ei); // accha quick sort me bhi recursion to lag hi rahi hai..
}

int main()
{
    int arr[] = {5, 1, 8, 2, 7, 6, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// t.c. = n(logn)  avg case
//  = n^2  worst case

// pivot point starting wale element ko lene se time complexity increase kar rahi hai.
// since number of operations are: n,n-1, n-2, n-3
// 8 7 6 5 4 3 2 1
// so we can use randomized pivot

// space complexity
// not O(1);
// since there are lot of call stack function call so s.c. is O(logn)

// selection and quick are unstable sort
// uses: internal sorting by computer somewhat similar, quick select , unstability where needed

// more optimised inbuilt sorting by quick sort

// bubble, insertion, merge stable
// selection me random swaps so unstable
