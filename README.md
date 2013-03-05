strcmp
======

Strcmp is a simple ruby gem that is used to compute how similar two strings are
to one another. It includes a fast C implementation of the [jaro-winkler]
(http://en.wikipedia.org/wiki/Jaro%E2%80%93Winkler_distance) distance algorithm
and soon the levenshtein distance algorithm. More metrics on the way. I claim no
ownership of the algorithm.

Installing
==========

    gem install strcmp

Usage
=====

Using the gem is simple. First add the require statement to the file you wish to
use it in.

    require 'strcmp'

To use the gem call:

    StrCmp.jaro_winkler("martha", "marhta") => 0.961111
    StrCmp.jaro("martha", "marhta") => 0.944444

