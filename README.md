# Project 1 – Bit-wise Logical Operations on Finite Bit Strings

**Course:** MATH 251  

---

## 1. Purpose of the Program

This program is a small demonstration of how logical connectives  
**AND**, **OR**, and **XOR** act on *bit strings* (strings of 0s and 1s).

The program:

1. Prompts the user for two bit strings of the same length.
2. Computes:
   - bitwise AND  
   - bitwise OR  
   - bitwise XOR  
3. Prints the resulting bit strings.

---
## 3. Data Type(s)

### 3.1 `BitString` data type

The program defines a simple structure:

```cpp
struct BitString {
    explicit BitString(std::string data = "") noexcept;
    std::string AND(BitString& other);
    std::string OR(BitString& other);
    std::string XOR(BitString& other);
    std::size_t size() noexcept;
    std::string::iterator begin() noexcept;
    std::string::iterator end() noexcept;
    std::string m_data;
};
```

### 3.2 Key features:

- Stores the underlying string of bits.
- Implements logic operations one bit at a time.
- Uses `assert` to ensure both bit strings are the same length before computing.

---

## 4. Compiling and Running

From a terminal:

```bash
g++ p1.cxx -o p1
./p1
```

---

## 5. Example Execution

```bash
ENTER BIT-STRING A: 1010
ENTER BIT-STRING B (MUST BE 4 BITS LONG): 1100

   AND RESULT: 1000
    OR RESULT: 1110
   XOR RESULT: 0110
```

---

### 6. Notes

- Program assumes the user enters only 0s and 1s.
- `assert` will terminate the program if the two strings differ in length.

This program was used to answer a question from:
Rosen, K. H. (2019). _Discrete mathematics and its applications_ (8th ed.). McGraw-Hill Education.
