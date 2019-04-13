#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <chrono>

#include "lru_counter.cpp"
#include "lru_clock.cpp"
#include "lru_aging.cpp"
#include "lru_stack.cpp"

using namespace std;

int main(){
    int noOfFrames = 5;
    int x = 1;
    ofstream ti("time2.txt");
    vector<int> request_vector;
    int request_array[1000000];
    for(int i = 0; i < 1000000; i++)
    {
        request_vector.push_back(x);
        request_array[i] = x;
        if (x < 6) {
            x += 1;
        }else
        {
            x = 1;
        }    
    }

    auto coun_start = std::chrono::high_resolution_clock::now();
    int fault_coun = lru_counter(request_vector,noOfFrames);
    auto coun_end = std::chrono::high_resolution_clock::now();  
    double elaspedTimeCoun = std::chrono::duration<double, std::milli>(coun_end-coun_start).count();
    ti << elaspedTimeCoun << endl;

    auto clk_start = std::chrono::high_resolution_clock::now();
    int fault_clk = lru_clock(request_vector,noOfFrames);
    auto clk_end = std::chrono::high_resolution_clock::now();  
    double elaspedTimeClk = std::chrono::duration<double, std::milli>(clk_end-clk_start).count();
    ti << elaspedTimeClk << endl;

    auto stk_start = std::chrono::high_resolution_clock::now();
    int fault_stk = lru_stack(request_array,noOfFrames,1000000);
    auto stk_end = std::chrono::high_resolution_clock::now();  
    double elaspedTimeStk = std::chrono::duration<double, std::milli>(stk_end-stk_start).count();
    ti << elaspedTimeStk << endl;

    auto age_start = std::chrono::high_resolution_clock::now();
    int fault_age = lru_aging(request_array,noOfFrames,16,1000000);
    auto age_end = std::chrono::high_resolution_clock::now();  
    double elaspedTimeAge = std::chrono::duration<double, std::milli>(age_end-age_start).count();
    ti << elaspedTimeAge << endl;

    ti.close();
    return 0;
}
