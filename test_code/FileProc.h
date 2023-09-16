#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

struct FileList
{
    std::string nameObj;
    std::string typeObj;
    float x;
    float y;
    double timeOfCreation{ 0.0 };
   
    friend std::istream& operator >>(std::istream& in, FileList& fl) {
        in >> fl.nameObj >> fl.x >> fl.y >> fl.typeObj >> fl.timeOfCreation;
        return in;
    }
};


class FileProcessing
{
public:
    void readFile(const std::string& tempStr);
    void writeToFile();
    void groupByName();
    void groupByTime();
    void groupBy_Type();
    
private:
    FileList fp;
    std::vector <FileList> f_vec;

    void openFile();
};


