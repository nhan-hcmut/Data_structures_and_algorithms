#include<iostream>
#include<algorithm>
using namespace std;

// used for sorting
struct Element {
    int value, index, freq;
};

// used for sorting by value
bool isSmaller(const Element& firstEle, const Element& secondEle) {return firstEle.value < secondEle.value;}

// used for sorting by frequency. If frequencies are the same, then sort by appearances
bool moreFrequentSmallerIndex(const Element& firstEle, const Element& secondEle) {
    if (firstEle.freq != secondEle.freq)
        return firstEle.freq > secondEle.freq;
    else
        return firstEle.index < secondEle.index;
}

void sortByFrequency(int arr[], int n) {
	Element* elements = new Element[n];
    
    for (int i = 0; i < n; i++) {
        // fill indexes in struct Element
        elements[i].index = i;

        // initialize frequencies as 0
        elements[i].freq = 0;

        // fill values in struct Element
        elements[i].value = arr[i];
    }

    /* sort array elements[] by value to move duplicate numbers next to each other. We use stable sort to preserve the relative order */
    stable_sort(elements, elements + n, isSmaller); // stable_sort in <algorithm> library

    /* initialize frequency of the first element as 1 */
    elements[0].freq = 1;

    /* count occurrences of remaining numbers */
    for (int i = 1; i < n; i++) {
        if (elements[i].value == elements[i - 1].value) {
            elements[i].freq += elements[i - 1].freq + 1;

            /* set frequency of previous element as 0 because we'll sort again by frequency (if frequencies are equal, then by index) */
            elements[i - 1].freq = 0;

            /* retain the first index. Remember the first index is always present in the first duplicate number because we use stable sort */
            elements[i].index = elements[i - 1].index;
        }

        /* if previous number is not equal to current one, set the frequency to 1 */
        else
            elements[i].freq = 1;
    }

    /* now we have frequency and the first index of each number.
       We sort the array by frequency. if frequencies are the same, we sort by index
    */
    stable_sort(elements, elements + n, moreFrequentSmallerIndex); // stable_sort in <algorithm> library
    
    for (int i = 0, y = 0; i < n && y < n; i++) {
        if (elements[i].freq == 0) break;

        for (int j = 0; j < elements[i].freq; j++)
            arr[y++] = elements[i].value;
    }
    delete[] elements;
}

int main() {

    // Test	1
	int arr[] = {-4, 1, 2, 2, -4, 9, 1, -1};
	int n = sizeof(arr) / sizeof(arr[0]);

	sortByFrequency(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " "; // Result: -4 -4 1 1 2 2 9 -1

    /* Test	2
	int arr[] = {-5, 3, 8, 1, -9, -9};
	int n = sizeof(arr) / sizeof(arr[0]);

	sortByFrequency(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " "; // Result: -9 -9 -5 3 8 1
    */
    return 0;
}
