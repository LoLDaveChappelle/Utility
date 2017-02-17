#pragma once
#include <string>

class ICastable
{
public:
	virtual ~ICastable() = default;

	virtual std::string getName() const = 0;
	virtual bool shouldCast() const = 0;
	virtual void cast() const = 0;
};
