#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
	std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << getName() << ": My job here is done!" << std::endl;

}
const std::string &Warlock::getName() const
{
	return this->_name;
}

const std::string& Warlock::getTitle() const
{
	return this->_title;

}

void Warlock::setTitle(const std::string &title)
{
	this->_title = title;
}

void Warlock::introduce() const
{
	std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	book.learnSpell(spell);
}
void Warlock::forgetSpell(std::string spell)
{
	book.forgetSpell(spell);
}
void Warlock::launchSpell(std::string spell, ATarget &target)
{
	ASpell *sp = book.createSpell(spell);
	if (sp)
		sp->launch(target);
}

// int main()
// {
// 	Warlock riched("Riched", "foo");
// 	riched.setTitle("Hello, I'm Riched the Warlock!");
// 	BrickWall model1;

// 	Polymorph* polymorph = new Polymorph();
// 	TargetGenerator tarGen;

// 	tarGen.learnTargetType(&model1);
// 	riched.learnSpell(polymorph);

// 	Fireball* fireball = new Fireball();
// 	riched.learnSpell(fireball);

// 	ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

// 	riched.introduce();
// 	riched.launchSpell("Polymorph", *wall);
// 	riched.launchSpell("Fireball", *wall);
// }