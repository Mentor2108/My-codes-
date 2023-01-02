#include <bits/stdc++.h>

#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007

#define YOURMENTOR ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define FOR(i, n, k) for(int i = 0; i<n; i+=k)
#define endl "\n"
#define PB push_back
#define F first
#define S second
#define VI vector<int>
#define PII pair<int, int>
#define VPII vector<<int, int>>

using namespace std;

int frame_count, ref_size;

int fifo(VI frame_table, VI ref) 
{
    int fault_count = 0, count = 0;
    bool exitloop = false;

    for (int i = 0; i < ref_size; i++) 
    {
        exitloop = false;
        if (frame_table[count] == -1) 
        {
            frame_table[count] = ref[i];
            count++;
            fault_count++;
            if (count == frame_count)
                count = 0;
        }
        else 
        {
            for (int j = 0; j < frame_count; j++)
            {
                if (frame_table[j] == ref[i])
                {
                    exitloop = true;
                    break;
                }
            }
            if (exitloop == true)
                continue;
            frame_table[count] = ref[i];
            count++;
            fault_count++;
            if (count == frame_count) 
                count = 0;
        }
    }
    return fault_count;
}

int calculateFarthestIndex(VI frame_table, VI ref, int start, VI time)
{
    int count = 0, temp;
    for (int i = start; i < ref_size; i++) 
    {
        temp = count;
        if (frame_table[count] == ref[i]) 
        {
            count++;
            i = start - 1;
        }
    }
    count = 0;
    for (int i = start; i < ref_size; i++) 
    {
        for (int j = 0; j < frame_count; j++) 
        {
            if (frame_table[j] == ref[i] && time[frame_table[j]] == 0) 
            {
                time[frame_table[j]]++;
                count++;
                if (count == frame_count) 
                    temp = j;
            }
        }
    }
    return temp;
}

int optimal(VI frame_table, VI ref, VI time) 
{
    int temp, fault_count = 0, count = 0;
    bool flag = false;
    for (int i = 0; i < ref_size; i++) 
    {
        for (int i = 0; i < 500; i++) 
            time[i] = 0;
        flag = false;
        if (frame_table[count] == -1) 
        {
            frame_table[count] = ref[i];
            count++;
            fault_count++;
            if (count == frame_count) 
                count = 0;
        }
        else
        {
            for (int j = 0; j < frame_count; j++) 
            {
                if (frame_table[j] == ref[i]) 
                {
                    flag = true;
                    break;
                }
            }
            if (flag == true) 
                continue;
            temp = calculateFarthestIndex(frame_table, ref, i, time);
            frame_table[temp] = ref[i];
            fault_count++;
        }
    }
    return fault_count;
}

int lru(VI frame_table, VI ref) {
    int temp_count[frame_count], time = 0, temp, fault_count = 0, count = 0;
    bool flag = false;

    for (int i = 0; i < frame_count; i++)
        temp_count[i] = 0;

    for (int i = 0; i < ref_size; i++)
    {
        time++;
        flag = false;
        if (frame_table[count] == -1) 
        {
            frame_table[count] = ref[i];
            temp_count[count] = time;
            count++;
            fault_count++;
            if (count == frame_count)
                count = 0;
        }
        else 
        {
            for (int j = 0; j < frame_count; j++) 
            {
                if (frame_table[j] == ref[i]) 
                {
                    flag = true;
                    temp_count[j] = time;
                    break;
                }
            }
            if (flag == true)
                continue;
            else //calculates minimum 
            {
                int temp2;
                int temp3 = 500;
                for (int k = 0; k < frame_count; k++) 
                {
                    if (temp_count[k] < temp3) 
                    {
                        temp3 = temp_count[k];
                        temp2 = k;
                    }
                }
                temp = temp2;
                frame_table[temp] = ref[i];
                temp_count[temp] = time;
                fault_count++;
            }
        }
    }

    return fault_count;
}

int main(int argc, char *argv[]) 
{
    frame_count  =  atoi(argv[1]);
    ref_size  =  atoi(argv[2]);
    VI time(500, 0);
    char replacement_policy[14];
    VI ref(ref_size);
    VI frame_table(frame_count, -1);

    for (int i  =  0; i  <  ref_size; i++)
        ref[i] = atoi(argv[i + 3]);
    
    strcpy(replacement_policy, argv[ref_size + 3]);

    if (strcmp(replacement_policy, "FIFO") == 0)
        cout << fifo(frame_table, ref) << endl;

    else if (strcmp(replacement_policy, "OPTIMAL") == 0)
        cout << optimal(frame_table, ref, time) << endl;

    else if (strcmp(replacement_policy, "LRU") == 0)
        cout << lru(frame_table, ref) << endl;

    else
        cout << "replacement policy not specified" << endl;

    return 0;
}