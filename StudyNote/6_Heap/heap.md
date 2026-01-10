# 堆積(Heap)

## 定義(Definition)

- **堆積(Heap)**是一種**完全二元樹(Complete Binary Tree)**。
- 滿足**Heap-Order Property(堆積順序性)**。
- 主要用途:
  - Priority Queue(優先佇列)
  - 排程系統(CPU Scheduling)
  - Heapsort(堆積排序)
  - 急診病患(檢傷等級高 → 優先)

## Heap 的兩大性質

### 1.Shape Property(結構性質)

Heap 一定是 完全二元樹：
- 每一層都填滿
- 最後一層可以不滿，但 必須由左到右填入

優點:
- 可以用**陣列(Array)**直接存，不會有空洞
- 不需要指標(比一般樹結構省記憶體)

### 2.Heap-Order Property(順序性質)

**Max Heap**
- 父節點 ≥ 子節點
- 最大值一定在Root

**Min Heap**
- 父節點 ≤ 子節點
- 最小值一定在Root

## Heap 基本操作與流程(Max heap)

### 1.Insert(插入)

步驟：
- 新節點插在最後一個位置(維持完全二元樹)。
- 與 Parent 比較。
- 若子節點較大，則交換。
- 重複直到順序正確或到 Root。
- 時間複雜度：O(log n)

### 2.Extract Max(取出最大值)
步驟：
- 移除 Root
- 用**最後一個節點**補到 Root
- 與較大的子節點比較
- 若子節點較大，則交換
- 重複直到順序正確或到 LEaf
- 時間複雜度：O(log n)

## 時間複雜度(Time complexity)

| 操作 |複雜度|說明|
| --- | --- | --- |
| **peek max/min** | O(1) | Root 直接存取 |
| **insert** | O(log n) | 樹高 |
| **extract max/min** | O(log n) | 樹高 |
| **heapsort** | O(n log n)| n 次 extract |
