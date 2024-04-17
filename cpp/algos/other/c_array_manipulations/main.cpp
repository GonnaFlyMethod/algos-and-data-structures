#include <iostream>
#include <functional>

void _iterate_over(unsigned int* start, unsigned int* end, std::function<void(unsigned int*)> logic_to_perform) {
    unsigned int *current = start;
    
    while (current <= end) {
        logic_to_perform(current);
        current++;
    }
}

// Create function fill_array
void fill_array(unsigned int *start, unsigned int *end) {
    auto func_to_perform = [&](unsigned int* current_address) -> void {
        unsigned int index = static_cast<unsigned int>(current_address - start);
        
        std::cout << "array index: " << index << '\n';
        
        unsigned int number{};

        std::cin >> number;

        *current_address = number;
    };

    _iterate_over(start, end, func_to_perform);
    
}

// Create function reverse_array
void reverse_array(unsigned int *start, unsigned int *end) {
    auto func_to_perform = [&](unsigned int* current_address) -> void {
        unsigned int delta = static_cast<unsigned int>(current_address - start);
        
        unsigned int *val_left = start + delta;
        unsigned int *val_right = end - delta;

        if (val_left < val_right) {
            unsigned int tmp = *val_left;

            *val_left = *val_right;
            *val_right = tmp;
        }
    };
    
    _iterate_over(start, end, func_to_perform);

}

// Crate function print_array
void print_array(unsigned int* start, unsigned int* end) {
    auto func_to_perform = [&](unsigned int* current_address) -> void {
        
        if (current_address == end) {
            std::cout << *current_address;
        }
        else {
            std::cout << *current_address << ", ";
        }
        };

    _iterate_over(start, end, func_to_perform);
}

int main() {
    constexpr unsigned int NUMS_OF_ELEMENTS_IN_ARRAY = 12;

    unsigned int numbers[NUMS_OF_ELEMENTS_IN_ARRAY]{};

    // Call functions
    unsigned int *end_of_arr = numbers + sizeof(numbers) / sizeof(numbers[0]) - 1;

    std::cout << "Please, fill out the array with integers. Number of elements in the array: "
        << NUMS_OF_ELEMENTS_IN_ARRAY << '\n';

    fill_array(numbers, end_of_arr);
    reverse_array(numbers, end_of_arr);
    
    std::cout << "Reversed array:\n";
    print_array(numbers, end_of_arr);

    return 0;
}
