#include <iostream>
#include <vector>
#include <string>

// HELPER FUNCTION TO CREATE A 100-DIMENSIONAL HYPERCUBE RECURSIVELY
template <typename T>
auto createHypercube(int dimensions, int size) -> typename std::vector<T>::size_type {
    if (dimensions == 1) {
        return std::vector<T>(size);
    } else {
        return std::vector<decltype(createHypercube<T>(dimensions - 1, size))>(size, createHypercube<T>(dimensions - 1, size));
    }
}

template <typename T>
std::string valueFromHypercube(auto& hypercube, const std::vector<int>& indices) {
    auto* ptr = &hypercube;
    for (int idx : indices) {
        ptr = &(*ptr)[idx];
    }
    return std::to_string(*ptr);
}

int main() {
    const int dimensions = 3;
    const int sideLength = 5; 

    // CREATE A DIMENSIONAL HYPERCUBE WITH SIDE LENGTH
    auto bongulus = createHypercube<int>(dimensions, sideLength);

    // FOR DEMONSTRATION, LET'S SET AND RETRIEVE A VALUE
    bongulus[1][1][1] = 42; // Example with fewer dimensions
    std::cout << "Value at [1][1][1]: " << bongulus[1][1][1] << std::endl;

    // NOTE: I think we can' handle 100 dimensions directly; this example uses 3 for simplicity
    return 0;
}
