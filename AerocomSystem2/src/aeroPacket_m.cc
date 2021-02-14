//
// Generated file, do not edit! Created by nedtool 5.4 from aeroPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "aeroPacket_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(AeroPacket)

AeroPacket::AeroPacket(const char *name, short kind) : ::omnetpp::cMessage(name,kind)
{
    this->sender = 0;
    this->generationTime = 0;
    this->queueLeavingTime = 0;
    this->ifaceLeavingTime = 0;
    this->controlTowerArrivalTime = 0;
    this->packetLength = 0;
}

AeroPacket::AeroPacket(const AeroPacket& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

AeroPacket::~AeroPacket()
{
}

AeroPacket& AeroPacket::operator=(const AeroPacket& other)
{
    if (this==&other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void AeroPacket::copy(const AeroPacket& other)
{
    this->sender = other.sender;
    this->generationTime = other.generationTime;
    this->queueLeavingTime = other.queueLeavingTime;
    this->ifaceLeavingTime = other.ifaceLeavingTime;
    this->controlTowerArrivalTime = other.controlTowerArrivalTime;
    this->packetLength = other.packetLength;
}

void AeroPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->sender);
    doParsimPacking(b,this->generationTime);
    doParsimPacking(b,this->queueLeavingTime);
    doParsimPacking(b,this->ifaceLeavingTime);
    doParsimPacking(b,this->controlTowerArrivalTime);
    doParsimPacking(b,this->packetLength);
}

void AeroPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->sender);
    doParsimUnpacking(b,this->generationTime);
    doParsimUnpacking(b,this->queueLeavingTime);
    doParsimUnpacking(b,this->ifaceLeavingTime);
    doParsimUnpacking(b,this->controlTowerArrivalTime);
    doParsimUnpacking(b,this->packetLength);
}

int AeroPacket::getSender() const
{
    return this->sender;
}

void AeroPacket::setSender(int sender)
{
    this->sender = sender;
}

::omnetpp::simtime_t AeroPacket::getGenerationTime() const
{
    return this->generationTime;
}

void AeroPacket::setGenerationTime(::omnetpp::simtime_t generationTime)
{
    this->generationTime = generationTime;
}

::omnetpp::simtime_t AeroPacket::getQueueLeavingTime() const
{
    return this->queueLeavingTime;
}

void AeroPacket::setQueueLeavingTime(::omnetpp::simtime_t queueLeavingTime)
{
    this->queueLeavingTime = queueLeavingTime;
}

::omnetpp::simtime_t AeroPacket::getIfaceLeavingTime() const
{
    return this->ifaceLeavingTime;
}

void AeroPacket::setIfaceLeavingTime(::omnetpp::simtime_t ifaceLeavingTime)
{
    this->ifaceLeavingTime = ifaceLeavingTime;
}

::omnetpp::simtime_t AeroPacket::getControlTowerArrivalTime() const
{
    return this->controlTowerArrivalTime;
}

void AeroPacket::setControlTowerArrivalTime(::omnetpp::simtime_t controlTowerArrivalTime)
{
    this->controlTowerArrivalTime = controlTowerArrivalTime;
}

int AeroPacket::getPacketLength() const
{
    return this->packetLength;
}

void AeroPacket::setPacketLength(int packetLength)
{
    this->packetLength = packetLength;
}

class AeroPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    AeroPacketDescriptor();
    virtual ~AeroPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(AeroPacketDescriptor)

AeroPacketDescriptor::AeroPacketDescriptor() : omnetpp::cClassDescriptor("AeroPacket", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

AeroPacketDescriptor::~AeroPacketDescriptor()
{
    delete[] propertynames;
}

bool AeroPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AeroPacket *>(obj)!=nullptr;
}

const char **AeroPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *AeroPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int AeroPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int AeroPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *AeroPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sender",
        "generationTime",
        "queueLeavingTime",
        "ifaceLeavingTime",
        "controlTowerArrivalTime",
        "packetLength",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int AeroPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sender")==0) return base+0;
    if (fieldName[0]=='g' && strcmp(fieldName, "generationTime")==0) return base+1;
    if (fieldName[0]=='q' && strcmp(fieldName, "queueLeavingTime")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "ifaceLeavingTime")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "controlTowerArrivalTime")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetLength")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *AeroPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **AeroPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AeroPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AeroPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    AeroPacket *pp = (AeroPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *AeroPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AeroPacket *pp = (AeroPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AeroPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    AeroPacket *pp = (AeroPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSender());
        case 1: return simtime2string(pp->getGenerationTime());
        case 2: return simtime2string(pp->getQueueLeavingTime());
        case 3: return simtime2string(pp->getIfaceLeavingTime());
        case 4: return simtime2string(pp->getControlTowerArrivalTime());
        case 5: return long2string(pp->getPacketLength());
        default: return "";
    }
}

bool AeroPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    AeroPacket *pp = (AeroPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setSender(string2long(value)); return true;
        case 1: pp->setGenerationTime(string2simtime(value)); return true;
        case 2: pp->setQueueLeavingTime(string2simtime(value)); return true;
        case 3: pp->setIfaceLeavingTime(string2simtime(value)); return true;
        case 4: pp->setControlTowerArrivalTime(string2simtime(value)); return true;
        case 5: pp->setPacketLength(string2long(value)); return true;
        default: return false;
    }
}

const char *AeroPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *AeroPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    AeroPacket *pp = (AeroPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


