#ifndef ROUTE_PLANNER_HPP
#define ROUTE_PLANNER_HPP

#include "Board.hpp"
#include <vector>

struct Node
{
    Node *prev;
    Point point; 
};

class RoutePlanner
{
public:
    std::vector<Point> calcPath( const Board & board, const Point & start, const Point & goal);

private:
    std::vector<Node> _openList;
    Node *_startNode;
    Node *_endNode;
};


#endif