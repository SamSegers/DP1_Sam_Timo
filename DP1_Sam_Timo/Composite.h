#ifndef _COMPOSITE_H
#define _COMPOSITE_H

#include "Component.h"

// samenstelling omdat er meestal ook wel iets voor/achter zit.
class Composite : public Component
{
protected:
	std::vector<Composite *> pComponents;
	std::vector<Composite *> PreviousComponents;
public:
	~Composite();
	virtual void DoThis();

	std::vector<Composite*> GetNext();
	std::vector<Composite*> GetPrevious();
	virtual void AddChild(Composite *Next);

	void SetPreviousComponent(Composite *Previous);
};

#endif