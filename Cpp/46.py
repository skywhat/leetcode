#!/usr/bin/env python

class Solution(object):
	def permute(self,nums):
		"""
		:type nums:List[int]
		:rtype:List[List[int]]
		"""
		res=[]
		if len(nums)==1:
			res.append(nums)
			return res
		for i in range(len(nums)):
			prev=list(nums)
			del prev[i]
			[res.append(x+[nums[i]]) for x in self.permute(prev)]
		return res
