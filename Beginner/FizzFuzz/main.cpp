#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
using namespace std;
using namespace chrono;

// ============================================================================
// 1. TRIAL DIVISION (SIMPLEST)
// ============================================================================

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> trialDivision(int limit) {
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

// ============================================================================
// 2. SIEVE OF ERATOSTHENES (MOST POPULAR)
// ============================================================================

vector<int> sieveOfEratosthenes(int limit) {
    if (limit < 2) return {};
    
    // Create boolean array, initially all true
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    // Sieve
    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            // Mark multiples of p as composite
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }
    
    // Collect primes
    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

// ============================================================================
// 3. OPTIMIZED SIEVE (ODD NUMBERS ONLY - 2X FASTER)
// ============================================================================

vector<int> optimizedSieve(int limit) {
    if (limit < 2) return {};
    
    vector<int> primes;
    if (limit >= 2) primes.push_back(2);
    if (limit < 3) return primes;
    
    // Only track odd numbers: index i represents 2*i+3
    // So index 0 = 3, index 1 = 5, index 2 = 7, etc.
    int size = (limit - 1) / 2;
    vector<bool> isPrime(size, true);
    
    for (int i = 0; i * i < size; i++) {
        if (isPrime[i]) {
            int p = 2 * i + 3;  // Actual prime value
            
            // Mark multiples: start at p², skip even multiples
            for (int j = (p * p - 3) / 2; j < size; j += p) {
                isPrime[j] = false;
            }
        }
    }
    
    // Collect odd primes
    for (int i = 0; i < size; i++) {
        if (isPrime[i]) {
            primes.push_back(2 * i + 3);
        }
    }
    
    return primes;
}

// ============================================================================
// 4. SEGMENTED SIEVE (LOW MEMORY FOR HUGE RANGES)
// ============================================================================

vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;
    
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
            for (long long i = (long long)p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }
    return primes;
}

vector<int> segmentedSieve(int limit) {
    if (limit < 2) return {};
    
    int sqrtLimit = (int)sqrt(limit);
    
    // Step 1: Get base primes up to √limit
    vector<int> basePrimes = simpleSieve(sqrtLimit);
    vector<int> result = basePrimes;
    
    // Step 2: Process in segments
    int segmentSize = sqrtLimit;
    int low = sqrtLimit + 1;
    
    while (low <= limit) {
        int high = min(low + segmentSize - 1, limit);
        
        // Create segment
        vector<bool> isPrime(high - low + 1, true);
        
        // Mark multiples of base primes
        for (int p : basePrimes) {
            // Find first multiple of p in [low, high]
            int start = max(p * p, ((low + p - 1) / p) * p);
            
            for (int j = start; j <= high; j += p) {
                isPrime[j - low] = false;
            }
        }
        
        // Collect primes from segment
        for (int i = 0; i < isPrime.size(); i++) {
            if (isPrime[i]) {
                result.push_back(low + i);
            }
        }
        
        low += segmentSize;
    }
    
    return result;
}

// ============================================================================
// 5. 6k ± 1 OPTIMIZATION (SMART TRIAL DIVISION)
// ============================================================================

