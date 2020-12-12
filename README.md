# CS 225 Final Project

## Algorithms: BFS, Astar, Dijkstra's

### Authors:

- Ben Civjan - bcivjan2
- Preston Chao - preston7
- Dennis Mccann - dmccann3
- Dom Quigley - djq2

---

## Building the application

1. Clone the project repository to your local machine
2. `cd` into the cloned repository
3. Enter the command `make` or `make map` into the terminal

## Demo Video

- https://drive.google.com/file/d/1rYTIJXVtSZPwhaKkZ_NOjIloH2ZZ5QJf/view?usp=sharing

## Running the application

1. To run a bfs traversal on a set of airport data enter the command
   `./map bfs` - This outputs the visited airports in the order of the traversal from San Diego International Airport
2. To run the Astar pathfinding algorithm enter the command `./map astar`
   - This finds a path from San Diego International Airport to Coimbatore International Airport
3. To run Dijkstra's algorithm enter the command `./map dijkstra`
   - Since the actual data set is so large the runtime for dijkstra's algorithm is very long
   - We remedied this by instead creating a smaller sample dataset and running the algorithm on that

## Testing the application

1. To build the tests enter the command `make test`
2. To run the tests:
   - To run all tests enter the command `./test`
   - To run all bfs tests enter `./test [part=bfs]`
   - To run all astar tests enter `./test [part=astar]`
   - To run all dijkstra tests enter `./test [part=dijkstra]`
