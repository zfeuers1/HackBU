//
//  Fire.cpp
//  HAX
//
//  Created by Zach Lite on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "Fire.h"
#include "Box.h"
#include <iostream>
using namespace std;
//need number of columns (4)

//(int p[][numCols]



void SearchNeighborsOfBox(Box &box, Box GameBoard[][8], array_coordinate *targets_to_be_destroyed, int *count,  bool isPlayerOne);
void DropBoxes(Box GameBoard[][8],array_coordinate *targets_to_be_destroyed, int *count);
void SortBoxes(array_coordinate *targets_to_be_destroyed, int *count);


bool Fire(Player &player, Box GameBoard[][8])
{
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            GameBoard[i][i].claimed=false;
        }
    }
    //printf("player position : %d \n", player.array_position);
    
    //Box *targets_to_be_destroyed[16];
    
    array_coordinate target_coordinates_to_be_destroyed[64];
    
    
    
    
    //need to fire
    
    //search the appropriate column of gameboard
    
    if (!player.player)
    {
        //if player 1
        cout <<"Player 1 " << endl;
        
        int target_count = 0;
        
        //Box target = GameBoard[0][player.array_position];
        GameBoard[0][player.array_position].claimed = true;
        
        
        //targets_to_be_destroyed[target_count] = &GameBoard[0][player.array_position];
        
        target_coordinates_to_be_destroyed[target_count].x = GameBoard[0][player.array_position].array_position_x;
        target_coordinates_to_be_destroyed[target_count].y = GameBoard[0][player.array_position].array_position_y;
        target_coordinates_to_be_destroyed[target_count].claimed = true;
        
        printf("start grid  %d : %d\n", target_coordinates_to_be_destroyed[target_count].x, target_coordinates_to_be_destroyed[target_count].y);
        target_count++;
        
        
        
        
        
        
        SearchNeighborsOfBox(GameBoard[0][player.array_position], GameBoard, target_coordinates_to_be_destroyed, &target_count, player.player);
        
        cout <<"TARGET COUNT " << target_count << endl;
        
        bool player1_made_path = false;
        for (int i = 0; i < target_count; i ++ )
        {
            //GameBoard[target_coordinates_to_be_destroyed[i].x][target_coordinates_to_be_destroyed[i].y].claimed = true;
            printf("square %d to be destroyed coord  %d : %d\n\n\n",i, target_coordinates_to_be_destroyed[i].x, target_coordinates_to_be_destroyed[i].y);
            
            if (target_coordinates_to_be_destroyed[i].x == 7)
            {
                player1_made_path = true;
            }
            
            
        }
        
        SortBoxes(target_coordinates_to_be_destroyed, &target_count);
        DropBoxes(GameBoard, target_coordinates_to_be_destroyed, &target_count);
        
        
       
        return player1_made_path;

        
        
    }
    
    else
    {
        // If player 2
        cout <<"Player 2 " << endl;
        int target_count = 0;
        
        //Box target = GameBoard[3][player.array_position];
        GameBoard[7][player.array_position].claimed = true;
        
        target_coordinates_to_be_destroyed[target_count].x = GameBoard[7][player.array_position].array_position_x;
        target_coordinates_to_be_destroyed[target_count].y = GameBoard[7][player.array_position].array_position_y;
        target_coordinates_to_be_destroyed[target_count].claimed = true;
        
        printf("start grid  %d : %d\n", target_coordinates_to_be_destroyed[target_count].x, target_coordinates_to_be_destroyed[target_count].y);
        target_count++;
        
        
        
        
        
        
        SearchNeighborsOfBox(GameBoard[7][player.array_position], GameBoard, target_coordinates_to_be_destroyed, &target_count, player.player);
        
        cout <<"TARGET COUNT " << target_count << endl;
        
        bool player2_made_path = false;
        for (int i = 0; i < target_count; i ++ )
        {
            //GameBoard[target_coordinates_to_be_destroyed[i].x][target_coordinates_to_be_destroyed[i].y].claimed = true;
            printf("square %d to be destroyed coord  %d : %d\n\n\n",i, target_coordinates_to_be_destroyed[i].x, target_coordinates_to_be_destroyed[i].y);
            
            if (target_coordinates_to_be_destroyed[i].x == 0)
            {
                player2_made_path = true;
            }
        }
        
        
        
        SortBoxes(target_coordinates_to_be_destroyed, &target_count);
        DropBoxes(GameBoard, target_coordinates_to_be_destroyed, &target_count);
        
        return player2_made_path;
        
    }
    
    
    
    
}


//recursive search function

