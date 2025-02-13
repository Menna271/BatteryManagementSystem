#include "CStorageSystem.hpp"
#include "CGrid.hpp"
#include "CPVPanel.hpp"
#include "CHouse.hpp"
#include "CEnergyContext.hpp"
#include <thread>
#include <chrono>

int main() {
    auto storage = std::make_shared<CStorageSystem>("configA.json");
    auto grid = std::make_shared<CGrid>();
    auto panel = std::make_shared<CPVPanel>();
    auto house = std::make_shared<CHouse>();
    auto context = std::make_shared<CEnergyContext>(storage, grid);
    storage->initializeStorageSystem(context);
    panel->registerObserver(context);
    house->registerObserver(context);

    while(true) {
        panel->updateMeasurements(3500.0,230.0,15.0);
        house->updateMeasurements(4000.0,230.0,16.0,60.0);
        std::this_thread::sleep_for(std::chrono::seconds(5));

        panel->updateMeasurements(4000.0,230.0,15.0);
        house->updateMeasurements(3500.0,230.0,16.0,60.0);
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    return 0;
}
