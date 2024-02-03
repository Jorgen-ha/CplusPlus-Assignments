// The maze
#include <iostream>  // Import the library for input/output
#include <string>

using namespace std; // Use the standard namespace

typedef enum {wood, wall, player} material;

struct tile {
    int x, y;
    bool isWall;
    material type;
};

#define NROWS 12
#define NCOLS 16

/// This function translates materials into a symbol in order to display it
char symbol(material m) {
    switch (m) {
    case wood:
        return ' ';
    case wall:
        return '*';
    case player:
        return 'O';
    default:
        return '?';
    }
}
/// @brief Prints the playground
/// @param playground 
void printPlayground(tile playground[NROWS][NCOLS]){
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            cout << symbol(playground[i][j].type);
        }
        cout << endl;
    }
}

/// @brief Builds the playground
/// @param playground 
/// @param x 
/// @param y 
void buildPlayground(tile playground[NROWS][NCOLS], int x, int y){
    for (int i=0; i < NROWS; i++){
        for (int j=0; j < NCOLS; j++){
            playground[i][j].x = i;
            playground[i][j].y = j;
            playground[i][j].isWall = (j==0 || i == (NROWS-1) || (i==0 && j!=3) || j==(NCOLS-1));
            if (playground[i][j].isWall) {
                playground[i][j].type = wall;
            } else {
                playground[i][j].type = wood;
            }
        }
    }
    playground[x][y].type = player;
}
/// @brief Processes the user input
/// @param input 
/// @param playground 
/// @param x 
/// @param y 
void processInput(char input, tile playground[NROWS][NCOLS], int &x, int &y){
    switch (input) {
    case 'l':
        if (!playground[x][y-1].isWall && y > 0){
            y -= 1;
        }   
        break;
    case 'r':
        if (!playground[x][y+1].isWall && y > 0){
            y += 1;
        }
        break;
    case 'u':
        if (!playground[x-1][y].isWall && x > 0){
            x -= 1;
        }
        break;
    case 'd':
        if (!playground[x+1][y].isWall && x > 0){
            x += 1;
        }
        break;
    default:
        break;
    }
}


int main(){
    tile playground[NROWS][NCOLS];
    int x= 5; int y= 5;                             // Player position  
    char input;                                     // Input from the user
    
    buildPlayground(playground, x, y);     // Building the playground
    printPlayground(playground);       // Printing the playground
    cin >> input;                       // Getting the input from the user
    while (input != 'q'){
        processInput(input, playground, x, y);          // Processing the input
        buildPlayground(playground, x, y);     // Building the playground
        printPlayground(playground);        // Printing the playground
        cin >> input;                       // Getting the input from the user
    }

    return 0;
}


