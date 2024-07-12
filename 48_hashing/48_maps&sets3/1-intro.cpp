/*
imagine we are given a array of huge size and someone is continuously asking us the 
number of occurences or frequency of numbers then instead of iterating over the array
each time we can simply use the unordered map and store its frequency...

-> usually array of 10^8 numbers take 1 second => 10^10 will take 100 seconds...
-> hashing === prestoring/fetching..

-> you can't declare more than array of size to be 10^5

->inside main fn you can declare int of size 10^6
-> globally you can declare int of size 10^7

-> inside main fn you can declare bool of size 10^7 and globally 10^8.....

-> if you declare globally then bydefault it is initialised with zero...

-> character mapping for lower case alphabet... lets take the size of hash array to 
be of 26 characters..

-> when we subtract two characters actually we are subtracting there ascii values...
-> for lowercase alphabet a subtract kiya...
-> hash[s[i]]  => here s[i] will be autocasted to integer from the character...

-> but instead of using the hash array we use the unordered map because it is memory
efficient 



unordered_map<> // Keys are not sorted O(1) - worst case O(n)
map<>  // Keys are sorted O(logn)

// Traverse the Map
for(auto it:map){
   // it.first  -> key
   // it.second -> value
}

// Existence of a Key Check
if(map.count(key)>0) cout<<"Yes"<<endl;



*/