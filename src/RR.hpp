#ifndef RR_HPP
#define RR_HPP
#include "Algorithm.hpp"
#include <vector>

class RR: public Algorithm{
    int quantum;
    public:
        ~RR(){}
        RR():Algorithm(){}
        RR(std::vector<Process> * processes, int quantum):Algorithm(processes){
            this->quantum = quantum;
        }
        int getQuantum(){
            return this->quantum;
        }
        void createJobQueue(std::vector<Process> * jobs, std::vector<Process> * jobQueue, int endtime);
        void scheduleCPU();
};

#endif