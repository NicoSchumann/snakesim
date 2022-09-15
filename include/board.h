#include <vector>

enum class Ground { kEmpty, kObstacle, kFruit };

class Board
{
public:
    Board( size_t width, size_t height);
    Board();
    ~Board() = default;

    Ground& at(size_t x, size_t y);

private:
    size_t _widht;
    size_t _height;
    std::vector<Ground> _board;

};