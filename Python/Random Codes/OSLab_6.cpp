//Taking input from File, but apparently the file input doesn't work in Euclid, so taking input normally
// We can replace cin with num to take input.

#include <bits/stdc++.h>

#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007

#define FOR(i, n, k) for(int i = 0; i<n; i+=k)
#define endl "\n"
#define PB push_back
#define F first
#define S second
#define VI vector<int>
#define PII pair<int, int>
#define VPII vector<pair<int, int>>

using namespace std;

vector<VI> max_resources, allocated_resources, need_resources, safe_sequence_all;
VI total_resources;

int resource_count;
int process_count;

void initializeData() {
    //Taking input from File, but apparently the file input doesn't work in Euclid, so taking input normally
    //We can replace cin with num to take input.

    // ifstream num("input.txt");
    int temp;

    // read number of resources and processes
    /*num >> resource_count;
    num >> process_count; */
    
    //Normal Input
    cin>>resource_count;
    cin>>process_count;


    // initialize total resources
    for (int i = 0; i < resource_count; i++) {
        // num >> temp;
        cin>>temp;
        total_resources.PB(temp);
    }

    // initialize the 2D vectors now that we have the dimensions
    max_resources.resize(process_count, VI(resource_count, -1));
    allocated_resources.resize(process_count, VI(resource_count, -1));
    need_resources.resize(process_count, VI(resource_count, -1));

    // fill the max resources matrix
    for (int i = 0; i < process_count; i++) {
        for (int j = 0; j < resource_count; j++) {
            // num >> max_resources[i][j];
            cin>>max_resources[i][j];
        }
    }

    // fill the allocated resources matrix
    for (int i = 0; i < process_count; i++) {
        for (int j = 0; j < resource_count; j++) {
            // num >> allocated_resources[i][j];
            cin >> allocated_resources[i][j];
        }
    }

    // fill the need resources matrix
    for (int i = 0; i < process_count; i++) {
        for (int j = 0; j < resource_count; j++) {
            need_resources[i][j] = max_resources[i][j] - allocated_resources[i][j];
        }
    }
}

bool canFinish(int process, VI available_resources) {
    for (int i = 0; i < resource_count; i++) {
        if (need_resources[process][i] > available_resources[i])
            return false;
    }

    return true;
}

void calculateSafeSequence(VI available_resources, VI safe_sequence, vector<bool> finished) {
    for (int i = 0; i < process_count; i++) {
        if (!finished[i] && canFinish(i, available_resources)) {
            // update available resources since process finished
            for (int j = 0; j < resource_count; j++)
            {
                available_resources[j] += allocated_resources[i][j];
            }
            finished[i] = true;
            
            // recursively call the function to print lexicographically
            safe_sequence.PB(i);
            calculateSafeSequence(available_resources, safe_sequence, finished);
            safe_sequence.pop_back();
            
            finished[i] = false;
            for (int j = 0; j < resource_count; j++)
            {
                available_resources[j] -= allocated_resources[i][j];
            }
        }
    }
    int l = safe_sequence.size();
    if (l == process_count) {
        safe_sequence_all.PB(safe_sequence);
    }

}

int main(int argc, char *argv[]) {
    initializeData();
    
    VI available_resources(resource_count);
    for (int i = 0; i < resource_count; i++) {
        int used = 0;
        for (int j = 0; j < process_count; j++) {
            used += allocated_resources[j][i];
        }
        available_resources[i] = total_resources[i] - used;
    }
    
    VI safe_sequence;
    vector<bool> finished(process_count, false);
    calculateSafeSequence(available_resources, safe_sequence, finished);
    int l = safe_sequence_all.size();
    cout << safe_sequence_all.size() << endl;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < process_count; j++) {
            cout << safe_sequence_all[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}