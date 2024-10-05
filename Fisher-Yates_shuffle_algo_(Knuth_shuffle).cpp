#include <iostream>
#include <vector>
#include <random>
#include <chrono>

template <typename T>
void fisherYatesShuffle(std::vector<T>& arr) {
    //Get a time-based seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    
    //Use the Mersenne Twister engine
    std::mt19937 generator(seed);

    for (int i = arr.size() - 1; i > 0; i--) {
        //Generate a random index between 0 and i (inclusive)
        std::uniform_int_distribution<int> distribution(0, i);
        int j = distribution(generator);

        //Swap elements at i and j
        std::swap(arr[i], arr[j]);
    }
}

//Utility function to print the vector

template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    //Example usage
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "Original array: ";
    printVector(numbers);

    fisherYatesShuffle(numbers);

    std::cout << "Shuffled array: ";
    printVector(numbers);

    return 0;
}
