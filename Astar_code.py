import heapq

def heuristic(a, b):
    """Calculate Manhattan distance heuristic."""
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def add_neighbours(position, maze):
    """Generate neighbors (up, down, left, right) of a position."""
    row, col = len(maze), len(maze[0])
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, Down, Left, Right
    neighbors = []
    
    # Check all four directions
    for dr, dc in directions:
        nr = position[0] + dr
        nc = position[1] + dc
        
        # Ensure within bounds and not a wall (maze value 1 is a wall)
        if 0 <= nr < row and 0 <= nc < col and maze[nr][nc] != 1:
            neighbors.append((nr, nc))
    
    return neighbors

def astar(maze, start, goal):
    """Implement the A* search algorithm to find the shortest path."""
    
    open_set = []  # Priority queue (min-heap) used to store nodes to explore next
    heapq.heappush(open_set, (0, start))  # Push the start node with f(n)=0

    came_from = {}  # Dictionary to reconstruct the path
    f_score = {start: heuristic(start, goal)}  # Set initial f_score for start
    g_score = {start: 0}  # Set initial g_score for start
    closed_set = set()  # Set to store visited nodes

    # Main loop: explore nodes
    while open_set:
        current_f, current = heapq.heappop(open_set)  # Get the node with lowest f_score
        
        # If the goal is reached, reconstruct and return the path
        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)  # Append the start node to complete the path
            path.reverse()  # Reverse the path to get it from start to goal
            return path

        closed_set.add(current)  # Mark current node as visited

        # Explore each valid neighbor of the current node
        for neighbor in add_neighbours(current, maze):
            if neighbor in closed_set:  # Skip neighbors that are already visited
                continue
            
            # Calculate the tentative g_score for this neighbor
            temp_g_score = g_score[current] + 1  # Step cost is always 1

            # If neighbor not in g_score or found a shorter path to it
            if neighbor not in g_score or temp_g_score < g_score[neighbor]:
                # Update the neighbor's parent and scores
                came_from[neighbor] = current
                g_score[neighbor] = temp_g_score
                f_score[neighbor] = temp_g_score + heuristic(neighbor, goal)

                # Add neighbor to open set with updated f_score
                heapq.heappush(open_set, (f_score[neighbor], neighbor))

        # Print current open set, closed set, g_score, and f_score for debugging
        print(f"Open Set (f_score, node): {open_set}")
        print(f"Closed Set (visited nodes): {closed_set}")
        print(f"g_score: {g_score}")
        print(f"f_score: {f_score}")

    return None  # Return None if no path is found

def print_maze_with_path(maze, path):
    """Print the maze with the found path."""
    maze_copy = [row[:] for row in maze]  # Create a copy of the maze
    for r, c in path:
        maze_copy[r][c] = '*'  # Mark the path with '*'
    
    for row in maze_copy:
        print(" ".join(str(cell) for cell in row))


# Example Usage
maze = [
    [0, 1, 0, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 0, 0],
    [1, 1, 1, 1, 0],
    [0, 0, 0, 0, 0]
]

start = (0, 0)  # Starting position
goal = (4, 4)   # Goal position

path = astar(maze, start, goal)  # Call the A* search function

if path:
    print("Path found:")
    print(path)
    print_maze_with_path(maze, path)  # Print the maze with the found path
else:
    print("No path found.")
