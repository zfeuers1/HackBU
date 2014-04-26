//
//  Fire.cpp
//  HAX
//
//  Created by Zach Lite on 4/25/14.
//  Copyright (c) 2014 Zach Lite. All rights reserved.
//

#include "Fire.h"

//need number of columns (4)

//(int p[][numCols]

struct array_coordinate {
    int x;
    int y;
    bool claimed;
};

void SearchNeighborsOfBox(Box &box, Box GameBoard[][4], array_coordinate *targets_to_be_destroyed, int *count,  bool isPlayerOne);


void Fire(Player &player, Box GameBoard[][4])
{
    
    //printf("player position : %d \n", player.array_position);
    
    //Box *targets_to_be_destroyed[16];

    array_coordinate target_coordinates_to_be_destroyed[16];
    
    
    

    //need to fire
    
    //search the appropriate column of gameboard
    
    if (!player.player)
    {
        //if player 0
        
        int target_count = 0;

        //Box target = GameBoard[0][player.array_position];
        GameBoard[0][player.array_position].claimed = true;

        
        //targets_to_be_destroyed[target_count] = &GameBoard[0][player.array_position];

        target_coordinates_to_be_destroyed[target_count].x = GameBoard[0][player.array_position].array_position_x;
        target_coordinates_to_be_destroyed[target_count].y = GameBoard[0][player.array_position].array_position_y;
        target_coordinates_to_be_destroyed[target_count].claimed = true;
        
        printf("gameboard to be destroyed coord  %d : %d\n\n\n\n\n", target_coordinates_to_be_destroyed[target_count].x, target_coordinates_to_be_destroyed[target_count].y);
        target_count++;

        

    

        
        SearchNeighborsOfBox(GameBoard[0][player.array_position], GameBoard, target_coordinates_to_be_destroyed, &target_count, player.player);

        cout <<"TARGET COUNT " << target_count << endl;


        for (int i = 0; i < target_count; i ++ )
        {
            GameBoard[target_coordinates_to_be_destroyed[i].x][target_coordinates_to_be_destroyed[i].y].claimed = true;
            printf("square %d to be destroyed coord  %d : %d\n\n\n",i, target_coordinates_to_be_destroyed[i].x, target_coordinates_to_be_destroyed[i].y);
        }
        
        
        //now array of targets to be destroyed should be complete
        
//        for(int i = 0; i < target_count; i++)
//        {
//            
//            if (target_coordinates_to_be_destroyed[i].claimed)
//            {
//                printf("Box destroyed %d : %d\n", target_coordinates_to_be_destroyed[i].x, target_coordinates_to_be_destroyed[i].y);
//            }
//            
//        }
        
        
        
        
        
        
    
        
        //once target is aquired, calculate longest path,
        
        //then destroy path
        
        //Fall
        
        //then Refill boxes
        
        
    }
    
    
}


//recursive search function

