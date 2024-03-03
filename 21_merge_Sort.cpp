
void merge(vector<int>&arr, int l, int mid, int h){
    int s1 = mid-l+1;
    int s2 = h-mid;

    int *arr1 = new int[s1];
    int *arr2 = new int[s2];

    

    for(int i=0; i<s1; i++) arr1[i] = arr[l+i];

    for(int i=0; i<s2; i++) arr2[i] = arr[mid+i+1];

    int i =0,j=0,k=l;

    while(i < s1 && j < s2){
        if(arr1[i] < arr2[j]) arr[k++] = arr1[i++];
        
        else arr[k++] = arr2[j++];
    }

    while(i < s1 ) arr[k++] = arr1[i++];

    while(j < s2 ) arr[k++] = arr2[j++];
}

void sort(vector<int>&arr, int l, int h){
    if(l < h){
        int mid = l + (h-l)/2;

        sort(arr, l, mid);
        sort(arr, mid+1, h);
        merge(arr, l,mid,h);
    }
}

void mergeSort(vector < int > & arr, int n) {
    sort(arr, 0, n-1);
}
