import time

# Initialize board
board = { 1 : ' ', 2 : ' ', 3: ' ',
         4 : ' ', 5 : ' ', 6 : ' ', 
         7 : ' ', 8 : ' ', 9 : ' '}

# Initialize variables
count = 0		# counter to track number of filled slots
winner = False		# boolean to check if anyone won
play = True		# boolen to check if the game should continue
tie = False		# boolean to check if there is a tie
curr_player = ''	# variable to store current player identifier
player_details = []	# list to store player identifier and marker

# Helper functions
def get_player_details(curr_player):
    """Function to get player identifier and marker"""
    if curr_player == 'A':
        return ['B','O']
    else:
        return ['A','X']
    

def print_board():
    """Function to print the board"""
    for i in board:
        print( i, ':', board[i], ' ', end='')
        if i%3 == 0:
            print()


def win_game(marker, player_id):
    """Function to check for winning combination"""
    if board[1] == marker and board[2] == marker and board[3] == marker or \
    board[4] == marker and board[5] == marker and board[6] == marker or \
    board[7] == marker and board[8] == marker and board[9] == marker or \
    board[1] == marker and board[4] == marker and board[7] == marker or \
    board[2] == marker and board[5] == marker and board[8] == marker or \
    board[3] == marker and board[6] == marker and board[9] == marker or \
    board[1] == marker and board[5] == marker and board[9] == marker or \
    board[3] == marker and board[5] == marker and board[7] == marker:

        print_board()
        time.sleep(1)
        print("Player", player_id, "wins!")
        return True

    else:
        return False


def insert_input(slot_num, marker):
    """Function for capturing user inputs"""
    while board[slot_num] != ' ':
        print("spot taken, pick another no.")
        slot_num = int(input())
    board[slot_num] = marker

def play_again():
    """Function to check if player wants to play again"""
    print("Do you want to play again?")
    play_again = input()

    if play_again.upper() == 'Y':
        for z in board:
            board[z] = ' '
        return True
    else:
        print("Thanks for playing. See you next time!")
        return False
    
# Main program
while play:

    print_board()

    player_details = get_player_details(curr_player)
    curr_player = player_details[0]
    print("Player {}: Enter a number between 1 and 9".format(curr_player))
    input_slot = int(input())

    #Inserting 'X' or 'O' in desired spot
    insert_input(input_slot, player_details[1])
    count += 1
    
    # Check if anybody won
    winner = win_game(player_details[1], curr_player)
    if count == 9 and not winner:
        print("It's a tie!!")
        tie = True
        print_board()

    # Check if players want to play again
    if winner or tie:
        play = play_again()
        if play:
            curr_player = ''
            count = 0