bool isPrimeOptimized(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Check divisors of form 6k±1 up to √n
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

vector<int> primes6kPlusMinus1(int limit) {
    vector<int> primes;
    
    if (limit >= 2) primes.push_back(2);
    if (limit >= 3) primes.push_back(3);
    
    // Check only 6k±1 candidates
    for (int k = 1; 6*k - 1 <= limit; k++) {
        int candidate1 = 6 * k - 1;
        int candidate2 = 6 * k + 1;
        
        if (candidate1 <= limit && isPrimeOptimized(candidate1)) {
            primes.push_back(candidate1);
        }
        if (candidate2 <= limit && isPrimeOptimized(candidate2)) {
            primes.push_back(candidate2);
        }
    }
    
    return primes;
}

// ============================================================================
// BENCHMARK FUNCTION
// ============================================================================

void benchmark(int limit) {
    cout << "\n==================================================" << endl;
    cout << "BENCHMARKING PRIME ALGORITHMS UP TO " << limit << endl;
    cout << "==================================================" << endl;
    
    // Trial Division
    auto start = high_resolution_clock::now();
    vector<int> p1 = trialDivision(limit);
    auto end = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end - start);
    cout << "Trial Division:          " << duration1.count() << " ms\t(found " << p1.size() << " primes)" << endl;
    
    // Sieve of Eratosthenes
    start = high_resolution_clock::now();
    vector<int> p2 = sieveOfEratosthenes(limit);
    end = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end - start);
    cout << "Sieve of Eratosthenes:   " << duration2.count() << " ms\t(found " << p2.size() << " primes)" << endl;
    
    // Optimized Sieve
    start = high_resolution_clock::now();
    vector<int> p3 = optimizedSieve(limit);
    end = high_resolution_clock::now();
    auto duration3 = duration_cast<milliseconds>(end - start);
    cout << "Optimized Sieve (odd):   " << duration3.count() << " ms\t(found " << p3.size() << " primes)" << endl;
    
    // Segmented Sieve
    start = high_resolution_clock::now();
    vector<int> p4 = segmentedSieve(limit);
    end = high_resolution_clock::now();
    auto duration4 = duration_cast<milliseconds>(end - start);
    cout << "Segmented Sieve:         " << duration4.count() << " ms\t(found " << p4.size() << " primes)" << endl;
    
    // 6k±1
    start = high_resolution_clock::now();
    vector<int> p5 = primes6kPlusMinus1(limit);
    end = high_resolution_clock::now();
    auto duration5 = duration_cast<milliseconds>(end - start);
    cout << "6k±1 Method:             " << duration5.count() << " ms\t(found " << p5.size() << " primes)" << endl;
    
    cout << "\nSpeedup (compared to Trial Division):" << endl;
    if (duration2.count() > 0) 
        cout << "  Sieve: " << (double)duration1.count() / duration2.count() << "x faster" << endl;
    if (duration3.count() > 0)
        cout << "  Optimized Sieve: " << (double)duration1.count() / duration3.count() << "x faster" << endl;
}

// ============================================================================
// DISPLAY PRIMES (FOR SMALL RANGES)
// ============================================================================

void displayPrimes(int limit) {
    cout << "\nPrimes up to " << limit << ":" << endl;
    vector<int> primes = sieveOfEratosthenes(limit);
    
    for (int i = 0; i < primes.size(); i++) {
        cout << primes[i];
        if (i < primes.size() - 1) cout << ", ";
        if ((i + 1) % 15 == 0) cout << endl;  // 15 primes per line
    }
    cout << endl;
    cout << "\nTotal: " << primes.size() << " primes" << endl;
}

// ============================================================================
// TEST INDIVIDUAL NUMBERS
// ============================================================================

void testIndividualNumbers() {
    cout << "\n==================================================" << endl;
    cout << "TESTING INDIVIDUAL NUMBERS" << endl;
    cout << "==================================================" << endl;
    
    vector<int> testCases = {0, 1, 2, 3, 4, 5, 17, 25, 97, 100, 101};
    
    for (int n : testCases) {
        bool result = isPrimeOptimized(n);
        cout << n << " is " << (result ? "PRIME" : "NOT PRIME") << endl;
    }
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main() {
    cout << "╔════════════════════════════════════════════════╗" << endl;
    cout << "║     PRIME NUMBER ALGORITHMS - ALL IN ONE      ║" << endl;
    cout << "╚════════════════════════════════════════════════╝" << endl;
    
    // Display primes up to 100
    displayPrimes(100);
    
    // Test individual numbers
    testIndividualNumbers();
    
    // Run benchmarks
    benchmark(10000);
    benchmark(100000);
    benchmark(1000000);
    
    // Optional: Uncomment for 10 million (takes longer)
    // benchmark(10000000);
    
    cout << "\n==================================================" << endl;
    cout << "KEY TAKEAWAYS:" << endl;
    cout << "==================================================" << endl;
    cout << "• Trial Division: O(n√n) - Good for single checks" << endl;
    cout << "• Sieve: O(n log log n) - BEST for finding ranges" << endl;
    cout << "• Optimized Sieve: 2x faster + 50% less memory" << endl;
    cout << "• Segmented Sieve: For billions with low RAM" << endl;
    cout << "• 6k±1: 3x faster trial division" << endl;
    cout << "==================================================" << endl;
    
    return 0;
}