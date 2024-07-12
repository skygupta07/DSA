/* either friend can go single or can pair up, find out number of ways in which n friends
can go to party

think about the perspective of nth friend-> can go single + can pair up(with boy or girl)
// base case -> if (n==1) return 1
if (n==2) -> (a ,b) (ab) return 2

if (n==3) -> as per c perspective-> c saying me akele jaunga + ab bahut hua mujhe bhi pair banana hai
c,(a,b)  c,(ab)  (ca)b  (cb)a    return 4


f(n) = f(n-1) + (n-1)c1*f(n-2)

jab pair banaya to apne saath ek aur bande ko khaa gaya ...so ab n-2 number of friends 
apna fn call karke dekh lo..'

=== f(n) = f(n-1) + (n-1)*f(n-2)


f(n) -> returns the number of way such that n friends can go to party...
if nth friend decided to go single  and baache hue n-1 friends apna 
dekh lena....(yaha nth friend har baar single single baad mai lag jaa raha hogaa...)

+ if nth friend decided to pair up then he has to choose 1 friend from remaining n-1 friends and 
then remaining n-2 friends apna dekh lo tum....















*/