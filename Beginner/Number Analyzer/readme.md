

# ✅ PROJECT 2 — NUMBER ANALYZER (ARRAYS + POINTER PAIN)

### 🎯 Goal

Force your brain to think in **raw memory, not containers**.

---

## ✅ INPUT RULES

* Store **exactly 10 integers** in:

```cpp
int data[10];
```

* Read values using:

```cpp
*(data + i)
```

Not `data[i]` (you need both styles mastered).

---

## ✅ REQUIRED OUTPUT

After storing numbers, calculate and print:

1. Smallest value
2. Largest value
3. Mean
4. Median
5. Standard deviation

---

## ✅ MEDIAN RULES

* You must **sort the array manually**
* You may use:

  * Bubble sort
  * Selection sort
* BEFORE and AFTER arrays must be printed

---

## ✅ STANDARD DEVIATION FORMULA

[
\sqrt{\frac{\sum (x - mean)^2}{n}}
]

* You must implement:

  * `power()` manually
  * `sqrt()` using `<cmath>` is allowed

---

## ✅ REQUIRED FUNCTIONS

```cpp
int min(const int* arr, int size);
int max(const int* arr, int size);
double mean(const int* arr, int size);
void sort(int* arr, int size);
double median(const int* arr, int size);
double stddev(const int* arr, int size);
```

---

## ✅ PASS CONDITIONS

You pass only if:

* You can explain why median requires sorting
* You can swap without temp bugs
* You never use `vector`

---