
#pragma once
//EXTERNAL INCLUDES
#include <list>
//INTERNAL INCLUDES

//Class Node
class Node 
{
//Declare public virtual functions.
public:
	Node();

	virtual void Update(void);

	virtual void SetParent(Node* parent);
	virtual void DeleteParents();
	virtual void DeleteChildren();

	virtual void MakeRoot(void);

	virtual void AddChild(Node* node);


	virtual void operator+=(Node* child);
	virtual void operator-=(Node* child);
	virtual bool operator==(Node* other);

//Declare private variables.
private:
	bool isRoot;

	Node* parent;
	std::list<Node*> children;
};