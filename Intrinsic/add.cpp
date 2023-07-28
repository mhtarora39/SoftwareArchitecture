#include <iostream>
#include <chrono>
#include <function>

std::function<double(void)> func;

void time_it(func& func) {
    auto this_time = std::chrono::system_clock::now();
    func();
    auto end_time =  std::chrono::system_clock::now();
    std::cout << "Total time in ms" << std::chrono::duration<double,std::milli>(end_time - this_time).count() << std::endl;
}

#define SIZE = 20000
float* array = (float*)malloc(SIZE*sizeof(float));

double add_normal() {
    double val = 0;
    for(int i = 0;i < SIZE; i++) {
        val = val + array[i];
    }
    return val;
}

double add_intrinsic() {
    double val = 0;
    for(int i = 0;i < SIZE; i++) {
        val = val + array[i];
    }
    return val;
}