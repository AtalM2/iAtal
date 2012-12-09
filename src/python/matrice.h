#include <vector>
#include <string>
#include <map>

class Matrix {
 private:
  std::vector<std::vector<std::map<std::string,std::string> > > mat;
  int x_robot;
  int y_robot;
  std::pair<int,int> orientation;

 public:
  Matrix();
  ~Matrix();
	
  std::string getElement() const;
  void avance();
  void turnLeft();
};
