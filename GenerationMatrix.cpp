#include "GenerationMatrix.h"

//in this case we have 3 adjacent cells
int GenerationMatrix::caseOne(int i, int j) const {
    int greenNeighboursCount = 0;
    greenNeighboursCount = generationMatrix[i + 1][j].getColor() +
        generationMatrix[i + 1][j + 1].getColor() + generationMatrix[i][j + 1].getColor();
    return greenNeighboursCount;
}

//in this case we have 5 adjacent cells
int GenerationMatrix::caseTwo(int i, int j) const {
    int greenNeighboursCount = 0;
    greenNeighboursCount = generationMatrix[i][j + 1].getColor() + generationMatrix[i][j - 1].getColor() +
        generationMatrix[i + 1][j - 1].getColor() + generationMatrix[i + 1][j].getColor() + 
        generationMatrix[i + 1][j + 1].getColor();
    return greenNeighboursCount;
}

//in this case we have 3 adjacent cells
int GenerationMatrix::caseThree(int i, int j) const {
    int greenNeighboursCount = 0;
    greenNeighboursCount = generationMatrix[i][j - 1].getColor() +
        generationMatrix[i + 1][j].getColor() + generationMatrix[i + 1][j - 1].getColor();
    return greenNeighboursCount;
}

//in this case we have 5 adjacent cells
int GenerationMatrix::caseFour(int i, int j) const {
    int greenNeighboursCount = 0;
    greenNeighboursCount = generationMatrix[i - 1][j].getColor() + generationMatrix[i + 1][j].getColor() +
        generationMatrix[i - 1][j + 1].getColor() + generationMatrix[i][j + 1].getColor() + 
        generationMatrix[i + 1][j + 1].getColor();
    return greenNeighboursCount;
}

//in this case we have 8 adjacent cells
int GenerationMatrix::caseFive(int i, int j) const {
    int greenNeighboursCount = 0;
    greenNeighboursCount = generationMatrix[i - 1][j - 1].getColor() + generationMatrix[i][j - 1].getColor() +
        generationMatrix[i - 1][j].getColor() + generationMatrix[i][j + 1].getColor() + 
        generationMatrix[i + 1][j].getColor() + generationMatrix[i - 1][j + 1].getColor() + 
        generationMatrix[i + 1][j - 1].getColor() + generationMatrix[i + 1][j + 1].getColor();
    return greenNeighboursCount;
}

//in this case we have 5 adjacent cells
int GenerationMatrix::caseSix(int i, int j) const {
    int greenNeighboursCount = 0;
    greenNeighboursCount = generationMatrix[i - 1][j].getColor() + generationMatrix[i + 1][j].getColor() +
        generationMatrix[i - 1][j - 1].getColor() + generationMatrix[i][j - 1].getColor() + 
        generationMatrix[i + 1][j - 1].getColor();
    return greenNeighboursCount;
}

//in this case we have 3 adjacent cells
int GenerationMatrix::caseSeven(int i, int j) const {
    int greenNeighboursCount = 0;
    greenNeighboursCount = generationMatrix[i - 1][j].getColor() +
        generationMatrix[i - 1][j + 1].getColor() + generationMatrix[i][j + 1].getColor();
    return greenNeighboursCount;
}

//in this case we have 5 adjacent cells
int GenerationMatrix::caseEight(int i, int j) const {
    int greenNeighboursCount = 0;
    greenNeighboursCount = generationMatrix[i][j + 1].getColor() + generationMatrix[i][j - 1].getColor() +
        generationMatrix[i - 1][j - 1].getColor() + generationMatrix[i - 1][j].getColor() + 
        generationMatrix[i - 1][j + 1].getColor();
    return greenNeighboursCount;
}

//in this case we have 3 adjacent cells
int GenerationMatrix::caseNine(int i, int j) const {
    int greenNeighboursCount = 0;
    greenNeighboursCount = generationMatrix[i - 1][j].getColor() +
        generationMatrix[i - 1][j - 1].getColor() + generationMatrix[i][j - 1].getColor();
    return greenNeighboursCount;
}

void GenerationMatrix::changeAppleColor(int i, int j, int greenNeighboursCount) {

    //green apples
    if (generationMatrix[i][j].getColor()) {
        if (greenNeighboursCount == 0 || greenNeighboursCount == 1 || greenNeighboursCount == 4
            || greenNeighboursCount == 5 || greenNeighboursCount == 7 || greenNeighboursCount == 8) temp[i][j].setColor(0);

        //increases counter only if the green apple has 2, 3 or 6 adjacent green apples
        else if (i == getX1() && j == getY1()) counter++;
    }

    //red apples
    if (!(generationMatrix[i][j].getColor())) {
        if (greenNeighboursCount == 3 || greenNeighboursCount == 6) {
            temp[i][j].setColor(1);

            //increases counter only if the red apple has 3 or 6 adjacent green apples
            if (i == getX1() && j == getY1()) counter++;
        }
    }

}

//helper function
void GenerationMatrix::deleteMatrix() {

    for (int i = 0; i < x; i++) {
        delete[] generationMatrix[i];
        delete[] temp[i];
    }

    delete[] generationMatrix;
    delete[] temp;
}

//Constructor
GenerationMatrix::GenerationMatrix(int _x, int _y){

    setX(_x);
    setY(_y);

    this->generationMatrix = new (nothrow)Apple * [_x];
    this->temp = new (nothrow)Apple * [_x];

    for (int i = 0; i < _x; i++) {
        generationMatrix[i] = new (nothrow)Apple[_y];
        temp[i] = new (nothrow)Apple[_y];
    }   
}

