#pragma once


struct FileList
{
    std::string nameObj;
    float x;
    float y;
    std::string typeObj;
    double timeOfCreation;

    friend std::istream& operator >>(std::istream& in, FileList& fl) {
        in >> fl.nameObj >> fl.x >> fl.y >> fl.typeObj >> fl.timeOfCreation;
        return in;
    }

};

class FileProcessing
{
public:
    void readFile(const std::string &tempStr )
    {
        std::ifstream in;
        in.open("test.txt");
        if (in.is_open())
        {
            while (!in.eof())
            {
                in >> fp;
                f_vec.push_back(fp);
            }
        }

        for (const auto i : f_vec)
        {
            std::cout << i.nameObj << ' ' << i.x << ' ' << i.y << ' ' << i.typeObj << ' ' << i.timeOfCreation << '\n';
        }

        in.close();
    }

    void writeToFile()
    {        
        std::ofstream out;
        out.open("test.txt", std::ios::app);
        std::cout << "Последовательно введите: Имя объекта, координаты X и Y, тип объекта и время создание" << '\n';
        
        std::cin >> fp.nameObj >> fp.x >> fp.y >> fp.typeObj >> fp.timeOfCreation;
        //f_vec.insert(f_vec.begin(), temp);
        out.precision(15);
        out << fp.nameObj << ' ' << fp.x << ' ' << fp.y << ' ' << fp.typeObj << ' ' << fp.timeOfCreation << '\n';

        readFile("test.txt");

        out.close();
    }

private:
    FileList fp;
    std::vector <FileList> f_vec;
};