#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP
#include <iostream>
#include <vector>
#include "Process.hpp"
#include <algorithm>


    // bool comp(Process a, Process b){
    //     return (a.getArrivalTime() < b.getArrivalTime());
    // }
class Algorithm{
    public:
        std::vector<Process> * processes;
        std::vector<int> schedule;
        double meanTurnAroundTime, meanCompletionTime, meanWaitingTime;
        virtual void scheduleCPU(){}
        ~Algorithm(){}
        Algorithm(){}
        Algorithm(std::vector<Process> * processes){
            this->processes = processes;
            std::sort(this->processes->begin(), this->processes->end(), [] (Process a, Process b){
                return (a.getArrivalTime() < b.getArrivalTime());
            });
            this->meanTurnAroundTime = 0;
            this->meanCompletionTime = 0;
            this->meanWaitingTime = 0;
        }
        
        void printSchedule(){
            for (int i = 0; i < schedule.size(); i++)
            {
                printf("[Process %d] - BeginTime: %d - EndTime: %d\n", schedule[i], processes->at(schedule[i]).getBeginTime(), processes->at(schedule[i]).getEndTime());
            }
        }
        void calculateProcessesStats(){
            for (int i = 0; i < processes->size(); i++)
            {
                processes->at(i).calculateStatistics();
            }
        }       
        void calculateMeanStatistics(){
            double sumTurnAroundTime = 0, sumCompletionTime = 0, sumWaitingTime = 0;
            for (int i = 0; i < processes->size(); i++)
            {
                sumTurnAroundTime += processes->at(i).getTurnAroundTime();
                sumCompletionTime += processes->at(i).getCompletionTime();
                sumWaitingTime += processes->at(i).getWaitingTime();
            }
            
            int sizeOfProcesses = processes->size();

            this->meanCompletionTime = sumCompletionTime / sizeOfProcesses;
            this->meanTurnAroundTime = sumTurnAroundTime / sizeOfProcesses;
            this->meanWaitingTime = sumWaitingTime / sizeOfProcesses;
        }

        void printStats(){
            printf("[+] Mean Turn Around Time: %.1lf\n[+] Mean Completion Time: %.1lf\n[+] Mean WaitingTime: %.1lf\n", meanTurnAroundTime, meanCompletionTime, meanWaitingTime);
        }

        double getMeanCompletionTime(){
            return this->meanCompletionTime;
        }
        double getMeanWaitingTime(){
            return this->meanWaitingTime;
        }
        double getMeanTurnAroundTime(){
            return this->meanTurnAroundTime;
        }
};



#endif