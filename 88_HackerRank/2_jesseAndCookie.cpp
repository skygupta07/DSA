 #include <iostream>
 #include <vector>
 using namespace std;
 int main(){
 
 }
 

 
 
 int cookies(int k, vector<int> A) {
    priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
    int ops = 0;

    while (pq.size() > 1 && pq.top() < k) {
        int smallest = pq.top();
        pq.pop();
        int smaller = pq.top();
        pq.pop();

        pq.push(smallest + 2 * smaller);
        ops++;
    }

    // Check the last remaining cookie
    if (pq.top() >= k) {
        return ops;
    } else {
        return -1;
    }
}