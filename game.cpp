//============================================================================
// Name        : MUHAMMAD ALI KHAN .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

/*
  NAME : MUHAMMAD ALI KHAN
  SECTION : B
  ROLL NO : i210429
  PROGRAMMING FUNDAMENTALS PROJECT
  RUSH-HOUR GAME
*/


#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include <fstream>                         //INCLUDING ALL THE DESIRED LIBRARIES
#include<string>
#include<stdlib.h>
#include<cmath>                           // library for basic math functions such as cos, sin, sqrt
#include <fstream>
#include <random>

using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 
 /* PLAYER DATA */

int getRandomNumberInRange(int min, int max) {
	int res = rand() % (max - min + 1) + min;
	return res;
}
 
 string player_taxi_color;
 string player_name;                    //DECLARING ALL THE VARIABLES IN STRINGS AND INTEGERS 
 int player_score = 0;
 int curr_time = 0;
 int game_time = 180;
 
 /* PASSENGER-DESTINATION DATA */

 int psngr_x1 = 450;           //VERTICAL AND HORZIONTAL LOCATION AND AXIS OF PASSENGER NUMBER 1
 int psngr_y1 = 150;
 int dstn_x1 = 1600;
 int dstn_y1 = 1600;
 string psngr_1_clr = "RED";  //THE COLOR OF THE PASSENGER 1

 int psngr_x2 = 170;
 int psngr_y2 = 770;         //VERTICAL AND HORZIONTAL LOCATION AND AXIS OF PASSENGER NUMBER 2
 int dstn_x2 = 1600;
 int dstn_y2 = 1600;
 string psngr_2_clr = "YELLOW";   //THE COLOR OF THE PASSENGER 2

 int psngr_x3 = 310;
 int psngr_y3 = 110;         //VERTICAL AND HORZIONTAL LOCATION AND AXIS OF PASSENGER NUMBER 3
 int dstn_x3 = 1600;
 int dstn_y3 = 1600;
 string psngr_3_clr = "YELLOW";   //THE COLOR OF THE PASSENGER 3

  int psngr_x4 = 700;
 int psngr_y4 = 400;          //VERTICAL AND HORZIONTAL LOCATION AND AXIS OF PASSENGER NUMBER 4
 int dstn_x4 = 1600;
 int dstn_y4 = 1600;
 string psngr_4_clr = "YELLOW";   //THE COLOR OF THE PASSENGER 4

  int psngr_x5 = 420;
 int psngr_y5 = 520;          //VERTICAL AND HORZIONTAL LOCATION AND AXIS OF PASSENGER NUMBER 5
 int dstn_x5 = 1600;
 int dstn_y5 = 1600;
 string psngr_5_clr = "YELLOW";   //THE COLOR OF THE PASSENGER 5

  int psngr_x6 = 660;
 int psngr_y6 = 660;          //VERTICAL AND HORZIONTAL LOCATION AND AXIS OF PASSENGER NUMBER 6
 int dstn_x6 = 1600;
 int dstn_y6 = 1600;
 string psngr_6_clr = "YELLOW";   //THE COLOR OF THE PASSENGER 6

  int psngr_x7 = 570;
 int psngr_y7 = 470;           //VERTICAL AND HORZIONTAL LOCATION AND AXIS OF PASSENGER NUMBER 7
 int dstn_x7 = 1600;
 int dstn_y7 = 1600;
 string psngr_7_clr = "YELLOW";   //THE COLOR OF THE PASSENGER 7

  int psngr_x8 = 799;
 int psngr_y8 = 399;             //VERTICAL AND HORZIONTAL LOCATION AND AXIS OF PASSENGER NUMBER 8
 int dstn_x8 = 1600;
 int dstn_y8 = 1600;
 string psngr_8_clr = "YELLOW";   //THE COLOR OF THE PASSENGER 8

  int psngr_x9 = 333;
 int psngr_y9 = 733;             //VERTICAL AND HORZIONTAL LOCATION AND AXIS OF PASSENGER NUMBER 9
 int dstn_x9 = 1600;
 int dstn_y9 = 1600;
 string psngr_9_clr = "YELLOW";   //THE COLOR OF THE PASSENGER 9

  int psngr_x10 = 226;
 int psngr_y10 = 616;           //VERTICAL AND HORZIONTAL LOCATION AND AXIS OF PASSENGER NUMBER 10
 int dstn_x10 = 1600;
 int dstn_y10 = 1600;
 string psngr_10_clr = "YELLOW";   //THE COLOR OF THE PASSENGER 10

 // CURRENT PASSENGER IDENTIFIER
 int psngr_idntfr = 1;
 

 // TRAFFIC
