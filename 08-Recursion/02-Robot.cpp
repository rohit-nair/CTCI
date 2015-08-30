#include <iostream>

static char RIGHT = 'R';
static char DOWN = 'D';

bool IsFree(int right, int down) {
    // Check whether one can move to that box.
    return true;
}

void FindPaths(std::string path, int right, int down, int level){
    if (right == 0 && down == 0){
        std::cout << path << "\n";
        return;
    }
    
    if (right > 0 && IsFree(right - 1, down)){
        path.insert(level, 1, RIGHT);
        // decrementing as we are appending,
        // If we were replacing, we would not decrement
        // as the next if will have the count wrong.
        // path[level] = RIGHT;
        --right;
        FindPaths(path, right, down, level+1);
    }
    if (down > 0 && IsFree(right, down-1)){
        path.insert(level, 1, DOWN);
        --down;
        FindPaths(path, right, down, level+1);
    }
}


int main() {
    int n = 4;
    std::string path = "";
    
    FindPaths(path, n-1, n-1, 0);
    return 0;
}