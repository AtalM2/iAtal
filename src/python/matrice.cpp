#include "matrice.h"

//constructeur
//construit une matrice de 3 cases
Matrix::Matrix(){
  x_robot = 0;
  y_robot = 0;
  orientation = std::pair<int,int>(0,1);

  std::map<std::string,std::string> mymap;
  mymap.insert(std::pair<std::string, std::string>("type","herbe"));

  std::vector<std::map<std::string,std::string> > v;
  //trois cases
  v.push_back(mymap);
  v.push_back(mymap);
  v.push_back(mymap);

  mat.push_back(v);
}

Matrix::~Matrix(){}

//retourne le type de la case EN FACE du robot sous forme de string
std::string Matrix::getElement() const{

  int xdiff = orientation.first;
  int ydiff = orientation.second;
  std::pair<int,int> askedCase (x_robot + xdiff,y_robot + ydiff);

  if (askedCase.first >= mat.size() || askedCase.second >= mat[askedCase.first].size())
    {
      return "void";
    }
  else
    {
      std::map<std::string,std::string> mymap = mat[x_robot + xdiff][y_robot + ydiff];
      return mymap["type"];
    }
}

//fait avancer le robot d'une case dans la direction dans laquelle il regarde
void Matrix::avance(){
  int xdiff = orientation.first;
  int ydiff = orientation.second;
  x_robot += xdiff;
  y_robot += ydiff;
}

//fait tourner le robot sur lui même sur la gauche
void Matrix::turnLeft(){
  if (orientation.first == 0 && orientation.second == 1)
    {
      orientation.first = 1;
      orientation.second = 0;
    }
  else if (orientation.first == 1 && orientation.second == 0)
    {
      orientation.first = 0;
      orientation.second = -1;
    }
  else if (orientation.first == 0 && orientation.second == -1)
    {
      orientation.first = -1;
      orientation.second = 0;
    }
  else
    {
      orientation.first = 0;
      orientation.second = 1;
    }

}
