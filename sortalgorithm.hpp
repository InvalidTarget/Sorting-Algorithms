#pragma once
#include <vector>
#include <algorithm>
#include <random> //Bogosort

inline void bubblesort(std::vector<int>& list){
    if(list.empty()) return;
    bool swapped = true;
    size_t n = list.size();
    while(swapped){
        swapped = false;
        for (size_t i = 1; i<n; i++){
            if (list[i-1]>list[i]){
                std::swap(list[i-1],list[i]);
                swapped = true;
            }
        }
        //Da das letzte Element schon sortiert ist,
        //ignorieren wir es im nächsten Durchlauf
        n--;
    }
}

inline void gnomesort(std::vector<int>& list){
    size_t i = 0; //unsigned integer
        while(i<list.size()-1){

            if (list[i]>list[i+1]){
                std::swap(list[i], list[i+1]);

                if (i > 0){
                    i--;
                }
            }
            else{
                i++;
            }
        }
}

inline void quicksort_helper(std::vector<int>& list, int low, int high){
    if(low >= high) return;

    int pivot = list[high];   // Pivot festlegen
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(list[j] <= pivot){
            i++;
            std::swap(list[i], list[j]);
        }
    }

    // Pivot an richtige Stelle bringen
    std::swap(list[i+1], list[high]);
    int pivot_index = i + 1;

    quicksort_helper(list, low, pivot_index - 1);
    quicksort_helper(list, pivot_index + 1, high);
}

inline void quicksort(std::vector<int>& list){
    if(list.empty()) return;
    quicksort_helper(list, 0, list.size() - 1);
}

inline void insertionsort(std::vector<int>& list){
    for(size_t i=0;i<list.size();i++){
        int currentvalue = list [i];
        size_t position = i;

        while (position>0 && list[position-1]>currentvalue){
            list[position] = list[position-1];
            position = position-1;
        }

        list[position] = currentvalue;
    }
}

inline void shuffle_list(std::vector<int>& list){
    std::random_device rd;
    std::mt19937 gen(rd());

    for(size_t i = list.size() - 1; i > 0; --i){
        if (list.size() < 2) {return;}
        std::uniform_int_distribution<> dist(0, i);
        size_t j = dist(gen);
        std::swap(list[i], list[j]);
    }
}

inline void bogosort(std::vector<int>& list){
        while(!std::is_sorted(list.begin(), list.end())){
            shuffle_list(list);
    }
}