void SearchNeighborsOfBox(Box &box, Box GameBoard[][8], array_coordinate *targets_to_be_destroyed, int *count,  bool isPlayerOne)
{
    //calling claimed int the wrong place
    
    Box neighbor;
    
    //search above box
    
    if (box.array_position_y > 0)
    {
        
        neighbor = GameBoard[box.array_position_x][box.array_position_y - 1];
        
        if((neighbor.color == box.color) && (!neighbor.claimed))
        {
            
            cout << "match above" << endl;
            
            
            targets_to_be_destroyed[*count].x = GameBoard[box.array_position_x ][box.array_position_y - 1].array_position_x;
            targets_to_be_destroyed[*count].y = GameBoard[box.array_position_x ][box.array_position_y - 1].array_position_y;
            targets_to_be_destroyed[*count].claimed = true;
            
            GameBoard[box.array_position_x ][box.array_position_y - 1].claimed = true;
            
            
            *count += 1;
            
            //TODO recursive neighbor finding
            SearchNeighborsOfBox(GameBoard[box.array_position_x][box.array_position_y - 1], GameBoard, targets_to_be_destroyed, count, isPlayerOne);
        }
        
    }
    
    
    //search below box
    
    if (box.array_position_y < 7)
    {
        
        neighbor = GameBoard[box.array_position_x][box.array_position_y + 1];
        if (neighbor.color == box.color && (!neighbor.claimed))
        {
            cout << "match below" << endl;
            
            
            
            targets_to_be_destroyed[*count].x = GameBoard[box.array_position_x ][box.array_position_y + 1].array_position_x;
            targets_to_be_destroyed[*count].y = GameBoard[box.array_position_x ][box.array_position_y + 1].array_position_y;
            targets_to_be_destroyed[*count].claimed = true;
            
            GameBoard[box.array_position_x ][box.array_position_y + 1].claimed = true;
            
            
            *count += 1;
            
            SearchNeighborsOfBox(GameBoard[box.array_position_x][box.array_position_y + 1], GameBoard, targets_to_be_destroyed, count, isPlayerOne);
            
            
            
        }
        
    }
    
    
    
    
    
    
    
    
    //search box to side
    
    if (!isPlayerOne)
    {
        if (box.array_position_x < 7)
        {
            neighbor = GameBoard[box.array_position_x + 1][box.array_position_y];
            if (neighbor.color == box.color && (!neighbor.claimed))
            {
                cout << "match right" << endl;
                
                
                targets_to_be_destroyed[*count].x = GameBoard[box.array_position_x + 1 ][box.array_position_y ].array_position_x;
                targets_to_be_destroyed[*count].y = GameBoard[box.array_position_x + 1][box.array_position_y ].array_position_y;
                targets_to_be_destroyed[*count].claimed = true;
                
                GameBoard[box.array_position_x + 1 ][box.array_position_y].claimed = true;
                
                
                *count += 1;
                
                SearchNeighborsOfBox(GameBoard[box.array_position_x + 1][box.array_position_y], GameBoard, targets_to_be_destroyed, count, isPlayerOne);
                
                
                
                
            }
            
            
        }
        
    }
    else
    {
        if (box.array_position_x > 0)
        {
            
            neighbor = GameBoard[box.array_position_x - 1][box.array_position_y];
            if (neighbor.color == box.color && (!neighbor.claimed))
            {
                
                cout << "match left" << endl;
                
                
                
                targets_to_be_destroyed[*count].x = GameBoard[box.array_position_x - 1 ][box.array_position_y ].array_position_x;
                targets_to_be_destroyed[*count].y = GameBoard[box.array_position_x - 1][box.array_position_y ].array_position_y;
                targets_to_be_destroyed[*count].claimed = true;
                GameBoard[box.array_position_x - 1 ][box.array_position_y].claimed = true;
                
                
                
                *count += 1;
                
                
                
                SearchNeighborsOfBox(GameBoard[box.array_position_x - 1][box.array_position_y], GameBoard, targets_to_be_destroyed, count, isPlayerOne);
                
            }
            
        }
    }
    
    
    
    
}




















