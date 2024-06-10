#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> check(int stx, int sty, vector<vector<char>> &grid) {
    vector<vector<int>> moves;
    int x = stx, y = sty;
    while(x >= 0) {
        if(grid[x][y] == 'E') {
            moves.push_back({x, y});
            break;
        }
        x--;
    }
    x = stx;
    y = sty;
    while(x < 8) {
        if(grid[x][y] == 'E') {
            moves.push_back({x, y});
            break;
        }
        x++;
    }
    x = stx;
    y = sty;
    while(y < 8) {
        if(grid[x][y] == 'E') {
            moves.push_back({x, y});
            break;
        }
        y++;
    }
    x = stx;
    y = sty;
    while(y >= 0) {
        if(grid[x][y] == 'E') {
            moves.push_back({x, y});
            break;
        }
        y--;
    }
    x = stx;
    y = sty;
    while(x < 8 && y < 8) {
        if(grid[x][y] == 'E') {
            moves.push_back({x, y});
            break;
        }
        x++;
        y++;
    }
    x = stx;
    y = sty;
    while(x >= 0 && y < 8) {
        if(grid[x][y] == 'E') {
            moves.push_back({x, y});
            break;
        }
        x--;
        y++;
    }
    x = stx;
    y = sty;
    while(x < 8 && y >= 0) {
        if(grid[x][y] == 'E') {
            moves.push_back({x, y});
            break;
        }
        x++;
        y--;
    }
    x = stx;
    y = sty;
    while(x >= 0 && y >= 0) {
        if(grid[x][y] == 'E') {
            moves.push_back({x, y});
            break;
        }
        x--;
        y--;
    }
    return moves;
}

int queen(int stx, int sty, vector<vector<char>> grid) {
    int count = 0;
    vector<vector<int>> moves = check(stx, sty, grid);
    for(int i = 0; i < moves.size(); i++) {
        int x = moves[i][0];
        int y = moves[i][1];
        grid[x][y] = '0';
        int cur = 1 + queen(x, y, grid);
        grid[x][y] = 'E';
        count = max(cur, count);
    }
    return count;
}

int main() {
    vector<vector<char>> grid(8, vector<char> (8));
    int stx, sty;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'Q') {
                stx = i;
                sty = j;
            }
        }
    }
    grid[stx][sty] = '0';
    cout << queen(stx, sty, grid) << endl;
}