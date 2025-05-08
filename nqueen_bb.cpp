#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void nqueens(vector<string> &board, int row,int n, vector<vector<string >> &answer,vector<int> &column,vector<int> &leftdiag,vector<int> &rightdiag){
    if(row == n){
        answer.push_back(board);
        return;
    }

    for(int i = 0;i<n;i++){
        if(column[i]==0 && leftdiag[row-i+n-1] == 0 && rightdiag[row+i]==0){
            board[row][i] = 'Q';
            column[i] = 1;
            leftdiag[row-i+n-1] = 1;
            rightdiag[row+i] = 1;
            nqueens(board,row+1,n,answer,column,leftdiag,rightdiag);
            board[row][i] = '.';
            column[i] = 0;
            leftdiag[row-i+n-1] = 0;
            rightdiag[row+i] = 0;

        }
    }
}

int main(){
    int n,row,coloumn;
    cout<<"Enter number of queens: ";
    cin>>n;
    vector<string> board(n,string(n,'.'));
    vector<vector<string> > answer;
    vector<int> column(n,0);
    vector<int> leftdiag(2*n-1,0);
    vector<int> rightdiag(2*n-1,0);
    nqueens(board,0,n,answer,column,leftdiag,rightdiag);
    int i = 0;
    for(auto it:answer){
        cout<<"Answer number: "<<i+1<<endl;
        for(auto it1:it){
            cout<<it1<<"\n";
        }
        cout<<"\n";
        i++;
    }
    return 0;
}