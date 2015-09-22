#include <skeleton.h>
#include "sklt_impl.h"


SKLTErrType SKLTCC SKLTInit(SkeletonHandleType **skltHnd)
{
	*skltHnd = reinterpret_cast<SkeletonHandleType*>(new SkeletonImpl);
	return SKLT_ERR_SUCCESS;
}

SKLTErrType SKLTCC SKLTDeInit(SkeletonHandleType *skltHnd)
{
	delete reinterpret_cast<SkeletonImpl*>(skltHnd);
	return SKLT_ERR_SUCCESS;
}

SKLTErrType SKLTCC SKLTGetInternals(SkeletonHandleType *skltHnd, char* dst, unsigned int dstSize)
{
	SkeletonImpl *impl = reinterpret_cast<SkeletonImpl*>(skltHnd);
	impl->copy_internals(dst, dstSize);
	return SKLT_ERR_SUCCESS;
}
