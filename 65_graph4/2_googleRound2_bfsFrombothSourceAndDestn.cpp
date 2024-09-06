/*
you are given an undirected and unweighted graph, with a source and destination node.
every edge has a color either red or blue. find the shortest path between source and 
destination such that: 

1. the path always starts at a red edge and ends at blue edge.
2. you can shift from red edge to blue edge only once...
3. there are no self loops or multiple edges...

soln 

there will be a intermediate node jiske left mai saari red node hongi..
and right mai blue node hongi...

ek baar ko source and destination ko chodd kar sabko intermediatory node maana..
and source se single source shortest path lagaya saari node tak ka...

now destination ko source maan ke waha se bfs lagaya..aur ab bas kewal blue hi node 
pe traverse kara...

now har node par in dono d1+d2 distance ka sum nikala...jo bhi min. hoga.. wo 
return karna hoga.



*/






/*

given an undirected , unweighted graph, a source and destination. find all nodes 
which come in atleast one shortest path from source to destination...

soln -> source se and destination se bfs chalao....and har node tak ka
shortest path store karo...

then jo bhi minimum sum hoga wo wala path answer mai include hoga...



*/