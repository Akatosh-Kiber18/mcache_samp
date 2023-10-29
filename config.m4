PHP_ARG_ENABLE(mcache_samp,
  [Whether to enable the "mcache_samp" extension],
  [  --enable-mcache        Enable "mcache_samp" extension support])

if test $PHP_MCACHE_SAMP != "no"; then
  PHP_SUBST(MCACHE_SAMP_SHARED_LIBADD)
  PHP_NEW_EXTENSION(mcache_samp, php_mcache_samp.c, $ext_shared)
fi
