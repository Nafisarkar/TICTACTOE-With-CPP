#include<iostream>
#include<random>


void print_Board(char game_board[5][5]);
void palaceBoard(char game_board[5][5],int position,char user);
void wincontrol(char game_board[5][5]);
void ckwin(char pass);


int main(){
    char game_board[5][5]={{' ','|',' ','|',' '},
                           {'-','+','-','+','-'},
                           {' ','|',' ','|',' '},
                           {'-','+','-','+','-'},
                           {' ','|',' ','|',' '}};
    int position;
    char user;
    for(int run=0;run<10;run++){
        wincontrol(game_board);
        system("cls");
        if(run%2==0){
            user = 'p';
        }
        else {
            user = 'c';
        }
        if(user=='c'){
            position = (rand() % 9 ) + 1;
        }
        else{
            print_Board(game_board);
            std::cout<<"POSITION (1-9)->";
            std::cin>>position;
            std::cout<<"YOUR POSITION "<<position<<std::endl;
        }
        palaceBoard(game_board,position,user);
        
    }

    
    return 0;
}

void print_Board(char game_board[5][5]){
        for(int i = 0; i <5;i++){
            for(int j = 0; j <5;j++){
                std::cout<<game_board[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
}

void palaceBoard(char game_board[5][5],int position,char user){
    char point;
    if(user == 'c'){
        point='X';
    }
    else{
        point='O';
    }

    switch(position){
        case 1: game_board[0][0]=point;
                break;
        case 2: game_board[0][2]=point;
                break;
        case 3: game_board[0][4]=point;
                break;
        case 4: game_board[2][0]=point;
                break;
        case 5: game_board[2][2]=point;
                break;
        case 6: game_board[2][4]=point;
                break;
        case 7: game_board[4][0]=point;
                break;
        case 8: game_board[4][2]=point;
                break;
        case 9: game_board[4][4]=point;
                break;
        default: break;
    }    
}

void wincontrol(char game_board[5][5]){
    char pass;
    if     (game_board[0][0] == game_board[0][2] == game_board[0][4]){
        ckwin(game_board[0][0]);
    }
    else if(game_board[2][0] == game_board[2][2] == game_board[2][4]){
        ckwin(game_board[2][0]);
    }
    else if(game_board[4][0] == game_board[4][2] == game_board[4][4]){
        ckwin(game_board[4][0]);
    }
    else if(game_board[0][0] == game_board[2][0] == game_board[4][0]){ 
        ckwin(game_board[0][0]);
    }
    else if(game_board[2][0] == game_board[2][2] == game_board[4][2]){
        ckwin(game_board[2][0]);
    }
    else if(game_board[0][4] == game_board[2][4] == game_board[4][4]){
        ckwin(game_board[0][4]);
    }
    else if(game_board[0][0] == game_board[2][2] == game_board[4][4]){
        ckwin(game_board[0][0]);
    }
    else if(game_board[0][4] == game_board[2][2] == game_board[4][0]){
        ckwin(game_board[0][4]);
    }
}

void ckwin(char pass){
        if(pass=='X'){
            std::cout << "COMPUTER WINS !!" <<std::endl;  
        }
        else{
            std::cout << " YOU WIN !!" <<std::endl;
        }
    }