//
//  utility.hpp
//  chessEngine
//
//  Created by Sebastian Fabian Echeandia Reynes on 24/03/23.
//  Copyright © 2023 me. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include "guiBoard.hpp"

bool renderPieces(sf::RenderWindow & window,
				std::vector<gui::chessPiece> const & whitePieces,
				std::vector<gui::chessPiece> const & blackPieces,
				gui::chessBoard const & chessBoard);

#endif /* utility_hpp */
