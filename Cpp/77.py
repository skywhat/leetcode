#!/usr/bin/env python

class Solution(object):
	def combine(self,n,k):
		"""
		:type n: int
		:type k: int
		:rtype: List[List[int]]
		"""
		res=[]
		if n==k:
			return [[x+1 for x in range(n)]]
		if k==1:
			return [[x+1] for x in range(n)]
		else:
			res=res+self.combine(n-1,k)
			[res.append(x+[n]) for x in self.combine(n-1,k-1)]
			return res

		"""
		combine(4,2)=combine(3,2)+combine(3,1)*4
		"""
