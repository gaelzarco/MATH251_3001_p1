# Project 1 – Bitwise Operations with Bit Strings

**File:** `p1.cxx`  
**Author:** Gael Zarco  
**Course:** MATH 251  
**Date:** 2025-11-14  

---

## 1. Purpose of the Program

This program is a small demonstration of how logical connectives  
**AND**, **OR**, and **XOR** act on *bit strings* (strings of 0s and 1s).

Each bit string represents a finite sequence of truth values:

- `1` = **True**
- `0` = **False**

The program:

1. Prompts the user for two bit strings of the same length.
2. Computes:
   - bitwise AND  
   - bitwise OR  
   - bitwise XOR  
3. Prints the resulting bit strings.

_This directly mirrors propositional logic._

---

## 2. Mathematical Interpretation

Let  

- $A = a_1 a_2 \dots a_n$  
- $B = b_1 b_2 \dots b_n$  

where each $a_i, b_i \in \{0,1\}$.

The program computes three new bit strings:
- $C = A \land B$
- $D = A \lor B$
- $E = A \oplus B$ denoted by:

- **AND:**  
  $c_i = 1$ \Leftrightarrow $a_i = 1$ **and** $b_i = 1$; otherwise $c_i = 0$.

- **OR:**  
  $d_i = 1$ \Leftrightarrow $a_i = 1$ **or** $b_i = 1$ (or both); otherwise $d_i = 0$.

- **XOR** (“exclusive or”):  
  $e_i = 1$ \Leftrightarrow $a_i \neq b_i$; otherwise $e_i = 0$.

So, for example, if

- $A = 1010$  
- $B = 1100$

then

- $A \land B = 1000$  
- $A \lor B = 1110$  
- $A \oplus B = 0110$

_This program automates these computations._

---

## 3. How the Code Is Organized

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
    std::string m_data;    // underlying "0101..." string
};
```

### 3.2 Key features:

- Stores the underlying string of bits.
- Implements logic operations one character at a time.
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
