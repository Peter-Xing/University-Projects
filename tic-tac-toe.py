#!/usr/bin/python
# -*- coding:utf-8 -*-


# Artificial Intellegence
# 三子棋，双方为电脑，根据已给出的棋局用极小极大算法算最后结果


import string
import sys

#get state string and output file path
s = sys.argv[1]
path = sys.argv[2]
prune = 0
ply = 0
if len(sys.argv) >= 4:
	prune = 1

if len(sys.argv) == 5:
	ply = sys.argv[4]

ply = int(ply)

#tell if it is end already
#either max / min wins, or draw(board full)
visited = []
utility = []
al = -999
be = 999


#define min-value(state), max-value(state) 
# recursion
def minimax(state,turn,alpha,beta,depth): 
	a = endgame(state)
	depth = depth + 1 #this node is depth steps away from root
	
	if a != 9 and ply == 0: # terminal , either -1,0,1
		utility.append(a)
		visited.append(state)
		return a # return utility value

	elif a != 9 and ply > 0: # terminal , either -1,0,1
		#use E(s) instead
		res = evaluation(state)

		utility.append(res)
		visited.append(state)
		return res # return utility value


	elif a == 9 and turn == 1 and prune == 0: #max turn, next is min's turn
		# loop the vacant positions, use min-v, 
		# find the min value of all min-v's return values
		po = []
		for x in range(0,9):
			if state[x] == '-':
				po.append(x)

		u2 = []
		for x in range(0,len(po)): #loop the vacant positions, each get a min-v 
			tem = list(state)
			tem[po[x]] = 'o'
			te = ''.join(tem)
			u2.append(minimax(te,0,alpha,beta,depth))

		a = min(u2)
		visited.append(state)
		utility.append(a)
		return a

	elif a == 9 and turn ==0 and prune == 0: #min turn, next is max
		# loop the vacant positions, use max-v, 
		# find the max value of all max-v's return values
		po = []
		for x in range(0,9):
			if state[x] == '-':
				po.append(x)

		u2 = []
		for x in range(0,len(po)): #loop the vacant positions, each get a max-v 
			tem = list(state)
			tem[po[x]] = 'x'
			te = ''.join(tem)
			u2.append(minimax(te,1,alpha,beta,depth))
		a = max(u2)
		visited.append(state)
		utility.append(a)
		return a


	elif a == 9 and turn == 1 and prune == 1 and ply == 0: # doing prunning, max turn, next is min turn
		# loop the vacant positions, use min-v, 
		# find the min value of all min-v's return values
		po = []
		for x in range(0,9):
			if state[x] == '-':
				po.append(x)


		v = 999 #no value yet
		for x in range(0,len(po)): #loop the vacant positions, each get a min-v 
			tem = list(state)
			tem[po[x]] = 'o'
			te = ''.join(tem)
			
			v2 = minimax(te,0,alpha,beta,depth)
			if v2 < v:
				v=v2
			if v2 <= alpha:
				visited.append(state)
				utility.append(v)
				return v
			if v2 < beta:
				beta = v2
		
		visited.append(state)
		utility.append(v)
		return v

	elif a == 9 and turn == 0 and prune == 1 and ply == 0: # doing prunning
		# find the max value of all min-v's return values
		po = []
		for x in range(0,9):
			if state[x] == '-':
				po.append(x)


		v = -999 #no value yet
		for x in range(0,len(po)): #loop the vacant positions, each get a max v
			tem = list(state)
			tem[po[x]] = 'x'
			te = ''.join(tem)
			
			v2 = minimax(te,1,alpha,beta,depth)
			if v2 > v:
				v=v2
			if v2 >= beta:
				visited.append(state)
				utility.append(v)
				return v
			if v2 > alpha:
				alpha = v2
		
		visited.append(state)
		utility.append(v)
		return v

	elif a == 9 and turn == 1 and prune == 1 and ply > 0 and depth < ply: # doing prunning, max turn, next is min turn
		# and doing Cut-off, eval function ....
		# loop the vacant positions, use min-v, 
		# find the min value of all min-v's return values

		po = []
		for x in range(0,9):
			if state[x] == '-':
				po.append(x)

		# just as normal prune
		v = 999 #no value yet
		for x in range(0,len(po)): #loop the vacant positions, each get a min-v 
			tem = list(state)
			tem[po[x]] = 'o'
			te = ''.join(tem)
			
			v2 = minimax(te,0,alpha,beta,depth)
			if v2 < v:
				v=v2
			if v2 <= alpha:
				visited.append(state)
				utility.append(v)
				return v
			if v2 < beta:
				beta = v2
			

		visited.append(state)
		utility.append(v)
		return v

		

	elif a == 9 and turn == 0 and prune == 1 and ply > 0 and depth<ply: # doing prunning, cut-off
		# find the max value of all min-v's return values
		po = []
		for x in range(0,9):
			if state[x] == '-':
				po.append(x)



		v = -999 #no value yet
		for x in range(0,len(po)): #loop the vacant positions, each get a max v
			tem = list(state)
			tem[po[x]] = 'x'
			te = ''.join(tem)
			
			v2 = minimax(te,1,alpha,beta,depth)
			if v2 > v:
				v=v2
			if v2 >= beta:
				visited.append(state)
				utility.append(v)
				return v
			if v2 > alpha:
				alpha = v2
			
		visited.append(state)
		utility.append(v)
		return v

	elif a == 9 and prune == 1 and ply > 0 and depth == ply:
		res = evaluation(state) # evaluation function returns an integer

		visited.append(state)
		utility.append(res)
		return res
	

