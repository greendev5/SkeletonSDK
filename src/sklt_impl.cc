#include <cstring>
#include "sklt_impl.h"


SkeletonImpl::SkeletonImpl()
{
	_internals.push_back("1");
	_internals.push_back("2");
	_internals.push_back("3");
}

SkeletonImpl::~SkeletonImpl()
{
}

void SkeletonImpl::copy_internals(char* dst, unsigned int dstSize)
{
	std::string res("");
	memset(dst, 0, dstSize);
	for (std::list<std::string>::iterator it=_internals.begin(); it != _internals.end(); ++it)
		res += *it + ", ";
	if (res.length() > dstSize - 1)
		return;
	else
		memcpy(dst, res.c_str(), res.length());
}
