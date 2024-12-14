# **Graph Camp Day 1 Notes**

### **1. Breadth-First Search (BFS)**  
- **Key Concept**:  
  BFS gives the shortest path from the source node to every other node in an **unweighted graph**.  

- **Black-Box Representation**:  
  - **Input**: Unweighted graph, source node (only one source node).  
  - **Output**: List of integers representing the shortest path distance from the source to every other node.  

---

### **2. Dijkstra’s Algorithm**  
- **Key Concept**:  
  Dijkstra’s algorithm is used to find the shortest path in a **weighted graph**.  

- **Black-Box Representation**:  
  - **Input**: Weighted graph, source node.  
  - **Output**: Shortest distance from the source to every other node.  

- **Practice Goal**: Solve **at least 10 high-quality problems** to master the algorithm.  

---

### **Problem: Nearest Hospital in a Weighted Graph**  
#### **Problem Statement**:  
- Given a weighted graph with 6 cities, where 2 cities (golden-marked) have hospitals, find the **nearest hospital** from each city.  

#### **Solutions**:  

1. **Brute Force Approach**  
   - Apply Dijkstra’s algorithm separately for each city with a hospital as the source.  
   - Repeat this for all hospital nodes (N times).  
   - **Time Complexity**: (N times {Dijkstra’s complexity})  

2. **Optimal Approach**  
   - **Modify the Graph**:  
     - Add a **fake node** connected to all hospitals with edges of weight 0.  
     - Run Dijkstra’s algorithm **once** from the fake node.  
   - This ensures the shortest path from any city to its nearest hospital.  

---

### **3. Alternate Edges Problem**  
#### **Problem Statement**:  
- In a graph with **hot edges** and **cold edges**, find the shortest path from a source node to a destination node with the constraint:  
  - No two consecutive edges can be of the same type (e.g., hot-cold-hot-cold).  

#### **Solution**:  

-> kaash framework
kaas aise hota hi ek hi city mai hospital hota...
-> aisa nahi h to chalo bana dete h...

as the graph is undirected -> so shortest distance from 
E to A is shortest distance from A to E also...



1. **Modify the Graph (G')**  
   - Double the number of nodes in the graph:  
     - Connect **single-dash nodes** to **double-dash nodes** with **cold edges**.  
     - Connect **double-dash nodes** back to **single-dash nodes** with **hot edges**.  
   - Add source and target nodes at the start and end.  

2. **Apply BFS**  
   - Perform BFS on the modified graph \( G' \).  
   - Subtract 2 from the result to account for the added source and target nodes.  

#### **Why BFS Cannot Be Applied Directly?**  
- BFS doesn’t account for the **coloring constraint** (no consecutive edges of the same type).  

---

### **4. Recipe for Solving Shortest Path Problems**  
- **Smell Test**: Does the problem "smell" like a shortest path problem?  
- **Constraints Check**: Identify constraints/variables that make the problem different from standard shortest path problems (e.g., alternate edge colors).  
- **Idea Development**: Develop a strategy to eliminate constraints by modifying the graph.  
- **Apply Standard Algorithm**: Use a standard algorithm like BFS or Dijkstra after modifying the graph.  

---

### **5. Time Complexity Considerations**  
- **Scenario 1**: Running \(N\) Dijkstra’s on 1 graph.  
- **Scenario 2**: Running 1 Dijkstra’s on N modified graphs.  
- Compare and choose the optimal approach based on constraints.  

---

### **6. Parade Path Problem**  
#### **Problem Statement**:  
- Given a directed graph with edge weights:  
  - Find the shortest path of a **parade** that starts at any city and ends at any city, with the path having **exactly \(k\) roads**.  

#### **Solution Using Graph Modification**:  

1. **Smell Test**:  
   - This is a shortest path problem with constraints.  

2. **Constraint Analysis**:  
   - Must have exactly k roads.  
   - Starting from any city is allowed.  

3. **Modify Graph G'**:  
   - Create \(k+1\) copies (layers) of the original graph.  
   - Add edges between layer \(i\) and \(i+1\) with the original edge weights.  
   - Moving through layers simulates traveling exactly \(k\) roads.  

4. **Apply Dijkstra’s Algorithm**:  
   - Add a source node at the beginning and a target node at the end.  
   - Use Dijkstra’s to calculate the shortest path in the modified graph.  

---

### **7. General Insights**  
- **Two Approaches to Solve Graph Problems**:  
  1. Modify the graph and apply a standard algorithm (easier).  
  2. Keep the graph the same but modify the algorithm (tougher).  

- **Checklist for Solving Problems**:  
  - Smell test.  
  - Identify constraints and variables (masale test).  
  - Develop a strategy to eliminate constraints.  
  - Apply a standard algorithm or a modified version.  

---

### **Homework**  
- Solve the **"Chocolate Problem"** (details to be shared on WhatsApp). -> done  
- Practice **graph-based shortest path problems** asked in PhonePe.  

