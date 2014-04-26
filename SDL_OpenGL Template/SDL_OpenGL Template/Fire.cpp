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

struct array_coordinate {
    int x;
    int y;
    bool claimed;
};

void SearchNeighborsOfBox(Box &box, Box GameBoard[][4], array_coordinate *targets_to_be_destroyed, int *count,  bool isPlayerOne);
void DropBoxes(Box GameBoard[][4],array_coordinate *targets_to_be_destroyed, int *count);
void SortBoxes(array_coordinate *targets_to_be_destroyed, int *count);


void Fire(Player &player, Box GameBoard[][4])
{
    
    //printf("player position : %d \n", player.array_position);
    
    //Box *targets_to_be_destroyed[16];

    array_coordinate target_coordinates_to_be_destroyed[16];
    
    
    

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


        for (int i = 0; i < target_count; i ++ )
        {
            //GameBoard[target_coordinates_to_be_destroyed[i].x][target_coordinates_to_be_destroyed[i].y].claimed = true;
            printf("square %d to be destroyed coord  %d : %d\n\n\n",i, target_coordinates_to_be_destroyed[i].x, target_coordinates_to_be_destroyed[i].y);
        }
    
        
        //once target is aquired, calculate longest path,
        
        //then destroy path
        
        //Fall
        
        //then Refill boxes
        SortBoxes(target_coordinates_to_be_destroyed, &target_count);
        DropBoxes(GameBoard, target_coordinates_to_be_destroyed, &target_count);

        
    }
    
    if (player.player)
    {
        // If player 2
        cout <<"Player 2 " << endl;
        int target_count = 0;
        
        //Box target = GameBoard[3][player.array_position];
        GameBoard[3][player.array_position].claimed = true;
        
        target_coordinates_to_be_destroyed[target_count].x = GameBoard[3][player.array_position].array_position_x;
        target_coordinates_to_be_destroyed[target_count].y = GameBoard[3][player.array_position].array_position_y;
        target_coordinates_to_be_destroyed[target_count].claimed = true;
        
        printf("start grid  %d : %d\n", target_coordinates_to_be_destroyed[target_count].x, target_coordinates_to_be_destroyed[target_count].y);
        target_count++;
        
        
        
        
        
        
        SearchNeighborsOfBox(GameBoard[3][player.array_position], GameBoard, target_coordinates_to_be_destroyed, &target_count, player.player);
        
        cout <<"TARGET COUNT " << target_count << endl;
        
        
        for (int i = 0; i < target_count; i ++ )
        {
            //GameBoard[target_coordinates_to_be_destroyed[i].x][target_coordinates_to_be_destroyed[i].y].claimed = true;
            printf("square %d to be destroyed coord  %d : %d\n\n\n",i, target_coordinates_to_be_destroyed[i].x, target_coordinates_to_be_destroyed[i].y);
        }

      
        SortBoxes(target_coordinates_to_be_destroyed, &target_count);
        DropBoxes(GameBoard, target_coordinates_to_be_destroyed, &target_count);
    }
    
    
    
    
}


//recursive search function

void SearchNeighborsOfBox(Box &box, Box GameBoard[][4], array_coordinate *targets_to_be_destroyed, int *count,  bool isPlayerOne)
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

    if (box.array_position_y < 3)
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
        if (box.array_position_x < 3)
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

    for(int i=0;i<*count;i++){
        
        cout << targets_to_be_destroyed[i].x << ", " << targets_to_be_destroyed[i].y << endl;
    }
    
    int temp;
    int cnt =0;
    array_coordinate tempArray[16];
    for (int k = 0; k<4; k++) {
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
    cout << "Sorted" << endl;
    for(int i=0;i<*count;i++){
        
        cout << targets_to_be_destroyed[i].x << ", " << targets_to_be_destroyed[i].y << endl;
    }
    
    
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
        
        if(targets_to_be_destroyed[i].y > 3){
            targets_to_be_destroyed[i].y = 0;
        }
    }
    
    cout << "Sorted" << endl;
    for(int i=0;i<*count;i++){
        
        cout << targets_to_be_destroyed[i].x << ", " << targets_to_be_destroyed[i].y << endl;
    }
    

    
    
}

void DropBoxes(Box GameBoard[][4],array_coordinate *targets_to_be_destroyed, int *count){
    
    for(int colm = 0; colm < 4; colm++){
    
        for(int i =0; i < *count ; i++){
            if(targets_to_be_destroyed[i].x == colm){
                
                if(targets_to_be_destroyed[i].y == 0){
                    GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].DropTop();
                }else if(targets_to_be_destroyed[i].y == 1){
                
                    GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].Drop(
                                                                                               GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 1]);
                    GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 1].DropTop();
                }else if(targets_to_be_destroyed[i].y == 2){
                    GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].Drop(
                                                                                               GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 1]);
                    GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -1].Drop(
                                                                                               GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 2]);
                    GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 2].DropTop();
                
                }else{
                    GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y].Drop(
                                                                                               GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 1]);
                    
                    GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y-1].Drop(
                                                                                               GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 2]);
                    GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y -2].Drop(
                                                                                                  GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 3]);
                    GameBoard[targets_to_be_destroyed[i].x][targets_to_be_destroyed[i].y - 3].DropTop();
                
                }
                
            }else{
                break;
            }
        }
    
    
    
    }
    

}








