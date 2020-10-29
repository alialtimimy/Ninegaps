#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int attempts = 0;     
 
int change;
   
int main_board[9]={1,2,3,4,5,6,7,8,9}; // It defines the main board to store all the values from 1-9
int missing_array[9]; // This line generates an array of size 9 to keep track of missing values
int game_board[9]; // It defines an array to form the actual game board with random numbers and hidden values
int temp_board[9]; // It defines an array which is a copy of the game_board and will be displayed to the user and will be updated in each iteration
int row_results[3]; // this is an array that stores the results of calculation of each row
int column_results[3]; // this is an array that stores the results of calculation of each column
char operators_array[12]; // this is an array that stores random operations
int r;
int n; 
int rn; //rn is for random numbers
int t; //t is for temp 
int diff; //lvl of difficulty
char cg; // this is to check if the user solved the game
int pg; // variable for play again
int mc; // missing number variable
   
srand(time(NULL));  //random generator
 
do{ //loop begins
cg=1;
diff=0;
printf("Welcome to Nine-Gaps game!...\n"); //outputs a welcome message and the following
printf("*****************************\n");
printf("      *****************      \n");
printf("            *****            \n");
printf("              *              \n");

        //loop begins
do{
printf("Choose the level of difficulty:1-Beginner, 2-Intermediate, 3-Advanced, 4-Expert\n"); //asks user for difficulty
scanf("%d",&diff); //reads users input
if ((diff < 1) || (diff > 4)) //if statement checking if the correct difficulty has been chosen
printf("The entered value is not valid\n"); //if diff is not between 1 and 4, outputs a error message
else{
switch (diff){ //switch statement for difficulty 
case 1:
printf("Beginner chosen!\n"); //output for "1"
break; //break so it does not go through the other cases 
case 2:
printf("Intermediate chosen!\n"); //output for "2" 
break;  //break so it does not go through the other cases 
case 3:
printf("Advanced chosen!\n"); //output for "3"
break;  //break so it does not go through the other cases 
case 4:
printf("Expert chosen!\n"); //output for "4"
break;  //break so it does not go through the other cases 
       }
       break;
   }
   } while (1); //while loop when its true  
       

for(int r = 8; r > 0; r--){ //for loop begins for main board
rn = rand() % (r + 1); //equation for random numbers
change = main_board[r];
main_board[r] = main_board[rn];
main_board[rn] = change;
}
for(int r = 0; r < 9; r++){ //for loop begins 

}

puts(" ");

   
int operators_array_COPY[12]; //this part gives us 12 operands "+" or "-" or "*"
for(int r = 0; r < 12; r++){ //for loop begins
rn = rand()%3 + 1; 
operators_array_COPY[r] = rn;
}
for(r = 0; r < 12; r++){
if(operators_array_COPY[r] == 1){ //if statement for operators
operators_array[r] = '+';
}
if(operators_array_COPY[r] == 2){ 
operators_array[r] = '-';
}
if(operators_array_COPY[r] == 3){
operators_array[r] = 'x';
}
}

for(r = 0; r < 12; r++){ //for loop 
}

puts(" ");
//calculates results for row and column operations
row_results[0] = main_board[0];                      
row_results[1] = main_board[3];
row_results[2] = main_board[6];

column_results[0] = main_board[0];
column_results[1] = main_board[1];
column_results[2] = main_board[2];

for(r = 0; r < 2; r++){ //row 1
if(operators_array[r] == '+'){
row_results[0] = row_results[0] + main_board[r+1];
}
if(operators_array[r] == '-'){
row_results[0] = row_results[0] - main_board[r+1];
}
if(operators_array[r] == 'x'){
row_results[0] = row_results[0] * main_board[r+1];
}
}
for(r = 2; r < 4; r++){ //row 2
if(operators_array[r] == '+'){
row_results[1] = row_results[1] + main_board[r+2];
}
if(operators_array[r] == '-'){
row_results[1] = row_results[1] - main_board[r+2];
}
if(operators_array[r] == 'x'){
row_results[1] = row_results[1] * main_board[r+2];
}
}
for(r = 4; r < 6; r++){ //row 2
if(operators_array[r] == '+'){
row_results[2] = row_results[2] + main_board[r+3];
}
if(operators_array[r] == '-'){
row_results[2] = row_results[2] - main_board[r+3];
}
if(operators_array[r] == 'x'){                                
row_results[2] = row_results[2] * main_board[r+3];
}
}
for(r = 6; r < 8; r++){ //row 1
n = r;
if(r == 7){
n = 9;
}
if(operators_array[n] == '+'){
column_results[0] = column_results[0] + main_board[n-3];
}
if(operators_array[n] == '-'){
column_results[0] = column_results[0] - main_board[n-3];
}
if(operators_array[n] == 'x'){
column_results[0] = column_results[0] * main_board[n-3];
}
}
for(r = 7; r < 9; r++){ // row 1
n = r;
if(r == 8){
n = 10;
}

if(operators_array[n] == '+'){
column_results[1] = column_results[1] + main_board[n-3];
}
if(operators_array[n] == '-'){
column_results[1] = column_results[1] - main_board[n-3];
}
if(operators_array[n] == 'x'){
column_results[1] = column_results[1] * main_board[n-3];
}
}

for(r = 8; r < 10; r++){ //row 1
n = r;
if(r == 9){
n = 11;
}

if(operators_array[n] == '+'){
column_results[2] = column_results[2] + main_board[n-3];
}
if(operators_array[n] == '-'){
column_results[2] = column_results[2] - main_board[n-3];
}
if(operators_array[n] == 'x'){
column_results[2] = column_results[2] * main_board[n-3];
}
}
//outputs results
printf("Results for row 1: %d\n", row_results[0]);
printf("Results for row 2: %d\n", row_results[1]);
printf("Results for row 3: %d\n", row_results[2]);
printf("Results for column 1: %d\n", column_results[0]);
printf("Results for column 2: %d\n", column_results[1]);
printf("Results for column 3: %d\n", column_results[2]);

       
for(r = 0; r < 9; r++){
missing_array[r] = 0;
}

printf(" \n"); 
for(int r = 0; r < 9; r++){ //for loop begins 
game_board[r] = main_board[r];
}

puts(" ");
r=0; // initialize to 0
int o = rand()%8; 
int p = rand()%8; 
int q = rand()%8;
if(diff == 1){ //if statement for difficulty 1 (what happens to board)
o = rand()%8;
p = rand()%8;
q = rand()%8;
while(o == p || o == q || q == p){ //while loop
o = rand()%8;
p = rand()%8;
q = rand()%8;
}
missing_array[o] = game_board[o]; 
missing_array[p] = game_board[p];
missing_array[q] = game_board[q];
game_board[o] = '?'; //outputs '?' for missing values
game_board[p] = '?';
game_board[q] = '?';
}
if(diff == 2){ //if statement for difficulty 2 
q = rand()%8;
while(r < 2){
r++; //increments r by 1 in loop
o = rand()%8;
p = rand()%8;
while(o == p || game_board[o] == '?' || game_board[p] == '?' || p == q || q == o){ 
o = rand()%8;
o = rand()%8;
}
missing_array[o] = game_board[o];
missing_array[p] = game_board[p];

game_board[o] = '?'; //outputs '?' for missing values 
game_board[p] = '?';

}
missing_array[q] = game_board[q];
game_board[q] = '?';
}
if(diff == 3){ //if statement for difficulty 3
q = rand()%8;
while(r < 3){
r++;
o = rand()%8;
p = rand()%8;
while(o == p || game_board[o] == '?' || game_board[p] == '?' || p== q || q == o){
o = rand()%8;
p = rand()%8;
}
missing_array[o] = game_board[o];
missing_array[p] = game_board[p];
game_board[o] = '?'; //outputs ? for missing values 
game_board[p] = '?';
}
missing_array[q] = game_board[q];
game_board[q] = '?';
}
if(diff == 4){ //if statement for difficulty 4
r = 0;
while(r < 9){
missing_array[r] = game_board[r];
game_board[r] = '?';
r++;
}
}

printf(" \n");  
for(int r = 0; r < 9; r++){ //copies gameboard into temp board
temp_board[r] = game_board[r];
}

printf(" \n");
do{
       
        
//updates board every time new values are entered
printf("Game Board:\n");
printf("---------------------------------------------------\n");


for (r=0;r<3;r++){
if (r>0){                
for (n=0;n<3;n++){
printf(" %c\t\t", operators_array[3*(r+1)+ n]);
}
printf("\n");
}
               
for (n=0;n<3;n++){          
if (game_board[(r*3)+n]!='?')
printf(" %d\t ", temp_board[(r*3)+n]);
else if (game_board[(r*3)+n]!=temp_board[(r*3)+n]){
printf(" %d?\t ", temp_board[(r*3)+n]);
}	
else
printf(" ?\t ");
               
if (n<2)
printf(" %c\t", operators_array[(r*2) + n]);
else
printf("= %d", row_results[r]);       //output results
}
printf("\n");
if (r==2)
printf (" =\t\t =\t\t =\n");    
}	
for (r=0;r<3;r++)               //output results 
printf(" %d\t\t", column_results[r]);
printf("\n---------------------------------------------------\n");
//outputs missing values
mc = 0; //initializes mc to 0
int missing_array_SPECIFICVALUES[9];	
printf("Missing Variables:");
if(diff != 4){ //if statement for difficulty 4
for(int r = 0;r < 9; r++){
if(missing_array[r] != 0){
mc++; //increments mc
missing_array_SPECIFICVALUES[r] = missing_array[r];
}
}
}else if(diff == 4){
for(int r = 0;r < 10; r++){
if(missing_array[r] != 0){
mc++;
missing_array_SPECIFICVALUES[r] = missing_array[r];
}
}
}


if(diff == 4){
for (r = 0 ; r < 9; r++){
for (n = 0 ; n < r; n++){
if (missing_array_SPECIFICVALUES[n] > missing_array_SPECIFICVALUES[n+1]) /* For decreasing order use < */
{
t = missing_array_SPECIFICVALUES[n];
missing_array_SPECIFICVALUES[n]   = missing_array_SPECIFICVALUES[n+1];
missing_array_SPECIFICVALUES[n+1] = t;
}
}
}
}

for(int r = 0;r < 9; r++){
if(missing_array[r] != 0){
printf("% d,", missing_array_SPECIFICVALUES[r]);
}
}

puts(" ");
if(mc != 0){
printf("Missing Total #: %d", mc);
}else{
printf("Missing Total #: none");
}

puts(" ");

        
       
//break if the missing values are empty    

if(missing_array[0] == 0 && missing_array[1] == 0 && missing_array[2] == 0 && missing_array[3] == 0 && missing_array[4] == 0 && missing_array[5] == 0 && missing_array[6] == 0 && missing_array[7] == 0 && mc == 0){
break;
}


//ask the user to enter a row column and value

printf("Enter a row number (1-3), column(1-3), value(One of the missing values):\n");
int m; //initializes y
int e;  //initializes y
int y; //initializes y
scanf("%d %d %d", &m, &e, &y); //reads m, e and y and stores 
if (m==0 || e==0 || y==0) 
break;
       
if (r < 1 || r > 3 || e < 1 || e > 3){
puts("Invalid row and/or column numbers. Try again.");
continue;
}
if (y < 1 || y > 9) {
printf("value incorrect. Try again.\n");
continue;
       }
if(m == 1 && e == 1 && y != main_board[0]){
attempts = attempts+1;
}
if(m == 1 && e == 2 && y != main_board[1]){
attempts = attempts+1;
}
if(m == 1 && e == 3 && y != main_board[2]){
attempts = attempts+1;

}
if(m == 2 && e == 1 && y != main_board[3]){
attempts = attempts+1;
}
if(m == 2 && e == 2 && y != main_board[4]){
attempts = attempts+1;
}
if(m == 2 && e == 3 && y != main_board[5]){
attempts = attempts+1;
}
if(m == 3 && e == 1 && y != main_board[6]){
attempts = attempts+1;
printf("Trials: %d/5", attempts);
}
if(m == 3 && e == 2 && y != main_board[7]){
attempts = attempts+1;
}
if(m == 3 && e == 3 && y != main_board[8]){
attempts = attempts+1;
}



           

//if the cell is changeable it adds the value into the cell and takes it off the missing values, if not, it gives an error and repeats the loop



puts(" ");

if(m ==1 && e == 1 && y == main_board[0]){
missing_array[0] = 0;
temp_board[0] = main_board[0];
}
if(m ==1 && e == 2 && y == main_board[1]){
missing_array[1] = 0;
temp_board[1] = main_board[1];
}
if(m ==1 && e == 3 && y == main_board[2]){
missing_array[2] = 0;
temp_board[2] = main_board[2];
}
if(m ==2 && e == 1 && y == main_board[3]){
missing_array[3] = 0;
temp_board[3] = main_board[3];
}
if(m ==2 && e == 2 && y == main_board[4]){
missing_array[4] = 0;
temp_board[4] = main_board[4];
}
if(m ==2 && e == 3 && y == main_board[5]){
missing_array[5] = 0;
temp_board[5] = main_board[5];
}
if(m ==3 && e == 1 && y == main_board[6]){
missing_array[6] = 0;
temp_board[6] = main_board[6];
}
if(m ==3 && e == 2 && y == main_board[7]){
missing_array[7] = 0;
temp_board[7] = main_board[7];
}
if(m ==3 && e == 3 && y == main_board[8]){
missing_array[8] = 0;
temp_board[8] = main_board[8];
}

if(attempts > 5){
cg = 1;
break;
}



} while (1); // end of the inner loop



if(mc == 0 && attempts < 5){
cg = 2;
}else{
cg = 1;
}

       
if (cg == 2)             
printf ("**** Congratulations!!!****\n ***You Won!!!!*** \n"); //outputs victory
else    
printf ("Do you want to play again? 1=Yes 0=No \n"); // ask the user to play again
 
scanf ("%d", &pg); //reads pg 
attempts = 0; //initializes attempts to 0
if (!pg){
printf("Bye!"); //outputs bye
break; //breaks 
}
} while (1); //end
}