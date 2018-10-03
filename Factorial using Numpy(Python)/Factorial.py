import numpy as np

def create_array(x,y):

    Input = np.arange(int(x),int(y))
    return Input

choice = input("Please enter a range for your array: ")

print("Array created ---> ", create_array(1,choice))

a = create_array(1,choice).prod()

print("\nThe factorial of your array is: ", (a * int(choice)))