void SearchNeighborsOfBox(Box &box, Box GameBoard[][4], array_coordinate *targets_to_be_destroyed, int *count,  bool isPlayerOne)
{
    

    Box neighbor;
    
    //search above box

    if (box.array_position_y > 0)
    {
        cout << "search above" <<endl;
        
        neighbor = GameBoard[box.array_position_x][box.array_position_y - 1];
        
        if((neighbor.color == box.color) && (!neighbor.claimed))
        {
            
            cout << "match above" << endl;
            

            targets_to_be_destroyed[*count].x = GameBoard[box.array_position_x ][box.array_position_y - 1].array_position_x;
            targets_to_be_destroyed[*count].y = GameBoard[box.array_position_x ][box.array_position_y - 1].array_position_y;
            targets_to_be_destroyed[*count].claimed = true;
           
            printf("square to be destroyed coord  %d : %d\n\n\n", targets_to_be_destroyed[*count].x, targets_to_be_destroyed[*count].y);

            *count += 1;



            
            
            //TODO recursive neighbor finding
            //SearchNeighborsOfBox(GameBoard[box.array_position_x][box.array_position_y - 1], GameBoard, targets_to_be_destroyed, count, isPlayerOne);
        }
        else
        {
//            cout << "colors do not match.  printing both";
//            cout << "Box coordinate : " << box.array_position_x << " "  << box.array_position_y << endl;;
//            cout << "neighbor coordinate : " << neighbor.array_position_x <<" "  << neighbor.array_position_y << endl;;

            
        }
    }
   

    //search below box

    if (box.array_position_y < 3)
    {
        cout << "search below" <<endl;

        neighbor = GameBoard[box.array_position_x][box.array_position_y + 1];
        if (neighbor.color == box.color && (!neighbor.claimed))
        {
            cout << "match below" << endl;

            

            targets_to_be_destroyed[*count].x = GameBoard[box.array_position_x ][box.array_position_y + 1].array_position_x;
            targets_to_be_destroyed[*count].y = GameBoard[box.array_position_x ][box.array_position_y + 1].array_position_y;
            targets_to_be_destroyed[*count].claimed = true;
           
            printf("square to be destroyed coord  %d : %d\n\n\n", targets_to_be_destroyed[*count].x, targets_to_be_destroyed[*count].y);

            *count += 1;

            //SearchNeighborsOfBox(GameBoard[box.array_position_x][box.array_position_y + 1], GameBoard, targets_to_be_destroyed, count, isPlayerOne);


            
        }
        else
        {
//            cout <<"LKSDJKFJLDJSK"<<endl;
//            cout << "colors do not match.  printing both";
//            cout << "Box coordinate : " << box.array_position_x << " "  << box.array_position_y << endl;;
//            cout << "neighbor coordinate : " << neighbor.array_position_x <<" "  << neighbor.array_position_y << endl;;

        }
    }
    
  
    
    
    
    
    
    
    //search box to side
    
    if (!isPlayerOne)
    {
        cout << "is player one " << endl;
        if (box.array_position_x < 3)
        {
            cout << "need to search neigbor" << endl;
            neighbor = GameBoard[box.array_position_x + 1][box.array_position_y];
            if (neighbor.color == box.color && (!neighbor.claimed))
            {
                cout << "match right" << endl;


                targets_to_be_destroyed[*count].x = GameBoard[box.array_position_x + 1 ][box.array_position_y ].array_position_x;
                targets_to_be_destroyed[*count].y = GameBoard[box.array_position_x + 1][box.array_position_y ].array_position_y;
                targets_to_be_destroyed[*count].claimed = true;

                printf("square to be destroyed coord  %d : %d\n\n\n", targets_to_be_destroyed[*count].x, targets_to_be_destroyed[*count].y);

                *count += 1;

                //SearchNeighborsOfBox(GameBoard[box.array_position_x + 1][box.array_position_y], GameBoard, targets_to_be_destroyed, count, isPlayerOne);

                


            }
            //else
//                cout << "colors do not match.  printing both";
//            cout << "Box coordinate : " << box.array_position_x << " "  << box.array_position_y << endl;;
//            cout << "neighbor coordinate : " << neighbor.array_position_x <<" "  << neighbor.array_position_y << endl;;


        }
        
    }
    else
    {        cout << "is player two " << endl;

        if (box.array_position_x > 0)
        {
            cout << "need to search neigbor" << endl;

            neighbor = GameBoard[box.array_position_x - 1][box.array_position_y];
            if (neighbor.color == box.color && (!neighbor.claimed))
            {

                cout << "match left" << endl;


                targets_to_be_destroyed[*count].x = GameBoard[box.array_position_x - 1 ][box.array_position_y ].array_position_x;
                targets_to_be_destroyed[*count].y = GameBoard[box.array_position_x - 1][box.array_position_y ].array_position_y;
                targets_to_be_destroyed[*count].claimed = true;
                
                
                *count += 1;


                
                //SearchNeighborsOfBox(GameBoard[box.array_position_x - 1][box.array_position_y], GameBoard, targets_to_be_destroyed, count, isPlayerOne);

            }
            else
            {
//                cout << "colors do not match.  printing both";
//                cout << "Box coordinate : " << box.array_position_x << " "  << box.array_position_y << endl;;
//                cout << "neighbor coordinate : " << neighbor.array_position_x <<" "  << neighbor.array_position_y << endl;;

                
            }
        }
    }
    

    

}




//bool isColorEqualtoColor







