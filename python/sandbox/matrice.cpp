#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <boost/python.hpp>
#include <Python.h>

using namespace std;

class Matrix {
	private:
	vector<vector<map<string,string> > > mat;
	int x_robot;
	int y_robot;

	public:
	Matrix();
	~Matrix();
	
	string getElement() const;
};



Matrix::Matrix(){
	x_robot = 0;
	y_robot = 0;

	map<string,string> mymap;
	mymap.insert(pair<string, string>("type","herbe"));

	vector<map<string,string> > v;
	v.push_back(mymap);

	mat.push_back(v);
}

Matrix::~Matrix(){}

string Matrix::getElement() const {
	map<string,string> mymap = mat[x_robot][y_robot];
	return mymap["type"];
//	return "YOUPI";
}



BOOST_PYTHON_MODULE(elements) {
boost::python::class_<Matrix>("Matrix")
.def("getElement" , &Matrix::getElement);
}
