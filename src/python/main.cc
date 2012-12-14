// -*- c-basic-offset: 2; -*-
#include <Python.h>
#include <boost/python.hpp>
#include <vector>
#include <string>
#include <map>
#include "matrice.h"
#include "model/map.h"

int main(int argc, char **argv)
{
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file.py>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  Py_Initialize();

  try
    {

      boost::python::object main = boost::python::import("__main__"); 
      boost::python::object py_ = main.attr("__dict__"); 
  
      exec_file(argv[1], py_, py_);
     
      //Joseph for memory
      // boost::python::object func = py_["func"];
      //int a=1, b=2;
      //py_["a"] = boost::python::object(a);
      //py_["b"] = object(b);
      	
      //boost::python::object result = func(a);

      //std::string val = boost::python::extract<std::string>(result);
      //std::cout << "iAtal dit : " << val << std::endl; 
      
      boost::python::object strat = py_["strat"];
      boost::python::object isEnded = py_["isEnded"];

      //Model creation. Robot in 0,0 , facing north
      Model *aModel = new Model(0,0,std::pair<int,int>(0,1), 3, 3, 15,15);

      Matrix mat = Matrix();

      boost::python::object endTestRes = isEnded();
      bool endTest = boost::python::extract<bool>(endTestRes);
      std::cout << endTest << std::endl;

      while (!endTest){
	  //getElement regarde la case devant le robot et renvoie son
	  //type

	boost::shared_ptr<Model> aModel;
        strat(boost::python::ptr(o.get()));

	/*
	std::string a = mat.getElement();
	
	
	py_["case_avant"] = boost::python::object(a);
	boost::python::object res = strat(a);
	
	std::string result = boost::python::extract<std::string>(res);
	//std::cout << "result = " << result << std::endl;
	
	  if (result == "avance")
	    {
	      mat.avance();
	      std::cout << "avance" << std::endl;
	    }
	  else
	    {
	      mat.turnLeft();
	      std::cout << "tourne" << std::endl;
	    }
	*/

	  endTestRes = isEnded();
	  endTest = boost::python::extract<bool>(endTestRes);
	  

	}
    }
  catch (boost::python::error_already_set)
    {
      PyErr_Print();
    }

  Py_Finalize();

  return 0;
}

