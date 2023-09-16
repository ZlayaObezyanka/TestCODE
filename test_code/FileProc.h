#pragma once


struct FileList
{
    std::string nameObj;
    std::string typeObj;
    float x;
    float y;
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
        openFile();
        for (const auto& i : f_vec)
        {
            std::cout << i.nameObj << ' ' << i.x << ' ' << i.y << ' ' << i.typeObj << ' ' << i.timeOfCreation << '\n';
        }
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
        
        out.close();
    }

    void groupByName()
    {
        openFile();
        std::sort(f_vec.begin(), f_vec.end(), 
            [](const FileList &fl1, const FileList &fl2)
            {
                return fl1.nameObj < fl2.nameObj;
            }
        );
        std::ofstream save;
        save.open("Name.txt");

        if (save.is_open())
        {
            for (const auto& i : f_vec)
            {
                save << i.nameObj << ' ' << i.x << ' ' << i.y << ' ' << i.typeObj << ' ' << i.timeOfCreation << '\n';
            }
        }
        readFile("Name.txt");
        save.close();
        f_vec.clear();
    }

    void groupByTime()
    {
        openFile();
        std::sort(f_vec.begin(), f_vec.end(),
            [](const FileList& fl1, const FileList& fl2)
            {
                return fl1.timeOfCreation< fl2.timeOfCreation;
            }
        );

        std::ofstream save;
        save.open("Time.txt");

        if (save.is_open())
        {
            for (const auto& i : f_vec)
            {
                save << i.nameObj << ' ' << i.x << ' ' << i.y << ' ' << i.typeObj << ' ' << i.timeOfCreation << '\n';
            }
        }

        readFile("Time.txt");
        save.close();
        f_vec.clear();
    }

    void groupBy_Type()
    {
        openFile();
         std::sort(f_vec.begin(), f_vec.end(),
            [](const FileList& fl1, const FileList& fl2)
            {
                return fl1.typeObj < fl2.typeObj;
            }
        );
        std::ofstream save;
        save.open("Type.txt");

        if (save.is_open())
        {
            for (const auto& i : f_vec)
            {
                save << i.nameObj << ' ' << i.x << ' ' << i.y<< ' ' << i.typeObj<< ' ' << i.timeOfCreation<< '\n';
            }
        }

        readFile("Type.txt");
        save.close();
        f_vec.clear();
    }

private:
    FileList fp;
    std::vector <FileList> f_vec;

    inline void openFile()
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
        in.close();
    }

};


