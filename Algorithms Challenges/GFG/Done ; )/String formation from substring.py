str = "djdjddjdj"

class Solution:
	def __init__(self):
		self.n = []

	def isRepeat(self, s):
		l = s[0]
		self.n.append(s.count(l))
		#print(self.n)
		if s.count(l) > 1:
			#if all(self.n[i] % self.n[i+1] == 0 or self.n[i] % self.n[i+1] == self.n[i] for i in range(len(self.n)-1)):
			self.n.sort()
			if all(self.n[i] % self.n[0] == 0 for i in range(1,len(self.n))):
				lst = [ele for ele in s.split(l,self.n[0]) if ele.strip()]
				if len(lst) == 0:
					return 1
				else:
					return self.isRepeat("".join(lst))
		return 0

X = Solution()

print(X.isRepeat(str))
