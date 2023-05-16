#include<bits/stdc++.h>

using namespace std;

int main()
{
    int algo, proc_count;
    cin>>algo; // reads which algorithm
    cin>>proc_count; // read no of processes
    vector<int> arrival_time(proc_count), burst_time(proc_count);
    for(int i =0; i<proc_count; i++)
        cin>>arrival_time[i]; //Reads Arrival Time
    for(int i = 0; i<proc_count; i++)
        cin>>burst_time[i]; // Reads Burst Time

    // Initialising and Declaring vectors for the processes
    vector<int> ready_queue(proc_count, 0), completion_time(proc_count,-1), start_time(proc_count, -1);
    vector<int> response_time(proc_count, 0), waiting_time(proc_count, 0), turnaround_time(proc_count, 0);
    vector<int> remaining_time = burst_time; //RT = BT initially

    // Algorithm 1: FCFS
    if (algo == 1)
    {
        // Sorting Based on Arrival Time
        vector<pair<int, int>> temp(proc_count);
        for(int i =0; i<proc_count; i++)
        {
            temp[i].second = i;
            temp[i].first = arrival_time[i];
        }
        sort(temp.begin(), temp.end());
        for(int i = 0; i<proc_count; i++)
        {
            ready_queue[i] = temp[i].second;
        }

        int t = 0;
        while (ready_queue.size() > 0)
        {
            if (t >= arrival_time[ready_queue[0]]) // when there are items to schedule
            {
                //for deleting the first element of the ready queue
                vector<int>::iterator it;
                it = ready_queue.begin();
                int p = *it; // p is now the running process
                ready_queue.erase(it); 

                start_time[p] = t;
                completion_time[p] = start_time[p] + burst_time[p];
                response_time[p] = start_time[p] - arrival_time[p];
                turnaround_time[p] = completion_time[p] - arrival_time[p];
                waiting_time[p] = turnaround_time[p] - burst_time[p];
                t = completion_time[p] - 1;  // skip to the time when p completes
            }
            t++;
        }
    }
    // Algorithm 2: SJF
    else if (algo == 2)
    {
        int t = 0;
        // Sorting Based on Arrival Time
        vector<pair<int, int>> temp(proc_count);
        for(int i =0; i<proc_count; i++)
        {
            temp[i].second = i;
            temp[i].first = arrival_time[i];
        }
        sort(temp.begin(), temp.end());
        for(int i = 0; i<proc_count; i++)
        {
            ready_queue[i] = temp[i].second;
        }

        while (ready_queue.size() > 0)
        {
            if (t >= arrival_time[ready_queue[0]])
            {
                int count = 0;
                for (auto i: ready_queue) // check how many processes are ready to be queued
                    if (t >= arrival_time[i])
                        count++;
                        // Sorting Based on Arrival Time
                
                // sort available processes based on burst times
                vector<pair<int, int>> temp(count);
                for(int i = 0; i < count; i++)
                {
                    temp[i].second = ready_queue[i];
                    temp[i].first = burst_time[i];
                }
                sort(temp.begin(), temp.end());
                for(int i = 0; i<count; i++)
                {
                    ready_queue[i] = temp[i].second;
                }
                
                //For removing first element of the ready_queue
                vector<int>::iterator it;
                it = ready_queue.begin();
                int p = *it; // p is now the running process
                ready_queue.erase(it); 

                start_time[p] = t;
                completion_time[p] = start_time[p] + burst_time[p];
                response_time[p] = start_time[p] - arrival_time[p];
                turnaround_time[p] = completion_time[p] - arrival_time[p];
                waiting_time[p] = turnaround_time[p] - burst_time[p];
                t = completion_time[p] - 1;
            }       
            t++;
        }
    }

    //Algorithm 3: SRTF
    else if (algo == 3)
    {
        int t = 0, p = 0;

        // Sorting Based on Arrival Time
        vector<pair<int, int>> temp(proc_count);
        for(int i =0; i<proc_count; i++)
        {
            temp[i].second = i;
            temp[i].first = arrival_time[i];
        }
        sort(temp.begin(), temp.end());
        for(int i = 0; i<proc_count; i++)
        {
            ready_queue[i] = temp[i].second;
        }

        while (ready_queue.size() > 0)
        {
            int count = 0;
            for (auto i: ready_queue)
                if (t >= arrival_time[i])
                    count++;
            std::cout<<"hi";
            if (std::count(arrival_time.begin(), arrival_time.end(), t) == 0 || t == completion_time[p] && count!=0) 
             // only preempt when something new occurs
            {
                std::cout<<"hello";
                if (t < completion_time[p]) // save the state of preemted process and add it back to ready queue
                {
                    ready_queue.insert(ready_queue.begin(), p);
                    remaining_time[p] = completion_time[p] - t;
                }
                count = 0;
                for (auto i: ready_queue)
                    if (t >= arrival_time[i])
                        count++;

                // sort available processes based on remaining burst times
                vector<pair<int, int>> temp(count);
                for(int i = 0; i < count; i++)
                {
                    temp[i].second = ready_queue[i];
                    temp[i].first = remaining_time[i];
                }
                sort(temp.begin(), temp.end());
                for(int i = 0; i<count; i++)
                {
                    ready_queue[i] = temp[i].second;
                }

                //For removing first element of the ready_queue
                vector<int>::iterator it;
                it = ready_queue.begin();
                int p = *it; // p is now the running process
                ready_queue.erase(it); 

                if (start_time[p] == -1) // only if being processed 1st time
                    start_time[p] = t;
                completion_time[p] = t + remaining_time[p];
                response_time[p] = start_time[p] - arrival_time[p];
                turnaround_time[p] = completion_time[p] - arrival_time[p];
                waiting_time[p] = turnaround_time[p] - burst_time[p];
            }
            t++;
        }
    }

    // priority preemprive scheduling
    // same as SRTF but second sorting is based on priority rather than remaining time
    else if (algo == 4)
    {
        vector<int> priority_val(proc_count);
        for(int i =0; i<proc_count; i++)
            cin>>priority_val[i]; //Reads the priority Values
        
        int t = 0, p = 0;
        // Sorting Based on Arrival Time
        vector<pair<int, int>> temp(proc_count);
        for(int i =0; i<proc_count; i++)
        {
            temp[i].second = i;
            temp[i].first = arrival_time[i];
        }
        sort(temp.begin(), temp.end());
        for(int i = 0; i<proc_count; i++)
        {
            ready_queue[i] = temp[i].second;
        }

        while (ready_queue.size() > 0)
        {
            int count = 0;
            for (auto i: ready_queue)
                if (t >= arrival_time[i])
                    count++;
            if (std::count(arrival_time.begin(), arrival_time.end(), t) == 0 || t == completion_time[p] && count!=0)
             // only preempt when something new occurs
            {
                if (t < completion_time[p])
                {
                    ready_queue.insert(ready_queue.begin(), p);
                    remaining_time[p] = completion_time[p] - t;
                }
                count = 0;
                for (auto i: ready_queue)
                    if (t >= arrival_time[i])
                        count++;

                // sort available processes based on Priority Value
                vector<pair<int, int>> temp(count);
                for(int i = 0; i < count; i++)
                {
                    temp[i].second = ready_queue[i];
                    temp[i].first = priority_val[i];
                }
                sort(temp.begin(), temp.end());
                for(int i = 0; i<count; i++)
                {
                    ready_queue[i] = temp[i].second;
                }    

                //For removing first element of the ready_queue
                vector<int>::iterator it;
                it = ready_queue.begin();
                int p = *it; // p is now the running process
                ready_queue.erase(it); 

                if (start_time[p] == -1)
                    start_time[p] = t;
                completion_time[p] = t + remaining_time[p];
                response_time[p] = start_time[p] - arrival_time[p];
                turnaround_time[p] = completion_time[p] - arrival_time[p];
                waiting_time[p] = turnaround_time[p] - burst_time[p];
            }
            t++;
        }      
    }
    //Algorithm 5: RR
    else if (algo == 5)
    {
        int time_quantum;
        cin>>time_quantum;
        
        ready_queue.clear(); // ready queue concept is used differnetly than previous ones
        int t = arrival_time[0];
        for (int i: arrival_time)
            t = min(i, t);
        int p = 0, timer = time_quantum;

        while (ready_queue.size() > 0 || t <= *max_element(arrival_time.begin(), arrival_time.end()))
        {
            int l = arrival_time.size();
            for (int i = 0; i<l; i++) // as soon as a process arrives, append it to ready queue
                if (t == arrival_time[i])
                    ready_queue.push_back(i);

            if ((t >= completion_time[p] || timer >= time_quantum) && ready_queue.size() > 0) // preemnt when time quantum expires or process burst time ends
            {
                if (t < completion_time[p]) // add preempted process at the end on queue
                {
                    ready_queue.push_back(p);
                    remaining_time[p] = completion_time[p] - t;
                }

                //For removing first element of the ready_queue
                vector<int>::iterator it;
                it = ready_queue.begin();
                int p = *it; // p is now the running process
                ready_queue.erase(it); 


                if (start_time[p] == -1)
                    start_time[p] = t;
                completion_time[p] = t + remaining_time[p];
                response_time[p] = start_time[p] - arrival_time[p];
                turnaround_time[p] = completion_time[p] - arrival_time[p];
                waiting_time[p] = turnaround_time[p] - burst_time[p];
                timer = 0; // reset the time quantum timer
            }
            t++;
            timer++;
        }
    }
    double throughput = (double) proc_count / (double) *max_element(completion_time.begin(), completion_time.end());
    for(int i = 0; i<proc_count; i++)
        std::cout<<waiting_time[i]<<" ";
    std::cout<<endl;
    for(int i = 0; i<proc_count; i++)
        std::cout<<response_time[i]<<" ";
    std::cout<<endl;
    for(int i = 0; i<proc_count; i++)
        std::cout<<turnaround_time[i]<<" ";
    std::cout<<endl;
    std::cout<<throughput;
    // print(*waiting_time, sep=' ')
    // print(*response_time, sep=' ')
    // print(*turnaround_time, sep=' ')
    // print("%.4f"%throughput)
}