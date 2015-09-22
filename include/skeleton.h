#ifndef __SKELETON_H
#define __SKELETON_H

//Below macros will default appropriately
#if defined SKELETON_DLL_COMPILE
	#if defined _WIN32
		#define USE_EXPORT __declspec(dllexport)
	#elif defined __APPLE__
		#define USE_EXPORT __attribute__((__visibility__("default")))
	#elif defined __ANDROID__
		#define USE_EXPORT __attribute__ ((visibility ("default")))    
	#else
		#define USE_EXPORT __declspec(dllexport)
	#endif
#elif defined SKELETON_STATIC_COMPILE
	#if defined _WIN32
		#define USE_EXPORT
	#elif defined __APPLE__ 
		#define USE_EXPORT __attribute__((__visibility__("default")))
	#elif defined __ANDROID__						   
		#define USE_EXPORT __attribute__ ((visibility ("default")))
	#else
		#define USE_EXPORT 
	#endif
#else
	#if defined __ANDROID__
		#define USE_EXPORT 
	#elif defined __APPLE__
		#define USE_EXPORT
	#else
		#define USE_EXPORT __declspec(dllimport)
	#endif
#endif

//Below Macros are taken from compiler environment
#if defined _WIN32
	#define SKLTEXPORT  USE_EXPORT
	#define SKLTCC __cdecl	//calling convention used by the library
#elif defined __APPLE__
	#define SKLTEXPORT USE_EXPORT
	#define SKLTCC  //calling convention used by the library
#elif defined __ANDROID__
	#define SKLTEXPORT USE_EXPORT
	#define SKLTCC 	//calling convention used by the library
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void SkeletonHandleType;

typedef enum
{
	SKLT_ERR_SUCCESS,
	SKLT_ERR_RESOURCE_ERROR,
} SKLTErrType;


//
SKLTEXPORT SKLTErrType SKLTCC SKLTInit(SkeletonHandleType **skltHnd);

//
SKLTEXPORT SKLTErrType SKLTCC SKLTDeInit(SkeletonHandleType *skltHnd);

//
SKLTEXPORT SKLTErrType SKLTCC SKLTGetInternals(SkeletonHandleType *skltHnd, char* dst, unsigned int dstSize);

#ifdef __cplusplus
}
#endif

#endif // __SKELETON_H