//  DrawCircle(500, 530, 25, colors[LIGHT_STEEL_BLUE]);
// 	DrawCircle(180, 200, 30, colors[LIGHT_PINK]);
// 	DrawCircle(390, 410, 40, colors[DARK_ORCHID]);
// 	DrawCircle(580, 620, 40, colors[PURPLE]);


 int tc_x1 = 780; 		//LOCATIONS
 int tc_y1 = 810;
 
 int tc_x2 = 680; 		//LOCATIONS
 int tc_y2 = 700;
 
 int tc_x3 = 190; 		//LOCATIONS
 int tc_y3 = 210;
 
 int tc_x4 = 480;  		//LOCATIONS
 int tc_y4 = 520;
 
int getPointToDeduct() {
	return player_taxi_color == "R" ? 2 : 4;     //DETERMINING THE TAXI COLOR
} 

void SetCanvasSize(int width, int height)        //FUCNTION FOR SETTING UP THE CANVAS 
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


int xI = 5, yI =840 ;                //INITIAL POSITION OF THE CAR

void drawCar() {
	//DrawCircle(xI, yI, 20, colors[player_taxi_color == "R" ? RED : YELLOW]);	

	DrawRoundRect(xI,yI,40,40, colors[player_taxi_color == "R" ? RED : YELLOW],50);   //DRAW CAR FUNTION
	glutPostRedisplay();              //DRAWING THE CAR ON THE SCREEN
}


bool flag = true;
void moveCar() {                    // MOVEMENT OF THE CAR 
	
	if (xI > 10 && flag) {
		xI -= 10;                  // THE DECREMENT IN THE X-AXIS
		cout << "going left";
		if(xI < 100)
			flag = false;
	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;                 // THE INCREMENT IN THE X-AXIS
		if (xI > 900)
			flag = true;
	}
}

bool tc1_Flag = true;
void moveTraffic() {
	cout<<xI;

	if (tc_x1 > 50 && tc1_Flag)   
	{   
		tc_x1 += 10;
		tc_y2 += 10;                    //MOVEMENTS OF THE RANDOM CARS PLACED IN THE WINDOW
		tc_x3 += 10;
		tc_y4 += 10;

		cout << "going left";          //DIRECTIONS ON THE TERMINAL
		if(tc_x1 > 200)
			flag = false;

	}
	else if (tc_x1 < 1010 && !tc1_Flag) {
		cout << "go right";             //DIRECTIONS ON THE TERMINAL
		tc_x1 -= 10;
		tc_y2 -= 10;                   //MOVEMENTS OF THE RANDOM CARS PLACED IN THE WINDOW
		tc_x3 -= 10;
		tc_y4 -= 10;

		if (tc_x1 < 100)
			tc1_Flag = true;
	}

}