void SortBoxes(array_coordinate *targets_to_be_destroyed, int *count){
    
    
    
    int temp;
    int cnt =0;
    array_coordinate tempArray[64];
    for (int k = 0; k<8; k++) {
        for (int j=0; j<*count; j++) {
            if (targets_to_be_destroyed[j].x == k) {
                tempArray[cnt].x = targets_to_be_destroyed[j].x;
                tempArray[cnt].y = targets_to_be_destroyed[j].y;
                cnt++;
            }
        }
    }
    
    for(int j=0; j<*count; j++){
        targets_to_be_destroyed[j].x = tempArray[j].x;
        targets_to_be_destroyed[j].y =  tempArray[j].y;
    }
    /*cout << "Sorted" << endl;
     for(int i=0;i<*count;i++){
     
     cout << targets_to_be_destroyed[i].x << ", " << targets_to_be_destroyed[i].y << endl;
     }*/
    
    
    for(int row = 0; row< *count; row++){
        for (int colm = row; colm < *count ; colm++) {
            if(targets_to_be_destroyed[row].x == targets_to_be_destroyed[colm + 1].x){
                if(targets_to_be_destroyed[row].y > targets_to_be_destroyed[colm + 1].y){
                    
                    temp = targets_to_be_destroyed[row].y;
                    targets_to_be_destroyed[row].y = targets_to_be_destroyed[colm+1].y;
                    targets_to_be_destroyed[colm+1].y = temp;
                }
                
                
            }
        }
    }
    
    for(int i=0;i<*count;i++){
        
        if(targets_to_be_destroyed[i].y > 7 || targets_to_be_destroyed[i].y < 0){
            targets_to_be_destroyed[i].y = 0;
        }
    }
    
    /*cout << "Sorted" << endl;
     for(int i=0;i<*count;i++){
     
     cout << targets_to_be_destroyed[i].x << ", " << targets_to_be_destroyed[i].y << endl;
     }*/
    for(int i=0;i<*count;i++){
        
        cout << targets_to_be_destroyed[i].x << ", " << targets_to_be_destroyed[i].y << endl;
    }
    
    
    
    
}

void DropBoxes(Box GameBoard[][8],array_coordinate *targets_to_be_destroyed, int *count){
    cout << endl << endl;
    for(int i=0;i<*count;i++){
        
        cout << targets_to_be_destroyed[i].x << ", " << targets_to_be_destroyed[i].y << endl;
    }
    int i = 0;
    for(int colm = 0; colm < 8; colm++){
        while(targets_to_be_destroyed[i].x == colm){
            
            
            if(targets_to_be_destroyed[i].y == 0){
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].DropTop();
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].claimed=false;
                cout << "Colm = " << colm << endl;
                cout << "Destroy Top" << endl;
                
            }else if(targets_to_be_destroyed[i].y == 1){
                
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].Drop(
                                                                                           GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 1]);
                
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 1].DropTop();
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 1].claimed=false;
                cout << "Colm = " << colm << endl;
                
                cout << "Destroy 2" << endl;
                cout << "Destroy Top" << endl;
            }else if(targets_to_be_destroyed[i].y == 2){
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].Drop(
                                                                                           GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 1]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -1].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 2]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 2].DropTop();
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-1].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-2].claimed=false;
                cout << "Colm = " << colm << endl;
                
                cout << "Destroy 3" << endl;
                cout << "Destroy 2" << endl;
                cout << "Destroy Top" << endl;
                
            }else if(targets_to_be_destroyed[i].y == 3){
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].Drop(
                                                                                           GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 1]);
                
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-1].Drop(
                                                                                             GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 2]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -2].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 3]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 3].DropTop();
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-1].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-2].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-3].claimed=false;
                cout << "Colm = " << colm << endl;
                
                cout << "Destroy 4" << endl;
                cout << "Destroy 3" << endl;
                cout << "Destroy 2" << endl;
                cout << "Destroy Top" << endl;
                
            }else if(targets_to_be_destroyed[i].y == 4){
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].Drop(
                                                                                           GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 1]);
                
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-1].Drop(
                                                                                             GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 2]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -2].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 3]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -3].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 4]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 4].DropTop();
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-1].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-2].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-3].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-4].claimed=false;
            }
            else if(targets_to_be_destroyed[i].y == 5){
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].Drop(
                                                                                           GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 1]);
                
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-1].Drop(
                                                                                             GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 2]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -2].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 3]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -3].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 4]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -4].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 5]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 5].DropTop();
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-1].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-2].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-3].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-4].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-5].claimed=false;
            }
            else if(targets_to_be_destroyed[i].y == 6){
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].Drop(
                                                                                           GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 1]);
                
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-1].Drop(
                                                                                             GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 2]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -2].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 3]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -3].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 4]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -4].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 5]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -5].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 6]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 6].DropTop();
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-1].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-2].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-3].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-4].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-5].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-6].claimed=false;
            }
            else if(targets_to_be_destroyed[i].y == 7){
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].Drop(
                                                                                           GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 1]);
                
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-1].Drop(
                                                                                             GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 2]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -2].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 3]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -3].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 4]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -4].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 5]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -5].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 6]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -6].Drop(
                                                                                              GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 7]);
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 7].DropTop();
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-1].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-2].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-3].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-4].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-5].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-6].claimed=false;
                GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-7].claimed=false;

            }
            
            i++;
        }
        
    }
}







