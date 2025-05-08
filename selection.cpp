#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void swap(int &a,int&b){
    int temp = a;
    a = b;
    b = temp;
}

void print_array(vector<int> a){
    for(int i = 0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}

void selection_sort(vector<int>& arr){
    for(int i = 0;i<arr.size();i++){
        int min_ind = i;
        for(int j = i;j<arr.size();j++){
            if(arr[j]<arr[min_ind]){
                min_ind = j;
            }
        }
        swap(arr[i],arr[min_ind]);
    }
    print_array(arr);
} 

int main(){
    int N;
    cout<<"Enter the number of elements in the array: ";
    cin>>N;
    vector<int> arr(N);
    for(int i = 0;i<N;i++){
        cout<<"Enter number at postion: "<<i+1<<": ";
        cin>>arr[i];
    }
    selection_sort(arr);
}
