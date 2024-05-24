

// tree is a non linear data structure
/// it is ideal for representing hierarchial data...

// node- basic entity
// root-> top node
// children 
// parent 
// sibling 
// ancestor -> node ke upar jitne bhi unse uska relation are their ancestors...
// descendant- babies
// leaf - no son
// internal nodes: nodes with atleast one child..
// / depth: no. of edges from root to the node.
// height: no. of edges from root to the deepest leaf...
// degree == number of child
// binary tree -> less than equal to 2 child

// tree is made up of nodes and edges
// n nodes -> n-1 edges..-> reason everyone is being pointed by other node but 
// no one is pointing the root node



// degree of a tree is the highest degree of a node among all the nodes present in the tree..


// types of Binary trees..........
// 1. Full or strict binary tree -> All nodes have either 0 or 2 child

// 2. Perfect binary tree -> Internal nodes have 2 children + All leaf nodes are on same level..
 
// 3. complete binary tree -> All levels are completely filled except possibly the last level +
                                // last level must have its key as left as possible..
// or if you represent the binary tree in form of array then there should be no gap in array

// 4. Degenerate node -> Every parent node has exactly one child

// 5. skewed trees -> i.e. in left skewed all bent towards left


/*
binary tree ko array ke format me likhoge and agar koi node missing hai to uske 
corresponding array me blank space leave kar dena hai..

properties->
1. traversing by bfs ans dfs algo
2. it has no loop no circuit no self loop

trees benefits->
1. hierarchial data structure
2. searching efficiency
3. sorting
4. dynamic data
5. efficient insertion and deletion
6. easy to implement


root, left subtree and right subtree are foundation of any tree...

-> balanced binary tree ->for every node the difference between the levels of LST 
and RST should be atmost 1...

-> null ko child mai count mat kiya karo..


















*/