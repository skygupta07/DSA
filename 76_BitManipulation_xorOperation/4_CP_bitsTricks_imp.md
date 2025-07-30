# Bitwise Tricks and Optimizations

## 1. Check if a Number is Odd or Even

### Standard Approach:

- Perform modulo operation with `2`.

```cpp
if (n % 2 == 0) {
    cout << "Even";
} else {
    cout << "Odd";
}
```

- If remainder = 0 → Even
- If remainder = 1 → Odd

### Optimized Approach (Bitwise Trick):

```cpp
if (n & 1) {
    cout << "Odd";
} else {
    cout << "Even";
}
```

- The `& 1` operation extracts the least significant bit (LSB):
  - If LSB is `1` → Odd
  - If LSB is `0` → Even

---

## 2. Check if a Number is a Power of 2

### Trick:

```cpp
if (n > 0 && (n & (n - 1)) == 0) {
    cout << "Power of 2";
} else {
    cout << "Not a Power of 2";
}
```

### Explanation:

- `n & (n - 1)` removes the rightmost set bit.
- If the result is `0`, then `n` is a power of 2 (e.g., `8 = 1000`, `8-1 = 0111`, `8 & 7 = 0000`).
- **Edge Case:** This fails for `n = 0`, so we check `n > 0`.

---

## 3. Working with the kth Bit

### a) Check if kth Bit is Set

```cpp
if (x & (1 << k)) {
    cout << "kth Bit is Set";
} else {
    cout << "kth Bit is Not Set";
}
```

### b) Toggle the kth Bit

```cpp
x ^= (1 << k);
```

### c) Set the kth Bit

```cpp
x |= (1 << k);
```

### d) Clear the kth Bit

```cpp
x &= ~(1 << k);
```

---

## 4. Multiply or Divide by a Power of 2

### Multiply `x * 2^k`

```cpp
x << k;   // Equivalent to x * (2^k)
```

### Divide `x / 2^k`

```cpp
x >> k;   // Equivalent to x / (2^k)
```

---

## 5. Compute `x % 2^k` - ratna padega... prove to karke dekh liya...
matlab simply 2powk - 1 se AND hi kar do bhai...

```cpp
x & ((1 << k) - 1);
```

### Explanation:

- `(1 << k) - 1` creates a mask of `k` ones (e.g., `k=3` → `00000111`).
- `x & mask` gives the remainder when divided by `2^k`.

---

## 6. Swap Two Numbers Without a Temporary Variable

```cpp
a ^= b;
b ^= a;
a ^= b;
```

### Explanation:

- `a^b` flips bits where `a` and `b` differ, effectively swapping them.

---

## 7. XOR Set Bit Property

### Given:

- `x = count of set bits in A`
- `y = count of set bits in B`
- `z = count of set bits in A ^ B`

#### Property:

- If `x + y` is even → `z` is even
- If `x + y` is odd → `z` is odd

---

## 8. Replace `x = A` with `B` and `x = B` with `A`

```cpp
x = A ^ B ^ x;
```

---

## 9. Add Two Numbers Without `+` Operator

### Using Bitwise Operators:

```cpp
while (b != 0) {
    int carry = a & b;
    a = a ^ b;
    b = carry << 1;
}
```

### Explanation:

- `a ^ b` → Sum without carry
- `a & b` → Carry bits
- `carry << 1` → Shift carry for next addition

---

## 10. Count Number of Set Bits in a Number

```cpp
int count = __builtin_popcount(x);  // For int
long long count = __builtin_popcountll(x);  // For long long
```

### Explanation:

- Built-in GCC function that counts `1s` in the binary representation of `x`.

---

## 11. Remove the Last Set Bit (Rightmost 1)

```cpp
x = x & (x - 1);
```

### Explanation:

- This operation removes the lowest `1` bit in `x` efficiently.

---

### Additional Notes:

- `1 << k` → Gives `2^k` in binary (e.g., `1 << 3` → `1000`)
- `2^k - 1` → Gives all bits set below `k` (e.g., `3 = 011`, `7 = 0111`)

---

### Summary Table:

| Operation          | Expression                |
| ------------------ | ------------------------- | --------- |
| Check Even/Odd     | `n & 1`                   |
| Power of 2 Check   | `n & (n - 1) == 0`        |
| Set kth Bit        | `x | (1 << k)`            |
| Clear kth Bit      | `x & ~(1 << k)`           |
| Toggle kth Bit     | `x ^ (1 << k)`            |
| Multiply by `2^k`  | `x << k`                  |
| Divide by `2^k`    | `x >> k`                  |
| `x % 2^k`          | `x & ((1 << k) - 1)`      |
| Swap Two Numbers   | `a ^= b; b ^= a; a ^= b;` |
| Remove Rightmost 1 | `x & (x - 1)`             |
| Count Set Bits     | `__builtin_popcount(x)`   |
