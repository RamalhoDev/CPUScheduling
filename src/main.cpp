#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "FCFS.hpp"
#include "SJF.hpp"
#include "RR.hpp"
#define PATH  "file.txt"
#define QUANTUM 2

void printProcesses(std::vector<Process> * processes);
std::vector<Process> * getProcesses(std::string * filename);

int main(int argc, const char * argv[]){
    std::string filename;
    std::vector<Process> * processes;
    FCFS * fcfs;
    SJF * sjf;
    RR * rr;
    if(argc > 1){
        filename = argv[1];
    }else{
        filename = PATH;
    }
    processes = getProcesses(&filename);
    // fcfs = new FCFS(processes);
    // fcfs->scheduleCPU();
    // fcfs->calculateProcessesStats();
    // fcfs->calculateMeanStatistics();
    // fcfs->printSchedule();
    // fcfs->printStats();

    sjf = new SJF(processes);
    sjf->scheduleCPU();
    sjf->calculateProcessesStats();
    sjf->calculateMeanStatistics();
    sjf->printSchedule();
    sjf->printStats();
    sjf->calculateMeanStatistics();
    sjf->~SJF();
    processes->~vector();

    // rr = new RR(processes, QUANTUM);
    // // rr->scheduleCPU();
    // // rr->calculateProcessesStats();
    // // rr->calculateMeanStatistics();
    // // rr->printSchedule();
    // // rr->printStats();

    return 0;
}

std::vector<Process> * getProcesses(std::string * filename){
    int arrivalTime, burstTime, count = 0;
    std::vector<Process> * processes = new std::vector<Process>();
    std:: cout << "[+] Open file: " << *filename << std::endl;

    std::ifstream file;
    file.open(*filename);

    if(!file.is_open()){
        std::cout << "[+] File: (" << *filename << ") not found \n";
        return NULL;
    }
    
    while(file.good()){
        file >> arrivalTime >> burstTime;
        processes->push_back(Process(count, arrivalTime, burstTime));
        count++;
    }

    file.close();
    return processes;
}

