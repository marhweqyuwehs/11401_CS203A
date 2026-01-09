# 陣列(Array)

## 定義(Definition)

- **陣列(Array)**是一種用來儲存相同**資料型別(data type)**的元素的資料結構。
- 每個元素都可以透過**索引（index）**直接存取。
- 資料在記憶體中是**連續配置**的。

## Visualization
```c
Array: [   ]   [   ]    [   ]     [   ]     [   ]     [   ]  
Index:   0       1        2         3         4         5      
```

## 抽象資料型別(ADT)
- **Create(n)**:建立大小為 n 的陣列。
- **Access(A,i)**:取得索引 i 的元素。
- **UPdate(A,i,x)**:修改索引 i 的值為 x。
- **Insert(A,i,x)**:在索引 i 插入 x。
- **Delete(A,i)**:刪除索引 i 的元素。
- **Traversal(A)**:依序走訪所有元素。
- **Search(A,x)**:搜尋值 x 的位置。

## Array Declaration
### Static Array
#### Declaration
```c
// 1D array with five elements
int array[5];
```
#### Initialization
```c
// Initialize the integer array with 10, 20, 30, 40, 50
int array[5] = {10, 20, 30, 40, 50};

// Initialize by for loop
for (int i = 0; i < 5; i++) {
    array[i] = i + 1;
}
```

#### Access
```c
// Retrieve the third element from array
printf("%d", array[2]);
```

#### Traverse
```c
// Traverse the entire array and print
for (int i = 0; i < 5; i++) {
    printf("%d", array[i]);
}
```
### Dynamic Array

#### Declaration
```c
// Dynamic array initialization by malloc()
int *array;
int n = 10;
array = (int *) malloc(n * sizeof(int));
```

#### Initialization
```c
// Initialize by for loop
for (int i = 0; i < n; i++) {
    array[i] = i + 1;
}
```

#### Access
```c
// Access the element by index
for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
}
```

#### Traverse
```c
// Traverse the entire array and print
for (int i = 0; i < 5; i++) {
    printf("%d", array[i]);
}
```
### Resize
 >調整動態陣列的大小，可以使用**realloc**函式重新配置記憶體空間

```c
int *array;
int n = 10;
array = (int *) malloc(n * sizeof(int));

// Initialize the array
for (int i = 0; i < n; i++) {
    array[i] = i + 1;
}

// Double the size of the array
n = n * 2;
int *temp = (int *) realloc(array, n * sizeof(int));

if (temp == NULL) {
    free(array);
    return -1; // Handle memory allocation failure
}

array = temp;

// Initialize the new elements
for (int i = n / 2; i < n; i++) {
    array[i] = i + 1;
}
```

## 搜尋(search)
- linear Search
  - 逐一比對
  - 適用未排序陣列
  - **時間複雜度**：O(n)
- BInary Search
  - 需先排序
  - 每次縮小搜尋範圍
  - **時間複雜度**：O(log n)
## 排序(Sorting)
### Bubble Sort
- 比較相鄰元素，大的往後交換
- **時間複雜度**: 
  - Best:O(n)
  - Average:O(n²)
  - Worst:O(n²) 
### Selection Sort
- 每一輪從未排序區間中選出最小值，放到正確位置
- **時間複雜度**:
  - Best:O(n²) 
  - Average:O(n²) 
  - Worst:O(n²) 
### Insertion Sort
- 將元素插入到已排序的區間中
- **時間複雜度**:
  - Best:O(n)
  - Average:O(n²) 
  - Worst:O(n²) 

## 時間複雜度(Time complexity)

| 操作 |複雜度|說明|
| --- | --- | --- |
| **Access** | O(1) | 存取值 |
| **Update** | O(1) | 更新 |
| **Traversal** | O(n) | 遍歷Array |
| **Insert** | O(n) | 插入 |
| **Delete** | O(n) | 刪除 |
| **Search** | O(n)/O(logn)|排序/未排序|


## 優缺點（Advantages & Disadvantages）
### 優點（Advantages）
- 隨機存取快
  - 透過 index 存取，時間複雜度 O(1)
- 記憶體連續
  - Cache 友善，效能佳
  

 ### 缺點（Disadvantages）
- 大小固定
   - Static Array 無法調整大小
- 插入與刪除效率差
  - 需要位移元素，O(n)