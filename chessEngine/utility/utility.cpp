//
//  utility.cpp
//  chessEngine
//
//  Created by Sebastian Fabian Echeandia Reynes on 24/03/23.
//  Copyright © 2023 me. All rights reserved.
//

#include "utility.hpp"

bool renderPieces(sf::RenderWindow & window,
				std::vector<gui::chessPiece> const & whitePieces,
				std::vector<gui::chessPiece> const & blackPieces,
				gui::chessBoard const & chessBoard)
{
	window.draw(chessBoard.sprite);
	
	for(int i = 0; i < whitePieces.size(); i++)
	{
		//window.draw(whitePieces[i].sprite);
	}
	for(int i = 0; i < blackPieces.size(); i++)
	{
		//window.draw(blackPieces[i].sprite);
	}
	
}
