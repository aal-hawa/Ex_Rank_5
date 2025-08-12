#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}
TargetGenerator::~TargetGenerator()
{}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
	{
		std::map<std::string, ATarget *>::iterator it = book.find(target->getType());
		if (it == book.end())
			book[target->getType()] = target->clone();
	}
}
void TargetGenerator::forgetTargetType(std::string const &target)
{
	std::map<std::string, ATarget *>::iterator it = book.find(target);
	if (it != book.end())
	{
		delete it->second;
		book.erase(target);
	}
}
ATarget* TargetGenerator::createTarget(std::string const &target)
{
	std::map<std::string, ATarget *>::iterator it = book.find(target);
	if (it != book.end())
		return (it->second);
	return nullptr;
}