
![Logo](assets/banner.png)

This repository contains a C++ implementation of the A* (A-Star) pathfinding algorithm. It is used for finding the shortest path on a grid, taking into account obstacles and costs. The project includes a variety of grid maps (easy, medium, hard) and solutions for each.
![License: GPL-3.0](https://img.shields.io/badge/License-GPL%203.0-blue.svg)

## Overview

The A* algorithm is a well-known pathfinding algorithm that combines the advantages of Dijkstra’s algorithm and greedy best-first search. It efficiently finds the shortest path from a start node to a goal node in a grid-based environment.

### Key Features
- A* pathfinding on 2D grid maps.
- Supports dynamic grid loading from files.
- Customizable heuristic (Manhattan distance used here).
- Path visualization using '*' for the found path.

## How to Use

### Prerequisites:
- A C++ compiler (e.g., `g++`).
- The C++ standard library for `iostream`, `fstream`, and `vector`.

### Compilation:
To compile the program, run the following command:

```bash
g++ -o astar src/main.cpp
```

### Running the Program:
To run the program, use the following command:

```bash
./astar
```

The program will read the map from a file (located in `MapVersions/`) and execute the A* algorithm to find the path.

### Example Grid

Here’s an example of what a map looks like:

```
1 1 1 1 1         1 * * * 1
1 S 0 1 E   -->   1 S 0 * E
1 1 1 1 1         1 1 1 1 1
                  Goal Reached
```

- `1` represents walkable spaces.
- `0` represents obstacles.
- `S` is the starting point.
- `E` is the endpoint.

### Map Versions
Maps can be found in the `MapVersions/` folder. The following difficulty levels are available:
- `easy.txt`
- `medium.txt`
- `hard.txt`

### Solutions
The `Solutions/` folder contains the solutions (i.e., the paths found by the algorithm) for each map.

- `easy_solution.txt`
- `medium_solution.txt`
- `hard_solution.txt`

## Documentation

You can find more details in the `docs/` folder, including the **Project Overview PDF**.

- [Project Overview PDF](docs/project_overview.pdf)

## License

This project is licensed under the GNU General Public License v3.0 (GPL-3.0). See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Special thanks to the creators of the YouTube videos and resources used in this project:
  - Sebastian Lague
  - Computerphile
  - Anish Krishnan

- Appreciation to the "Introduction to A*" article for providing valuable insights and information that helped guide the implementation of the algorithm. [\[Link to the article\]](https://theory.stanford.edu/~amitp/GameProgramming/AStarComparison.html)
