BETA v1.0

General Remarks: main.cpp mostly remains unchanged. lots of internal changes to classes.
The next move is to start encapsulating move verification functions inside of the player class.

Added

+Player class for storing player name and player move.

+Game class for storing the current player turn and the current state of the game (stalemate, checkmate, no winner, etc)

+Vectors for storing the piece and players.

+class movement has been encapsulated and now exhibits polymorphism.
Big issue with acessing derived class members now because of base class pointers. will work on later in future revision

