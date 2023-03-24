//
//  guiBoard.cpp
//  chessEngine
//
//  Created by Sebastian Fabian Echeandia Reynes on 23/03/23.
//

#include "guiBoard.hpp"

gui::chessPiece::chessPiece(std::pair<int, int> position, gui::pieceType pieceType)
{
    _position = position;
    _pieceType = pieceType;
    _previousPosition = position;
    _hasMoved = false;
    _exists = true;
}

bool gui::setupBoard(std::vector<gui::chessPiece> & whitePieces,
                std::vector<gui::chessPiece> & blackPieces,
                gui::chessBoard & chessBoard)
{
    std::vector<std::string> whitePiecesFileNames {"assets/whitePawn.png",
        "assets/whiteRook.png",
        "assets/whiteKnight.png",
        "assets/whiteBishop.png",
        "assets/whiteQueen.png",
        "assets/whiteKing.png"};
    std::vector<std::string> blackPiecesFileNames {"assets/blackPawn.png",
        "assets/blackRook.png",
        "assets/blackKnight.png",
        "assets/blackBishop.png",
        "assets/blackQueen.png",
        "assets/blackKing.png"};
    sf::Texture whitePiecesTextures[6];
    sf::Texture blackPiecesTextures[6];
    
    for (int i = 0; i < whitePiecesFileNames.size(); i++)
    {
        whitePiecesTextures[i].loadFromFile(whitePiecesFileNames[i]);
        blackPiecesTextures[i].loadFromFile(blackPiecesFileNames[i]);
    }
    
    sf::FloatRect pieceRect;
    for(int i = 1; i < 9; i++)
    {
        gui::chessPiece whitePawn(std::make_pair(2,i), gui::pieceType::pawn);
        whitePawn.texture = whitePiecesTextures[0];
		whitePawn.sprite.setTexture(whitePawn.texture);
		pieceRect = whitePawn.sprite.getLocalBounds();
		whitePawn.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		whitePieces.push_back(whitePawn);
		
        gui::chessPiece blackPawn(std::make_pair(2,i), gui::pieceType::pawn);
        blackPawn.texture = blackPiecesTextures[0];
		blackPawn.sprite.setTexture(blackPawn.texture);
		pieceRect = blackPawn.sprite.getLocalBounds();
		blackPawn.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		blackPieces.push_back(blackPawn);
    }
    
	for(int i = 0; i < 1; i++)
    {
        gui::chessPiece whiteRook(std::make_pair(1,1+i*8), gui::pieceType::rook);
		whiteRook.texture = whitePiecesTextures[1];
		whiteRook.sprite.setTexture(whiteRook.texture);
		pieceRect = whiteRook.sprite.getLocalBounds();
		whiteRook.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		whitePieces.push_back(whiteRook);
		
		gui::chessPiece blackRook(std::make_pair(8,1+i*8), gui::pieceType::rook);
		blackRook.texture = blackPiecesTextures[1];
		blackRook.sprite.setTexture(blackRook.texture);
		pieceRect = blackRook.sprite.getLocalBounds();
		blackRook.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		blackPieces.push_back(blackRook);
		
		gui::chessPiece whiteKnight(std::make_pair(1,2+i*7), gui::pieceType::knight);
		whiteKnight.texture = whitePiecesTextures[2];
		whiteKnight.sprite.setTexture(whiteKnight.texture);
		pieceRect = whiteKnight.sprite.getLocalBounds();
		whiteKnight.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		whitePieces.push_back(whiteKnight);
		
		gui::chessPiece blackKnight(std::make_pair(8,2+i*7), gui::pieceType::rook);
		blackKnight.texture = blackPiecesTextures[1];
		blackKnight.sprite.setTexture(blackKnight.texture);
		pieceRect = blackKnight.sprite.getLocalBounds();
		blackKnight.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		blackPieces.push_back(blackKnight);
		
		gui::chessPiece whiteBishop(std::make_pair(1,3+i*6), gui::pieceType::bishop);
		whiteBishop.texture = whitePiecesTextures[3];
		whiteBishop.sprite.setTexture(whiteBishop.texture);
		pieceRect = whiteBishop.sprite.getLocalBounds();
		whiteBishop.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		whitePieces.push_back(whiteBishop);
		
		gui::chessPiece blackBishop(std::make_pair(8,3+i*6), gui::pieceType::bishop);
		blackBishop.texture = blackPiecesTextures[3];
		blackBishop.sprite.setTexture(blackBishop.texture);
		pieceRect = blackBishop.sprite.getLocalBounds();
		blackBishop.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		blackPieces.push_back(blackBishop);
    }
    
    gui::chessPiece whiteQueen(std::make_pair(1,4), gui::pieceType::queen);
    whiteQueen.texture = whitePiecesTextures[4];
	whiteQueen.sprite.setTexture(whiteQueen.texture);
	pieceRect = whiteQueen.sprite.getLocalBounds();
	whiteQueen.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
	whitePieces.push_back(whiteQueen);
	
	gui::chessPiece whiteKing(std::make_pair(1,5), gui::pieceType::king);
	whiteKing.texture = whitePiecesTextures[5];
	whiteKing.sprite.setTexture(whiteKing.texture);
	pieceRect = whiteKing.sprite.getLocalBounds();
	whiteKing.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
	whitePieces.push_back(whiteKing);
	
	gui::chessPiece blackQueen(std::make_pair(1,4), gui::pieceType::queen);
	blackQueen.texture = blackPiecesTextures[4];
	blackQueen.sprite.setTexture(blackQueen.texture);
	pieceRect = blackQueen.sprite.getLocalBounds();
	blackQueen.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
	whitePieces.push_back(blackQueen);
	
	gui::chessPiece blackKing(std::make_pair(1,5), gui::pieceType::king);
	blackKing.texture = blackPiecesTextures[5];
	blackKing.sprite.setTexture(blackKing.texture);
	pieceRect = blackKing.sprite.getLocalBounds();
	blackKing.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
	whitePieces.push_back(blackKing);
	
	chessBoard.texture.loadFromFile("assets/board.jpeg");
	chessBoard.sprite.setTexture(chessBoard.texture);
	chessBoard.sprite.setPosition(0, 0);
	chessBoard.sprite.setScale(1.69, 1.69);
	
	return true;
    
}