/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
	
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	//glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
	//		0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	//glClearColor(1,1,1,1);
	glClearColor(0.6,0.6,0.6,0.6);             // THE COLOR OF THE BACKGROUND


	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	// TRAFFIC
	 DrawCircle(tc_x1, tc_y1, 20, colors[DARK_BLUE]);         // RANDOM CARS PLACED ON THE WINDOW 
	 DrawCircle(tc_x2, tc_y2, 20, colors[DARK_BLUE]);
	 DrawCircle(tc_x3, tc_y3, 20, colors[DARK_BLUE]);
	 DrawCircle(tc_x4, tc_y4, 20, colors[DARK_BLUE]);

	
	//DrawLine( 0 , 0 ,  100 , 100 , 500 , colors[BLACK] );	
	//DrawLine( 50 , 100 ,  100 , 840 , 50 , colors[BLACK] );	
	//DrawLine( 150 , 150 ,  150 , 840 , 60 , colors[BLACK] );	
	//DrawLine( 200 , 200 ,  200 , 840 , 60 , colors[BLACK] );	
	//DrawLine( 250 , 250 ,  250 , 840 , 70 , colors[BLACK] );	
	//DrawLine( 300 , 300 ,  300 , 840 , 70 , colors[BLACK] );	


	//Display Score
	DrawString( 50, 800, "SCORE=" + to_string(player_score), colors[BLACK]);     //UPDATION IN THE SCORE OF THE CAR
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawCircle( 30, 50 ,40, colors[MISTY_ROSE] ); 

	// GRID
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	
	
	DrawLine( 50 , 0 ,  50 , 840 , 20 , colors[BLACK] );	
	DrawLine( 100 , 0 ,  100 , 840 , 20 , colors[BLACK] );	// LINES DRAWN ON THE GRID
	DrawLine( 150 , 0 ,  150 , 840 , 20 , colors[BLACK] );	
	DrawLine( 200 , 0 ,  200 , 840 , 20 , colors[BLACK] );	
	DrawLine( 250 , 0 ,  250 , 840 , 20 , colors[BLACK] );	
	DrawLine( 300 , 0 ,  300 , 840 , 20 , colors[BLACK] );	
	DrawLine( 350 , 0 ,  350 , 840 , 20 , colors[BLACK] );	
	DrawLine( 400 , 0 ,  400 , 840 , 20 , colors[BLACK] );	
	DrawLine( 450 , 0 ,  450 , 840 , 20 , colors[BLACK] );	
	DrawLine( 500 , 0 ,  500 , 840 , 20 , colors[BLACK] );	
	DrawLine( 550 , 0 ,  550 , 840 , 20 , colors[BLACK] );	// LINES DRAWN ON THE GRID
	DrawLine( 600 , 0 ,  600 , 840 , 20 , colors[BLACK] );	
	DrawLine( 650 , 0 ,  650 , 840 , 20 , colors[BLACK] );	
	DrawLine( 700 , 0 ,  700 , 840 , 20 , colors[BLACK] );
	DrawLine( 750 , 0 ,  750 , 840 , 20 , colors[BLACK] );	
	DrawLine( 800 , 0 ,  800 , 840 , 20 , colors[BLACK] );	
	DrawLine( 850 , 0 ,  850 , 840 , 20 , colors[BLACK] );	
	DrawLine( 900 , 0 ,  900 , 840 , 20 , colors[BLACK] );	
	DrawLine( 950 , 0 ,  950 , 840 , 20 , colors[BLACK] );
	DrawLine( 1000 , 0 ,  1000 , 840 , 20 , colors[BLACK] );	
	DrawLine( 1050 , 0 ,  1050 , 840 , 20 , colors[BLACK] );	
	
	

	// PERSON & DESTINATION

	DrawRoundRect(psngr_x1,psngr_y1,25,35,colors[psngr_1_clr == "RED" ? RED : GRAY],30);   // PASSENGERS DROPING AND COLORS 
	DrawCircle( dstn_x1 , dstn_y1 , 5,colors[FOREST_GREEN]);                                      // COLOR CHANGING FROM RED TO GREY AFTER DROPING THE PASSENGER
	
	DrawRoundRect(psngr_x2,psngr_y2,25,35,colors[psngr_2_clr == "RED" ? RED : GRAY],30);
	DrawCircle( dstn_x2 , dstn_y2 , 5,colors[FOREST_GREEN]); 

	DrawRoundRect(psngr_x3,psngr_y3,25,35,colors[psngr_3_clr == "RED" ? RED : GRAY],30);
	DrawCircle( dstn_x3,dstn_y3,5,colors[FOREST_GREEN]); 

	DrawRoundRect(psngr_x4,psngr_y4,25,35,colors[psngr_4_clr == "RED" ? RED : GRAY],30);
	DrawCircle( dstn_x4,dstn_y4,5,colors[FOREST_GREEN]); 
	
	DrawRoundRect(psngr_x5,psngr_y5,25,35,colors[psngr_5_clr == "RED" ? RED : GRAY],30);  // PASSENGERS DROPING AND COLORS 
	DrawCircle( dstn_x5,dstn_y5,5,colors[FOREST_GREEN]); 
	
	DrawRoundRect(psngr_x6,psngr_y6,25,35,colors[psngr_6_clr == "RED" ? RED : GRAY],30); // COLOR CHANGING FROM RED TO GREY AFTER DROPING THE PASSENGER
	DrawCircle( dstn_x6,dstn_y6,5,colors[FOREST_GREEN]); 
	
	DrawRoundRect(psngr_x7,psngr_y7,25,35,colors[psngr_7_clr == "RED" ? RED : GRAY],30);
	DrawCircle( dstn_x7,dstn_y7,5,colors[FOREST_GREEN]); 
	
	DrawRoundRect(psngr_x8,psngr_y8,25,35,colors[psngr_8_clr == "RED" ? RED : GRAY],30);
	DrawCircle( dstn_x8,dstn_y8,5,colors[FOREST_GREEN]); 
	
	DrawRoundRect(psngr_x9,psngr_y9,25,35,colors[psngr_9_clr == "RED" ? RED : GRAY],30);
	DrawCircle( dstn_x9,dstn_y9,5,colors[FOREST_GREEN]); 
	
	DrawRoundRect(psngr_x10,psngr_y10,25,35,colors[psngr_10_clr == "RED" ? RED : GRAY],30);
	DrawCircle( dstn_x10,dstn_y10,5,colors[FOREST_GREEN]); 
	


	// HURDLES

	DrawSquare(400,900,50,colors[BLACK]);   //DRAWING ALL THE HURDLES
	DrawSquare(400,900,50,colors[BLACK]);
	
	
	DrawSquare(50,450,50,colors[BLACK]);
	DrawSquare(100,450,50,colors[BLACK]);
	DrawSquare(150,450,50,colors[BLACK]);   //DRAWING ALL THE HURDLES

	DrawSquare(700,650,50,colors[BLACK]);
	DrawSquare(742,650,50,colors[BLACK]);
	DrawSquare(780,650,50,colors[BLACK]);
	
	
	//DrawSquare(500,500,50,colors[BLACK]);
	//DrawSquare(500,450,50,colors[BLACK]);
	
	DrawSquare(800,100,50,colors[BLACK]);
	DrawSquare(740,100,50,colors[BLACK]);  //DRAWING ALL THE HURDLES
	DrawSquare(770,100,50,colors[BLACK]);

	DrawRectangle(900,500,50,200,colors[BLACK]);

	DrawRectangle(180,380,50,300,colors[BLACK]);
	                                                  //DRAWING ALL THE HURDLES
	DrawRectangle(700,350,220,40,colors[BLACK]);

	DrawRectangle(500,400,50,300,colors[BLACK]);

	//DrawSquare(800,300,40,colors[BLACK]);
	//DrawSquare(828,300,40,colors[BLACK]);
	//DrawSquare(864,300,40,colors[BLACK]);
	//DrawSquare(870,300,40,colors[BLACK]);

	DrawSquare(100,130,40,colors[BLACK]);
	DrawSquare(132,130,40,colors[BLACK]);
	DrawSquare(165,130,40,colors[BLACK]);
	DrawSquare(200,130,40,colors[BLACK]);


	//DrawRoundRect(200,300, 100,20,colors[BLACK], 0);
	//DrawRoundRect(200,300, 20,100,colors[BLACK], 0);

	//DrawRoundRect(900, 1000, 100,20,colors[BLACK], 0);
	//DrawRoundRect(900,1000, 20,100,colors[BLACK], 0);

	//DrawRoundRect(480,530, 100,20,colors[BLACK], 0);
	//DrawRoundRect(480,530, 20,100,colors[BLACK], 0);

	//DrawRoundRect(400,460, 100,20,colors[BLACK], 0);
	//DrawRoundRect(400,460, 20,100,colors[BLACK], 0);
	
	//DrawRoundRect(600,720, 100,20,colors[BLACK], 0);
	//DrawRoundRect(600,720, 20,100,colors[BLACK], 0);
	
	//DrawRoundRect(170,310, 100,20,colors[BLACK], 0);
	//DrawRoundRect(170,310, 20,100,colors[BLACK], 0);
	
	//DrawRoundRect(270,410, 100,20,colors[BLACK], 0);
	//DrawRoundRect(270,410, 20,100,colors[BLACK], 0);
	
	
	
	//DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);

	//DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	//DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	
	//DrawRoundRect(200,100,100,50,colors[BLACK],40);
	//DrawRoundRect(350,100,100,50,colors[BLACK],20);

	//TREES                  //DRAWING ALL THE TREES IN THE CODE

	DrawTriangle((22*35)+5, (11*35)+16,(22*35)+27, (11*35)+16,(22*35)+16, (11*35)+32,colors[GREEN]);
	DrawLine((22*35)+16, (11*35)+16,(22*35)+16,(11*35),10,colors[BROWN]);

	DrawTriangle((15*35)+5, (5*35)+16,(15*35)+27, (5*35)+16,(15*35)+16, (5*35)+32,colors[GREEN]);
	DrawLine((15*35)+16, (5*35)+16,(15*35)+16,(5*35),10,colors[BROWN]);

	DrawTriangle((25*32)+5, (25*32)+16,(25*32)+27, (25*32)+16,(25*32)+16, (25*32)+32,colors[GREEN]);
	DrawLine((25*32)+16, (25*32)+16,(25*32)+16,(25*32),10,colors[BROWN]);

	DrawTriangle((17*32)+5, (17*32)+16,(17*32)+27, (17*32)+16,(17*32)+16, (17*32)+32,colors[GREEN]);
	DrawLine((17*32)+16, (17*32)+16,(17*32)+16,(17*32),10,colors[BROWN]);
  
	//DRAWING ALL THE TREES IN THE CODE

	DrawTriangle((13*32)+5, (13*32)+16,(13*32)+27, (13*32)+16,(13*32)+16, (13*32)+32,colors[GREEN]);
	DrawLine((13*32)+16, (13*32)+16,(13*32)+16,(13*32),10,colors[BROWN]);

	DrawTriangle((8*32)+5, (8*32)+16,(8*32)+27, (8*32)+16,(8*32)+16, (8*32)+32,colors[GREEN]);
	DrawLine((8*32)+16, (8*32)+16,(8*32)+16,(8*32),10,colors[BROWN]);

	DrawTriangle((5*32)+5, (13*32)+16,(5*32)+27, (13*32)+16,(5*32)+16, (13*32)+32,colors[GREEN]);
	DrawLine((5*32)+16, (13*32)+16,(5*32)+16,(13*32),10,colors[BROWN]);

	//PERSONS
	                    //DRAWING ALL THE PERSONS

	//1       head
	DrawCircle((1*32)+16 ,(1*32)+27,5,colors[BLACK]);

	//body
	DrawLine((1*32)+16,(1*32)+10,(1*32)+16,(1*32)+32,1,colors[BLACK]);

	//arms
	DrawLine((1*32)+5,(1*32)+22,(1*32)+16,(1*32)+16,1,colors[BLACK]);
	DrawLine((1*32)+16,(1*32)+16,(1*32)+27,(1*32)+22,1,colors[BLACK]);

	//legs
	DrawLine((1*32)+16,(1*32)+10,(1*32)+8,(1*32),1,colors[BLACK]);
	DrawLine((1*32)+16,(1*32)+10,(1*32)+24,(1*32),1,colors[BLACK]);

	
	
	//2         head       //DRAWING ALL THE PERSONS
	DrawCircle((17*32)+16 ,(5*32)+27,5,colors[BLACK]);

	//body
	DrawLine((17*32)+16,(5*32)+10,(17*32)+16,(5*32)+32,1,colors[BLACK]);

	//arms
	DrawLine((17*32)+5,(5*32)+22,(17*32)+16,(5*32)+16,1,colors[BLACK]);
	DrawLine((17*32)+16,(5*32)+16,(17*32)+27,(5*32)+22,1,colors[BLACK]);

	//legs
	DrawLine((17*32)+16,(5*32)+10,(17*32)+8,(5*32),1,colors[BLACK]);
	DrawLine((17*32)+16,(5*32)+10,(17*32)+24,(5*32),1,colors[BLACK]);

	
	
	//3        head                  //DRAWING ALL THE PERSONS
	DrawCircle((9*32)+16 ,(20*32)+27,5,colors[BLACK]);

	//body
	DrawLine((9*32)+16,(20*32)+10,(9*32)+16,(20*32)+32,1,colors[BLACK]);

	//arms
	DrawLine((9*32)+5,(20*32)+22,(9*32)+16,(20*32)+16,1,colors[BLACK]);
	DrawLine((9*32)+16,(20*32)+16,(9*32)+27,(20*32)+22,1,colors[BLACK]);

	//legs
	DrawLine((9*32)+16,(20*32)+10,(9*32)+8,(20*32),1,colors[BLACK]);
	DrawLine((9*32)+16,(20*32)+10,(9*32)+24,(20*32),1,colors[BLACK]);

	
	
	//4       head              //DRAWING ALL THE PERSONS
	DrawCircle((20*32)+16 ,(22*32)+27,5,colors[BLACK]);

	//body
	DrawLine((20*32)+16,(22*32)+10,(20*32)+16,(22*32)+32,1,colors[BLACK]);

	//arms
	DrawLine((20*32)+5,(22*32)+22,(20*32)+16,(22*32)+16,1,colors[BLACK]);
	DrawLine((20*32)+16,(22*32)+16,(20*32)+27,(22*32)+22,1,colors[BLACK]);

	//legs
	DrawLine((20*32)+16,(22*32)+10,(20*32)+8,(22*32),1,colors[BLACK]);
	DrawLine((20*32)+16,(22*32)+10,(20*32)+24,(22*32),1,colors[BLACK]);

	//5       head                 //DRAWING ALL THE PERSONS
	DrawCircle((13*32)+16 ,(20*32)+27,5,colors[BLACK]);

	//body
	DrawLine((13*32)+16,(20*32)+10,(13*32)+16,(20*32)+32,1,colors[BLACK]);

	//arms
	DrawLine((13*32)+5,(20*32)+22,(13*32)+16,(20*32)+16,1,colors[BLACK]);
	DrawLine((13*32)+16,(20*32)+16,(13*32)+27,(20*32)+22,1,colors[BLACK]);

	//legs
	DrawLine((13*32)+16,(20*32)+10,(13*32)+8,(20*32),1,colors[BLACK]);
	DrawLine((13*32)+16,(20*32)+10,(13*32)+24,(20*32),1,colors[BLACK]);


