#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>

#include "lru_counter.cpp"
#include "lru_clock.cpp"
#include "lru_aging.cpp"
#include "lru_stack.cpp"

using namespace std;

int main(){
    int noOfFrames;
    ofstream coun("lru_coun.txt");
    ofstream clk("lru_clk.txt");
    ofstream age("lru_age.txt");
    ofstream stk("lru_stk.txt");

    vector<int> request_vector;
    int request_array[22];
    for(int i = 1; i <= 10; i++)
    {
        request_vector.push_back(i);
    }
    request_vector.push_back(2);
    request_vector.push_back(4);
    request_vector.push_back(2);
    request_vector.push_back(6);
    request_vector.push_back(10);
    request_vector.push_back(7);
    request_vector.push_back(3);
    request_vector.push_back(4);
    request_vector.push_back(9);
    request_vector.push_back(8);


    for(int i = 0; i < 20; i++)
    {
        request_array[i] = request_vector[i];
    }
    
    
    
    for(noOfFrames = 2; noOfFrames <= 10; noOfFrames++){
        
        int faults_clk = lru_clock(request_vector,noOfFrames);
        clk << faults_clk << "\n";

        int faults_stk = lru_stack(request_array,noOfFrames,20);
        stk << faults_stk << "\n";

        int faults_coun = lru_counter(request_vector,noOfFrames);
        coun << faults_coun << "\n";

        int faults_age = lru_aging(request_array,noOfFrames,20,20);
        age << faults_age << "\n";
    }

    coun.close();
    age.close();
    clk.close();
    stk.close();
    return 0;
}