#evaluation function E(s) = M(s) - O(s) after state s
def evaluation(state):

	c = 0 #count from 0
	#max's possible winning lines
	ma = countx(state)
	#min's possible winning lines
	mi = counto(state)

	dif = ma - mi

	return dif


def countx(state):#c is total count of win
	pos = [] #state's empty spots
	for i in range(0,9):
		if state[i] == "-":
			s1 = list(state)
			s1[i] = 'x'
			state=''.join(s1)

	#count how many winning lines mas has
	bd = [[5,5,5],[5,5,5],[5,5,5]]#board , row/column index 0 1 2
	for i in range(0,9):
		bd[i/3][i%3] = state[i]


	rows = []
	cols = []
	dia = []
	for x in range(0,3): # check rows
		sr = 0
		for y in range(0,3):
			if bd[x][y] == "x":
				sr += 1
		rows.append(sr)
	for x in range(0,3): # check columns
		sc = 0
		for y in range(0,3):
			if bd[y][x] == "x":
				sc += 1
		cols.append(sc)
	sd = 0 # check diagonal
	for x in range(0,3):
		if bd[x][x] == "x":
			sd += 1
	dia.append(sd)

	sd = 0
	for x in range(0,3):
		if bd[x][2-x] == "x":
			sd += 1
	dia.append(sd)

	total = 0
	for x in range(0,3):
		if rows[x] == 3:
			total = total + 1
		if cols[x] == 3:
			total = total + 1
	for y in range(0,2):
		if dia[y]== 3:
			total = total + 1
	return total



def counto(state):
	pos = [] #state's empty spots
	for i in range(0,9):
		if state[i] == "-":
			s1 = list(state)
			s1[i] = 'o'
			state=''.join(s1)

	#count how many winning lines mas has
	bd = [[5,5,5],[5,5,5],[5,5,5]]#board , row/column index 0 1 2
	for i in range(0,9):
		bd[i/3][i%3] = state[i]


	rows = []
	cols = []
	dia = []
	for x in range(0,3): # check rows
		sr = 0
		for y in range(0,3):
			if bd[x][y] == "o":
				sr += 1
		rows.append(sr)
	for x in range(0,3): # check columns
		sc = 0
		for y in range(0,3):
			if bd[y][x] == "o":
				sc += 1
		cols.append(sc)
	sd = 0 # check diagonal
	for x in range(0,3):
		if bd[x][x] == "o":
			sd += 1
	dia.append(sd)

	sd = 0
	for x in range(0,3):
		if bd[x][2-x] == "o":
			sd += 1
	dia.append(sd)

	total = 0
	for x in range(0,3):
		if rows[x] == 3:
			total = total + 1
		if cols[x] == 3:
			total = total + 1
	for y in range(0,2):
		if dia[y]== 3:
			total = total + 1
	return total



