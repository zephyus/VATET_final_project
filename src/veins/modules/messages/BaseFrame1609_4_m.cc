//
// Generated file, do not edit! Created by opp_msgtool 6.0 from veins/modules/messages/BaseFrame1609_4.msg.
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
#include <memory>
#include <type_traits>
#include "BaseFrame1609_4_m.h"

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
    for (int i = 0; i < n; i++) {
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
    for (int i = 0; i < n; i++) {
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
    for (int i = 0; i < n; i++) {
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

namespace veins {

Register_Class(BaseFrame1609_4)

BaseFrame1609_4::BaseFrame1609_4(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

BaseFrame1609_4::BaseFrame1609_4(const BaseFrame1609_4& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

BaseFrame1609_4::~BaseFrame1609_4()
{
}

BaseFrame1609_4& BaseFrame1609_4::operator=(const BaseFrame1609_4& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void BaseFrame1609_4::copy(const BaseFrame1609_4& other)
{
    this->channelNumber = other.channelNumber;
    this->userPriority = other.userPriority;
    this->psid = other.psid;
    this->recipientAddress = other.recipientAddress;
}

void BaseFrame1609_4::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->channelNumber);
    doParsimPacking(b,this->userPriority);
    doParsimPacking(b,this->psid);
    doParsimPacking(b,this->recipientAddress);
}

void BaseFrame1609_4::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->channelNumber);
    doParsimUnpacking(b,this->userPriority);
    doParsimUnpacking(b,this->psid);
    doParsimUnpacking(b,this->recipientAddress);
}

int BaseFrame1609_4::getChannelNumber() const
{
    return this->channelNumber;
}

void BaseFrame1609_4::setChannelNumber(int channelNumber)
{
    this->channelNumber = channelNumber;
}

int BaseFrame1609_4::getUserPriority() const
{
    return this->userPriority;
}

void BaseFrame1609_4::setUserPriority(int userPriority)
{
    this->userPriority = userPriority;
}

int BaseFrame1609_4::getPsid() const
{
    return this->psid;
}

void BaseFrame1609_4::setPsid(int psid)
{
    this->psid = psid;
}

const LAddress::L2Type& BaseFrame1609_4::getRecipientAddress() const
{
    return this->recipientAddress;
}

void BaseFrame1609_4::setRecipientAddress(const LAddress::L2Type& recipientAddress)
{
    this->recipientAddress = recipientAddress;
}

class BaseFrame1609_4Descriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_channelNumber,
        FIELD_userPriority,
        FIELD_psid,
        FIELD_recipientAddress,
    };
  public:
    BaseFrame1609_4Descriptor();
    virtual ~BaseFrame1609_4Descriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(BaseFrame1609_4Descriptor)

BaseFrame1609_4Descriptor::BaseFrame1609_4Descriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::BaseFrame1609_4)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

BaseFrame1609_4Descriptor::~BaseFrame1609_4Descriptor()
{
    delete[] propertyNames;
}

bool BaseFrame1609_4Descriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BaseFrame1609_4 *>(obj)!=nullptr;
}

const char **BaseFrame1609_4Descriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *BaseFrame1609_4Descriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int BaseFrame1609_4Descriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int BaseFrame1609_4Descriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_channelNumber
        FD_ISEDITABLE,    // FIELD_userPriority
        FD_ISEDITABLE,    // FIELD_psid
        0,    // FIELD_recipientAddress
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *BaseFrame1609_4Descriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "channelNumber",
        "userPriority",
        "psid",
        "recipientAddress",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int BaseFrame1609_4Descriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "channelNumber") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "userPriority") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "psid") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "recipientAddress") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *BaseFrame1609_4Descriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_channelNumber
        "int",    // FIELD_userPriority
        "int",    // FIELD_psid
        "veins::LAddress::L2Type",    // FIELD_recipientAddress
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **BaseFrame1609_4Descriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *BaseFrame1609_4Descriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int BaseFrame1609_4Descriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    BaseFrame1609_4 *pp = omnetpp::fromAnyPtr<BaseFrame1609_4>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BaseFrame1609_4Descriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    BaseFrame1609_4 *pp = omnetpp::fromAnyPtr<BaseFrame1609_4>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BaseFrame1609_4'", field);
    }
}

const char *BaseFrame1609_4Descriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    BaseFrame1609_4 *pp = omnetpp::fromAnyPtr<BaseFrame1609_4>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BaseFrame1609_4Descriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    BaseFrame1609_4 *pp = omnetpp::fromAnyPtr<BaseFrame1609_4>(object); (void)pp;
    switch (field) {
        case FIELD_channelNumber: return long2string(pp->getChannelNumber());
        case FIELD_userPriority: return long2string(pp->getUserPriority());
        case FIELD_psid: return long2string(pp->getPsid());
        case FIELD_recipientAddress: return "";
        default: return "";
    }
}

void BaseFrame1609_4Descriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    BaseFrame1609_4 *pp = omnetpp::fromAnyPtr<BaseFrame1609_4>(object); (void)pp;
    switch (field) {
        case FIELD_channelNumber: pp->setChannelNumber(string2long(value)); break;
        case FIELD_userPriority: pp->setUserPriority(string2long(value)); break;
        case FIELD_psid: pp->setPsid(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BaseFrame1609_4'", field);
    }
}

omnetpp::cValue BaseFrame1609_4Descriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    BaseFrame1609_4 *pp = omnetpp::fromAnyPtr<BaseFrame1609_4>(object); (void)pp;
    switch (field) {
        case FIELD_channelNumber: return pp->getChannelNumber();
        case FIELD_userPriority: return pp->getUserPriority();
        case FIELD_psid: return pp->getPsid();
        case FIELD_recipientAddress: return omnetpp::toAnyPtr(&pp->getRecipientAddress()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'BaseFrame1609_4' as cValue -- field index out of range?", field);
    }
}

void BaseFrame1609_4Descriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    BaseFrame1609_4 *pp = omnetpp::fromAnyPtr<BaseFrame1609_4>(object); (void)pp;
    switch (field) {
        case FIELD_channelNumber: pp->setChannelNumber(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_userPriority: pp->setUserPriority(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_psid: pp->setPsid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BaseFrame1609_4'", field);
    }
}

const char *BaseFrame1609_4Descriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr BaseFrame1609_4Descriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    BaseFrame1609_4 *pp = omnetpp::fromAnyPtr<BaseFrame1609_4>(object); (void)pp;
    switch (field) {
        case FIELD_recipientAddress: return omnetpp::toAnyPtr(&pp->getRecipientAddress()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void BaseFrame1609_4Descriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    BaseFrame1609_4 *pp = omnetpp::fromAnyPtr<BaseFrame1609_4>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BaseFrame1609_4'", field);
    }
}

}  // namespace veins

namespace omnetpp {

}  // namespace omnetpp

