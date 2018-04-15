#ifndef LIBPIRATES_CONFIG_H
#define LIBPIRATES_CONFIG_H

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <pandabase.h>
#include <notifyCategoryProxy.h>

#pragma warning (disable : 4273)
#pragma warning (disable : 4275)

#ifdef BUILDING_LIBPIRATES
	#define EXPCL_LIBPIRATES EXPORT_CLASS
	#define EXPTP_LIBPIRATES EXPORT_TEMPL
#else 
	#define EXPCL_LIBPIRATES IMPORT_CLASS
	#define EXPTP_LIBPIRATES IMPORT_TEMPL
#endif

NotifyCategoryDecl(libpirates, EXPCL_LIBPIRATES, EXPTP_LIBPIRATES);
extern EXPCL_LIBPIRATES void init_libpirates();

#endif