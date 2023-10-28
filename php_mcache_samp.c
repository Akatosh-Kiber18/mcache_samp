#include "php.h"
#include "mcache_samp.h"

zend_module_entry mcache_samp_module_entry = {
    STANDARD_MODULE_HEADER,
    "mcache_samp",        // Extension name
    NULL,                         // No dependencies
    NULL,                         // Module initialization function
    NULL,                         // Module shutdown function
    NULL,                         // Request initialization function
    NULL,                         // Request shutdown function
    NULL,                         // Module information
    "1.0",                        // Extension version
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(mcache_samp)
