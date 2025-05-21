//
// Generated file, do not edit! Created by opp_msgtool 6.0 from veins/modules/messages/TraCITrafficLightMessage.msg.
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
#include "TraCITrafficLightMessage_m.h"

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

Register_Enum(veins::TrafficLightAtrributeType, (veins::TrafficLightAtrributeType::NONE, veins::TrafficLightAtrributeType::LOGICID, veins::TrafficLightAtrributeType::PHASEID, veins::TrafficLightAtrributeType::SWITCHTIME, veins::TrafficLightAtrributeType::STATE));

Register_Enum(veins::TrafficLightChangeSource, (veins::TrafficLightChangeSource::UNKNOWN, veins::TrafficLightChangeSource::SUMO, veins::TrafficLightChangeSource::LOGIC, veins::TrafficLightChangeSource::RSU));

Register_Class(TraCITrafficLightMessage)

TraCITrafficLightMessage::TraCITrafficLightMessage(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

TraCITrafficLightMessage::TraCITrafficLightMessage(const TraCITrafficLightMessage& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

TraCITrafficLightMessage::~TraCITrafficLightMessage()
{
}

TraCITrafficLightMessage& TraCITrafficLightMessage::operator=(const TraCITrafficLightMessage& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void TraCITrafficLightMessage::copy(const TraCITrafficLightMessage& other)
{
    this->tlId = other.tlId;
    this->changedAttribute = other.changedAttribute;
    this->oldValue = other.oldValue;
    this->newValue = other.newValue;
    this->changeSource = other.changeSource;
}

void TraCITrafficLightMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->tlId);
    doParsimPacking(b,this->changedAttribute);
    doParsimPacking(b,this->oldValue);
    doParsimPacking(b,this->newValue);
    doParsimPacking(b,this->changeSource);
}

void TraCITrafficLightMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->tlId);
    doParsimUnpacking(b,this->changedAttribute);
    doParsimUnpacking(b,this->oldValue);
    doParsimUnpacking(b,this->newValue);
    doParsimUnpacking(b,this->changeSource);
}

const char * TraCITrafficLightMessage::getTlId() const
{
    return this->tlId.c_str();
}

void TraCITrafficLightMessage::setTlId(const char * tlId)
{
    this->tlId = tlId;
}

int TraCITrafficLightMessage::getChangedAttribute() const
{
    return this->changedAttribute;
}

void TraCITrafficLightMessage::setChangedAttribute(int changedAttribute)
{
    this->changedAttribute = changedAttribute;
}

const char * TraCITrafficLightMessage::getOldValue() const
{
    return this->oldValue.c_str();
}

void TraCITrafficLightMessage::setOldValue(const char * oldValue)
{
    this->oldValue = oldValue;
}

const char * TraCITrafficLightMessage::getNewValue() const
{
    return this->newValue.c_str();
}

void TraCITrafficLightMessage::setNewValue(const char * newValue)
{
    this->newValue = newValue;
}

int TraCITrafficLightMessage::getChangeSource() const
{
    return this->changeSource;
}

void TraCITrafficLightMessage::setChangeSource(int changeSource)
{
    this->changeSource = changeSource;
}

class TraCITrafficLightMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_tlId,
        FIELD_changedAttribute,
        FIELD_oldValue,
        FIELD_newValue,
        FIELD_changeSource,
    };
  public:
    TraCITrafficLightMessageDescriptor();
    virtual ~TraCITrafficLightMessageDescriptor();

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

Register_ClassDescriptor(TraCITrafficLightMessageDescriptor)

TraCITrafficLightMessageDescriptor::TraCITrafficLightMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::TraCITrafficLightMessage)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

TraCITrafficLightMessageDescriptor::~TraCITrafficLightMessageDescriptor()
{
    delete[] propertyNames;
}

bool TraCITrafficLightMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TraCITrafficLightMessage *>(obj)!=nullptr;
}

