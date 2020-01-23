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

#include "MyVehicle.h"

using namespace veins;
Define_Module(veins::MyVehicle);

void MyVehicle::initialize(int stage){
    DemoBaseApplLayer::initialize(stage);
    if (stage == 0) {
        currentSubscribedServiceId = -1;
        sendPeriod = 0.5;
        wsmSendEvt = new cMessage("wsm send task", 77); //77 is an arbitrary number
    }
    else if (stage == 1){
            scheduleAt(simTime()+sendPeriod, wsmSendEvt);
    }
}

void MyVehicle::onWSA(DemoServiceAdvertisment* wsa){
    if(currentSubscribedServiceId == -1){
        currentSubscribedServiceId = wsa->getPsid();
        std::cout << "channel set\n";
    }
}

void MyVehicle::onWSM(BaseFrame1609_4* frame){
}

void MyVehicle::handleSelfMsg(cMessage* msg){
    if (msg->getKind() == 77){ // same 77 as in initialize()
        NumVehicleMsg* nvm = new NumVehicleMsg();
        nvm->setSenderAddress(myId);
        nvm->setSenderPos(curPosition);
        nvm->setTimeStampP(simTime());
        nvm->setChannelNumber(static_cast<int>(Channel::cch));
        sendDown(nvm->dup());
        delete nvm;
        scheduleAt(simTime() + sendPeriod, wsmSendEvt);
    }
    else
        DemoBaseApplLayer::handleSelfMsg(msg);
}

