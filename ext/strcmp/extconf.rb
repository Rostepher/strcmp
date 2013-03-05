require 'mkmf'
$CFLAGS = "-std=c11 " + $CFLAGS
create_makefile "strcmp"