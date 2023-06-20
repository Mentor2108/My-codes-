#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a;
    string arr;
    cin>>arr;
    vector<int> ans;
    for(int i=0;i<N;i++){
        ans.push_back(arr[i]-48);
    }
    int cnt=0;
    int i=0;
    for(auto q: arr){
        i++;
        if(q=='1'){
            cnt++;
        }else{
            cnt=0;
        }
        if(cnt==5){
            ans.erase(ans.begin()+i);
            cnt=0;
        }
    }

    for(auto q: ans){
        cout << q << " ";    
    }
}