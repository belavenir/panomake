#include <iostream>
#include <fstream>

using namespace std;

const int ROWS = 256;
const int COLS = 512;


int main() {
    float depth[ROWS][COLS];

    FILE *file = fopen("../data/depth.csv", "r");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(file, "%f,", &depth[i][j]);
        }
    }
  cout <<depth[200][300] << endl;
  return 0;
}
