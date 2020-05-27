#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/VPMCheckAlpha.o \
	${OBJECTDIR}/VPMCheckCapture.o \
	${OBJECTDIR}/VPMCheckColor.o \
	${OBJECTDIR}/VPMCheckMovement.o \
	${OBJECTDIR}/VPMCheckNum.o \
	${OBJECTDIR}/VPMCheckPiece.o \
	${OBJECTDIR}/VPMKingMoveSafe.o \
	${OBJECTDIR}/VPMisBlocked.o \
	${OBJECTDIR}/VPMkingNotinCheck.o \
	${OBJECTDIR}/cannotMove.o \
	${OBJECTDIR}/convertAtlasCoordinatesToNumeric.o \
	${OBJECTDIR}/convertNumericToAtlasCoordinates.o \
	${OBJECTDIR}/copyTiles.o \
	${OBJECTDIR}/createMoveList.o \
	${OBJECTDIR}/displayBoard.o \
	${OBJECTDIR}/findSupports.o \
	${OBJECTDIR}/gameEnd.o \
	${OBJECTDIR}/generatePossibleMoves.o \
	${OBJECTDIR}/getPlayerMoveEnd.o \
	${OBJECTDIR}/getPlayerMoveStart.o \
	${OBJECTDIR}/initializeBoardPieces.o \
	${OBJECTDIR}/is50Moves.o \
	${OBJECTDIR}/isCheck.o \
	${OBJECTDIR}/isCheckmate.o \
	${OBJECTDIR}/isInsufficient.o \
	${OBJECTDIR}/isStalemate.o \
	${OBJECTDIR}/isWhite.o \
	${OBJECTDIR}/movePossible.o \
	${OBJECTDIR}/outputData.o \
	${OBJECTDIR}/outputInstructions.o \
	${OBJECTDIR}/outputName.o \
	${OBJECTDIR}/pawnPromotion.o \
	${OBJECTDIR}/pawnUpdate.o \
	${OBJECTDIR}/pieceSearchArrayPosition.o \
	${OBJECTDIR}/printMoveList.o \
	${OBJECTDIR}/readInPieceDataNames.o \
	${OBJECTDIR}/updateMoveList.o \
	${OBJECTDIR}/updateTiles.o \
	${OBJECTDIR}/verifyPlayerMove.o \
	${OBJECTDIR}/verifyPlayerMoveEnd.o \
	${OBJECTDIR}/verifyPlayerMoveStart.o \
	${OBJECTDIR}/welcome.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chess_game.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chess_game.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chess_game ${OBJECTFILES} ${LDLIBSOPTIONS} -static-libgcc -static-libstdc++

${OBJECTDIR}/VPMCheckAlpha.o: VPMCheckAlpha.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VPMCheckAlpha.o VPMCheckAlpha.cpp

${OBJECTDIR}/VPMCheckCapture.o: VPMCheckCapture.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VPMCheckCapture.o VPMCheckCapture.cpp

${OBJECTDIR}/VPMCheckColor.o: VPMCheckColor.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VPMCheckColor.o VPMCheckColor.cpp

${OBJECTDIR}/VPMCheckMovement.o: VPMCheckMovement.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VPMCheckMovement.o VPMCheckMovement.cpp

${OBJECTDIR}/VPMCheckNum.o: VPMCheckNum.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VPMCheckNum.o VPMCheckNum.cpp

${OBJECTDIR}/VPMCheckPiece.o: VPMCheckPiece.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VPMCheckPiece.o VPMCheckPiece.cpp

${OBJECTDIR}/VPMKingMoveSafe.o: VPMKingMoveSafe.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VPMKingMoveSafe.o VPMKingMoveSafe.cpp

${OBJECTDIR}/VPMisBlocked.o: VPMisBlocked.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VPMisBlocked.o VPMisBlocked.cpp

${OBJECTDIR}/VPMkingNotinCheck.o: VPMkingNotinCheck.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VPMkingNotinCheck.o VPMkingNotinCheck.cpp

${OBJECTDIR}/cannotMove.o: cannotMove.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cannotMove.o cannotMove.cpp

