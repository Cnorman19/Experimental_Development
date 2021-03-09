# This script is to help me understand nesting vs guard clauses

def numberToAccountingString(number):

	if(number == None):
		return
	if(number < 0):
		return('(' + str(number) + ')') # This string concatenation could LIKELY be handled better and written cleaner(Future to do)
	return str(number)

print(numberToAccountingString(2))
print(numberToAccountingString(-2))
print(numberToAccountingString(None))

# Equivalent Noobie code

#def ToAccounting(x):
# NO CHECK FOR UNDEFINED VALUES HERE
#	if(number < 0):
#		return('(' + str(number) + ')')
	
#	elif(number >= 0): * completely unnecessary elif
#		return number  *notice here the difference in return types*