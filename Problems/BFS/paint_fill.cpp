#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Dimentions of paint screen
#define R 8
#define C 8

void paintFill(int screen[][C], int r, int c, int oldColor, int newColor){

	if ( r<0 || c<0 || r>=R || c>=C )
		return;

	if (screen[r][c] != oldColor)
		return;

	screen[r][c] = newColor;

	paintFill(screen,r+1,c,oldColor,newColor);
	paintFill(screen,r-1,c,oldColor,newColor);
	paintFill(screen,r,c+1,oldColor,newColor);
	paintFill(screen,r,c-1,oldColor,newColor);

	
}

void paint(int screen[][C], int r, int c, int newColor){

	int oldColor = screen[r][c];

	paintFill(screen,r,c,oldColor,newColor);

}


int main(){


	int screen[R][C] = {{1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 0, 0, 1, 1, 0, 1, 1},
                        {1, 2, 2, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 2, 2, 0},
                        {1, 1, 1, 1, 1, 2, 1, 1},
                        {1, 1, 1, 1, 1, 2, 2, 1},};
    

    paint(screen,3,5,9);

    for (int i=0; i<R; i++){
        for (int j=0; j<C; j++)
           cout << screen[i][j] << " ";
        cout << endl;
    }

	return 0;

}