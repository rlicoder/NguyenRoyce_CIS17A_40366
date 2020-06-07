Beta v0.0

 General remarks:
 The purpose of this build is to simply encapsulate the base bones for displaying the board.
 I also just kept the basic functions outside the scope of a class to get practice passing class members.
 I will probably try to encapsulate them later.



Added
+Base class Piece. May make abstract later. The plan right now is to have this base class contain the most basic piece attributes:
 position, color, capture, etc. Will try and make an array of base classes for easy passing to functions.
 
+Derived classes: pawn, knight, bishop, etc. The plan is to have these pieces carry their own unique attributes.
 Each piece will have a "issupported" to tell whether or not it will be defended by another piece of the same color.
 Pawns and Kings are unique in movement (castling, enpassant) but also in gameplay (check, promotion)
 
+Generic functions from the previous non-OOP chess game. 
 These include: piecesearcharray position, checkmovement, checkblock.
 Will integrate later but not sure how yet.
 
 
+tiles class for the board array. Will contain the symbols of the board as well as variables for seeing if a tile is occupied or under attack.
Will implement the update functions later.
 
 

 

 
 