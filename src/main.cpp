#include "CStorageSystem.hpp"
#include "CGrid.hpp"
#include "CPVPanel.hpp"
#include "CHouse.hpp"
#include "CEnergyContext.hpp"
#include <thread>
#include <chrono>
#include <random>

int main() {
    auto storage = std::make_shared<CStorageSystem>("configA.json");
    storage->initializeStorageSystem();
    auto grid = std::make_shared<CGrid>();
    auto panel = std::make_shared<CPVPanel>();
    auto house = std::make_shared<CHouse>();
    auto context = std::make_shared<CEnergyContext>(storage, grid);
    panel->registerObserver(context);
    house->registerObserver(context);

    // for testing 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> pow(3500.0, 4800.0);
    std::uniform_real_distribution<> temp(60.0, 70.0);

    while(true) {
        // read measurements from sensors every 5 sec
        panel->updateMeasurements(pow(gen),230.0,15.0);
        house->updateMeasurements(pow(gen),230.0,16.0,60.0);
        context->setBatteryTemperature(temp(gen));
        std::cout << "----------------------------------------" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    return 0;
}
