#include <bits/stdc++.h>
using namespace std;
int check(int tic[][3]){
    for(int i=0; i<3; i++){
        if(tic[i][0]==tic[i][1] && tic[i][1]==tic[i][2] && tic[i][0]!=0)return tic[i][0];
        if(tic[0][i]==tic[1][i] && tic[1][i]==tic[2][i] && tic[0][i]!=0)return tic[0][i];
    }
    if(tic[0][0]==tic[1][1] && tic[1][1]==tic[2][2] && tic[0][0]!=0)return tic[0][0];
    if(tic[0][2]==tic[1][1] && tic[1][1]==tic[2][0] && tic[0][2]!=0)return tic[0][2];
    return 0;
}
void printtic(int tic[][3]){
    printf("   1   2   3\n");
    for(int i=0; i<3; i++){
        cout<<i+1<<"";
        for(int j=0; j<3; j++){
            if(j==0)cout<<" ";
            if(tic[i][j]==0)cout<<" . ";
            else if(tic[i][j]==1)cout<<" O ";
            else if(tic[i][j]==2)cout<<" X ";
            if(j!=2)cout<<"|";
        }
        cout<<endl<<"  __________"<<endl;
    }
    
}

int play(string p1, string p2, int tic[][3]){
    int win=0, x, y;
    int flag=1;
    for(int i=1; i<=9; i++){
        if(flag==1){
            cout<<p1<<", please enter coordinates of your move: ";
        }
        else {
            cout<<p2<<", please enter coordinates of your move: ";
        }
        while(1){
            cin>>x>>y;
            if(x>3||x<1||y>3||y<1)cout<<"Wrong coordinates! Please enter again: ";
            else if(tic[x-1][y-1]!=0)cout<<"Already occupied! Try entering some other coordinates: ";
            else break;
        }
        tic[x-1][y-1]=flag;
        printtic(tic);
        if(i>=5){
            win=check(tic);
            if(win!=0)return win;
        }
        flag=flag%2+1;
    }
    return 0;
}

int main(){
    int tic[3][3];
    for(int i=0; i<3; i++)for(int j=0; j<3; j++)tic[i][j]=0;
    string p1, p2;
    cout<<"Enter the name of player 1 (first to move- O): ";
    cin>>p1;
    cout<<"Enter the name of player 2 (second to move- X): ";
    cin>>p2;
    int win=play(p1, p2, tic);
    if(win==1)cout<<"Game Over!\n"<<p1<<" Wins!";
    else if(win==2)cout<<"Game Over!\n"<<p2<<" Wins!";
    else cout<<"Game Over!\n"<<"Draw!";
    return 0;
}