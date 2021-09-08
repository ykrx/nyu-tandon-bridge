/* Yulian Kraynyak
 * yk2562
 * HW13
 *
 * Predator-prey simulation implemented using polymorphism.
 */

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

/* Simulation Settings */
const int WORLD_WIDTH = 20;
const int WORLD_HEIGHT = 20;
const int INITIAL_ANTS = 100;
const int INITIAL_DOODLEBUGS = 5;
const int ANT_BREEDING_TIME = 3;
const int DOODLEBUG_BREEDING_TIME = 8;
const int DOODLEBUG_STEPS_TO_STARVATION = 3;

/* Organism Types */
const int ANT = 1;
const int DOODLEBUG = 2;

/* Organism Symbols */
const char ANT_SYMBOL = 'o';
const char DOODLEBUG_SYMBOL = 'X';
const char EMPTY_SYMBOL = '-';

/* Directions */
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;
const int NUMBER_OF_DIRECTIONS = 4;

/* Class Forward-Declarations */
class World;
class WorldSize;
class Organism;
class Ant;
class Doodlebug;
class Coordinate;

/* Function Prototypes */
int randomNumber(int n, int zeroIndexOffset = 0);
void generateWorld(WorldSize size);

/* Classes */
class WorldSize {
  private:
    int width;
    int height;
  public:
    WorldSize() {
        width = WORLD_WIDTH;
        height = WORLD_HEIGHT;
    }

    WorldSize(int _width, int _height) {
        width = _width;
        height = _height;
    }

    int maxCells() const { return width * height; }
    int get_width() const { return width; }
    int get_height() const { return height; }
};

class Coordinate {
  public:
    int row;
    int column;
};

class Organism {
  protected:
    World* world;
    string name;
    int stepsAlive;
    int stepsSinceBreeding;
    int row, column;

    void updateCoordinates(int direction, int& newRow, int& newColumn);
    bool isInWorld(int newRow, int newColumn);
  public:
    virtual int get_type() = 0;
    virtual void move();
    virtual void breed() = 0;
    virtual bool isStarving() { return false; };
};

class Ant : public Organism {
  public:
    Ant(World* _world, int _row, int _column) {
        world = _world;
        row = _row;
        column = _column;
        name = "Ant";
        stepsAlive = 0;
        stepsSinceBreeding = 0;
    }

    int get_type() override { return ANT; }
    void breed() override;
};

class Doodlebug : public Organism {
  public:
    int stepsSinceFeeding;

    Doodlebug(World* _world, int _row, int _column) {
        world = _world;
        row = _row;
        column = _column;
        name = "Doodlebug";
        stepsAlive = 0;
        stepsSinceBreeding = 0;
        stepsSinceFeeding = 0;
    }

    int get_type() override { return DOODLEBUG; }
    void move() override;
    void breed() override;
    bool isStarving() override { return stepsSinceFeeding >= DOODLEBUG_STEPS_TO_STARVATION; }
};

class World {
  protected:
    int stepCount;
    WorldSize size;

    void initAnts();
    void initDoodlebugs();
  public:
    Organism* cells[WORLD_WIDTH][WORLD_HEIGHT];

    World(WorldSize _size) {
        stepCount = 0;
        size = _size;

        for (int row = 0; row < size.get_width(); row++) {
            for (int column = 0; column < size.get_height(); column++) {
                cells[row][column] = nullptr;
            }
        }
    }

    bool settingsValid();
    void initialize() {
        initAnts();
        initDoodlebugs();
    }
    void print();
    void nextStep();
    WorldSize get_size() { return size; }
    virtual ~World();
};

/* Main */
int main() {
    generateWorld({ WORLD_WIDTH, WORLD_HEIGHT });
    return 0;
}

/* Functions */
void generateWorld(WorldSize size) {
    World world(size);

    srand(time(0)); // NOLINT
    if (world.settingsValid()) {
        world.initialize();
        world.print();
    }
}

