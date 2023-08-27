import random

array1 = [[" ", " ", " "], [" ", " ", " "], [" " , " ", " "]]
shapes = ["x", "o"]
occupied_space = []

# this func prints the maze 
def print_maze():
    for row_index in range(3):
        print(" {}  |  {}  |  {} ".format(array1[row_index] [0], array1[row_index] [1], array1[row_index] [2]))
        if row_index <= 1:
            print("---------------")
    print()


# this func implements a random move 
def comp_move():
    comp_move_row, comp_move_col = random.randint(0, 2), random.randint(0, 2)
    
    # checks if the moving space is occupied or not 
    # if yes then sends the program back to the start of the func
    if ("{}{}".format(comp_move_row, comp_move_col)) in occupied_space:
        comp_move()

    else:
        array1[comp_move_row][comp_move_col] = comp_shape

        # stores the occupied space in the array
        occupied_space.append("{}{}".format(comp_move_row, comp_move_col))
        check_win()
        print_maze()
        user_move()


# this func asks the user to make a move 
def user_move():
    str1 = str(input("Enter pos to move: "))
    user_move_row = int(str1[0])
    user_move_col = int(str1[2])

    # checks if the moving space is occupied or not
    # iF yes then sends the program back to the start of the func
    if ("{}{}".format(user_move_row, user_move_col)) in occupied_space:
        user_move()

    # stores the occupied space in the array
    else:
        array1[user_move_row][user_move_col] = user_shape
        occupied_space.append("{}{}".format(user_move_row, user_move_col))
        check_win()
        print_maze()
        comp_move()


# this func checks the winning condition
def check_win():

   
    # checks the win cond in all rows
    for row_index in range(3):
        if array1[row_index][0] == "x" or array1[row_index][0] == "o":
            if array1[row_index][0] == array1[row_index][1] == array1[row_index][2]:
                print("Game Over")
                print_maze()
                print(array1[row_index][0]," wins!")
                exit()

    # checks the win cond in all cols
    for col_index in range(3):
        if array1[0][col_index] == "x" or array1[0][col_index] == "o":
            if array1[0][col_index] == array1[1][col_index] == array1[2][col_index]:
                print("Game Over")
                print_maze()
                print(array1[0][col_index]," wins!")
                exit()

    # checks the win cond in both diagonals
    p = 0
    if array1[p][p] == "x" or array1[p][p] == "o":
        if array1[p][p] == array1[p + 1][p + 1] == array1[p + 2][p + 2]:
            print("Game Over")
            print_maze()
            print(array1[p][p]," wins!")
            exit()  

    m, n = 0, 2
    if array1[m][n] == "x" or array1[m][n] == "o":
        if array1[m][n] == array1[m + 1][n - 1] == array1[m + 2][n - 2]:
            print("Game Over")
            print_maze()
            print(array1[m][n]," wins!")
            exit()  


user_shape = str(input("\nEnter ur char: "))
comp_shape = shapes[shapes.index(user_shape) - 1]

if comp_shape == "o":
    comp_move()
else:
    user_move()