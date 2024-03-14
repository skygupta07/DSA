/*
1. shallow copy -> copy hai but independent nahi hai...matlab pehle ke changes dusre mai
reflect honge..

2. deep copy -> independent..

-> copy constructor used to copy objects
IMPORTANT

copy constructor mai variable are always passed by reference only...
reason because aapne agar pass by value de diya to phir wo copy jaegi and aap copy
hi create karne jaa rahe they...which means ye to infinite loop mai fas jaoge...

Bike (Bike &b){
    
}
*/


/*
Bike b1(5,100);
Bike b2; 
b2 = b1; // shallow copy banegi => not independent....


-------------------
Bike b2 = b1; // deep copy (reason because it is copy constructor)
Bike b2(b1); // deep copy since b1 pass kar diya






*/