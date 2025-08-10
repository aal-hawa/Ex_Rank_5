#include "ATarget.hpp"

const std::string &ATarget::getType() const
{
	return this->_type;
}


ATarget::ATarget(const std::string &type) : _type(type)
{

}
ATarget::~ATarget()
{

}

void ATarget::getHitBySpell(const ASpell &src) const
{
	std::cout << getType() << " has been " << src.getEffects() << "!" << std::endl;
}