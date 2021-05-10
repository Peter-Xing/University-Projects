#!/usr/bin/python
# -*- coding:utf-8 -*-

# Artificial Intellegence
#训练决策树

import string
import sys
from collections import Counter
import math


#define leaf and node
class Leaf:
	def __init__(self,label):
		self.label = label
		self.i = 1

	
	def display(self):
		print(self.label)

	def printype(self):
		print(type(self))


class Node:
	def __init__(self,attr,splitval,left,right):
		self.attr = attr
		self.splitval = splitval
		self.left = left
		self.right = right
		self.i = 0

	def display(self):
		print("attribute index is "+str(self.attr))
		print("splitval is "+str(self.splitval))

	def printype(self):
		print((self))

	



#get file path and minleaf integer
train = sys.argv[1] #training data set file
test = sys.argv[2] #testing data set file
minleaf = sys.argv[3] # int
minleaf = int(minleaf)

#first, use train file 
training = []
f = open(train, 'r')
for eachline in f:
	training.append(eachline)
f.close()

#total 901 rows in training, each has 11 attributes and 1 label
datas = [] #list of lists
for i in range(1,len(training)):
	tem = []
	tem2 = []
	tem = training[i].strip().split(" ")
	for each in tem:
		if each != "":
			each = float(each)
			tem2.append(each)
	datas.append(tem2)
#for each column c1 c2 ..., index from 0 to 899
example = datas
# example[0][11] = 7
# example[1][11] = 55
# print(example)

#define recursive DTL function
def DTL(data,minleaf):#data is list of lists of attributes and label
	#tell if all labels are the same in data
	ff = 0
	for each in data:
		if each[11] != data[0][11]:
			ff=1
	#tell if all decisions taken are the same
	flag = 0
	for ea in data:
		for i in range(0,11):
			if ea[i] != data[0][i]:
				flag = 1



	if len(data) <= minleaf or ff==0 or flag==0:# it is leaf node
		#create new leaf node
		leaf = data
		#find the unique mode in labels, when only one label appears most frequently
		labels = []
		key = []
		freq = []
		c = Counter()
		for pt in leaf:
			labels.append(pt[11])

		for i in labels:
			c[i]=c[i]+1

		for i in c:
			key.append(i)
			freq.append(c[i])
		maxv = max(freq)
		co = 0
		for x in freq:
			if x == maxv:
				co = co+1

		if co==1: #means only one mode 
    		#choose the label with mode
			for i in range(0,len(freq)):
				if maxv == freq[i]:
					lab = key[i]#lab the the label with unique mode
		else:
			lab = "unknown"

    	#add the label to leaf node, then return the leaf node
		leafnode = Leaf(lab)
		# leafnode.display()
		return leafnode

	#if it is not leaf, create a new node with splitval and attr
	ll = ChooseSplit(data)
	newnode = Node(ll[0],ll[1],[],[])
	# newnode.display()

	#then, recursive after using correct data
	# in <= and > groups
	index = ll[0]
	v = ll[1]
	data1 = []
	data2 = []
	for each in data:
		if each[index] <= v:
			data1.append(each)
		else:
			data2.append(each)

	#and exclude the attr used

	newnode.left = DTL(data1,minleaf)
	newnode.right = DTL(data2,minleaf)

	return newnode


#define ChooseSplit function
#use info gain from course slides
#return best attribute and splitvalue
def ChooseSplit(data):
	bestgain = 0
	bestattr = 0 #index of the best attr
	bestsplitv = 0

	#sort according to attribute index 0 to 10
	base = [[],[],[],[],[],[],[],[],[],[],[],[]]
	c = [[],[],[],[],[],[],[],[],[],[],[],[]]
	for i in range(0,len(data)):
		for y in range(0,len(data[0])):
			c[y].append(data[i][y])
			base[y].append(data[i][y])


	# for eahc in base:
	# 	print(eahc)


	#get I(R) first
	count = Counter()
	for i in c[11]:
		count[i]=count[i]+1

	# print(count.values())
	Ic = 0
	samples = len(c[11])

	for each in count.values():
		pr = float(each)/float(samples)
		Ic = Ic - pr*math.log(pr,2)


	#c[0] to c[10] is the list of values in each attribute
	#sort each attribute
	for x in range(0,len(c)-1):

		c[x].sort()# sorted c is ascending
		# print("attribute "+str(x)+" is :           "+str(c[x]))
		

		#in each attribute, get list of possible splitvalues
		#find the best attribute and its splitval
		#for each splitval, we try divide data based on it
		# <= splitval or > splitval, get gain
		#search the value here in base,find corresponding sample's label
		
		splitvalues = []
		for i in range(0,len(c[x])-1):# i = 0 to N-1
			splitval = (c[x][i]+c[x][i+1])/2.0
			splitvalues.append(splitval)
			
		# print("possible split values are: "+str(splitvalues))

		#in each attribute, try each splitvalue
		for val in splitvalues:
			# print(val)
			#in the attribute, less is number of samples in one group
			#gt is the other group
			less = []
			gt = []
			lessl = []
			gtl = []
			for ii in range(0,len(base[x])):
				if base[x][ii] <= val:
					less.append(base[x][ii])
					lessl.append(base[11][ii])
				else:
					gt.append(base[x][ii])
					gtl.append(base[11][ii])

			#calculate the info gain
			#find corresponding labels in each group
			#if attribute values are the same but labels
			#are different, count > 1, output the labels with 
			#the multiple attribute values if labels are different
			pr1 = len(less)/float(samples)
			pr2 = len(gt)/float(samples)


			c1 = Counter()
			for i in lessl:
				c1[i]=c1[i]+1
			c2 = Counter()
			for i in gtl:
				c2[i]=c2[i]+1


			Ic1 = 0
			for each in c1.values():
				pr = float(each)/float(len(less))
				Ic1 = Ic1 - pr*math.log(pr,2)

			Ic2 = 0
			for each in c2.values():
				pr = float(each)/float(len(gt))
				Ic2 = Ic2 - pr*math.log(pr,2)


			
			gain = Ic - Ic1*pr1 - Ic2*pr2
			# gain = round(gain,3)

			if gain > bestgain:
				bestgain = gain
				bestattr = x #index of the best attr
				bestsplitv = val


	ll = [bestattr,bestsplitv]
	return ll



def Predict(n,x):
	while n.i == 0:#while it is not leaf node
		if x[n.attr]<=n.splitval:
			n = n.left
		else:
			n = n.right
	return n.label



#Constructing decision tree
#next, read test file
testing = []
f = open(test, 'r')

for eachline in f:
	testing.append(eachline)

f.close()

#put the corresponding values in attribute columns
#each list below has the corresponding records in test file

datax = []#list of lists

for i in range(1,len(testing)):
	tem = []
	tem2 = []
	tem = testing[i].strip().split(" ")
	for each in tem:
		if each != "":
			each = float(each)
			tem2.append(each)
	# print(tem2)
	datax.append(tem2)


tree = DTL(example,minleaf)

for each in datax:
	la = Predict(tree,each)
	if type(la) == float:
		print(int(la))
	else:
		print(la)
