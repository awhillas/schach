#include <string>


class Square
{
  private:
    int col;
    int row;

  public:
    Square(int x, int y) : col(x), row(y){}

    string to_algebraic() {
      
    }

    string to_string() {
      return this.to_algebraic();
    }
};