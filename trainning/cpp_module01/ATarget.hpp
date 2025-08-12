#pragma once
#include <iostream>
#include "ASpell.hpp"

class ASpell;
class ATarget
{
	protected:
		std::string _type;
	public:
		const std::string &getType() const;

		virtual ATarget* clone() const = 0;

		ATarget(const std::string &type);
		virtual ~ATarget();

		void getHitBySpell(const ASpell &spell) const;
};