#include <glow/Referenced.h>

using namespace glow;

Referenced::Referenced()
: _refCounter(0)
{
}

Referenced::Referenced(const Referenced&)
: _refCounter(0)
{
}


Referenced::~Referenced()
{
}

Referenced& Referenced::operator=(const Referenced&)
{
	_refCounter = 0;
	return *this;
}

void Referenced::ref()
{
	_refCounter++;
}

void Referenced::unref()
{
	_refCounter--;
}

int Referenced::refCounter() const
{
	return _refCounter;
}