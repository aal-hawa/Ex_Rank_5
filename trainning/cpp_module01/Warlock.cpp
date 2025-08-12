#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

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


void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
	{
		std::map<std::string, ASpell *>::iterator it = book.find(spell->getName());
		if (it == book.end())
			book[spell->getName()] = spell->clone();
	}
}
void Warlock::forgetSpell(std::string spell)
{
	std::map<std::string, ASpell *>::iterator it = book.find(spell);
	if (it != book.end())
	{
		delete it->second;
		book.erase(spell);
	}
}
void Warlock::launchSpell(std::string spell, ATarget &target)
{
	std::map<std::string, ASpell *>::iterator it = book.find(spell);
	if (it != book.end())
		it->second->launch(target);
}


int main()
{
	Warlock riched("Reched", "the Titled");

	Dummy bob;
	Fwoosh* fwoosh = new Fwoosh();
	riched.learnSpell(fwoosh);

	riched.introduce();
	riched.launchSpell("Fwoosh", bob);

	riched.forgetSpell("Fwoosh");
	riched.launchSpell("Fwoosh", bob);
}