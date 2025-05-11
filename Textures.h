#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <vector>    // for std::vector
#include <iostream>  // for std::cerr

inline std::unordered_map<std::string, sf::Texture> pieceTextures;

inline void loadPieceTextures() {
    std::vector<std::string> pieces = {
        "BN", "BB", "BQ", "BR", "BK", "BP",
        "WN", "WB", "WQ", "WR", "WK", "WP",
    };

    for (const auto& piece : pieces) {
        sf::Texture texture;
        if (texture.loadFromFile("assets/" + piece + ".png")) {
            pieceTextures[piece] = texture;
        }
        else {
            std::cerr << piece << ".png is missing its texture file.\n";
        }
    }
}