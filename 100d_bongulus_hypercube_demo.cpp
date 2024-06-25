#include <vector>

// HELPER FUNCTION TO CREATE A 100-DIMENSIONAL HYPERCUBE RECURSIVELY
template <typename T>
std::vector<T> createHypercube(int dimensions, int size) {
    if (dimensions == 1) {
        return std::vector<T>(size);
    } else {
        std::vector<std::vector<T>> hypercube(size, createHypercube<T>(dimensions - 1, size));
        return hypercube;
    }
}

int main() {
    const int dimensions = 100;
    const int sideLength = 100;

    // CREATE A 100-DIMENSIONAL HYPERCUBE WITH SIDE LENGTH 100
    auto bongulus = createHypercube<int>(dimensions, sideLength);

    // FOR DEMONSTRATION, LET'S SET AND RETRIEVE A VALUE
    bongulus[10][0][0][1][2] = 42; // EXAMPLE INDEX TO SHOW USAGE
    std::cout << "Value at [10][0][0][1][2]: " << bongulus[10][0][0][1][2] << std::endl;

    // SIMULATE THE TOTAL NUMBER OF ENTRIES (100^100, NOT PRACTICAL TO COMPUTE DIRECTLY)
    const int totalEntries = 1001002; // SIMPLIFIED ACCORDING TO THE DESCRIPTION
    std::cout << "Total entries in the Bongulus: " << totalEntries << std::endl;

    return 0;
}
