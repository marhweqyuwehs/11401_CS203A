# 圖(graph)

## 定義(Definition)

圖(graph)是一種用來表示關係的資料結構，定義為：
> G = (V, E)
- **V (Vertices)**：點
- **E (Edges)**：邊

## 常見術語(Terminology)
- **Vertex (Node)**：頂點
- **Edeg**：邊
- **Degree**：度
- **In-degree / Out-degree**：有向圖的入度 / 出度
- **Path**：路徑
- **Subgraph**：子圖
- **Isomorphic Graphs**：同構圖（結構相同）

## 種類（Classification）
- **Connected Graph**：連通圖，任兩點可達
- **Undirected Graph**:無向圖
- **Directed Graph**:有向圖
- **Weighted Graph**:加權圖
- **Unweighted Graph**:無加權圖
- **Cyclic Graph**:循環圖

## 表示法(Representation)
分別是 Adjacency Matrix(鄰接矩陣) 和 Adjacency List(鄰接串列)
### 1.Adjacency Matrix(鄰接矩陣)
- 使用 V × V 矩陣
- matrix[i][j] = 1 / weight 表示存在邊
優點
- O(1) 查詢是否有邊
- 適合 Dense Graph
缺點
- 空間複雜度 O(V²)
- Sparse Graph 浪費記憶體

### 2.Adjacency List(鄰接串列)
- 每個頂點只存相鄰的節點

優點
- 空間 O(V + E)
- BFS / DFS 效率高
- 適合 Sparse Graph
缺點
- 查詢是否存在特定邊需 O(deg(v))

## 圖走訪(Graph Traversal)

### Breadth-First Search(BFS)
- 使用**Queue(FIFO)**
- 由近到遠、分層走訪
- 常用於：最短路徑

### Depth-First Search(DFS)
- 使用**Stack/Recursion**
- 一條路走到底再回溯
- 常用於：cycle 偵測、拓樸排序


## 時間複雜度(Time Complexity)

| 操作 | Matrix | List |
| --- | --- | --- |
| **spsace Complexity** | O(V²) | O(V + E) |
| **Insert edge** | O(1) | O(1) |
| **Delete edge** | O(1)| O(deg(u)) |
| **neighbor** | O(1) | O(deg(u)) |
| **BFS** | O(V²) | O(V + E) |
| **DFS** | O(V²) | O(V + E) |
| **Edge lookup (u, v)** | O(1) | O(deg(u)) |

