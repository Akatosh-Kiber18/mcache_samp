PHP_ARG_ENABLE(sample,
  [Whether to enable the "mcache_samp" extension],
  [  --enable-mcache        Enable "mcache_samp" extension support])

if test $PHP_SAMPLE != "no"; then
  PHP_SUBST(SAMPLE_SHARED_LIBADD)
  PHP_NEW_EXTENSION(mcache_samp, php_mcache_samp.c, $ext_shared)
fi
