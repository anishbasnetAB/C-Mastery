#include <iostream>
#include <limits>
#include <cstdint>

int main() {
    std::int64_t sum = 0;
    std::int64_t value = 0;

    std::cout << "Enter 5 numbers:\n";

    for (int i = 0; i < 5; ++i) {
        std::cin >> value;

        // Overflow check before adding
        if ((value > 0 && sum > std::numeric_limits<std::int64_t>::max() - value) ||
            (value < 0 && sum < std::numeric_limits<std::int64_t>::min() - value)) {
            std::cerr << "Overflow detected while summing.\n";
            return 1;
        }

        sum += value;
    }

    double average = static_cast<double>(sum) / 5.0;
    std::cout << "Average: " << average << "\n";

    return 0;
}
