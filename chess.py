# Simple Chess Game (Text-Based)
# Pieces: ♜ ♞ ♝ ♛ ♚ ♟ / ♖ ♘ ♗ ♕ ♔ ♙

def initialize_board():
    # Create an 8x8 chess board with initial positions
    board = [
        ['♜', '♞', '♝', '♛', '♚', '♝', '♞', '♜'],
        ['♟', '♟', '♟', '♟', '♟', '♟', '♟', '♟'],
        [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
        [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
        [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
        [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '],
        ['♙', '♙', '♙', '♙', '♙', '♙', '♙', '♙'],
        ['♖', '♘', '♗', '♕', '♔', '♗', '♘', '♖']
    ]
    return board

def print_board(board):
    print("  a b c d e f g h")
    print(" +-----------------+")
    for row in range(8):
        print(f"{8 - row}|", end="")
        for col in range(8):
            print(f"{board[row][col]} ", end="")
        print(f"|{8 - row}")
    print(" +-----------------+")
    print("  a b c d e f g h")

def is_valid_move(board, start, end, player):
    # Convert input like "a2" to (row, col)
    start_row = 8 - int(start[1])
    start_col = ord(start[0]) - ord('a')
    end_row = 8 - int(end[1])
    end_col = ord(end[0]) - ord('a')

    # Basic checks
    if board[start_row][start_col] == ' ':
        return False  # No piece at start
    if (player == "white" and board[start_row][start_col].isupper()) or \
       (player == "black" and board[start_row][start_col].islower()):
        return False  # Wrong color piece

    # Simplified movement rules (just basic direction checks)
    piece = board[start_row][start_col].lower()
    if piece == '♟':  # Pawn (simplified)
        direction = -1 if player == "white" else 1
        if start_col == end_col and end_row == start_row + direction:
            return board[end_row][end_col] == ' '
    # Add more piece rules here (rook, knight, etc.)

    return True  # Simplified validation for now

def play_chess():
    board = initialize_board()
    current_player = "white"
    
    while True:
        print_board(board)
        print(f"{current_player}'s turn")
        start = input("Enter start position (e.g., a2): ").strip().lower()
        end = input("Enter end position (e.g., a3): ").strip().lower()
        
        if is_valid_move(board, start, end, current_player):
            # Move the piece
            start_row = 8 - int(start[1])
            start_col = ord(start[0]) - ord('a')
            end_row = 8 - int(end[1])
            end_col = ord(end[0]) - ord('a')
            
            board[end_row][end_col] = board[start_row][start_col]
            board[start_row][start_col] = ' '
            current_player = "black" if current_player == "white" else "white"
        else:
            print("Invalid move! Try again.")

if __name__ == "__main__":
    play_chess()