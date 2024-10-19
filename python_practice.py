# python brush up

# any and all operations using the map funtion
def isEven(n):
    return (n%2==0)

list = [1,2,3,4,5]
anyResult = any(map(isEven, list))
allResult = all(map(isEven, list))
print("any result:", anyResult)
print("all result:", allResult)

# walrus operator
# not available in my python version, but is as follows
# the operator will both assign a value to a variable, while also evaluating
# as an expression. "y:= 3" will actually print "3" because the result is
# evaluated whereas "x=3" does not print anything.
x = 3
# y := 3

# lists in python
l1 = [1,2,3,2,5,2]
print("len of l1:", len(l1))
l2 = [7,8,9]
print("len of l1+l2:",len(l1+l2))
print(type(l1[2]))
print(l1)
# remove element with value 2 from the first position in the list
l1.remove(2)
print(l1)
# delete the first element from the list
del l1[0]
print(l1)
