# **Bit Manipulation Tricks & XOR Properties**

## **1️⃣ Find the Only Non-Repeating Element (Every Other Element Repeats Twice)**

### **Intuition:**
- XOR cancels out **same numbers** (`a ⊕ a = 0`).

- Remaining number after XORing **all elements** will be the unique one.

### **Approach:**
1. Initialize `ans = 0`. (kyuki zero ke saath xor karne se koi pharak nahi padta...)
2. Iterate through the array and XOR all elements.
3. The final value of `ans` will be the non-repeating element.

### **Code Implementation (C++):**
```cpp
int findUnique(vector<int>& arr) {
    int ans = 0;
    for (int num : arr) {
        ans ^= num;  // XOR all elements
    }
    return ans;
}
```
### **Example:**
```
Input:  [4, 1, 2, 1, 2]
Step-by-step XOR:
    4 ⊕ 1 ⊕ 2 ⊕ 1 ⊕ 2
    = (4 ⊕ 1 ⊕ 1) ⊕ (2 ⊕ 2)
    = 4 ⊕ 0 ⊕ 0
    = 4  ✅
Output: 4
```
### **Time Complexity:** `O(n)`
### **Space Complexity:** `O(1)`

---

## **2️⃣ Find Two Non-Repeating Elements (Every Other Element Repeats Twice)**

### **Intuition:**
- After XORing all elements, we get `XOR = a ⊕ b` (where `a` and `b` are the two unique numbers).
- Find **any set bit** in `XOR` (let's say at position `i`).
- Use this bit to divide numbers into **two groups**:
  - Group 1: Elements where `i-th` bit is **set (1)**.
  - Group 2: Elements where `i-th` bit is **unset (0)**.
- XOR within each group → gives `a` and `b`.

### **Approach:**
1. Compute `xorAll = XOR of all elements`.
2. Find **rightmost set bit** in `xorAll`.
3. Divide numbers into two groups **based on that bit**.
4. XOR elements within each group → gives `a` and `b`.

### **Code Implementation (C++):**
```cpp
vector<int> findTwoUnique(vector<int>& arr) {
    int xorAll = 0;
    for (int num : arr) xorAll ^= num;  // Step 1: XOR all elements

    int rightmostSetBit = xorAll & -xorAll;  // Step 2: Find rightmost set bit

    int x = 0, y = 0;
    for (int num : arr) {
        if (num & rightmostSetBit) x ^= num;  // Group 1
        else y ^= num;  // Group 2
    }
    return {x, y};
}
```
### **Example:**
```
Input: [4, 1, 2, 1, 2, 5]
Step-by-step XOR:
    4 ⊕ 1 ⊕ 2 ⊕ 1 ⊕ 2 ⊕ 5 = (4 ⊕ 5) = 0010 ⊕ 0101 = 0111 (7)

Rightmost set bit: 1st bit (0b0001)

Partition:
    Group 1 (set bit at position 1): [1, 1, 5]  → XOR = 5
    Group 2 (unset bit at position 1): [4, 2, 2] → XOR = 4

Output: [4, 5] ✅
```
### **Time Complexity:** `O(n)`
### **Space Complexity:** `O(1)`

---

## **3️⃣ Find the Only Non-Repeating Element (Every Other Element Repeats Thrice)**
### **Intuition:**
- Every bit position (0 to 31) will have counts **as multiples of 3**, except for the unique element.
- We can **count bits at each position** and take modulo `3` → if `count % 3 != 0`, that bit belongs to the unique number.

### **Approach:**
1. Create a **32-bit frequency array** `bitCount[32]`.
2. Count occurrences of `1` at each bit position.
3. If `bitCount[i] % 3 != 0`, set that bit in the final answer.

### **Code Implementation (C++):**
```cpp
int findUniqueInThrice(vector<int>& arr) {
    int bitCount[32] = {0};

    for (int num : arr) { // array ke har number pe gaye..
        for (int i = 0; i < 32; i++) {  // uss number ki har bit par gaye...
            if (num & (1 << i)) bitCount[i]++; // agar wo bit set h to phir hum bhi bitCount mai bit ka count increase kar dete h 
        } 
    }

    int ans = 0;
    for (int i = 0; i < 32; i++) {
        // agar ith bit 3 baar nahi aa rahi hogi... to phir answer ki ith bit set kar denge....
        if (bitCount[i] % 3 != 0) {
            ans |= (1 << i);
        }
    }
    
    return ans;
}
```
### **Example:**
```
Input: [2, 2, 3, 2]
Bit representation:
    2 → 0010
    2 → 0010
    3 → 0011
    2 → 0010
Bit counts:
    0th bit: 1   (odd → 1)
    1st bit: 4   (multiple of 3 → 0)
    2nd bit: 0   (multiple of 3 → 0)
    3rd bit: 0   (multiple of 3 → 0)

Final result = 0011 (3)
Output: 3 ✅
```
### **Time Complexity:** `O(n)`
### **Space Complexity:** `O(1)`

---

## **Properties of XOR (`⊕`)**
| Property | Explanation |
|----------|------------|
| `a ⊕ a = 0` | XOR of same number is 0 |
| `a ⊕ 0 = a` | XOR with 0 doesn’t change the number |
| `a ⊕ b = b ⊕ a` | XOR is **commutative** |
| `a ⊕ (b ⊕ c) = (a ⊕ b) ⊕ c` | XOR is **associative** |

---

## **Why XOR Works for Finding Unique Elements?**
1. **Repeating elements cancel out:** Since `x ⊕ x = 0`, duplicate elements become zero.
2. **Remaining unique elements stay:** The leftover non-repeating elements remain because they **don’t have a duplicate** to cancel out.