// Checks if simulation settings don't conflict
bool World::settingsValid() {
    if (size.maxCells() < INITIAL_ANTS) {
        cout << "ERROR: INITIAL_ANTS = " << INITIAL_ANTS;
        cout << " is greater than the maximum number of cells (";
        cout << size.get_width() << " * " << size.get_height();
        cout << " = " << size.maxCells() << "). ";

        return false;
    }else if (size.maxCells() < INITIAL_DOODLEBUGS) {
        cout << "ERROR: INITIAL_DOODLEBUGS = " << INITIAL_DOODLEBUGS;
        cout << " is greater than the maximum number of cells (";
        cout << size.get_width() << " * " << size.get_height();
        cout << " = " << size.maxCells() << "). ";

        return false;
    }else {
        return true;
    }
}

void World::initAnts() {
    int ants = 0;

    while (ants < INITIAL_ANTS) {
        int row = randomNumber(size.get_width());
        int column = randomNumber(size.get_height());

        if (cells[row][column] == nullptr) {
            cells[row][column] = new Ant(this, row, column);
            ants++;
        }
    }
}

void World::initDoodlebugs() {
    int doodlebugs = 0;

    while (doodlebugs < INITIAL_DOODLEBUGS) {
        int row = randomNumber(size.get_width());
        int column = randomNumber(size.get_height());

        if (cells[row][column] == nullptr) {
            cells[row][column] = new Doodlebug(this, row, column);
            doodlebugs++;
        }
    }
}

