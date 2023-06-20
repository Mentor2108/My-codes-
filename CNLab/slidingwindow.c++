

// Problem 1: Sliding Window Protocol

#include<iostream>
using namespace std;

int main(){
    int window_size;
    cout << "Enter Window Size: ";
    cin >> window_size;

    int frames_no;
    cout << "Enter number of frames: ";
    cin >> frames_no;

    cout << "Enter " << frames_no << " frames: ";

    int frames[frames_no+1];
    for(int i=1;i<=frames_no;i++){
        cin >> frames[i];
    }

    for(int i=1;i<=frames_no;i++)
    {
        if(i%window_size==0)
        {
            cout<<frames[i]<<"\n";
            cout<<"Acknowledgement received by sender\n";
        }
        else
            cout<<frames[i]<<" ";
    }
 
    if(frames_no%window_size!=0)
        cout<<"\nAcknowledgement received by sender\n";
 
    return 0;
}

