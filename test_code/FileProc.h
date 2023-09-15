#pragma once
class FileProcessing
{

public:
    void readFile()
    {
        std::string line;
        std::ifstream in("test.txt");

        while (std::getline(in, line))
        {
            std::cout << line << '\n';
        }
        in.close();
    }

    void writeToFile()
    {
        std::ofstream out;

        out.open("test.txt", std::ios::app);
        std::cout << "Последовательно введите: Имя объуекта, координаты X и Y, тип объекта и время создание" << '\n';
        std::cin >> nameObj >> x >> y >> typeObj >> time;

        out.precision(15);
        out << nameObj << ' ' << x << ' ' << y << ' ' << typeObj << ' ' << time << std::endl;

        readFile();

        out.close();
    }

private:
    std::string nameObj;
    float x;
    float y;
    std::string typeObj;
    double time;
    std::list <std::string> fileList;
};