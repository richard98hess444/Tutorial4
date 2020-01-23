//
// Generated file, do not edit! Created by nedtool 5.5 from NumVehicleMsg.msg.
//

#ifndef __VEINS_NUMVEHICLEMSG_M_H
#define __VEINS_NUMVEHICLEMSG_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0505
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// cplusplus {{
#include "veins/base/utils/Coord.h"
#include "veins/modules/messages/BaseFrame1609_4_m.h"
#include "veins/base/utils/SimpleAddress.h"
// }}


namespace veins {

/**
 * Class generated from <tt>NumVehicleMsg.msg:28</tt> by nedtool.
 * <pre>
 * packet NumVehicleMsg extends BaseFrame1609_4
 * {
 *     Coord senderPos;
 *     int numVehicles;
 *     simtime_t timeStampP;
 *     LAddress::L2Type senderAddress = -1;
 * }
 * </pre>
 */
class NumVehicleMsg : public ::veins::BaseFrame1609_4
{
  protected:
    Coord senderPos;
    int numVehicles;
    ::omnetpp::simtime_t timeStampP;
    LAddress::L2Type senderAddress;

  private:
    void copy(const NumVehicleMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const NumVehicleMsg&);

  public:
    NumVehicleMsg(const char *name=nullptr, short kind=0);
    NumVehicleMsg(const NumVehicleMsg& other);
    virtual ~NumVehicleMsg();
    NumVehicleMsg& operator=(const NumVehicleMsg& other);
    virtual NumVehicleMsg *dup() const override {return new NumVehicleMsg(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual Coord& getSenderPos();
    virtual const Coord& getSenderPos() const {return const_cast<NumVehicleMsg*>(this)->getSenderPos();}
    virtual void setSenderPos(const Coord& senderPos);
    virtual int getNumVehicles() const;
    virtual void setNumVehicles(int numVehicles);
    virtual ::omnetpp::simtime_t getTimeStampP() const;
    virtual void setTimeStampP(::omnetpp::simtime_t timeStampP);
    virtual LAddress::L2Type& getSenderAddress();
    virtual const LAddress::L2Type& getSenderAddress() const {return const_cast<NumVehicleMsg*>(this)->getSenderAddress();}
    virtual void setSenderAddress(const LAddress::L2Type& senderAddress);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const NumVehicleMsg& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, NumVehicleMsg& obj) {obj.parsimUnpack(b);}

} // namespace veins

#endif // ifndef __VEINS_NUMVEHICLEMSG_M_H
