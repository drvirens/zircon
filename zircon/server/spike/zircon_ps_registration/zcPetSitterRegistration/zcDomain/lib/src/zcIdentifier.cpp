#include "zcIdentifier.h"

zcIdentifier::zcIdentifier() : id_("")
{
}

zcIdentifier::~zcIdentifier()
{
}

zcIdentifier::zcIdentifier(const std::string &aId)
    : id_(aId)
{
}
std::string zcIdentifier::Id() const
{
    return id_;
}