#include "SJF.hpp"

void SJF::updateAvailableJobs(std::vector<Process> * jobs, std::vector<Process> * availableJobs, int endtime){
    static int stopped = 0;
    for (int i = stopped; i < jobs->size(); i++)
    {
        if(jobs->at(i).getArrivalTime() <= endtime || availableJobs->size() == 0){
            availableJobs->push_back(jobs->at(i));
            stopped = i+1;
        }
    }

}

void SJF::scheduleCPU(){
    std::vector<Process> jobs = std::vector<Process>(*processes);
    std::vector<Process> availableJobs;
    std::vector<bool> flags = std::vector<bool>(processes->size(), false);
    int endtime = 0, stopped = 0, size, idBefore, id, remainingBurstTime;
    Process auxiliar;

    updateAvailableJobs(&jobs, &availableJobs, endtime);

    do
    {
        std::sort(availableJobs.begin(), availableJobs.end(),  [] (Process a, Process b){
            return (a.getBurstTime() < b.getBurstTime());
        }); 
        id = availableJobs[0].getId();
        size = schedule.size();
        schedule.push_back(id);
        if(size > 0){
            idBefore = schedule[size-1];
            remainingBurstTime = processes->at(idBefore).getBurstTime() - (availableJobs[0].getArrivalTime() - processes->at(idBefore).getBeginTime());
            if(processes->at(idBefore).getEndTime() > availableJobs[0].getArrivalTime() && availableJobs[0].getBurstTime() < processes->at(idBefore).getBurstTime() && remainingBurstTime > availableJobs[0].getBurstTime()){
                processes->at(idBefore).setEndTime(processes->at(id).getArrivalTime());
                auxiliar = Process(processes->at(idBefore));
                auxiliar.setBurstTime(auxiliar.getBurstTime() - (processes->at(idBefore).getEndTime() - processes->at(idBefore).getBeginTime()));
                availableJobs.push_back(auxiliar);
                processes->at(id).setBeginTime(processes->at(idBefore).getEndTime());
                processes->at(id).setEndTime(processes->at(id).getBeginTime() + processes->at(id).getBurstTime());
            }else{
                if(!flags[id]){
                    processes->at(id).setBeginTime(std::max(processes->at(idBefore).getEndTime(), processes->at(id).getArrivalTime()));
                    flags[id] = true;
                }
                processes->at(id).setEndTime(processes->at(id).getBurstTime() + processes->at(id).getBeginTime());
            }
        }else{
            processes->at(id).setBeginTime(processes->at(id).getArrivalTime());
            processes->at(id).setEndTime(processes->at(id).getBeginTime() + processes->at(id).getBurstTime());
            flags[id] = true;
        }
        availableJobs.erase(availableJobs.begin());
        endtime = processes->at(id).getEndTime();
        updateAvailableJobs(&jobs, &availableJobs, endtime);
    }while(!availableJobs.empty());    
}
