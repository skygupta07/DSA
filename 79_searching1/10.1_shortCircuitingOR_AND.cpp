/*
 ->> In an OR operation, if the first condition evaluates to TRUE, 
    the second condition is not evaluated at all.
This is because the result of an OR operation will always be true if any one of the conditions is true.

(application -> aisa question jisme array out of bound bhi check karna h... and dusri condition bhi check 
karni h to better is ki if statement mai aap pehle index out of bound wali condition pehle daal de then 
OR laga ke next condition likh liya kare...) {rule derived from bvc bounded visited condition}

->> In an AND operation, if the first condition evaluates to FALSE, 
the second condition is not evaluated. This is because for AND to be true, 
both conditions must be true. So if one fails, the whole expression is guaranteed to be false.

->> Conditions are evaluated from left to right.

->> The AND operator has a higher precedence than the OR operator
*/