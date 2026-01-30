import random

# -------------------------
# A single cell in the grid
# -------------------------
class Cell:
    def __init__(self, x, y):
        self.x = x                  # X position in grid
        self.y = y                  # Y position in grid

        # Walls around the cell
        # True  = wall exists
        # False = opening
        self.walls = {
            'north': True,
            'south': True,
            'east':  True,
            'west':  True
        }

        # Used during maze generation
        self.visited = False


# -------------------------
# The grid of cells
# -------------------------
class Grid:
    def __init__(self, width, height):
        self.width = width
        self.height = height

        # Create a 2D array of cells
        self.cells = [
            [Cell(x, y) for y in range(height)]
            for x in range(width)
        ]


    # Safely get a cell (returns None if out of bounds)
    def get_cell(self, x, y):
        if 0 <= x < self.width and 0 <= y < self.height:
            return self.cells[x][y]
        return None


    # Find unvisited neighboring cells
    def get_neighbors(self, cell):
        neighbors = []

        # (dx, dy, wall_direction, opposite_wall)
        directions = [
            (0, -1, 'north', 'south'),
            (0,  1, 'south', 'north'),
            (1,  0, 'east',  'west'),
            (-1, 0, 'west',  'east')
        ]

        for dx, dy, direction, opposite in directions:
            nx, ny = cell.x + dx, cell.y + dy
            neighbor = self.get_cell(nx, ny)

            # Only consider neighbors we haven't visited yet
            if neighbor and not neighbor.visited:
                neighbors.append((neighbor, direction, opposite))

        return neighbors


    # -------------------------
    # Maze generation (DFS)
    # -------------------------
    def generate_maze(self):

        # Pick a random starting column on the NORTH edge
        start_x = random.randint(0, self.width - 1)
        start_cell = self.get_cell(start_x, 0)

        # Open the north wall so the maze has an entrance
        start_cell.walls['north'] = False

        # Stack for Depth-First Search
        stack = [start_cell]
        start_cell.visited = True

        # While there are still cells to explore
        while stack:
            current = stack[-1]

            # Find all unvisited neighbors
            neighbors = self.get_neighbors(current)

            if neighbors:
                # Pick a random neighbor
                neighbor, direction, opposite = random.choice(neighbors)

                # Knock down the wall between current and neighbor
                current.walls[direction] = False
                neighbor.walls[opposite] = False

                # Mark neighbor as visited and continue
                neighbor.visited = True
                stack.append(neighbor)

            else:
                # Dead end → backtrack
                stack.pop()

        # Open an exit on the SOUTH edge
        end_x = random.randint(0, self.width - 1)
        end_cell = self.get_cell(end_x, self.height - 1)
        end_cell.walls['south'] = False


    # -------------------------
    # ASCII drawing of the maze
    # -------------------------
    def draw(self):
        for y in range(self.height):

            # Draw north walls
            for x in range(self.width):
                print("+", end="")
                print("---" if self.cells[x][y].walls['north'] else "   ", end="")
            print("+")


            # Draw west walls and cell interior
            for x in range(self.width):
                print("|" if self.cells[x][y].walls['west'] else " ", end="")
                print("   ", end="")
            print("|")  # Right border

        # Draw bottom wall
        for x in range(self.width):
            print("+", end="")
            print("---" if self.cells[x][self.height - 1].walls['south'] else "   ", end="")
        print("+")


# -------------------------
# Run it
# -------------------------
if __name__ == "__main__":
    grid = Grid(10, 20)
    grid.generate_maze()
    grid.draw()

