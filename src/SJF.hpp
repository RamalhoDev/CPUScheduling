#ifndef SJF_HPP
#define SJF_HPP
#include "Algorithm.hpp"

class SJF:public Algorithm{
    int findNextAvailableJobs(std::vector<Process> * availableJobs, int endtime, int position);
    public:
        ~SJF(){}
        SJF():Algorithm(){}
        SJF(std::vector<Process> * processes):Algorithm(processes){}
        void updateAvailableJobs(std::vector<Process> * jobs, std::vector<Process> * availableJobs, int endtime);
        void scheduleCPU();
};

#endif