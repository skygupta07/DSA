/*

in singly ll, if you are at node then you can you never go back => dll used
dll is a kind of capsule containing pointer to previous node, the data and 
the pointer to next node also...

-> yaha head ka prev aur tail ka next null hoga
-> koi aur null ko point kar sakta hai.. but null kabhi kisi ko point nahi karta...

advantage:
1. reversal of linked list becomes easy..
2. if any node of linked list is given, we can traverse through the entire list..

bol bachhan ki tarah ek dum aakhri node pe jaake agar rukna hai to...
while (temp->next != NULL) ki condition lagao...

aur agar puri length naapni ho ya har node ke liye computation karni ho to ...
while (temp != NULL)
*/