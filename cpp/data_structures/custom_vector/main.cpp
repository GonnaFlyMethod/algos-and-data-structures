#include <iostream>
#include <functional>

template <class T>
void _iterate_over(
    T arr[], int size, std::function<void(T*, int)> logic_to_perform) {

    for (int i{}; i < size; i++) {
        logic_to_perform(&arr[i], size);
    }
}

template <class T>
void print_array(T arr[], int size) {
    
    auto func_to_perform = [&](T* memory_addr, int size) -> void {
        __int64 current_index = memory_addr - arr;
        T current_elem = *memory_addr;

        if (current_index < size - 1) {
            std::cout << current_elem << ", ";
        }
        else {
            std::cout << current_elem;
        }

        };

    _iterate_over<T>(arr, size, func_to_perform);
}
//
// TODO: using tempalates

template <class T>
class CustomVector {
public:
    CustomVector() {
        storage = new T[capacity_delta];
        current_capacity_pool = capacity_delta;
        current_size_of_arr = 0;
    }

    ~CustomVector() {
        delete[] storage;
        storage = nullptr;

        current_capacity_pool = 0;
        current_size_of_arr = 0;
    }

    int get_current_size() {
        return current_size_of_arr;
    }

    void push(T elem) {
        if (current_capacity_pool == 0) {
            int new_capacity_of_arr = current_size_of_arr + capacity_delta;

            T* tmp = new T[new_capacity_of_arr];

            for (int i{}; i < current_size_of_arr; i++) {
                tmp[i] = storage[i];
            }

            delete[] storage;

            storage = tmp;
            tmp = nullptr;

            current_capacity_pool = capacity_delta;
        }

        storage[current_size_of_arr] = elem;
        current_size_of_arr++;
        current_capacity_pool--;

    }

    T* get_begin_ptr() {
        return storage;
    }

    const int operator[](int index) const {
        if (index < 0 || index >(current_size_of_arr - 1)) {
            throw std::out_of_range("index of out range -> InvVector");;
        }

        return storage[index];
    }

    CustomVector* operator+=(CustomVector &other) {
        int other_vector_size = get_current_size();

        for (int i{};i < other_vector_size; i++) {
            push(other[i]);
        }

        CustomVector *this_instance = this;

        return this_instance;
    }

private:
    T* storage = nullptr;

    int current_size_of_arr{};
    const int capacity_delta = 2;

    int current_capacity_pool{};
};

void stable_partition(int arr[], int size, CustomVector<int> *out) {
    CustomVector<int> odd_buffer = CustomVector<int>();
    
    auto func_to_perform = [&](int *current_memory_addr, int size) {
        int current_elem = *current_memory_addr;
        
        if (current_elem % 2 == 0) {
            out->push(current_elem);
        }

        else {
            odd_buffer.push(current_elem);
        }


        if (current_memory_addr - arr == size - 1) {
            (*out) += odd_buffer;
        }
    };
    
    _iterate_over<int>(arr, size, func_to_perform);
}


int main() {
    int arr[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
        
    int array_size = sizeof(arr) / sizeof(int);

    CustomVector<int> result = CustomVector<int>();
    
    stable_partition(arr, array_size, &result);
    print_array<int>(result.get_begin_ptr(), result.get_current_size());

    std::cout << '\n';

    CustomVector<std::string> str_vec = CustomVector<std::string>();
    str_vec.push("Rust");
    str_vec.push("Zig");
    str_vec.push("C++");

    print_array<std::string>(str_vec.get_begin_ptr(), str_vec.get_current_size());

    return 0;
}