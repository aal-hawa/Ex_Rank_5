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

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
}