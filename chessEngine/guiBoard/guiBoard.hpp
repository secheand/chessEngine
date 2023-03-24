//
//  guiBoard.hpp
//  chessEngine
//
//  Created by Sebastian Fabian Echeandia Reynes on 23/03/23.
//

#ifndef guiBoard_hpp
#define guiBoard_hpp

#include <utility>
#include <string>

#include <SFML/Graphics.hpp>

namespace gui {
    enum pieceType {
        pawn,
        rook,
        knight,
        bishop,
        queen,
        king
    };

    class chessPiece {
        
    public:
        chessPiece(std::pair<int, int> position,
                       gui::pieceType pieceType,
                       std::pair<int, int> previousPosition);
        sf::Sprite sprite;
        std::pair<int, int> getPosition();
        void updatePosition(std::pair<int, int>);
        gui::pieceType getPieceType();
        std::pair<int, int> getPreviousPosition;
        
        
    private:
        std::pair<int, int> position;
        gui::pieceType pieceType;
        std::pair<int, int> previousPosition;
        
    };

}

#endif /* guiBoard_hpp */
