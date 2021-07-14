# "0" is water
# "1" is ground

# You will get an 2 D array, find number of islands
# For example here:

# [["1","1","0","1","0"],
#  ["1","1","0","1","1"],
#  ["0","0","1","0","0"],
#  ["1","1","1","0","1"]]

# There are 4 islands


class Solution:
	
	def __init__(self, grid):
		self.grid = grid
		self.num_of_islands = 0
		
	def count_num_of_islands(self):
		n = len(self.grid)
		m = len(self.grid[0])

		for i in range(n):
			for j in range(m):
				if self.grid[i][j] == "1":
					self.num_of_islands += 1
					
					self.make_water(i, j, n, m, self.grid)
	
	def make_water(self, i, j, n, m, grid):
		if i < 0 or j < 0 or i >= n or j >= m:
			return
		
		if grid[i][j] == "0":
			return
		
		else:
			grid[i][j] = "0"

			self.make_water(i + 1, j, n, m, grid)
			self.make_water(i, j + 1, n, m, grid)
			self.make_water(i - 1, j, n, m, grid)
			self.make_water(i, j - 1, n, m, grid)

	def get_num_of_islands(self):
		return self.num_of_islands


ob1 = Solution([["1","1","0","1","0"],
                ["1","1","0","1","1"],
				["0","0","1","0","0"],
				["1","1","1","0","1"]])
ob1.count_num_of_islands()
print(ob1.get_num_of_islands())