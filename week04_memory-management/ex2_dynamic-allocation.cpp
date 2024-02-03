// The maze with dynamic allocation
#include <iostream>  // Import the library for input/output
#include <string>

using namespace std; // Use the standard namespace

typedef enum {wood, wall, player} material;

struct tile {
    int x, y;
    bool isWall;
    material type;
};

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
void printPlayground(tile **playground, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << symbol(playground[i][j].type);
        }
        cout << endl;
    }
}

/// @brief Builds the playground
void buildPlayground(tile **playground, int rows, int cols, int x, int y){
    for (int i=0; i < rows; i++){
        for (int j=0; j < cols; j++){
            playground[i][j].x = i;
            playground[i][j].y = j;
            playground[i][j].isWall = (j==0 || i == (rows-1) || (i==0 && j!=3) || j==(cols-1));
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
void processInput(char input, tile **playground, int &x, int &y){
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
    int rows, cols;
    cin >> rows; cin >> cols;
    // Create the maze
    tile **playground = new tile*[rows];
    for (int i=0; i < rows; i++){
        playground[i] = new tile[cols];
    }
    int x = rows/2; int y = cols/2;        // Player position  
    
    buildPlayground(playground, rows, cols, x, y);     // Building the playground
    printPlayground(playground, rows, cols);           // Printing the playground

    char input;                                // Input from the user
    cin >> input;                              // Getting the input from the user
    while (input != 'q'){
        processInput(input, playground, x, y); // Processing the input
        buildPlayground(playground, rows, cols, x, y);     // Building the playground
        printPlayground(playground, rows, cols);           // Printing the playground
        cin >> input;                          // Getting the input from the user
    }

    // Delete the maze
    for (int i=0; i < rows; i++){
        delete[] playground[i];
    }
    delete[] playground;

    return 0;
}


