#include "GenerationMatrix.h"

int main() {

    int x, y, x1, y1, N;

   // cout << "Enter height and width of the grid: ";

    while (!(cin >> x >> y) || x < 0 || x > 1000 || y < 0 || y > 1000){
        cout << "Please enter numbers between 0 and 1000: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    GenerationMatrix matrix(x, y);

  //  cout << endl << "Enter the generation matrix" << endl;

    for (int i = 0; i < matrix.getX(); i++) {
        
        string apples;
        cin >> apples;

        for (int j = 0; j < matrix.getY(); j++) {
            matrix.setApple(i, j, apples[j]-'0');
        }
    }
    
   // cout << endl << "Enter coordinates: ";
    while (!(cin >> x1 >> y1 ) || x1 < 0 || x1 > x || y1 < 0 || y1 > y) {
        cout << "Allowed interval for x1: "<<0<<"-"<<x<<endl<< 
            "Allowed interval for y1: " << 0 << "-" << y << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
   
  //  cout << endl << "Enter generations number: ";
    
    while (!(cin >> N) || N < 0){
        cout << "Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    }
    matrix.setCoordinates(x1, y1);
    
    matrix.generations(N);
   
   // cout << "The cell with coordinates x1("<<matrix.getX1()<<") and y1("<<matrix.getY1()<<") was green "<<
   //     matrix.getCounter()<<" generations from Generation Zero until Generation "<<N<<".";
    
    cout << matrix.getCounter();

    return 0;
}
