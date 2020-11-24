#pragma once

#include <fstream>
#include <sstream>
#include <string>

#include "Location.h"

using std::getline;
using std::ifstream;
using std::stringstream;
using std::string;


class PizzaZine {
private:
  // dynamic array allocate it in the constructor
    Location* pizzaLocations;
    size_t size;

public:
    //default constructor
    PizzaZine(const size_t& = 50);
    //constructor

    //destructor
    ~PizzaZine();

    Location& operator[](size_t);

    // This function is implemented for you
    void readInFile(const string&);
};

PizzaZine::PizzaZine(const size_t& actSize)
{
  size = actSize;
  pizzaLocations = new Location[size];
}

PizzaZine::~PizzaZine(){
  delete [] pizzaLocations;
}

Location& PizzaZine::operator[](size_t index) {
  //doesnt go outside the bounds
    return pizzaLocations[index];

}

void PizzaZine::readInFile(const string& filename) {
    ifstream inFile(filename);
    Location newLoc;

    string line;
    string cell;

    // Read each line
    for (int i = 0; i < size; ++i) {
        // Break each line up into 'cells'
        getline(inFile, line);
        stringstream lineStream(line);
        while(getline(lineStream, newLoc.name, ',')) {
            getline(lineStream, newLoc.address, ',');
            getline(lineStream, newLoc.city, ',');
            getline(lineStream, cell, ',');
            if (!cell.empty()) {
                newLoc.postalCode = stoul(cell);
            }

            getline(lineStream, newLoc.province, ',');
            getline(lineStream, cell, ',');
            newLoc.latitude = stod(cell);
            getline(lineStream, cell, ',');
            newLoc.longitude = stod(cell);

            newLoc.priceRangeMin = -1;
            getline(lineStream, cell, ',');
            if (!cell.empty()) {
                newLoc.priceRangeMin = stoul(cell);
            }

            newLoc.priceRangeMax = -1;
            getline(lineStream, cell, ',');
            if (!cell.empty() && cell != "\r") {
                newLoc.priceRangeMax = stoul(cell);
            }
            pizzaLocations[i] = newLoc;
        }
    }
}
