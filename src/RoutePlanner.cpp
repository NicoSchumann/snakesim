#include "RoutePlanner.hpp"


std::vector<sf::Vector2<size_t>> RoutePlanner::calcPath(const Board & board, const sf::Vector2<size_t> & start, const sf::Vector2<size_t> & goal)
{
    // TODO
    _board = std::unique_ptr<const Board>(& board);
    std::vector<sf::Vector2<size_t>> path;

    return path;
}

std::vector<sf::Vector2<size_t>> RoutePlanner::getNeighbors(Node & node)
{
    std::vector<sf::Vector2<size_t>> neighbors;
    neighbors.emplace_back(node.cell.x-1,node.cell.y);
    neighbors.emplace_back(node.cell.x+1,node.cell.y);
    neighbors.emplace_back(node.cell.x,node.cell.y+1);
    neighbors.emplace_back(node.cell.x,node.cell.y-1);

    // the world is a donut
    for(auto & cell : neighbors)
    {
        cell.x %= _board->width(); 
        cell.y %= _board->height();
    }
    return neighbors;

}