${OBJECTDIR}/convertAtlasCoordinatesToNumeric.o: convertAtlasCoordinatesToNumeric.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/convertAtlasCoordinatesToNumeric.o convertAtlasCoordinatesToNumeric.cpp

${OBJECTDIR}/convertNumericToAtlasCoordinates.o: convertNumericToAtlasCoordinates.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/convertNumericToAtlasCoordinates.o convertNumericToAtlasCoordinates.cpp

${OBJECTDIR}/copyTiles.o: copyTiles.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/copyTiles.o copyTiles.cpp

${OBJECTDIR}/createMoveList.o: createMoveList.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/createMoveList.o createMoveList.cpp

${OBJECTDIR}/displayBoard.o: displayBoard.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/displayBoard.o displayBoard.cpp

${OBJECTDIR}/findSupports.o: findSupports.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/findSupports.o findSupports.cpp

${OBJECTDIR}/gameEnd.o: gameEnd.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/gameEnd.o gameEnd.cpp

${OBJECTDIR}/generatePossibleMoves.o: generatePossibleMoves.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/generatePossibleMoves.o generatePossibleMoves.cpp

${OBJECTDIR}/getPlayerMoveEnd.o: getPlayerMoveEnd.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/getPlayerMoveEnd.o getPlayerMoveEnd.cpp

${OBJECTDIR}/getPlayerMoveStart.o: getPlayerMoveStart.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/getPlayerMoveStart.o getPlayerMoveStart.cpp

${OBJECTDIR}/initializeBoardPieces.o: initializeBoardPieces.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/initializeBoardPieces.o initializeBoardPieces.cpp

${OBJECTDIR}/is50Moves.o: is50Moves.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/is50Moves.o is50Moves.cpp

${OBJECTDIR}/isCheck.o: isCheck.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/isCheck.o isCheck.cpp

${OBJECTDIR}/isCheckmate.o: isCheckmate.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/isCheckmate.o isCheckmate.cpp

${OBJECTDIR}/isInsufficient.o: isInsufficient.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/isInsufficient.o isInsufficient.cpp

${OBJECTDIR}/isStalemate.o: isStalemate.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/isStalemate.o isStalemate.cpp

${OBJECTDIR}/isWhite.o: isWhite.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/isWhite.o isWhite.cpp

${OBJECTDIR}/movePossible.o: movePossible.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/movePossible.o movePossible.cpp

${OBJECTDIR}/outputData.o: outputData.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/outputData.o outputData.cpp

${OBJECTDIR}/outputInstructions.o: outputInstructions.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/outputInstructions.o outputInstructions.cpp

${OBJECTDIR}/outputName.o: outputName.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/outputName.o outputName.cpp

${OBJECTDIR}/pawnPromotion.o: pawnPromotion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/pawnPromotion.o pawnPromotion.cpp

${OBJECTDIR}/pawnUpdate.o: pawnUpdate.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/pawnUpdate.o pawnUpdate.cpp

${OBJECTDIR}/pieceSearchArrayPosition.o: pieceSearchArrayPosition.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/pieceSearchArrayPosition.o pieceSearchArrayPosition.cpp

${OBJECTDIR}/printMoveList.o: printMoveList.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/printMoveList.o printMoveList.cpp

${OBJECTDIR}/readInPieceDataNames.o: readInPieceDataNames.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/readInPieceDataNames.o readInPieceDataNames.cpp

${OBJECTDIR}/updateMoveList.o: updateMoveList.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/updateMoveList.o updateMoveList.cpp

${OBJECTDIR}/updateTiles.o: updateTiles.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/updateTiles.o updateTiles.cpp

${OBJECTDIR}/verifyPlayerMove.o: verifyPlayerMove.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/verifyPlayerMove.o verifyPlayerMove.cpp

${OBJECTDIR}/verifyPlayerMoveEnd.o: verifyPlayerMoveEnd.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/verifyPlayerMoveEnd.o verifyPlayerMoveEnd.cpp

${OBJECTDIR}/verifyPlayerMoveStart.o: verifyPlayerMoveStart.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/verifyPlayerMoveStart.o verifyPlayerMoveStart.cpp

${OBJECTDIR}/welcome.o: welcome.cc
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/welcome.o welcome.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
