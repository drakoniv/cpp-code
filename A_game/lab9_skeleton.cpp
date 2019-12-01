/*
 * COMP2011 2019F
 * Lab 9: Game development using dynamic memory allocation
 *
 * Source file: lab9_skeleton.cpp
 */

#include "lab9.h"

using namespace std;


// Task 1
// Create a monster using dynamic memory allocation "new"
// The monster should be an instance of the Character structure
// Randomly set the power of monster and location
// Initialize all the pointers of the "bags" to nullptr
// Return the monster you create
Character* create_monster()
{
    // Add your code here
    Character* monster = nullptr; // assign pointer to nullptr
    monster = new Character; // create new character
    // assign properties to monster
    monster->type = MONSTER;
    monster->power = rand() % MAX_POWER;
    monster->location.row = rand() % MAZE_SIZE;
    monster->location.col = rand() % MAZE_SIZE;
    monster->num_collected = 0;
    for (int i = 0; i < MAX_NUM_MONSTERS; i++) {
        monster->bag[i] = nullptr;
    }
    //return monster object
    return monster;
}


// Task 2
// Move the hero relatively by (move_row, move_col)
// (e.g. if move_row is 0, move_col is -1, the hero is moving towards the left.)
// You should be careful about the border situation when your hero hits the wall
// If hero beats a monster, "collect" it to his "bag" and remove it from the 2D "board"
// Returns false if the hero got beaten by the monster;
// otherwise true
// (Note: you may also need to check if the hero can or cannot move in the specified direction)
bool move_hero(GameBoard* game, int move_row, int move_col)
{
    // Add your code here
    int& heroCol = game->hero.location.col;
    int& heroRow = game->hero.location.row;
    game->board[heroRow][heroCol] = nullptr;
    if( move_col == 1) {
        if(heroCol < MAZE_SIZE-1) {
           heroCol += 1;
        } else {
            cout<< " Border detected" << endl;
        }
    } else if( move_col == -1) {
        if((heroCol) > 0) {
            heroCol -= 1;
        }else {
            cout<< " Border detected" << endl;
        }
    } else if ( move_col == 0) {
        if( move_row == 1) {
            if((heroRow) < MAZE_SIZE-1) {
                heroRow += 1;
            }else {
                cout<< " Border detected" << endl;
            }
        } else if( move_row == -1) {
            if(heroRow > 0) {
                heroRow -= 1;
            }else {
                cout<< " Border detected" << endl;
            }
        }
    }
    if(game->board[heroRow][heroCol] != nullptr) {
        if(game->board[heroRow][heroCol] -> type == MONSTER) {
            if(game->hero.power >= game->board[heroRow][heroCol]->power) {
                game->hero.bag[game->hero.num_collected] = game->board[heroRow][heroCol];
                game->hero.num_collected += 1;
                game->num_monsters -= 1;
                game->board[heroRow][heroCol] = nullptr;
            } else {
                cout << "you lose!" << endl;
                return false;
            }
        }
    }

    game->board[heroRow][heroCol] = &(game->hero);
    return true;
}


// Task 3
// Delete all the monsters you have created using "delete" operation
// which contain both "alive" and "dead" ones
// Note: the hero (i.e. hero) is a static object, no need to "delete".
// Note: remember to reset all pointers to nullptr
void delete_all_monsters(GameBoard* game)
{
    // Add your code here
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if(game->board[i][j] != nullptr && game->board[i][j]->type == MONSTER) {
                delete(game->board[i][j]);
                game->board[i][j] = nullptr;
            }
        }
    }
    for (int i=0; i< game->hero.num_collected; i++) {
        if(game->hero.bag[i] != nullptr) {
            delete(game->hero.bag[i]);
            game->hero.bag[i] = nullptr;
        }
    }
}

/*** The following functions are give. ***/
// Initialize the hero (hero)
void init_hero(Character* hero, int p, Location loc)
{
    // Set location member of hero to loc, type to HERO, power to p
    hero->location = loc;
    hero->type = HERO;
    hero->power = p;
    // Initialize the bag to nullptrs & num_collected to 0
    hero->num_collected = 0;
    for (int i=0; i<MAX_NUM_MONSTERS; i++)
        hero->bag[i] = nullptr;
}

// Initialize the 2D Board
void init_game(GameBoard* game, int num)
{
    // Initialize the board by setting all pointers of board to nullptr
    for (int i=0; i<MAZE_SIZE; i++)
        for (int j=0; j<MAZE_SIZE; j++)
            game->board[i][j] = nullptr;

    // Initialize the hero member of game
    Location l = {0, 0};
    init_hero(&(game->hero), 3, l);
    // Have the pointer at (0, 0) points to the hero member
    game->board[l.row][l.col] = &(game->hero);

    // Set the num_monsters member of game to num, and create the monsters accordingly
    game->num_monsters = num;

    // To garantee all monsters are at different locations on the board
    Character* temp = nullptr;
    for (int i=0; i<game->num_monsters; i++)
    {
        temp = create_monster();
        while (game->board[temp->location.row][temp->location.col]!=nullptr)
        {
            delete temp;
            temp = nullptr;
            temp = create_monster();
        }
        game->board[temp->location.row][temp->location.col] = temp;
    }
}


// Draw the board showing where the hero and monsters are, and the current status
void draw_game(const GameBoard* game)
{
    // Draw the boarder
    for (int i=0; i<=MAZE_SIZE+1; i++)
        cout << "=";
    cout << endl;
    for (int i=0; i<MAZE_SIZE; i++)
    {
        // Draw the boarder
        cout << "|";
        for (int j=0; j<MAZE_SIZE; j++)
        {
            // Print a space if no Character object is there
            if (game->board[i][j] == nullptr)
                cout << " ";
            else {
                // Print the hero
                if (game->board[i][j]->type == HERO)
                    cout << HERO_SYMBOL;
                else
                    // Print the monster
                    cout << game->board[i][j]->power;
            }
        }
        // Draw the boarder
        cout << "|" << endl;
    }
    // Draw the boarder
    for (int i=0; i<=MAZE_SIZE+1; i++)
        cout << "=";
    cout << endl;

    // Display the status of the hero member
    cout << "Hero's current power: " << game->hero.power << endl;
    cout << "Hero has collected: ";
    for (int i=0; i<game->hero.num_collected; i++)
        cout << game->hero.bag[i]->power << ", ";
    cout << endl;
}