void World::print() {
    cout << "STEP: " << stepCount++ << endl;

    for (int row = 0; row < size.get_width(); row++) {
        for (int column = 0; column < size.get_height(); column++) {
            if (cells[row][column] != nullptr) {
                if (cells[row][column]->get_type() == ANT) {
                    cout << ANT_SYMBOL;
                }else if (cells[row][column]->get_type() == DOODLEBUG) {
                    cout << DOODLEBUG_SYMBOL;
                }
            }else {
                cout << EMPTY_SYMBOL;
            }
            // Pads all columns with a space, besides the last one
            if (column != size.get_width() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "Press Enter (Return on Mac) to move to the next step, or any other character to stop the simulation.";

    char temp;
    cin.get(temp);

    if (temp != '\n') {
        cout << endl;
        cout << "Simulation stopped.";
        cout << endl;
        exit(1);
    }else {
        cout << endl;
        nextStep();
    }
}

void World::nextStep() {
    // Move all Doodlebugs
    for (int row = 0; row < size.get_height(); row++) {
        for (int column = 0; column < size.get_width(); column++) {
            if (cells[row][column] != nullptr) {
                if (cells[row][column]->get_type() == DOODLEBUG) {
                    cells[row][column]->move();
                }
            }
        }
    }
    // Move all Ants
    for (int row = 0; row < size.get_height(); row++) {
        for (int column = 0; column < size.get_width(); column++) {
            if (cells[row][column] != nullptr) {
                if (cells[row][column]->get_type() == ANT) {
                    cells[row][column]->move();
                }
            }
        }
    }
    // Breed all Organisms
    for (int row = 0; row < size.get_height(); row++) {
        for (int column = 0; column < size.get_width(); column++) {
            if (cells[row][column] != nullptr) {
                cells[row][column]->breed();
            }
        }
    }
    // Kill all starving Doodlebugs
    for (int row = 0; row < size.get_height(); row++) {
        for (int column = 0; column < size.get_width(); column++) {
            if (cells[row][column] != nullptr) {
                if (cells[row][column]->get_type() == DOODLEBUG && cells[row][column]->isStarving()) {
                    cells[row][column] = nullptr;
                }
            }
        }
    }
    print();
}

World::~World() {
    for (int row = 0; row < size.get_height(); row++) {
        for (int column = 0; column < size.get_width(); column++) {
            if (cells[row][column] != nullptr) {
                delete cells[row][column];
            }
        }
    }
}

void Organism::move() {
    int newRow = row;
    int newColumn = column;
    int direction = randomNumber(NUMBER_OF_DIRECTIONS, 1);

    ++stepsAlive;
    ++stepsSinceBreeding;
    updateCoordinates(direction, newRow, newColumn);

    if (isInWorld(newRow, newColumn)) {
        if (world->cells[newRow][newColumn] == nullptr) {
            world->cells[newRow][newColumn] = this;
            world->cells[row][column] = nullptr;
            row = newRow;
            column = newColumn;
        }else {
            return;
        }
    }
}

void Doodlebug::move() {
    int newRow = row;
    int newColumn = column;
    int direction = randomNumber(NUMBER_OF_DIRECTIONS, 1);

    ++stepsAlive;
    ++stepsSinceBreeding;
    ++stepsSinceFeeding;
    updateCoordinates(direction, newRow, newColumn);

    // 1. First look for adjacent ants
    vector<Coordinate> adjacentAnts;
    for (int i = 1; i <= NUMBER_OF_DIRECTIONS; i++) {
        int _row = row;
        int _column = column;

        updateCoordinates(i, _row, _column);

        if (isInWorld(_row, _column) && (world->cells[_row][_column] != nullptr) && (world->cells[_row][_column]->get_type() == ANT)) {
            adjacentAnts.push_back({ _row, _column });
        }
    }
    // 2. If adjacent ants exist, eat random one and move to its place
    if (!adjacentAnts.empty()) {
        int randomIndex = randomNumber(adjacentAnts.size());

        world->cells[adjacentAnts[randomIndex].row][adjacentAnts[randomIndex].column] = this;
        world->cells[row][column] = nullptr;
        row = adjacentAnts[randomIndex].row;
        column = adjacentAnts[randomIndex].column;
        stepsSinceFeeding = 0;
    }else {
        // Else, move to a free adjacent cell
        if (isInWorld(newRow, newColumn)) {
            if (world->cells[newRow][newColumn] == nullptr) {
                world->cells[newRow][newColumn] = this;
                world->cells[row][column] = nullptr;
                row = newRow;
                column = newColumn;
            }
        }
    }
}

void Ant::breed() {
    vector<Coordinate> adjacentCells = {
            { row,     column - 1 }, // Up
            { row,     column + 1 }, // Down
            { row - 1, column }, // Left
            { row + 1, column } // Right
    };

    if (stepsSinceBreeding >= ANT_BREEDING_TIME) {
        // Purges vector of coordinates not in world
        for (int i = 0; i < adjacentCells.size(); i++) {
            if (!isInWorld(adjacentCells[i].row, adjacentCells[i].column)) {
                adjacentCells.erase(adjacentCells.begin() + i);
            }
        }
        for (Coordinate adjacentCell : adjacentCells) {
            if (world->cells[adjacentCell.row][adjacentCell.column] == nullptr) {
                world->cells[adjacentCell.row][adjacentCell.column] = new Ant(world, adjacentCell.row, adjacentCell.column);
                stepsSinceBreeding = 0;

                break;
            }
        }
    }
}

void Doodlebug::breed() {
    vector<Coordinate> adjacentCells = {
            { row,     column - 1 }, // Up
            { row,     column + 1 }, // Down
            { row - 1, column }, // Left
            { row + 1, column } // Right
    };

    if (stepsSinceBreeding >= DOODLEBUG_BREEDING_TIME) {
        for (int i = 0; i < adjacentCells.size(); i++) {
            // Purges vector of coordinates not in world
            if (!isInWorld(adjacentCells[i].row, adjacentCells[i].column)) {
                adjacentCells.erase(adjacentCells.begin() + i);
            }
        }
        for (Coordinate adjacentCell : adjacentCells) {
            if (world->cells[adjacentCell.row][adjacentCell.column] == nullptr) {
                world->cells[adjacentCell.row][adjacentCell.column] = new Doodlebug(world, adjacentCell.row, adjacentCell.column);
                stepsSinceBreeding = 0;
                break;
            }
        }
    }
}

void Organism::updateCoordinates(int direction, int& newRow, int& newColumn) {
    switch (direction) {
        case UP:
            newRow--;
            break;
        case DOWN:
            newRow++;
            break;
        case LEFT:
            newColumn--;
            break;
        case RIGHT:
            newColumn++;
            break;
        default:
            break;
    }
}

// Checks if coordinates are within the world bounds
bool Organism::isInWorld(int newRow, int newColumn) {
    return ((newRow >= 0) && (newRow < world->get_size().get_height()) && (newColumn >= 0) && (newColumn < world->get_size().get_width()));
}

// Picks a random number in range of zeroIndexOffset (default = 0) to n
int randomNumber(int n, int zeroIndexOffset) {
    return (rand() % n) + zeroIndexOffset; //NOLINT
}