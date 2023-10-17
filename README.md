# rubiks-cube-solver
Program for finding optimal Rubik's cube solution
# Description

# Initial idea

My solution to the optimal Rubik's cube move sequence problem uses graph theory.
Every Rubik's cube state can be represented as a vertex in a graph and making a move as an edge between different vertexes. Therefore the optimal solution is the shortest path between an initial state of the cube and the state of the solved cube.
Since the graph is unweighted (every move counts the same) the shortest path can be found using a graph traversal algorithm such as BFS.

# How fast is it?

It is a known fact that optimal solution for the Rubik's cube consists of at most 20 moves.
Hence BFS would go at most 20 nodes deep in the search. Unfortunately, because from every state there are edges to 18 different states, every next layer of the BFS will be up to 18 times bigger than the previous one. In reality it will be less than 18 times more, because there are many ways to reach the same cube state and the BFS will not visit the same vertex twice.
But still in the worst case scenario BFS would have to search through all 43 252 003 274 489 856 000 possible Rubik's cube states, which would take computer a lot of time.

# Improvement

Every layer further from the initial node will have more nodes than the previous layer. That's why we can use meet in the middle technique here!
Instead of running BFS only from the initial state and searching for the solved state, the BFS can be run from the initial state and the solved state simultanously. Then the two searches will meet in the middle of the shortest path between the initial and solved states. Therefore, the BFS will traverse at most 10 layers deep from both sides. It is only requiered to store states visited from both sides in some hash maps.

# Final speed

Now, using the meet in the middle technique the total number of visited states will be the size of the 10-th layer times 2 since the BFS runs from both sides. The number of states in the 10-th layer will be equal to about 10 billion (which can be shown by running a BFS).
Therefore the program will have to visit about 20 billion position and store all of them in the hash map.
Taking a relatively big constant factor of looking through 18 moves and 20 billion positions to visit, program will in the worst case scenario run for several hours up to a few days (depending on hardware)
Hash map storing 20 billion positions (128 bits per position) would require about 300 GB of memory

# Usage

To use the program you need to compile it first using c++ 17 or higher.
g++ -std=c++17 -o cubesolver cubesolver.cpp
then run it
./cubesolver
Program takes as an input a list of moves in Rubik's cube move notation separated by a space or enter and a "0" indicating end of input.
(there is a folder called examples with sample inputs)
Program outputs optimal solution to the given cube position as a list of moves in the Rubik's cube move notation.

# Example input:

D' U' D L L D' R' R' F R B2 L2 D 0

# Example output:

/*************************************/

Found solution in 9 moves

Checked 434457 positions in the proccess

D' L2 B2 R' F' R2 D L2 U 

/*************************************/
