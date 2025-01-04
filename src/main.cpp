#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <fstream>

using namespace std;


vector<vector<char> > map;

int rows = 0;
int cols = 0;

struct Node {
    int x, y;
    int g;
    int h;
    int f;
    Node *parent;

    Node(int x, int y, int g, int h, Node *parent)
        : x(x), y(y), g(g), h(h), parent(parent) {
        f = g + h;
    }

    bool operator>(const Node &other) const {
        if (f == other.f)
            return h > other.h;
        return f > other.f;
    }
};

bool isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && map[x][y] != '0';
}

vector<pair<int, int> > getNeighbors(int x, int y) {
    vector<pair<int, int> > neighbors = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
    return neighbors;
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void printPath(const Node *node) {
    if (node == nullptr) return;
    printPath(node->parent);
    if (map[node->x][node->y] != 'S' && map[node->x][node->y] != 'E') {
        map[node->x][node->y] = '*';
    }
}

void printMap() {
    for (const auto &row: map) {
        for (char cell: row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

void aStarAlgorithm(int startX, int startY, int goalX, int goalY) {
    priority_queue<Node, vector<Node>, greater<Node> > openList;
    vector<vector<bool> > closedList(rows, vector<bool>(cols, false));
    vector<vector<Node *> > cameFrom(rows, vector<Node *>(cols, nullptr));

    Node *startNode = new Node(startX, startY, 0, heuristic(startX, startY, goalX, goalY), nullptr);
    openList.push(*startNode);

    while (!openList.empty()) {
        Node currentNode = openList.top();
        openList.pop();

        if (currentNode.x == goalX && currentNode.y == goalY) {
            printPath(&currentNode);
            printMap();
            cout << "Goal Reached" << endl;
            return;
        }

        closedList[currentNode.x][currentNode.y] = true;

        for (const auto &neighbor: getNeighbors(currentNode.x, currentNode.y)) {
            int nx = neighbor.first;
            int ny = neighbor.second;

            if (isValid(nx, ny) && !closedList[nx][ny]) {
                int g = currentNode.g + 1;
                int h = heuristic(nx, ny, goalX, goalY);

                Node *neighborNode = new Node(nx, ny, g, h, new Node(currentNode));
                if (!cameFrom[nx][ny] || neighborNode->f < cameFrom[nx][ny]->f) {
                    openList.push(*neighborNode);
                    cameFrom[nx][ny] = neighborNode;

                    // Delete the dynamically allocated neighborNode
                    delete neighborNode;
                }
            }
        }
    }

    cout << "No path found" << endl;
    delete startNode; // Delete startNode when we're done with it if the loop ends with no path
}

void loadMapFromFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    map.clear();
    string line;
    while (getline(file, line)) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }

        vector<char> row;
        for (char cell: line) {
            if (cell == '1' || cell == '0' || cell == 'S' || cell == 'E') {
                row.push_back(cell);
            }
        }

        // Only add non-empty rows to the map
        if (!row.empty()) {
            map.emplace_back(row);
        }
    }

    file.close();

    // Updating Rows and Columns size
    rows = map.size();
    cols = map[0].size();
}


int main() {
    string filename = "MapVersions/easy.txt"; // Path to the grid file
    loadMapFromFile(filename);

    int startX = 0, startY = 0;
    int goalX = 0, goalY = 0;

    bool startFound = false, goalFound = false;
    for (int i = 0; i < rows && !(startFound && goalFound); ++i) {
        for (int j = 0; j < cols; ++j) {
            if (map[i][j] == 'S') {
                startX = i;
                startY = j;
                startFound = true;
            }
            if (map[i][j] == 'E') {
                goalX = i;
                goalY = j;
                goalFound = true;
            }
        }
    }

    aStarAlgorithm(startX, startY, goalX, goalY);

    return 0;
}
