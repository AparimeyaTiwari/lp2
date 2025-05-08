#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool isSafe(vector<string> &board,int row,int col,int N){
    
    //check vertically
    for(int x=0;x<row;x++){
        if(board[x][col] == 'Q'){
            return false;
        }
    }

    //check upper left diagonal
    for(int x=row-1,y=col-1;x>=0&&y>=0;x--,y--){
        if(board[x][y] == 'Q'){
            return false;
        }
    }

    //check upper right diagonal
    for(int x=row-1,y=col+1;x>=0 && y<N;x--,y++){
        if(board[x][y]=='Q'){
            return false;
        }
    }

    return true;
}

void nQueens(vector<string> &board,int row,int n, vector<vector<string> > &answer){
    if(row == n){
        answer.push_back(board);
        return;
    }

    for(int i = 0;i<n;i++){
        if(isSafe(board,row,i,n)){
            board[row][i] = 'Q';
            nQueens(board,row+1,n,answer);
            board[row][i] = '.';
        }
    }
}
int main(){
    int N; // number of queens
    cout<<"Enter number of queens: ";
    cin>>N;
    vector<string> board(N,string(N,'.'));// intializing our board
    vector<vector <string> > answer;
    nQueens(board,0,N,answer);
    int i = 0;
    for(auto it1:answer){
        i += 1;
        cout<<"ANSWER NUMBER: "<<i<<endl;
        for(auto it2:it1){
            cout<<it2<<endl;
        }
        cout<<"\n";
    }
    return 0;
}
