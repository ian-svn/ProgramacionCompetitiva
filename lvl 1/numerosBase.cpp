// cambiabase_ian-svn

#include <bits/stdc++.h>
using namespace std;

vector<string> cambiabase(vector<int> nums,int b){
    vector<string> numB;

    for(int x=0;x<nums.size();x++){
        string solve;
        do{
            int rest = nums[x]%b;
            solve+=rest+'0';
            nums[x]/=b;
        }while(nums[x]>0);
        reverse(solve.begin(),solve.end());
        numB.push_back(solve); 
    }
    return numB;
}

int main(){

    int N,b;
    cin >> N >> b;

    vector<int> nums;
    for(int x=0;x<N;x++){
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<string> solve = cambiabase(nums,b);

    for(string num : solve){
        cout << num << " ";
    }

    return 0;
}