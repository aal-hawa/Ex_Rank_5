#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title): _name(name), _title(title)
{
	std::cout << getName() << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
	std::cout << getName() << ": My job here is done!" << std::endl;
}
const std::string& Warlock::getName() const
{
	return this->_name;
}
const std::string &Warlock::getTitle() const
{
	return this->_title;
}
void Warlock::setTitle(const std::string &title)
{
	this->_title = title;
}
void Warlock::introduce() const
{
	std::cout << getName() << ": I am " <<getName() << ", " << getTitle() << "!" << std::endl;
}


int main()
{
	Warlock const richard("Richard", "Mistress of Magma");
	richard.introduce();
	std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

	Warlock* jack = new Warlock("Jack", "the long");
	jack->introduce();
	jack->setTitle("the Mighty");
	jack->introduce();
	delete jack;

	return 0;
}