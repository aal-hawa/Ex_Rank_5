#include "SpellBook.hpp"

	SpellBook::SpellBook()
	{}
	SpellBook::~SpellBook()
	{}

	void SpellBook::learnSpell(ASpell *spell)
	{
		if (spell)
		{
			std::map<std::string, ASpell *>::iterator it = book.find(spell->getName());
			if (it == book.end())
				book[spell->getName()] = spell->clone();
		}
	}
	void SpellBook::forgetSpell(std::string const &spell)
	{
		std::map<std::string, ASpell *>::iterator it = book.find(spell);
		if (it != book.end())
		{
			delete it->second;
			book.erase(spell);
		}
	}
	ASpell* SpellBook::createSpell(std::string const &spell)
	{
		std::map<std::string, ASpell *>::iterator it = book.find(spell);
		if (it != book.end())
			return (it->second);
		return nullptr;
	}