int search(int sortedArray[], int toFind, int len) 
{
    // Returns index of toFind in sortedArray, or -1 if not found
    int low = 0;
    int high = len - 1;
    int mid;

    int l = sortedArray[low];
    int h = sortedArray[high];

    while (l < toFind && h > toFind) {
        mid = low + ((int)(high - low)*(int)(toFind - l))/(1+(int)(h-l));

        int m = sortedArray[mid];

        if (m < toFind) {
            l = sortedArray[low = mid + 1];
        } else if (m > toFind) {
            h = sortedArray[high = mid - 1];
        } else {
            return mid;
        }
    }

    if (l == toFind)
        return low;
    else if (h == toFind)
        return high;
    else
        return -1; // Not found
}