#ifndef FCFS_HPP
#define FCFS_HPP
#include"Algorithm.hpp"

class FCFS: public Algorithm{
    public:
        ~FCFS(){}
        FCFS():Algorithm(){}
        FCFS(std::vector<Process> * processes):Algorithm(processes){}
        
        void scheduleCPU();
};

#endif