


class Piece
{
public:
    Piece();
    ~Piece();

public:
    enum PieceType {
        I = 0,
        J,
        L,
        O,
        S,
        T,
        Z
    };

    struct Point {
        int x;
        int y;
    };

private:
    PieceType m_type;
    Point m_lowest;
};
