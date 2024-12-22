/*
given a grid of n*m size. every cell of the grid is marked as
'L', 'R', 'U', 'D' . character on a cell denotes that if you are standing at that cell
then in which direction you can move to....

check if we start from cell (0, 0) can we reach to cell marked (n-1, m-1)
constraint : space : O(1) and matrix is not modifiable...


solution -> instead of thinking about that if we can reach ....we should think
in which case we would not be able to reach...else in other cases i would be able to reach...
agar mai kahi loop mai fas gaya tab nahi pahuch paunga...


--- there wouldn't be any cycle if it is possible to reach destination...
we will get a cycle if we revisit a cell twice....

worst case mai bhi n*m steps hi travel karte aap 
agar n*m se jyada step count kiye hai to paaka cycle thi....


----approach2 ----

hare and tortoise soln (slow fast pointer) -> O(1) space -> googlel
slow = slow->next 
fast = fast->next->next;

if at any point slow and fast meet, then there is cycle return false ...
while in case if fast goes out of the grid..then you can reach the destination...



*/