/*if ( && tc1_Flag) {

		if()

			flag = false;

	}
	else if ( && !tc1_Flag) {
		

		if ()

			tc1_Flag = true;
	}
	*/

	drawCar();
	glutSwapBuffers(); // do not modify this line..

}

int getCarSpeed(){
	return player_taxi_color == "Y" ? 10 : 5;	
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= getCarSpeed() + player_score;

	} else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += getCarSpeed() + player_score;
	} else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += getCarSpeed() + player_score;
	}

	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= getCarSpeed() + player_score;
	}

	// DEDUCT POINTS IF HITS HURDLES
	// if((xI > 300 && xI < 400) && (yI > 700 && yI < 750)) {
	// 	player_score = player_score - getPointToDeduct();
	// 	yI -= 100;
	// 	xI -= 100;
	// }
	if((xI > 700 && xI < 750) && (yI > 300 && yI < 400)) {                     // STOPPING AND RESTRICTING THE CARS 
		player_score = player_score - getPointToDeduct();
		yI -= 100;                                                            // BY DETERMINING THEIR AXIS LOCATION
		xI -= 100;
	}

	if((xI > 900 && xI < 500) && (yI > 50 && yI < 200)) {                 // STOPPING AND RESTRICTING THE CARS 
		player_score = player_score - getPointToDeduct();
		yI -= 100;
		xI -= 100;                                                        // BY DETERMINING THEIR AXIS LOCATION
	}

	if((xI > 180 && xI < 380) && (yI > 50 && yI < 300)) {                  // STOPPING AND RESTRICTING THE CARS 
		player_score = player_score - getPointToDeduct();
		yI -= 100;
		xI -= 100;                                                        // BY DETERMINING THEIR AXIS LOCATION
	}

	if((xI > 500 && xI < 400) && (yI > 50 && yI < 300)) {
		player_score = player_score - getPointToDeduct();                // RESTRICTING THE MOVEMENTS 
		yI -= 100;
		xI -= 100;
	}					

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}

	// SPACE BAR - pick passenger
	if(key == 32){
		//player_score = "SCORE=1150";
		 
		switch(psngr_idntfr) {				//CASES FOR IDENTIFYINF THE PASSENGERS AT THEIR RESPECTIVE LOCATION
			case 1:
				psngr_x1 = 1500;
				psngr_y1 = 1500;
				dstn_x1 = 750;
				dstn_y1 = 750;

			break;
			case 2:                       	//CASES FOR IDENTIFYINF THE PASSENGERS AT THEIR RESPECTIVE LOCATION
				psngr_x2 = 1500;
				psngr_y2 = 1500;
				dstn_x2 = 350;
				dstn_y2 = 350;
			break;
			case 3:                       	//CASES FOR IDENTIFYINF THE PASSENGERS AT THEIR RESPECTIVE LOCATION
				psngr_x3 = 1500;
				psngr_y3 = 1500;
				dstn_x3 = 420;
				dstn_y3 = 420;
			break;
		
		    case 4:                        	//CASES FOR IDENTIFYINF THE PASSENGERS AT THEIR RESPECTIVE LOCATION
				psngr_x4 = 1500;
				psngr_y4 = 1500;
				dstn_x4 = 120;
				dstn_y4 = 120;
			break;

			case 5:                     	//CASES FOR IDENTIFYINF THE PASSENGERS AT THEIR RESPECTIVE LOCATION
				psngr_x5 = 1500;
				psngr_y5 = 1500;
				dstn_x5 = 670;
				dstn_y5 = 670;
			break;

			case 6:
				psngr_x6 = 1500;
				psngr_y6 = 1500;
				dstn_x6 = 330;
				dstn_y6 = 330;
			break;

			case 7:
				psngr_x7 = 1500;
				psngr_y7 = 1500;
				dstn_x7 = 210;
				dstn_y7 = 210;
			break;

			case 8:
				psngr_x8 = 1500;
				psngr_y8 = 1500;
				dstn_x8 = 800;
				dstn_y8 = 800;
			break;

			case 9:
				psngr_x9 = 1500;
				psngr_y9 = 1500;
				dstn_x9 = 510;
				dstn_y9 = 510;
			break;

			case 10:								//CASES FOR IDENTIFYINF THE PASSENGERS AT THEIR RESPECTIVE LOCATION
				psngr_x10 = 1500;
				psngr_y10 = 1500;
				dstn_x10 = 789;
				dstn_y10 = 789;
			break;
		}
	}

	// TAB - Drop passenger
	if(key == 9){
		switch(psngr_idntfr) 
		{
			case 1:                         //LOCATIONS FOR DISAPPEARING THE PASSENGER AFTER PICKING THE PASSENGER
				psngr_x1 = 750;
				psngr_y1 = 750;
				dstn_x1 = 1600;				//LOCATION OUTSIDE THE WINDOWS FOR SHOWING THAT THE PASSENGER IS BEING PICKED
				dstn_y1 = 1600;
				psngr_1_clr = "YELLOW";
				psngr_2_clr = "RED";
				psngr_idntfr = 2;
				player_score += 10;

			break;
			case 2:
				psngr_x2 = 350;
				psngr_y2 = 350;
				dstn_x2 = 1600;           	//LOCATION OUTSIDE THE WINDOWS
				dstn_y2 = 1600;
				psngr_2_clr = "YELLOW";
				psngr_3_clr = "RED";
				psngr_idntfr = 3;
				player_score += 10;
			break;
			case 3:
				psngr_x3 = 420;
				psngr_y3 = 420;
				dstn_x3 = 1600;           	//LOCATION OUTSIDE THE WINDOWS
				dstn_y3 = 1600;
				psngr_3_clr = "YELLOW";
				psngr_4_clr = "RED";
				psngr_idntfr = 4;
				player_score += 10;
			break;
			case 4:
				psngr_x4 = 120;
				psngr_y4 = 120;
				dstn_x4 = 1600;
				dstn_y4 = 1600;         	//LOCATION OUTSIDE THE WINDOWS
				psngr_4_clr = "YELLOW";
				psngr_5_clr = "RED";
				psngr_idntfr = 5;
				player_score += 10;

			break;
			case 5:
				psngr_x5 = 670;
				psngr_y5 = 670;
				dstn_x5 = 1600;            //LOCATION OUTSIDE THE WINDOWS
				dstn_y5 = 1600;
				psngr_5_clr = "YELLOW";
				psngr_6_clr = "RED";
				psngr_idntfr = 6;
				player_score += 10;

			break;
			case 6:
				psngr_x6 = 330;
				psngr_y6 = 330;
				dstn_x6 = 1600;            //LOCATION OUTSIDE THE WINDOWS
				dstn_y6 = 1600;
				psngr_6_clr = "YELLOW";
				psngr_7_clr = "RED";
				psngr_idntfr = 7;
				player_score += 10;

			break;
			case 7:
				psngr_x7 = 210;
				psngr_y7 = 210;
				dstn_x7 = 1600;
				dstn_y7 = 1600;            //LOCATION OUTSIDE THE WINDOWS
				psngr_7_clr = "YELLOW";
				psngr_8_clr = "RED";
				psngr_idntfr = 8;
				player_score += 10;

			break;
			case 8:
				psngr_x8 = 800;
				psngr_y8 = 800;
				dstn_x8 = 1600;
				dstn_y8 = 1600;            //LOCATION OUTSIDE THE WINDOWS
				psngr_8_clr = "YELLOW";
				psngr_9_clr = "RED";
				psngr_idntfr = 9;
				player_score += 10;

			break;
			case 9:
				psngr_x9 = 510;
				psngr_y9 = 510;
				dstn_x9 = 1600;
				dstn_y9 = 1600;          //LOCATION OUTSIDE THE WINDOWS
				psngr_9_clr = "YELLOW";
				psngr_10_clr = "RED";
			    psngr_idntfr = 10;
				player_score += 10;

			break;
			case 10:
				psngr_x10 = 789;
				psngr_y10 = 789;
				dstn_x10 = 1600;
				dstn_y10 = 1600;           //LOCATION OUTSIDE THE WINDOWS
				psngr_10_clr = "YELLOW";
				psngr_idntfr = 1;
				player_score += 10;

			break;
		}
	}
		
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	//moveCar();
	moveTraffic();                      // CALLING THE FUNCTION FOR MOVING THE RANDOM CARS ON THE ROAD
    
	// once again we tell the library to call our Timer function after next 1000/FPS

	curr_time++;
	if(curr_time == game_time || player_score == 100) {
		glutHideWindow();
		glutLeaveMainLoop();
	}
		
	glutTimerFunc(1000, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}

