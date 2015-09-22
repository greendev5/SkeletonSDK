#ifndef __SKLT_IMPL_H
#define __SKLT_IMPL_H

#include <string>
#include <list>

class SkeletonImpl
{

public:
	SkeletonImpl();
	~SkeletonImpl();

	void copy_internals(char* dst, unsigned int dstSize);

private:
	std::list<std::string> _internals;
};


#endif //__SKLT_IMPL_H
