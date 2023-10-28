#ifndef PHP_CACHE_EXTENSION_H
#define PHP_CACHE_EXTENSION_H

#ifdef __cplusplus
extern "C" {
#include "php.h"
}
#endif

// Define a struct to hold the cache data.
typedef struct {
    zend_object std;
    zend_array* cache;
} cache_object;

// Cache methods
PHP_METHOD(Cache, __construct);
PHP_METHOD(Cache, set);
PHP_METHOD(Cache, get);
PHP_METHOD(Cache, delete);

// Extension initialization function
PHP_MINIT_FUNCTION(cache);

// Define the Cache class entry
extern zend_class_entry* cache_ce;

// Extension setup
extern const zend_function_entry cache_methods[];

#endif /* PHP_CACHE_EXTENSION_H */
