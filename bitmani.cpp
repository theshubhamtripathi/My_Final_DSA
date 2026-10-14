# Bit Manipulation — C++ Quick Revision Notes

## 1. Check if a number is Odd or Even
```cpp
if (x & 1)
    cout << "Odd";
else
    cout << "Even";
```
- If `(x & 1) == 1` → Odd
- If `(x & 1) == 0` → Even

## 2. Check if a Number is a Power of 2
```cpp
if (x > 0 && (x & (x - 1)) == 0)
    cout << "Yes";
else
    cout << "No";
```
- A positive power of 2 has exactly one set bit.
- Examples: 1, 2, 4, 8, 16, 32.

## 3. Check if the Kth Bit is Set
```cpp
if (x & (1 << k))
    cout << "Set";
else
    cout << "Not Set";
```
- `1 << k` = \(2^k\), for nonnegative `k` within the valid shift range.
- Bit positions are **0-indexed from the right**.

## 4. Toggle the Kth Bit
```cpp
x = x ^ (1 << k);
// Short form:
x ^= (1 << k);
```
- If the bit is 0 → it becomes 1.
- If the bit is 1 → it becomes 0.

## 5. Set the Kth Bit (Make it 1)
```cpp
x = x | (1 << k);
// Short form:
x |= (1 << k);
```

## 6. Unset the Kth Bit (Make it 0)
```cpp
x = x & ~(1 << k);
// Short form:
x &= ~(1 << k);
```

## 7. Multiply or Divide by 2^k
```cpp
x << k  // Multiply by 2^k
x >> k  // Divide by 2^k (integer division for nonnegative x)
```
- Left shift multiplies by \(2^k\) when the result is representable.
- Right shift divides a nonnegative integer by \(2^k\), discarding the remainder.
- Example: `8 << 2 = 32`, `20 >> 2 = 5`.

## 8. Find x % 2^k
```cpp
x & ((1 << k) - 1)
```
- For nonnegative `x`, this gives the remainder when dividing by \(2^k\).
- Example: `13 & ((1 << 2) - 1) = 1`, because `13 % 4 = 1`.

## 9. Count the Number of Set Bits (1s)
```cpp
int cnt = __builtin_popcount(x);
```
- Counts the number of set bits in an `int`.
- Example: `x = 13` → binary `1101` → answer = `3`.
- For `long long`, use:
```cpp
int cnt = __builtin_popcountll(x);
```

## 10. XOR Properties (Very Important)
```cpp
x ^ x = 0
x ^ 0 = x
x ^ y = y ^ x
```
- XORing a number with itself cancels it out.
- XOR of all array elements finds the unique element when every other element appears exactly twice.

Example:
```cpp
int ans = 0;
for (int x : nums)
    ans ^= x;
```

## 11. Remove the Rightmost Set Bit
```cpp
x = x & (x - 1);
// Short form:
x &= (x - 1);
```
- Removes the rightmost `1` bit.
- Useful for counting set bits and checking powers of 2.

## Quick Revision Table

| Task | Expression |
|---|---|
| Check odd/even | `x & 1` |
| Check power of 2 | `x > 0 && (x & (x-1)) == 0` |
| Check Kth bit | `x & (1 << k)` |
| Toggle Kth bit | `x ^ (1 << k)` |
| Set Kth bit | `x \| (1 << k)` |
| Unset Kth bit | `x & ~(1 << k)` |
| Multiply by \(2^k\) | `x << k` |
| Divide by \(2^k\) | `x >> k` |
| Remainder modulo \(2^k\) | `x & ((1 << k) - 1)` |
| Count set bits (`int`) | `__builtin_popcount(x)` |
| Count set bits (`long long`) | `__builtin_popcountll(x)` |
| Remove rightmost set bit | `x & (x - 1)` |

**Important:** These shift expressions assume a valid shift amount. For large bit positions, use an unsigned type such as `1u` or `1ULL` as appropriate, and ensure the shift count is smaller than the type's bit width.

