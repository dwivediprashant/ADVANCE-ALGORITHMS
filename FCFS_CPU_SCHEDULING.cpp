#include<iostream>
using namespace std;
void inputInArray(int arr[],int n){
    int inp;
    for(int i=0;i<n;i++){
        cin>>inp;
        arr[i]=inp;
    }
}
void sortAndMap(int arrivalTime[],int burstTime[],int n){
    //using bubble sort
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            //swap
            if(arrivalTime[j]>arrivalTime[j+1]){
                //swap in arrival time
                int temp=arrivalTime[j];
                arrivalTime[j]=arrivalTime[j+1];
                arrivalTime[j+1]=temp;
                //also we need to verify that burst time correctly map with uts respective arrival time so also swap in bursttime
                temp=burstTime[j];
                burstTime[j]=burstTime[j+1];
                burstTime[j+1]=temp;

            }
        }
    }
}
void getCompleteTime(int burstTime[],int arrivalTime[],int completeTime[],int n){
    completeTime[0]=burstTime[0];
    for(int i=1;i<n;i++){
        completeTime[i]=completeTime[i-1]+burstTime[i];
    }
}
void getTAT(int completeTime[],int arrivalTime[],int turnAroundTime[],int n){
    for(int i=0;i<n;i++){
        turnAroundTime[i]=completeTime[i]-arrivalTime[i];
    }
}
void getWT(int turnAroundTime[],int burstTime[],int waitingTime[],int n){
    for(int i=0;i<n;i++){
        waitingTime[i]=turnAroundTime[i]-burstTime[i];
    }
}
int main(){
    int n=4;
    int burstTime[n];
    int arrivalTime[n];
    int completeTime[n];
    int turnAroundTime[n];
    int waitingTime[n];
    //burst time input
    cout<<"Enter cpu burst time of processes : \n";
    inputInArray(burstTime,n);
    //arrival time time input
    cout<<"Enter process arrival time of processes : \n";
    inputInArray(arrivalTime,n);
    //sort two array
    sortAndMap(arrivalTime,burstTime,n);
    //calculating completion time
    getCompleteTime(burstTime,arrivalTime,completeTime,n);
    //calculate turn around time
    getTAT(completeTime,arrivalTime,turnAroundTime,n);
    //calculate waiting time
    getWT(turnAroundTime,burstTime,waitingTime,n);
    //printing result
    cout<<"---------RESULT------------\n";
    cout<<"P_ID : CT : BT : AT : TAT : WT\n";
    for(int i=0;i<n;i++){
        cout<<"P"<<i<<" : "<<completeTime[i]<<" : "<<burstTime[i]<<" : "<<arrivalTime[i]<<" : "<<turnAroundTime[i]<<" : "<<waitingTime[i]<<"\n";
    }
    return 0;
}