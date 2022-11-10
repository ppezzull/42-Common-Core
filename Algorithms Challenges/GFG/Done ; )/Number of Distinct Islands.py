from typing import List

grid = [[1, 1, 0, 0, 0],
        [1, 1, 0, 0, 0],
        [0, 0, 0, 1, 1],
        [0, 0, 0, 1, 1]]

grid2 = [[1, 1, 0, 1, 1], 
         [1, 0, 0, 0, 0], 
         [0, 0, 0, 0, 1], 
         [1, 1, 0, 1, 1]]

class Solution:
    def countDistinctIslands(self, grid : List[List[int]]):
        if grid == None or grid == [[]]:
            return 0

        rows = len(grid[0])
        columns = len(grid)
    
        islands = 0
        islands_lst = []

        for column in range(columns):
            for row in range(rows):
                if grid[column][row] == 1:
                    island = self.get_island(grid,column,row)
                    if island not in islands_lst:
                        islands += 1   
                        islands_lst.append(island)                        
        return islands

    def get_island(self,grid,column,row):
        q = [[column,row]]
        min_y = column
        min_x = row
        island = [] 

        while len(q) != 0:
            i = q.pop(0)
            y = i[0]
            x = i[1]
            min_x = x if x < min_x else min_x
            min_y = y if y < min_y else min_y
            if grid[y][x] == 1:
                grid[y][x] = 2
                self.append_if(q,grid,x+1,y)
                self.append_if(q,grid,x,y+1)
                self.append_if(q,grid,x-1,y)
                self.append_if(q,grid,x,y-1)
                island.append([y,x])

        return [[i[0]-min_y,i[1]-min_x] for i in island]
        
    def append_if(self,q,grid,x,y):
        try:
            if x >= 0 and y >= 0 and grid[y][x]:
                q.append([y,x])
        except:
            pass
    
X = Solution()

print(X.countDistinctIslands(grid))
print(X.countDistinctIslands(grid2))
                

# islands = [[i for i, bin in enumerate(row) if bin] for row in grid]
        # islands = []

        # for row in grid:
        #     island = []
        #     for i,bin in enumerate(row):
        #         if bin:

        #             island.append(i)
        #         elif island:
        #             islands.append(island)
        #             island = []
        #     if island:
        #             islands.append(island)            