#define endgame(state), tell whether it is end now, and 
#return current utility if it is the end.
#otherwise, return 9,meaning not end
def endgame(state):
	bd = [[5,5,5],[5,5,5],[5,5,5]]#board , row/column index 0 1 2
	for i in range(0,9):
		bd[i/3][i%3] = state[i]


	#now check if it is end
	rows = []
	cols = []
	dia = []
	for x in range(0,3): # check rows
		sr = 0
		for y in range(0,3):
			if bd[x][y] == "x":
				sr += 1
			elif bd[x][y] == "o":
				sr -= 1
		rows.append(sr)

	for x in range(0,3): # check columns
		sc = 0
		for y in range(0,3):
			if bd[y][x] == "x":
				sc += 1
			elif bd[y][x] == "o":
				sc -= 1
		cols.append(sc)

	sd = 0 # check diagonal
	for x in range(0,3):
		if bd[x][x] == "x":
			sd += 1
		elif bd[x][x] == "o":
			sd -= 1
	dia.append(sd)

	sd = 0
	for x in range(0,3):
		if bd[x][2-x] == "x":
			sd += 1
		elif bd[x][2-x] == "o":
			sd -= 1
	dia.append(sd)

	#anyone wins , the game ends,return utility
	flag = 0
	for x in range(0,3):
		if rows[x] == 3 or cols[x] == 3:
			flag = 1
		elif rows[x] == -3 or cols[x] == -3:
			flag = -1
	for x in range(0,2):
		if dia[x] == 3:
			flag = 1
		elif dia[x] == -3:
			flag = -1


	
	#if the board is full , the game ends
	full = 0
	for i in range(0,9):
		if state[i] == "-":
			full=1
	if full==0 and flag == 0:
		flag = 0
	elif full > 0 and flag == 0:
		flag = 9 # The game is still on, return 9 for later

	return flag




#first see if max / min wins
#use sum of rows, columns, diagonal to check
for aaa in range(0,1):
	#1. if input state is end, just quit
	if endgame(s) != 9:
		break

	#2. next, the game is still on, check whose turn it is now
	nx = 0
	no = 0
	turn = 0 # 0 is min's turn, 1 is max's turn
	for i in range(0,9):
		if s[i] == "x":
			nx += 1
		elif s[i] == "o":
			no += 1
	if nx>no:
		turn = 0
	else:
		turn = 1



	# see which positions are left to choose
	po = []
	for x in range(0,9):
		if s[x] == '-':
			po.append(x)
	# print(po)

	d = 0
	if turn == 1: #max go, call max-v function
		u1 = []
		for x in range(0,len(po)): #loop the vacant positions, each get a max-v 
			tem = list(s)
			tem[po[x]] = 'x'
			te = ''.join(tem)
			child = minimax(te,1,al,be,d)
			u1.append(child)
			#returned value needs to be compared with al, assign if necessary
			if child > al:
				al = child


		for i in range(0,len(u1)):
			if u1[i] == max(u1): #find the max of max-v's utilities, make the action
				s1 = list(s)
				s1[po[i]] = "x"
				s=''.join(s1)
				break

		move = s	


	elif turn == 0: #min go, call min-v function
		u2 = []
		for x in range(0,len(po)): #loop the vacant positions, each get a min-v 
			tem = list(s)
			tem[po[x]] = "o"
			te = ''.join(tem)
			ch = minimax(te,0,al,be,d)
			u2.append(ch)
			#returned value needs to be compared with be, assign if necessary
			if ch < be:
				be = ch
		

		for i in range(0,len(u2)):
			if u2[i] == min(u2): #find the min of min-v's utilities, make the action
				s1 = list(s)
				s1[po[i]] = 'o'
				s=''.join(s1)
				break
		move = s



	print(move)

	# for x in range(0,len(visited)):
	# 	print(visited[x]+" "+str(utility[x]))


	filewriter = open(path, 'w')

	for x in range(0,len(visited)):
		filewriter.write(visited[x]+" "+str(utility[x])+'\n')

	filewriter.close()