void windowDisplay(int argc, char*argv[]){
	
	
	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("RUSH HOUR BY MUHAMMAD ALI KHAN"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	glutMainLoop();
	
	
	
}


/*
 * our gateway main function
 * */
int main(int argc, char*argv[])                      //DISPLAYING THE MENU
	{
	
	cout << "***************CHOOSE THE COLOR OF YOUR TAXI*************"<<endl<<endl << endl;    // DISPLAYING THE STANDERED MESSAGES
	cout << "*******ENTER R FOR SELECTING THE RED COLOR*******"<<endl<<endl << endl;
	cout << "*********ENTER Y FOR YELLOW COLOR********"<<endl<<endl << endl;
	
	cin >> player_taxi_color;
	
	if(player_taxi_color == "R" || player_taxi_color == "Y")    //CHECKING IF THE COLOR OF THE TAXI IS YELLOW OR RED
	
	{
	
		cout << "******ENTER THE NAME OF THE USER******"<<endl ;
		cin >> player_name;

		cout << "YOU HAVE CHOOSEN " << player_taxi_color <<"COLOR FOR PLAYING"<<  endl;	
		cout << "PLAYER NAME IS : " << player_name <<  endl;	
	
	} 

	windowDisplay(argc, argv);
	
	if(curr_time == game_time || player_score == 100)        //CONDITION FOR ENDING THE GAME
	{
		cout << "Game Over!";

	string scores[10] = {};
	string names[5] = {};

	fstream fs_name, fs_score;                // FILE HANDLING 
	fs_score.open("highscores.txt", ios:: in);	//again opening the file but in reading mode
	
	int i = 0;
	while (!fs_score.eof()) {
		string score; fs_score >> score;
		if(score.size() > 0){
			scores[i] = score;
			//names[i] = name;
		}
	}
	fs_score.close();
	for(int j=0; j<5;j++){
		cout << scores[j];
	}

	fs_score.open("highscores.txt", ios::out);	
	fs_score << player_name << ":" << to_string(player_score) + "\n";	
	for(int j=0; j<10;j++){
		if(scores[j].size() > 0)
			fs_score << scores[j] + "\n";	
	}
	fs_score.close();	//closing the file
	}		
	return 1;
}
#endif /* RushHour_CPP_ */
