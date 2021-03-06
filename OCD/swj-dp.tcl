{\rtf1\ansi\ansicpg1252\deff0\deflang1031{\fonttbl{\f0\fswiss\fcharset0 Arial;}}
{\*\generator Msftedit 5.41.15.1515;}\viewkind4\uc1\pard\f0\fs20 # ARM Debug Interface V5 (ADI_V5) utility\par
# ... Mostly for SWJ-DP (not SW-DP or JTAG-DP, since\par
# SW-DP and JTAG-DP targets don't need to switch based\par
# on which transport is active.\par
#\par
# declare a JTAG or SWD Debug Access Point (DAP)\par
# based on the transport in use with this session.\par
# You can't access JTAG ops when SWD is active, etc.\par
\par
# params are currently what "jtag newtap" uses\par
# because OpenOCD internals are still strongly biased\par
# to JTAG ....  but for SWD, "irlen" etc are ignored,\par
# and the internals work differently\par
\par
# for now, ignore non-JTAG and non-SWD transports\par
# (e.g. initial flash programming via SPI or UART)\par
\par
# split out "chip" and "tag" so we can someday handle\par
# them more uniformly irlen too...)\par
\par
proc swj_newdap \{chip tag args\} \{\par
set tran [transport select]\par
if [string equal $tran "jtag"] \{ eval jtag newtap $chip $tag $args\}\par
if [string equal $tran "swd"] \{ eval swd newdap $chip $tag $args \}\par
\}\par
}
 