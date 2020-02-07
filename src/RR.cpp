#include "RR.hpp"

void RR::createJobQueue(std::vector<Process> * jobs, std::vector<Process> * jobQueue, int endtime){
    int size = jobs->size();
    for (int i = size-1; i >= 0; i--)
    {
        if(jobs->at(i).getArrivalTime() > endtime){
            break;
        }else{
            jobQueue->push_back(jobs->at(i));
            jobs->pop_back();
        }
    }
}

void RR::scheduleCPU(){
    std::vector<Process> jobs;
    std::vector<Process> jobQueue;
    std::vector<bool> flags = std::vector<bool>(processes->size(), false);
    Process aux;
    int endtime = 0, size = 0, id;

    for (int i = processes->size()-1; i >= 0; i--)
    {
        jobs.push_back(processes->at(i));
    }

    createJobQueue(&jobs, &jobQueue, endtime);

    do
    {
        id = jobQueue[0].getId();
    
        schedule.push_back(id);
        if(!flags[id]){
            processes->at(id).setBeginTime(endtime);
            flags[id] = true;
        }
        processes->at(id).setEndTime(endtime + std::min(quantum, jobQueue[0].getBurstTime()));
    
        endtime = processes->at(id).getEndTime();

        createJobQueue(&jobs, &jobQueue, endtime);

        if(jobQueue[0].getBurstTime() - std::min(quantum, jobQueue[0].getBurstTime()) > 0){
            aux = Process(jobQueue[0]);
            aux.setBurstTime(jobQueue[0].getBurstTime() - std::min(quantum, jobQueue[0].getBurstTime()));
            jobQueue.push_back(aux);
        }
        jobQueue.erase(jobQueue.begin());
        
    } while (!jobQueue.empty());
}