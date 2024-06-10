#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};

void findPath(int i, int j, int n, vector<vector<int>> &arr, vector<string> &des, string path, vector<vector<int>> &vis) {
    if ((i == 0 && j == n - 1) || (i == n - 1 && j == n - 1)) {
        des.push_back(path);
        return ;
    }
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] != 0 && vis[x][y] == 0) {
            findPath(x, y, n, arr, des, path + dir[k], vis);
        } 
    }
    vis[i][j] = 0;
    return ;
}

void findPathO(int i, int j, int n, int m, int rem, vector<vector<int>> &arr, vector<pair<string, int>> &desO, string path, vector<vector<int>> &vis) {
    if ((i == 0 && j == n - 1 && rem >= 0) || (i == n -1  && j == n - 1 && rem >= 0)) {
        desO.push_back({path, rem});
        return ;
    }
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] != 0 && vis[x][y] == 0 && rem - arr[i][j] - arr[x][y] >= 0) {
            if (arr[x][y] == 9) {
                findPathO(x, y, n, m, m, arr, desO, path + dir[k], vis);
            } else {
                findPathO(x, y, n, m, rem - arr[i][j] - arr[x][y], arr, desO, path + dir[k], vis);
            }
        } 
    }
    vis[i][j] = 0;
    return ;
}

int main() {
    int n, m; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> m;
    vector<string> des;
    vector<pair<string, int>> desO;
    vector<vector<int>> vis(n, vector<int> (n, 0));
    findPath(0, 0, n, arr, des, "", vis);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vis[i][j] = 0;
        }
    }
    findPathO(0, 0, n, m, m, arr, desO, "", vis);
    if (des.size() != 0 && desO.size() != 0) {
        cout << "The available paths are\n";
        for (string it : des) cout << it << "\n";
        cout << "The feasible paths with remaining oxygen levels are\n";
        for (auto it : desO) cout << it.first << " " << it.second << "\n";
    } else if (des.size() == 0) {
        cout << "No path available to reach the destination";
    } else {
        cout << "The available paths are\n";
        for (string it : des) cout << it << "\n";
        cout << "No feasible path";
    }
}