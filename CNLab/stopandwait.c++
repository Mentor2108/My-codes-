
// Problem 1: Stop and Wait Protocol
#include<iostream>
// #include<windows.h>
#include<unistd.h>
#include<random>
using namespace std;

int main(){
    int frames;
    cout << "Enter number of frames: ";
    cin >> frames;

    cout << "Frame_No ";
    cout << "Data\t";
    cout << "Waiting_Time(Sec) ";
    cout << "Acknowledgement ";
    cout << "Resend\n";

    for(int i=1;i<=frames;i++){
        cout << i << " \t ";
        cout << rand()%100 << "\t\t";

        int time = (rand()%(3)+1);
        if(time != 3){
            for(int i=1;i<=time;i++){
                sleep(1);
                if(i!=time){
                    cout << i << ",";
                }else{
                    cout << i << "\t\t";
                }
            }
            cout << "Yes\t   ";
            cout << "No\n";
        }else{
            for(int i=1;i<=time;i++){
                sleep(1);
                if(i!=time){
                    cout << i << ",";
                }else{
                    cout << i << "\t\t";
                }
            }
            cout << "No\t   ";
            cout << "Resend\n";
        }   
    }
    cout << "All the data packets are transmitted";
}


