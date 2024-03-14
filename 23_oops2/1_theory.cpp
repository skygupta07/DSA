/*

I used class concept and created user defined data type => ki mai ab iska object
(little bit like variable) bana sakta hu...

scope resolution operator (::) se to accha hai ki aap this (->) operator ka use karo..

normal jab variables bante they tab unke liye memory compile time pe hi allocate ho jaati
thi like int ke liye 8 bytes but class to ek bluePrint hai => memory is only assigned 
when we create a object for that class

-> you can actually pass class in function parameter...
-> mai kisi object ko pura pura aise print to nahi kara sakta...=> usko pehle kisi 
object mai store kar then aage kucch karna 

// STATIC VS DYNAMIC memory allocation
you can't always preDecide that there will be this much amount of memory usage this time
you can't assume ki 100 hi player aaenge maybe 1000 players aae ya kewal 10 hi
players aa paye..






when a program is compiled then->
1. compilation error is detected
2. memory is allocated to variables  
=> in all this stack memory is used on compile time...
=> and heap memory is used on runtime =>for realtime memory allocation...
=> new <anydataType> issey heap mai se memory allocate hogi...
-> basically are pointers are used for dynamic memory allocation



-> agar aapke paas normal object hai tab to aap simply dot operator ka use karke value
fetch kar lo...
-> but agar aapke paas pointer object aaya tab to bhaiya -> operator use karo 
-> linked list wagera mai bhi daba ke pointers urf dynamic memory allocation ka game

// nested class use 
// this -> currently waale class ka...
// array of object can be created...

*/