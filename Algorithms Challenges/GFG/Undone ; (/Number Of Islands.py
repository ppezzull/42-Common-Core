from typing import List

def print_graph(graph):
    for row in graph:
        print(row)
    print()

class Solution:
    def copy_grid(self, src):
        copy = []
        for i in src:
            copy.append(i[:])
        return(copy)

    def countislands(self, grid):
        if grid == None or grid == [[]]:
            return 0

        rows = len(grid[0])
        columns = len(grid)

        n_islands = 0
        grid2 = self.copy_grid(grid)

        for column in range(columns):
            for row in range(rows):
                if grid2[column][row] == 1:
                    self.get_island(grid2,column,row)
                    n_islands += 1              

        return n_islands

    def get_island(self,grid,column,row):
        q = [[column,row]]

        while len(q) != 0:
            i = q.pop(0)
            y = i[0]
            x = i[1]
            if grid[y][x] == 1:
                grid[y][x] = 2
                self.append_if(q,grid,x+1,y)
                self.append_if(q,grid,x,y+1)
                self.append_if(q,grid,x-1,y)
                self.append_if(q,grid,x,y-1)

    def append_if(self,q,grid,x,y):
        try:
            if x >= 0 and y >= 0 and grid[y][x]: q.append([y,x])
        except: pass

    def numOfIslands(self, rows: int, cols : int, operators : List[List[int]]):
        n_of_islands = []
        water = [[0 for col in range(cols)] for row in range(rows)]

        for operator in operators:
            y = operator[0]
            x = operator[1]
            water[y][x] = 1
            print_graph(water)
            n_of_islands.append(self.countislands(water))
        
        return n_of_islands

X = Solution()
print(X.numOfIslands(3, 4, [[1,1], [0,1], [1,2], [2,2]]))
