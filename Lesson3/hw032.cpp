#include <iostream>
#include <vector>
#include <memory>


class Sensor
{
    private:
        std::shared_ptr<std::vector<int>> indication;

    public:
        Sensor() : indication(std::make_shared<std::vector<int>>()) {}

        Sensor(std::shared_ptr<std::vector<int>> data) : indication(data) {}

        void addIndication(int value)
        {
            indication->push_back(value);
        }

        void printIndication() const
        {
            for (int val : *indication)
            {
            std::cout << val << " ";
            }
            std::cout << std::endl;
        }
};


int main()
{    
    std::shared_ptr<std::vector<int>> vectorIndication = std::make_shared<std::vector<int>>();

    Sensor sensor1(vectorIndication);
    Sensor sensor2(vectorIndication);

    sensor1.addIndication(10);
    sensor1.addIndication(20);

    sensor2.addIndication(30);
    sensor2.addIndication(40);

    std::cout << "Sensor1 readings: ";
    sensor1.printIndication();

    std::cout << "Sensor2 readings: ";
    sensor2.printIndication();

    return 0;
}
