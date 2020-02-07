#include "FCFS.hpp"

void FCFS::scheduleCPU(){
    schedule.push_back(processes->at(0).getId());
    processes->at(0).setBeginTime(processes->at(0).getArrivalTime());
    processes->at(0).setEndTime(processes->at(0).getBeginTime() + processes->at(0).getBurstTime());

    for (int i = 1; i < this->processes->size(); i++)
    {
        schedule.push_back(processes->at(i).getId());
        processes->at(i).setBeginTime( std::max(processes->at(i).getArrivalTime(),processes->at(i-1).getEndTime()));
        processes->at(i).setEndTime(processes->at(i).getBeginTime() + processes->at(i).getBurstTime());
    }
}