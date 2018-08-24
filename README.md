UDPoverTCP
==========

Bridge to transfer broadcast UDP packets over a TCP network.

SNBGui
======

The SNBGui is a graphical interface to start the bridge. It has two working
modes: "UDP to TCP", and "TCP to UDP".

"UDP to TCP" can be used to set the udp port to listen for udp-packets, and
the tcp-port on which the tcp-connection can be established.

"TCP to UDP" can be used to set the host address and tcp port to connect to,
and the udp-port on which the udp-packets will be broadcasted again.

SNBTests
========

The SNBTests currently contains one test: broadcasting udp-packets on one port
and receiving udp-packets on another. When used with SNBGui (or the command-
line version) this can be setup such that we can test if the bridge works.

To test the bridge make sure that SNBTests broadcasts at the udp port SNBGui
is listening on, and that SNBTests listends at the port the SNBGui is
broadcasting on.

License
=======

See the LICENSE file in this repository.

Copyright
=========

Written by Patrick Hanckmann (hanckmann@gmail.com).

To Do
=====

The command-line version needs to be finalised.

Known issues
============

None currently.

If you find any, please contact me via the issue tracker!
# UDPoverTCP_gcc