GenerationMatrix::GenerationMatrix(const GenerationMatrix& t) {
    deleteMatrix();

    setX(t.getX());
    setY(t.getY());

    generationMatrix = new Apple * [getX()];
    for (int i = 0; i < getX(); i++) {
        generationMatrix[i] = new Apple[getY()];
        temp[i] = new Apple[getY()];
    }

    for (int i = 0; i < getX(); i++) {
        for (int j = 0; j < getY(); j++) {
            generationMatrix[i][j] = t.generationMatrix[i][j];
            temp[i][j] = t.temp[i][j];
        }
    }
}

GenerationMatrix& GenerationMatrix::operator=(const GenerationMatrix& gm){
    if (this != &gm) {
        deleteMatrix();

        setX(gm.getX());
        setY(gm.getY());

        generationMatrix = new Apple * [getX()];
        for (int i = 0; i < getX(); i++) {
            generationMatrix[i] = new Apple[getY()];
            temp[i] = new Apple[getY()];
        }

        for (int i = 0; i < getX(); i++) {
            for (int j = 0; j < getY(); j++) {
                generationMatrix[i][j] = gm.generationMatrix[i][j];
                temp[i][j] = gm.temp[i][j];
            }
        }
    }
    return *this;
}

//Destructor
GenerationMatrix::~GenerationMatrix() {
    deleteMatrix();
}

void GenerationMatrix::generations(int N) {
    while(N--){
    for (int i = 0; i < getX(); i++) {
        for (int j = 0; j < getY(); j++) {
            int greenNeighboursCount = 0;

            if (i == 0) {
                if (j == 0) {
                    greenNeighboursCount = caseOne(i, j);
                    changeAppleColor(i, j, greenNeighboursCount);
                    continue;
                }

                if (j > 0 && j < getY() - 1) {
                    greenNeighboursCount = caseTwo(i, j);
                    changeAppleColor(i, j, greenNeighboursCount);
                    continue;
                }

                if (j == getY() - 1) {
                    greenNeighboursCount = caseThree(i, j);
                    changeAppleColor(i, j, greenNeighboursCount);
                    continue;
                }
            }

            if (i > 0 && i < getX() - 1) {

                if (j == 0) {
                    greenNeighboursCount = caseFour(i, j);
                    changeAppleColor(i, j, greenNeighboursCount);
                    continue;
                }

                if (j > 0 && j < getY() - 1) {
                    greenNeighboursCount = caseFive(i, j);
                    changeAppleColor(i, j, greenNeighboursCount);
                    continue;
                }

                if (j == getY() - 1) {
                    greenNeighboursCount = caseSix(i, j);
                    changeAppleColor(i, j, greenNeighboursCount);
                    continue;
                }
            }

            if (i == getX() - 1) {

                if (j == 0) {
                    greenNeighboursCount = caseSeven(i, j);
                    changeAppleColor(i, j, greenNeighboursCount);
                    continue;
                }

                if (j > 0 && j < getY() - 1) {
                    greenNeighboursCount = caseEight(i, j);
                    changeAppleColor(i, j, greenNeighboursCount);
                    continue;
                }

                if (j == getY() - 1) {
                    greenNeighboursCount = caseNine(i, j);
                    changeAppleColor(i, j, greenNeighboursCount);
                    continue;
                }
            }
        }
    }

    switchMatrices();
    }
}

void GenerationMatrix::switchMatrices() {

    for (int i = 0; i < getX(); i++) {
        delete[] generationMatrix[i];
    }

    delete[] generationMatrix;

    generationMatrix = new (nothrow)Apple * [getX()];
    for (int i = 0; i < getX(); i++) {
        generationMatrix[i] = new (nothrow)Apple[getY()];
    }

    for (int i = 0; i < getX(); i++) {
        for (int j = 0; j < getY(); j++) {
            generationMatrix[i][j] = temp[i][j];
        }
    }
}

//setters
void GenerationMatrix::setCoordinates(int _x1, int _y1){
    this->x1 = _x1;
    this->y1 = _y1;
}

void GenerationMatrix::setX(int _x) {
    this->x = _x;
}

void GenerationMatrix::setY(int _y) {
    this->y = _y;
}

void GenerationMatrix::setApple(int _x, int _y, int appleColor) {

   generationMatrix[_x][_y].setColor(appleColor);
   temp[_x][_y].setColor(appleColor);
    
}

//print functions
void GenerationMatrix::printMatrix() const {
    
    for (int i = 0; i < getX(); i++) {
        for (int j = 0; j < getY(); j++) {
            cout << generationMatrix[i][j];
        }
        cout << endl;
    }

    cout << endl;
}

void GenerationMatrix::printTempMatrix() const {
   
    for (int i = 0; i < getX(); i++) {
        for (int j = 0; j < getY(); j++) {
            cout << temp[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//getters
int GenerationMatrix::getCounter() const {
    return this->counter;
}

int GenerationMatrix::getX1() const {
    return this->x1;
}

int GenerationMatrix::getY1() const {
    return this->y1;
}

int GenerationMatrix::getX() const {
    return this->x;
}

int GenerationMatrix::getY() const {
    return this->y;
}

int GenerationMatrix::getAppleColor(int _x, int _y) {
    if (_x >= getX() || _y >= getY() || _x < 0 || _y < 0) cout << "Wrong index!" << endl;
    else return generationMatrix[_x][_y].getColor();
}
