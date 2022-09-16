#ifndef ROUTE_PLANNER_HPP
#define ROUTE_PLANNER_HPP

#include "Board.hpp"
#include <vector>
#include <memory>

struct Node
{
    Node *prev;
    sf::Vector2<size_t> cell;
    bool visited {false};
};

class RoutePlanner
{
public:
    std::vector<sf::Vector2<size_t>> calcPath( const Board & board, const sf::Vector2<size_t> & start, const sf::Vector2<size_t> & goal);

private:
    inline size_t calcHVal(const sf::Vector2<size_t> & a, const sf::Vector2<size_t> & b) const;
    std::vector<sf::Vector2<size_t>> getNeighbors(Node & node);
    std::vector<Node> _openList;
    Node *_startNode;
    Node *_endNode;

    std::unique_ptr<const Board> _board;
};

// inline methods
size_t calcHVal( const sf::Vector2<size_t> & a, const sf::Vector2<size_t> & b)
{
    return ( a.x>=b.x ? a.x-b.x : b.x-a.x )
         + ( a.y>=b.y ? a.y-b.y : b.y-a.y ); 
}


#endif