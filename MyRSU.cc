//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "MyRSU.h"
#include "NumVehicleMsg_m.h"

using namespace veins;
Define_Module(veins::MyRSU);

void MyRSU::initialize(int stage){
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
            currentOfferedServiceId = 17; // whatever number you'd like
    }
    else if (stage == 1){
            startService(Channel::sch2, currentOfferedServiceId, "NumVehicle Service");
    }
}

void MyRSU::onWSM(BaseFrame1609_4* frame){
    if (NumVehicleMsg* wsm = check_and_cast<NumVehicleMsg*>(frame)){
        // check_and_cast will return NULL if frame is not in type NumVehicleMsg
        Coord senderPos = wsm->getSenderPos();
        double distance = (senderPos - curPosition).length();
        std::cout << "CarId: " << wsm->getSenderAddress() << " Distance: " << distance << "\n";
    }
}
