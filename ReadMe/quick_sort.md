# 快速排序

## C实现
```c
int partition(int low, int high){
    int key = l[low];
    while(low < high){
        while(low < high && l[high] > key) high --;
        l[low] =  l[high];
        while(low < high && l[low] < key) low ++;
        l[high] =  l[low];
    } 
    l[low] = key;
    return low;
}

void qsort(int low, int high){
    if(low < high){
        int pos = partition(low,high);
        qsort(low,pos-1);
        qsort(pos+1,high);
    }
}
```
