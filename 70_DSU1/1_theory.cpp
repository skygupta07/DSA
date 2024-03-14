/*
helps to solve clustering/grouping like problem
-> you will be having some element and you need to aggregate/add them in different 
groups/clusters, and sometimes we neglect need to identify the group any elements 
belong to..

-> helps to solve connected component problem 
-> leader/parent of group -> to uniquely identify a group we will pick any element 
from the group and make it the representation/leader/parent of the group...

-> leader ke naam se hi group jaana bhi jaega -> i.e. group of A

-> what fn dsu need to support? -> union and find operation
ans-> union(a,b)-> adds the group where element B belongs to the group where element
A belongs or vice-versa

union(1,5) -> matlab 5 jis bhi group ko belong karta hai....usko laake mai 1 ke group 
mai jod dunga...aur final group ka representative 1 hi hoga(#baap)

find operation -> this will be used to find which group x belongs to...
we will return the parent of the group that x belongs to....

-> dsu supports mainly these two operations, the reason why it is also called
union find algorithm...

*/



/*
approac1 -> represent every group as a set


approach2 -> can we use array?
indexes represent actual element!!!
while values in array denote which group i belong to i.e. par[i]
-> initially jab koi group nahi baney hai tab to sab apne hi group se belong kar rahe hai..
array approach mai 
union opern t.c. = O(n)
find opern t.c. = O(1)

approach3 -> (doubly linked list) dll based 
find O(n) union O(1)

above approach inefficient coz in worst case there can be n replacements

union(4,3) -> union of 4 comma 3 ka matlab hai ki jin jin elements ka parent 3 hai
unke parents ko 4 kardo....


*/

/*
apprach 4->to improve we have union by size 
-> simply merge smaller group into larger group...
-> yaha par number of updates kam ho jaenge....
->  1 pehli baar 1 size wale se update hoga then 2 size wale se then 4 size wale se hi 
update ho payega kewal...
i.e. on avg each element will now be updated only logn times only..

-> we have tree data structure to represent parent child relationship there...
now bas simply link laga do...
-> ab yaha sabka parent directly nahi milega ...ek se dusre mai jump karna hoga jab
tak ki self loop na mile ab wo hi parent hoga...



approach 5 ->union by rank
jitni baar 1 (for e.g) update hona tha utni hi baar linking bhi add ho rahi..
i.e. log(n) times.

initially sabki rank 1
smaller rank waala bigger rank wale mai merge hoga...

approach 6 (one more optimization) -> union by rank/size with path compression

// jab reucrsive call base case hit karta hai tab har step wo koi value return karta hai...
simply aap seedhe sabko parent se hi attach kar do na...itne mediator kyu chahiye...

find fn find karte huye hi parent ko bhi maintain karte gaye and this optimisation 
makes the algo run in almost constant time as per inverse ackermann fn 
t.c. O(log*n) logstarn   ->in how many operation you can reduce n to less than 1 by
taking log again and again









*/