const char **TraCITrafficLightMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TraCITrafficLightMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TraCITrafficLightMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int TraCITrafficLightMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_tlId
        FD_ISEDITABLE,    // FIELD_changedAttribute
        FD_ISEDITABLE,    // FIELD_oldValue
        FD_ISEDITABLE,    // FIELD_newValue
        FD_ISEDITABLE,    // FIELD_changeSource
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *TraCITrafficLightMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tlId",
        "changedAttribute",
        "oldValue",
        "newValue",
        "changeSource",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int TraCITrafficLightMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "tlId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "changedAttribute") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "oldValue") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "newValue") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "changeSource") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *TraCITrafficLightMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_tlId
        "int",    // FIELD_changedAttribute
        "string",    // FIELD_oldValue
        "string",    // FIELD_newValue
        "int",    // FIELD_changeSource
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **TraCITrafficLightMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_changedAttribute: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        case FIELD_changeSource: {
            static const char *names[] = { "enum", "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *TraCITrafficLightMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_changedAttribute:
            if (!strcmp(propertyName, "enum")) return "TrafficLightAtrributeType";
            if (!strcmp(propertyName, "enum")) return "veins::TrafficLightAtrributeType";
            return nullptr;
        case FIELD_changeSource:
            if (!strcmp(propertyName, "enum")) return "TrafficLightChangeSource";
            if (!strcmp(propertyName, "enum")) return "veins::TrafficLightChangeSource";
            return nullptr;
        default: return nullptr;
    }
}

int TraCITrafficLightMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    TraCITrafficLightMessage *pp = omnetpp::fromAnyPtr<TraCITrafficLightMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TraCITrafficLightMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    TraCITrafficLightMessage *pp = omnetpp::fromAnyPtr<TraCITrafficLightMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TraCITrafficLightMessage'", field);
    }
}

const char *TraCITrafficLightMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    TraCITrafficLightMessage *pp = omnetpp::fromAnyPtr<TraCITrafficLightMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TraCITrafficLightMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    TraCITrafficLightMessage *pp = omnetpp::fromAnyPtr<TraCITrafficLightMessage>(object); (void)pp;
    switch (field) {
        case FIELD_tlId: return oppstring2string(pp->getTlId());
        case FIELD_changedAttribute: return enum2string(pp->getChangedAttribute(), "veins::TrafficLightAtrributeType");
        case FIELD_oldValue: return oppstring2string(pp->getOldValue());
        case FIELD_newValue: return oppstring2string(pp->getNewValue());
        case FIELD_changeSource: return enum2string(pp->getChangeSource(), "veins::TrafficLightChangeSource");
        default: return "";
    }
}

void TraCITrafficLightMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TraCITrafficLightMessage *pp = omnetpp::fromAnyPtr<TraCITrafficLightMessage>(object); (void)pp;
    switch (field) {
        case FIELD_tlId: pp->setTlId((value)); break;
        case FIELD_changedAttribute: pp->setChangedAttribute((veins::TrafficLightAtrributeType)string2enum(value, "veins::TrafficLightAtrributeType")); break;
        case FIELD_oldValue: pp->setOldValue((value)); break;
        case FIELD_newValue: pp->setNewValue((value)); break;
        case FIELD_changeSource: pp->setChangeSource((veins::TrafficLightChangeSource)string2enum(value, "veins::TrafficLightChangeSource")); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TraCITrafficLightMessage'", field);
    }
}

omnetpp::cValue TraCITrafficLightMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    TraCITrafficLightMessage *pp = omnetpp::fromAnyPtr<TraCITrafficLightMessage>(object); (void)pp;
    switch (field) {
        case FIELD_tlId: return pp->getTlId();
        case FIELD_changedAttribute: return pp->getChangedAttribute();
        case FIELD_oldValue: return pp->getOldValue();
        case FIELD_newValue: return pp->getNewValue();
        case FIELD_changeSource: return pp->getChangeSource();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'TraCITrafficLightMessage' as cValue -- field index out of range?", field);
    }
}

void TraCITrafficLightMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TraCITrafficLightMessage *pp = omnetpp::fromAnyPtr<TraCITrafficLightMessage>(object); (void)pp;
    switch (field) {
        case FIELD_tlId: pp->setTlId(value.stringValue()); break;
        case FIELD_changedAttribute: pp->setChangedAttribute((veins::TrafficLightAtrributeType)value.intValue()); break;
        case FIELD_oldValue: pp->setOldValue(value.stringValue()); break;
        case FIELD_newValue: pp->setNewValue(value.stringValue()); break;
        case FIELD_changeSource: pp->setChangeSource((veins::TrafficLightChangeSource)value.intValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TraCITrafficLightMessage'", field);
    }
}

const char *TraCITrafficLightMessageDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr TraCITrafficLightMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    TraCITrafficLightMessage *pp = omnetpp::fromAnyPtr<TraCITrafficLightMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TraCITrafficLightMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    TraCITrafficLightMessage *pp = omnetpp::fromAnyPtr<TraCITrafficLightMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TraCITrafficLightMessage'", field);
    }
}

}  // namespace veins

namespace omnetpp {

}  // namespace omnetpp

