# mcache_samp

In the repo directory use:
```
phpize
./configure
make
```
Then:

move ```mcache_samp.so``` file to the ```/usr/lib/php/[your PHP version]```

create ```mcache_samp.ini``` file in the ```/etc/php/[your PHP version]/mods-available```

add symlink on ```mcache_samp.ini``` file in the ```/etc/php/[your PHP version]/cli/conf.d```
