#include<iostream>
#include<random>


void print_Board(char game_board[5][5]);
void palaceBoard(char game_board[5][5],int position,char user);
int dumAI();
void winchk(char gb[5][5]);
void call_winner(char c);

int main(){
    char game_board[5][5]={{' ','|',' ','|',' '},
                           {'-','+','-','+','-'},
                           {' ','|',' ','|',' '},
                           {'-','+','-','+','-'},
                           {' ','|',' ','|',' '}};
                           
    int position,count=0;
    char user;
    int player_array[5];
    for(int run=0;run<9;run++){
        
        system("cls");
        if(run%2==0){
            user = 'p';
        }
        else {
            user = 'c';
        }
        if(user=='c'){
            position = dumAI();
        }
        else{
            print_Board(game_board);
            std::cout<<"POSITION (1-9)->";    
            std::cin>>position;
            player_array[count]=position;
            count++;
            std::cout<<"YOUR POSITION "<<position<<std::endl;
        }
        palaceBoard(game_board,position,user);
    }
    print_Board(game_board);
    for(int j=0;j<5;j++){
        std::cout<<player_array[j]<<std::endl;
    }
    return 0;
}

void print_Board(char game_board[5][5]){
        winchk(game_board);
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
        case 1: if(user == 'c' && game_board[0][0]=='O'){
                    position = dumAI();
                    palaceBoard(game_board,position,user);
                    break;
                }
                else{
                    game_board[0][0]=point;
                    break;
                }
        case 2: if(user == 'c' && game_board[0][2]=='O'){
                    position=dumAI();
                    palaceBoard(game_board,position,user);
                    break;
                }
                else{
                    game_board[0][2]=point;
                    break;
                }
        case 3: if(user == 'c' && game_board[0][4]=='O'){
                    position=dumAI();
                    palaceBoard(game_board,position,user);
                    break;
                }
                else{
                    game_board[0][4]=point;
                    break;
                }
        case 4: if(user == 'c' && game_board[2][0]=='O'){
                    position=dumAI();
                    palaceBoard(game_board,position,user);
                    break;
                }
                else{
                    game_board[2][0]=point;
                    break;
                }
        case 5: if(user == 'c' && game_board[2][2]=='O'){
                    position=dumAI();
                    palaceBoard(game_board,position,user);
                    break;
                }
                else{
                    game_board[2][2]=point;
                    break;
                }
        case 6: if(user == 'c' && game_board[2][4]=='O'){
                    position=dumAI();
                    palaceBoard(game_board,position,user);
                    break;
                }
                else{
                    game_board[2][4]=point;
                    break;
                }
        case 7: if(user == 'c' && game_board[4][0]=='O'){
                    position=dumAI();
                    palaceBoard(game_board,position,user);
                    break;
                }
                else{
                    game_board[4][0]=point;
                    break;
                }
        case 8: if(user == 'c' && game_board[4][2]=='O'){
                    position=dumAI();
                    palaceBoard(game_board,position,user);
                    break;
                }
                else{
                    game_board[4][2]=point;
                    break;
                }
        case 9: if(user == 'c' && game_board[4][4]=='O'){
                    position=dumAI();
                    palaceBoard(game_board,position,user);
                    break;
                }
                else{
                    game_board[4][4]=point;
                    break;
                }
        default: break;
    }
    
}

int dumAI(){
    int ran = (rand() % 9 ) + 1;
    std::cout<<"ran is "<<ran<<std::endl;
    return ran;
}

void winchk(char gb[5][5]){
    if(gb[0][0]==gb[0][2]&&gb[0][4]==gb[0][2]&&gb[0][0]!=' '){
        call_winner(gb[0][0]);
    }
    else if(gb[2][0]==gb[2][2]==gb[2][4]&&gb[2][0]!=' '){
        call_winner(gb[2][0]);
    }
    else if(gb[4][0]==gb[4][2]==gb[4][4]&&gb[4][0]!=' '){
        call_winner(gb[4][0]);
    }
}

void call_winner(char c){
    if(c == 'O'){
        std::cout<<"winner is you!"<<std::endl;
        system("exit");
    }
    else{
        std::cout<<"Winner is the dumAI"<<std::endl;
        system("exit");
    }
}