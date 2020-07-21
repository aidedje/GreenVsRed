#pragma once
#include "Apple.h"

class GenerationMatrix {

private:
	Apple** generationMatrix;
	Apple** temp;

	int x; // number of the columns
	int y; // number of the rows

	int x1; 
	int y1;

	int counter = 0; // count of the generations until generation N 
					// where the apple with coordinates x1,y1 was green

	int caseOne(int i, int j) const;
	int caseTwo(int i, int j) const;
	int caseThree(int i, int j) const;
	int caseFour(int i, int j) const;
	int caseFive(int i, int j) const;
	int caseSix(int i, int j) const;
	int caseSeven(int i, int j) const;
	int caseEight(int i, int j) const;
	int caseNine(int i, int j) const;

	void changeAppleColor(int i, int j, int greenNeighboursCount);
	void deleteMatrix();

public:
	
	GenerationMatrix(int _x, int _y);
	GenerationMatrix(const GenerationMatrix& t);
	GenerationMatrix& operator=(const GenerationMatrix& gm);
	~GenerationMatrix();

	void generations(int N);

	void switchMatrices(); 

	void setCoordinates(int _x1, int _y1);

	void setX(int _x);
	void setY(int _y);

	void setApple(int _x, int _y, int appleColor);

	void printMatrix() const;
	void printTempMatrix() const;

	int getCounter() const;

	int getX1() const;
	int getY1() const;

	int getX() const;
	int getY() const;

	int getAppleColor(int _x, int _y);
};