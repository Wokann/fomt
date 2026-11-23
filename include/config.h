#ifndef GUARD_CONFIG_H
#define GUARD_CONFIG_H

// Uncomment to enable optional fixes for retail game bugs.
//#define BUGFIX

// Uncomment to enable optional regional unification.
//#define UNIFY_REGIONS

#ifdef UNIFY_REGIONS
#ifndef BUGFIX
#define BUGFIX
#endif
#endif

#endif // GUARD_CONFIG_H
