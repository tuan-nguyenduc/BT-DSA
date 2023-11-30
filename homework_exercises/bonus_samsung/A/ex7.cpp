#include <iostream>
#include <vector>

using namespace std;

bool isValid(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

void floodFillDFS(vector<vector<int>>& image, int x, int y, int newColor, int originalColor) {
    if (!isValid(x, y, image.size(), image[0].size()) || image[x][y] != originalColor) {
        return;
    }

    image[x][y] = newColor;

    floodFillDFS(image, x + 1, y, newColor, originalColor);
    floodFillDFS(image, x - 1, y, newColor, originalColor);
    floodFillDFS(image, x, y + 1, newColor, originalColor);
    floodFillDFS(image, x, y - 1, newColor, originalColor);
}

void floodFill(vector<vector<int>>& image, int x, int y, int newColor) {
    int originalColor = image[x][y];

    if (originalColor != newColor) {
        floodFillDFS(image, x, y, newColor, originalColor);
    }
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 1, 1}
    };

    cout << "Image before flood-fill:" << endl;
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    floodFill(image, 1, 1, 2);

    cout << "\nImage after flood-fill:" << endl;
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
