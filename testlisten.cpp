#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "sortalgorithm.hpp"

using namespace std;

vector<int> favourite_numbers = {700,2,5,13,67,55,285,4,15,500,3,5,7,347,347,7,547,453,8,836,8358,6,836,8,568,5,6,84,568,45468,68,8,84};

void print_list(vector<int> list, string description = ""){
    cout << description << ": ";
    for(int x: list){
        cout << x <<", ";
    }
    cout << endl;
}

template <typename Func>
void test_sort(std::vector<int>& list, Func sort_func, const std::string& name){
    print_list(favourite_numbers,"Unsortiert");
    auto start = std::chrono::high_resolution_clock::now();
    sort_func(list);  // in-place Sortierung
    auto end = std::chrono::high_resolution_clock::now();

    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    print_list(list, name);
        std::cout << name << " dauerte ";

    if (ns < 1'000) {
        std::cout << ns << " Nanosekunden";
    }
    else if (ns < 1'000'000) {
        std::cout << ns / 1'000.0 << " Mikrosekunden";
    }
    else if (ns < 1'000'000'000) {
        std::cout << ns / 1'000'000.0 << " Millisekunden";
    }
    else {
        std::cout << ns / 1'000'000'000.0 << " Sekunden";
    }

    std::cout << "\n\n";
}


int main(){
    cout << "=== Sortieralgorithmus Test ===\n\n";
    shuffle_list(favourite_numbers);
    vector<int> shuffled_list = favourite_numbers;
    
    test_sort(favourite_numbers, gnomesort, "Gnomesort");

    favourite_numbers = shuffled_list;
    test_sort(favourite_numbers, quicksort, "Quicksort");
    
    favourite_numbers = shuffled_list;
    test_sort(favourite_numbers, bubblesort, "Bubblesort");

    // Für Bogosort unbedingt kleine Liste!
    //favourite_numbers = shuffled_list;
    //test_sort(favourite_numbers, bogosort, "Bogosort");
    

    return 0;
}