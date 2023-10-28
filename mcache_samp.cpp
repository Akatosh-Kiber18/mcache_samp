extern "C" {
#include "php.h"
}

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
PHP_MINIT_FUNCTION(cache) {
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "Cache", NULL);
    cache_ce = zend_register_internal_class(&ce);
    cache_ce->create_object = cache_create_object;

    zend_declare_property_null(cache_ce, "cacheData", sizeof("cacheData") - 1, ZEND_ACC_PRIVATE);

    zend_declare_class_constant_long(cache_ce, "CACHE_HIT", sizeof("CACHE_HIT") - 1, 1);
    zend_declare_class_constant_long(cache_ce, "CACHE_MISS", sizeof("CACHE_MISS") - 1, 0);

    return SUCCESS;
}

// Constructor
PHP_METHOD(Cache, __construct) {
    cache_object* obj = Z_CACHE_P(getThis());
    obj->cache = zend_new_array(1);

    zend_update_property(cache_ce, getThis(), "cacheData", sizeof("cacheData") - 1, obj->cache);
}

// Set a cache value
PHP_METHOD(Cache, set) {
    zend_string* key;
    zval* value;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "Sz", &key, &value) == FAILURE) {
        return;
    }

    cache_object* obj = Z_CACHE_P(getThis());

    zval* copy;
    ZVAL_DUP(copy, value);

    zend_hash_update(obj->cache, key, copy);
}

// Get a cache value
PHP_METHOD(Cache, get) {
    zend_string* key;
    zval* value;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &key) == FAILURE) {
        return;
    }

    cache_object* obj = Z_CACHE_P(getThis());

    if ((value = zend_hash_find(obj->cache, key)) != NULL) {
        RETURN_ZVAL(value, 1, 0);
    } else {
        RETURN_NULL();
    }
}

// Delete a cache value
PHP_METHOD(Cache, delete) {
    zend_string* key;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &key) == FAILURE) {
        return;
    }

    cache_object* obj = Z_CACHE_P(getThis());
    zend_hash_del(obj->cache, key);
}

// Extension setup
const zend_function_entry cache_methods[] = {
    PHP_ME(Cache, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(Cache, set, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Cache, get, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Cache, delete, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

// Extension entry
zend_module_entry cache_module_entry = {
    STANDARD_MODULE_HEADER,
    "cache", // Extension name
    NULL,    // No dependencies
    PHP_MINIT(cache), // Module initialization
    NULL,    // Module shutdown
    NULL,    // Request initialization
    NULL,    // Request shutdown
    NULL,    // Module information
    "1.0",   // Extension version
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_CACHE
ZEND_GET_MODULE(cache)
#endif
