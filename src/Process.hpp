#ifndef PROCESS_HPP
#define PROCESS_HPP

class Process{
    int id;
    int arrivalTime;
    int burstTime;
    int turnAroundTime;
    int completionTime;
    int waitingTime;
    int beginTime;
    int endTime;


    public:
        Process(){}
        Process(int id, int arrivalTime, int burstTime){
            this->id = id;
            this->arrivalTime = arrivalTime;
            this->burstTime = burstTime;
        }
        int getBurstTime(){
            return burstTime;
        }
        int getArrivalTime(){
            return arrivalTime;
        }
        int getId(){
            return id;
        }
        int getBeginTime(){
            return beginTime;
        }
        int getEndTime(){
            return endTime;
        }
        int getCompletionTime(){
            return completionTime;
        }
        int getTurnAroundTime(){
            return turnAroundTime;
        }
        int getWaitingTime(){
            return waitingTime;
        }
        void setBeginTime(int beginTime){
            this->beginTime = beginTime;
        }
        void setEndTime(int endTime){
            this->endTime = endTime;
        }
        void setBurstTime(int burstTime){
            this->burstTime = burstTime;
        }
        void calculateStatistics(){
            calculateCompletionTime();
            calculateTurnAroundTime();
            calculateWaitingTime();
        }
        void calculateTurnAroundTime(){
            this->turnAroundTime = this->endTime - this->arrivalTime;
        }
        void calculateCompletionTime(){
            this->completionTime = this->beginTime - this->arrivalTime;
        }
        void calculateWaitingTime(){
            this->waitingTime = this->turnAroundTime - this->burstTime;
        }
};

#endif