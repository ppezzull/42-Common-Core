from typing import List

def print_graph(graph):
    for i in graph:
        print(i)

class Solution:
    def is_new_island(self, water, x, y):
        check = self.check
        if  check(water, x + 1, y) == 1 or \
            check(water, x, y + 1) == 1 or \
            check(water, x - 1, y) == 1 or \
            check(water, x, y - 1) == 1:
            return 0
        return 1

    def check(self, water, x, y):
        try:
            if x >= 0 and y >= 0 and water[x][y]:
                return 1
        except:
            return 0

    def numOfIslands(self, rows: int, cols : int, operators : List[List[int]]):
        islands_map = {}
        islands_groups = []

        n_of_islands = []
        water = [[0 for col in range(cols)] for row in range(rows)]

        start = operators.pop(0)
        islands_map.update({"0": start})

        for i in range(len(operators)):
            x = operators[i][0]
            y = operators[i][1]
            id = f"{i + 1}"
            islands_map[id] = [x,y]
            
            water[x][y] = 1
            print(i)
        print(islands_map, operators)    
        
        return n_of_islands


X = Solution().numOfIslands
print(X(4, 3, [[1, 2], [0, 1], [3,2]]))